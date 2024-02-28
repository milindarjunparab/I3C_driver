/*(C) 2023 Cadence Design Systems, Inc. 
This file is licensed under the Cadence Public License Version 1.0 (the “License”), a copy of which is available at https://www.cadence.com/content/dam/cadence-www/global/en_US/documents/terms-and-conditions/Cadence-Public-License-Version-1.0.pdf, and is distributed "AS IS." TO THE  MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, CADENCE DISCLAIMS ALL WARRANTIES AND IN NO EVENT SHALL BE LIABLE TO ANY PARTY FOR ANY DAMAGES ARISING OUT OF OR RELATING TO USE OF THIS FILE. Please see the License for the full text of applicable terms.
*
 ******************************************************************************
 * cdn_log.h
 * System wide debug log messaging framework
 *****************************************************************************/

#ifndef INCLUDE_CDN_LOG_H

#define INCLUDE_CDN_LOG_H

#include "cdn_assert.h"
#include "cdn_inttypes.h"
#ifdef __cplusplus
extern "C" {
#endif

/* parasoft-begin-suppress MISRAC2012-RULE_8_6-a "An identifier with external linkage shall have exactly one external definition, DRV-4757" */
/* parasoft-begin-suppress MISRAC2012-DIR_4_9-a "A function should be used in preference to a function-like macro where they are interchangeable, DRV-4759" */

#ifdef DEBUG
 #if DEBUG
  #define CFP_DBG_MSG 1
 #endif
#endif

/**
 * Modules definitions
 */
#define CLIENT_MSG         0x01000000

#define DBG_GEN_MSG        0xFFFFFFFF

/**
 * Log level:
 * DBG_CRIT - critical
 * DBG_WARN - warning
 * DBG_FYI - fyi
 * DBG_HIVERB - highly verbose
 * DBG_INFLOOP - infinite loop debug
 */
#define DBG_CRIT 0
#define DBG_WARN 5
#define DBG_FYI 10
#define DBG_HIVERB 100
#define DBG_INFLOOP 200

/* module mask: */
#ifdef _HAVE_DBG_LOG_INT_
uint32_t g_dbg_enable_log  = 0;
#else
extern uint32_t g_dbg_enable_log;
#endif

/* level, counter, state: */
#ifdef _HAVE_DBG_LOG_INT_
uint32_t g_dbg_log_lvl = DBG_CRIT;
uint32_t g_dbg_log_cnt = 0;
uint32_t g_dbg_state = 0;
#else
extern uint32_t g_dbg_log_lvl;
extern uint32_t g_dbg_log_cnt;
extern uint32_t g_dbg_state;
#endif

/* There is possibility to provide custom logging functions instead of default
 *   - DbgMsg
 * by defining macros:
 *   - DEBUG for DbgMsg with custom print implementation
 *
 * There is also possibility to provide own implementation of printf() routine by
 * defining function:
 *   DbgPrint
 * that provides name of functions that replace printf().
 * Their prototype:
 *   void DbgPrint(const char *fmt, ...)
 *
 * If DEBUG symbol is defined, then appropriate prototype is declared within this header file.
 *
 * If DEBUG is not defined, print is not used. Existing macros will not print any data.
 */

/* For DEBUG build, use custom logging with own implementation of DbgPrint */
#ifdef DEBUG
extern void DbgPrint(const char *fmt, ...);
#define cDbgMsg( _t, _x, ...) ( ((_x) ==  0) || \
                                (((_t) & g_dbg_enable_log) && ((_x) <= g_dbg_log_lvl)) ? \
                                DbgPrint( __VA_ARGS__) : 0 )
#else
#define cDbgMsg( _t, _x, ...)
#endif /* DEBUG */

#ifdef CFP_DBG_MSG
#define DbgMsg( t, x, ...)  cDbgMsg( (t), (x), __VA_ARGS__ )
#else
#define DbgMsg( t, x, ...)
#endif

#define DEBUG_PREFIX "[%-20.20s %4d %4" PRId32 "]-"

/* ******** Default vDbgMsg ******** */
#  define vDbgMsg(log_lvl, module, msg, ...)    DbgMsg( (log_lvl), (module), (DEBUG_PREFIX msg), __func__, \
                                                        __LINE__, g_dbg_log_cnt++, __VA_ARGS__)

/* ******** Default cvDbgMsg ******** */
#  define cvDbgMsg(log_lvl, module, msg, ...)   cDbgMsg( (log_lvl), (module), (DEBUG_PREFIX msg), __func__, \
                                                         __LINE__, g_dbg_log_cnt++, __VA_ARGS__)

/* ******** Default cvDbgMsg ******** */
#  define evDbgMsg(log_lvl, module, msg, ...)   { cDbgMsg( (log_lvl), (module), (DEBUG_PREFIX msg), __func__,         \
                                                           __LINE__, g_dbg_log_cnt++, __VA_ARGS__); \
                                                  assert(0); }

#define DbgMsgSetLvl( x ) (g_dbg_log_lvl = (x))
#define DbgMsgEnableModule( x ) (g_dbg_enable_log |= (x) )
#define DbgMsgDisableModule( x ) (g_dbg_enable_log &= ~( (uint32_t) (x) ))
#define DbgMsgClearAll( _x ) ( g_dbg_enable_log = (_x) )

#define SetDbgState( _x ) (g_dbg_state = (_x) )
#define GetDbgState       (g_dbg_state)

#ifdef __cplusplus
}
#endif

/* parasoft-end-suppress MISRAC2012-RULE_8_6-a */
/* parasoft-end-suppress MISRAC2012-DIR_4_9-a */

#endif /* INCLUDE_CDN_LOG_H */
