/******************************************************************************
 * Copyright (C) 2016-2018 Cadence Design Systems, Inc.
 * All rights reserved worldwide.
 ******************************************************************************
 * csp.h
 * Interface for Configurable System Platform
 *
 * This is the "hardware abstraction layer" for bare-metal software.
 *****************************************************************************/

#ifndef CSP_H
#define CSP_H

#include <cps.h>
#include <cdn_errno.h>
#include <csp_asm.h>

/******************************************************************************
 * Definitions
 *****************************************************************************/

/**
 * csp_stringify macro helper
 */
#define csp_stringify_h(...) \
    #__VA_ARGS__

/**
 * csp_get_irq macro helper, concatenation
 */
#define csp_get_irq_hc(cpu, num, irq_macro) \
    cpu ## num ## _ ## irq_macro

/**
 * csp_get_irq macro helper, evaluation
 */
#define csp_get_irq_he(cpu, num, irq_macro) \
    csp_get_irq_hc(cpu, num, irq_macro)


#ifdef CSP_IO_FUNCTIONS

/**
 * Reads 8-bits
 */
uint8_t csp_read8(volatile uint8_t *addr);

/**
 * Writes 8-bits
 */
void csp_write8(volatile uint8_t *addr, uint8_t data);

/**
 * Reads 16-bits, address should be aligned
 */
uint16_t csp_read16(volatile uint16_t *addr);

/**
 * Writes 16-bits, address should be aligned
 */
void csp_write16(volatile uint16_t *addr, uint16_t data);

/**
 * Reads 32-bits, address should be aligned
 */
uint32_t csp_read32(volatile uint32_t *addr);

/**
 * Writes 32-bits, address should be aligned
 */
void csp_write32(volatile uint32_t *addr, uint32_t data);

/**
 * Reads 64-bits, address should be aligned
 */
uint64_t csp_read64(volatile uint64_t *addr);

/**
 * Writes 64-bits, address should be aligned
 */
void csp_write64(volatile uint64_t *addr, uint64_t data);

#else

/**
 * Reads 8-bits
 */
#define csp_read8(addr) \
    (*((volatile uint8_t *)(addr)))

/**
 * Writes 8-bits
 */
#define csp_write8(addr, data) \
    *((volatile uint8_t *)(addr)) = (data)

/**
 * Reads 16-bits, address should be aligned
 */
#define csp_read16(addr) \
    (*((volatile uint16_t *)(addr)))

/**
 * Writes 16-bits, address should be aligned
 */
#define csp_write16(addr, data) \
    *((volatile uint16_t *)(addr)) = (data)

/**
 * Reads 32-bits, address should be aligned
 */
#define csp_read32(addr) \
    (*((volatile uint32_t *)(addr)))

/**
 * Writes 32-bits, address should be aligned
 */
#define csp_write32(addr, data) \
    *((volatile uint32_t *)(addr)) = (data)

/**
 * Reads 64-bits, address should be aligned
 */
#define csp_read64(addr) \
    (*((volatile uint64_t *)(addr)))

/**
 * Writes 64-bits, address should be aligned
 */
#define csp_write64(addr, data) \
    *((volatile uint64_t *)(addr)) = (data)

#endif


/**
 * Default CSP_IRQ_CTRL values macros
 */
#ifndef CSP_IRQ_CTRL_TYPE
#define CSP_IRQ_CTRL_TYPE \
    CSP_CPU_TYPE
#endif

#ifndef CSP_IRQ_CTRL_NUMBER
#define CSP_IRQ_CTRL_NUMBER \
    CSP_CPU_NUMBER
#endif


/**
 * Converts text or macro to a string
 * Example: csp_stringify(CSP_CPU_TYPE)
 */
#define csp_stringify(...) \
    csp_stringify_h(__VA_ARGS__)

/**
 * Appends IRQ_CTRL name to irq_macro
 * This allows to skip CPU type in the code and make it more portable
 * Example: i2c0_irq_number = csp_get_irq(I2C0_IRQ);
 */
#define csp_get_irq(irq_macro) \
    csp_get_irq_he(CSP_IRQ_CTRL_TYPE, CSP_IRQ_CTRL_NUMBER, irq_macro)


/**
 * Prints a message
 */
#define csp_printf(format, ...) \
    printf(format, ##__VA_ARGS__)

/**
 * Prints an error message
 */
#define csp_printf_error(format, ...) \
    do { \
        csp_printf("ERROR: "); \
        csp_printf(format, ##__VA_ARGS__); \
    } while (0)

/**
 * Prints a warning message
 */
#define csp_printf_warning(format, ...) \
    do { \
        csp_printf("WARNING: "); \
        csp_printf(format, ##__VA_ARGS__); \
    } while (0)

/**
 * Prints an info message
 */
#define csp_printf_info(format, ...) \
    do { \
        csp_printf("INFO: "); \
        csp_printf(format, ##__VA_ARGS__); \
    } while (0)

/**
 * Prints a debug message,
 * if DEBUG is defined, for example using SW_DEBUG=1 parameter
 */
#ifdef DEBUG
#define csp_printf_debug(format, ...) \
    do { \
        csp_printf("DEBUG: "); \
        csp_printf(format, ##__VA_ARGS__); \
    } while (0)
#else
#define csp_printf_debug(...) \
    do {} while (0)
#endif

/******************************************************************************
 * Types
 *****************************************************************************/

typedef uint32_t csp_irq_number_t;
typedef uint32_t csp_result_t;
typedef uint8_t  csp_version_t;

typedef void (*csp_irq_handler_ptr_t)(csp_irq_number_t number);
typedef void (*csp_irq_handler_arg_ptr_t)(void *arg);

typedef enum csp_irq_type {
    CSP_IT_HIGH_LEVEL_SENSITIVE,
    CSP_IT_RISING_EDGE_SENSITIVE,
} csp_irq_type_t;

typedef enum csp_id_flow {
    CSP_IF_FPGA     = 0x0,
    CSP_IF_PROTIUM  = 0x1,
    CSP_IF_ICE      = 0x2,
    CSP_IF_IXCOM    = 0x3,
    CSP_IF_SIM      = 0x4,
    CSP_IF_VSP      = 0x5,
    CSP_IF_TLM      = 0x6,
    CSP_IF_HYBRID   = 0x7,
} csp_id_flow_t;


/******************************************************************************
 * Common functions
 *****************************************************************************/

/**
 * Returns Clock Frequency in Hz, deprecated
 * @return clock frequency
 */
uint32_t csp_get_clock_frequency(void);

/**
 * Returns CPU Clock Frequency in Hz
 * @return clock frequency
 */
uint32_t csp_get_clock_cpu_frequency(void);

/**
 * Returns Core Clock Frequency in Hz
 * @return clock frequency
 */
uint32_t csp_get_clock_core_frequency(void);

/**
 * Returns whole ID register, deprecated
 * @return id register
 */
uint32_t csp_get_version(void);

/**
 * Returns current CSP flow
 * @return csp flow
 */
csp_id_flow_t csp_get_id_flow(void);

/**
 * Returns Major Version of the CSP
 * @return major version
 */
csp_version_t csp_get_id_major_version(void);

/**
 * Returns Minor Version of the CSP
 * @return minor version
 */
csp_version_t csp_get_id_minor_version(void);

/**
 * Returns Configuration specific bits
 * @return config bits value
 */
uint8_t csp_get_id_config(void);

/**
 * Returns status of STDIO output, like UART TX
 * @return 1 if output is available, 0 otherwise
 */
bool csp_get_id_output(void);

/**
 * Returns status of STDIO input, like UART RX
 * @return 1 if input is available, 0 otherwise
 */
bool csp_get_id_input(void);

/**
 * Checks if csp configuration has two core systems
 * @return 1 if dual system, 0 otherwise
 */
bool csp_get_id_dual_system(void);

/**
 * Checks if software runs on the second core in dual system configuration
 * @return 1 if second system, 0 otherwise
 */
bool csp_get_id_dual_second(void);

/**
 * Check if software should run tests automatically, without any interactions
 * @return 1 if automatic test, 0 otherwise
 */
bool csp_get_id_automatic_test(void);

/**
 * Checks if GUI, like SimVision, is available
 * @return 1 if GUI, 0 otherwise
 */
bool csp_get_id_gui(void);

/**
 * Returns the CPU Core Number for multi core processors
 * @return core number
 */
uint8_t csp_get_core_number(void);


/******************************************************************************
 * Sysregs counter
 *****************************************************************************/

/**
 * Returns 64-bit value of the sysregs counter
 * @return timer value
 */
uint64_t csp_get_counter_value(void);

/**
 * Returns lower, 32-bit value of the sysregs counter.
 * Uses single read operation
 * @return timer lower value
 */
uint32_t csp_get_counter_low_value(void);

/**
 * Resets sysregs counter to 0
 */
void csp_reset_counter(void);


/******************************************************************************
 * Delays
 *****************************************************************************/

/**
 * Delays software execution by number of nanoseconds
 * @param ns nanoseconds
 */
void csp_delay_ns(uint32_t ns);

/**
 * Delays software execution by number of microseconds
 * @param us microseconds
 */
void csp_delay_us(uint32_t us);

/**
 * Delays software execution by number of milliseconds
 * @param ms milliseconds
 */
void csp_delay_ms(uint32_t ms);

/**
 * Delays software execution by number of seconds
 * @param s seconds
 */
void csp_delay_s(uint32_t s);


/******************************************************************************
 * Interrupts
 *****************************************************************************/

/**
 * Returns number of supported interrupts
 * @return number of interrupts
 */
csp_irq_number_t csp_get_irq_count(void);

/**
 * Gets interrupt number for specified interrupt pin
 * @param p interrupt pin
 * @param n interrupt number
 * @return 0 if OK, error code otherwise
 */
csp_result_t csp_get_irq_number(csp_irq_number_t p, csp_irq_number_t *n);

/**
 * Assigns the interrupt handler to the interrupt with given number
 *
 * void interrupt_handler(csp_irq_number_t interrupt_number) {}
 *
 * @param n interrupt number
 * @param h interrupt handler
 * @return 0 if OK, error code otherwise
 */
csp_result_t csp_set_irq_handler(csp_irq_number_t n,
        csp_irq_handler_ptr_t h);

/**
 * Assigns the interrupt handler to the interrupt with given number
 * and argument pointer
 *
 * void interrupt_handler(void *arg) {}
 *
 * @param n interrupt number
 * @param h interrupt handler
 * @param arg interrupt handler argument
 * @return 0 if OK, error code otherwise
 */
csp_result_t csp_set_irq_handler_arg(csp_irq_number_t n,
        csp_irq_handler_arg_ptr_t h, void *arg);

/**
 * Sets interrupt type
 * @param n interrupt number
 * @param t interrupt type
 * @return 0 if OK, error code otherwise
 */
csp_result_t csp_set_irq_type(csp_irq_number_t n, csp_irq_type_t t);

/**
 * Sets interrupt to a pending state
 * @param n interrupt number
 * @return 0 if OK, error code otherwise
 */
csp_result_t csp_set_irq_pending(csp_irq_number_t n);

/**
 * Enables the interrupt
 * @param n interrupt number
 */
void csp_set_irq_on(csp_irq_number_t n);

/**
 * Disables the interrupt
 * @param n interrupt number
 */
void csp_set_irq_off(csp_irq_number_t n);

/**
 * Enables interrupts
 */
void csp_set_irqs_on(void);

/**
 * Disables interrupts
 */
void csp_set_irqs_off(void);

/******************************************************************************
 * Barriers
 *****************************************************************************/

/**
 * Memory barrier
 * Waits until previous data accesses are finished
 */
#ifndef csp_memory_barrier
#define csp_memory_barrier() \
    asm volatile ("" ::: "memory")
#endif

/**
 * Write Barrier
 * Waits until previous stores are finished
 */
#ifndef csp_memory_barrier_write
#define csp_memory_barrier_write() \
    asm volatile ("" ::: "memory")
#endif

/**
 * Read Barrier
 * Waits until previous loads are finished
 */
#ifndef csp_memory_barrier_read
#define csp_memory_barrier_read() \
    asm volatile ("" ::: "memory")
#endif

/******************************************************************************
 * Caches
 *****************************************************************************/

/**
 * Initializes instruction and data cache, if it's available.
 * Sets RAM as Cacheable (Write - Alloc) and IO space as Device.
 * Depending on the CPU it may also initialize MMU
 * @return 0 if OK
 * @return EOPNOTSUPP if cache is not supported
 * @return EIO if cache setup failed
 */
csp_result_t csp_init_caches(void);

/**
 * Returns status of Instruction Cache
 * @return 0 if cache is enabled
 * @return EAGAIN if cache is disabled
 * @return EOPNOTSUPP if cache is not supported
 */
csp_result_t csp_get_instruction_cache_status(void);

/**
 * Returns status of Data Cache.
 * @return 0 if cache is enabled
 * @return EAGAIN if cache is disabled
 * @return EOPNOTSUPP if cache is not supported
 */
csp_result_t csp_get_data_cache_status(void);

/**
 * Returns status of Memory Management Unit
 * @return 0 if MMU is enabled
 * @return EAGAIN if MMU is disabled
 * @return EOPNOTSUPP if MMU is not supported
 */
csp_result_t csp_get_mmu_status(void);

/**
 * Invalidates whole Data Cache.
 * It will receive data from memory during next read
 */
void csp_data_cache_invalidate_all(void);

/**
 * Invalidates region of Data Cache.
 * It will receive data from memory during next read
 * @param a region address
 * @param s region size
 */
void csp_data_cache_invalidate_region(void *a, size_t s);

/**
 * Flushes (cleans) whole Data Cache.
 * All dirty lines in cache will be written back to memory
 */
void csp_data_cache_flush_all(void);

/**
 * Flushes (cleans) region of Data Cache.
 * All dirty lines in cache will be written back to memory
 * @param a region address
 * @param s region size
 */
void csp_data_cache_flush_region(void *a, size_t s);

/**
 * Flushes (cleans) and invalidates whole Data Cache.
 */
void csp_data_cache_flush_invalidate_all(void);

/**
 * Flushes (cleans) and invalidates region of Data Cache.
 * @param a region address
 * @param s region size
 */
void csp_data_cache_flush_invalidate_region(void *a, size_t s);

/**
 * Invalidates whole Instruction Cache.
 * It will receive data from memory during next read
 */
void csp_instruction_cache_invalidate_all(void);

/**
 * Invalidates region of Instruction Cache.
 * @param a region address
 * @param s region size
 */
void csp_instruction_cache_invalidate_region(void *a, size_t s);


/******************************************************************************
 * Self-test reporting
 *****************************************************************************/

/**
 * You should call this function at the start of a self-checking test.  It
 * will set the status_leds to 0xFF and disable the status_led_enable signal.
 */
void csp_test_start(void);

/**
 * You should call this function at the end of a self-checking test.  The
 * rc (return code) parameter should be zero for a pass or non-zero for an
 * error condition.
 *
 * After 10 seconds the status LEDs are disabled again, so on the hardware
 * you have 10 seconds to check the results visually.
 * @param rc return code
 */
void csp_test_complete(uint8_t rc);

#endif
