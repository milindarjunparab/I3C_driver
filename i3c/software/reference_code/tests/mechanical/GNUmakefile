###############################################################################
#
# Instructions:
#
# This makefile is for GNU make 3.79 or later.
#
# This is an example of building the mechanical test code and the driver.
#
# Inputs:
# - CROSS_COMPILE: GCC compiler prefix
# - CFLAGS: flags to C compiler
#
#
# Targets:
#   build: build mechanical tests
#	all: build and run mechanical tests
#	clean: remove objects
#
###############################################################################

COMPONENT_NAME := i3c

###############################################################################
# Configurable variables
###############################################################################

CC      := $(CROSS_COMPILE)gcc

###############################################################################
# Calculated variables
###############################################################################

DIR     := $(abspath .)
TMPDIR  ?= $(DIR)/tmp

CFLAGS  := -g -O0 -DMECHANICAL_TESTS=1 -DI3C_REGS_BASE=0xCADE4ECE -DI3C_REGS_SIZE=0x00001000 -DI3CS_REGS_BASE=0xCADE4ECE -DI3C_SLV0_REGS_SIZE=0x00001000 $(EXTRA_CFLAGS)

DRVDIR  := $(abspath $(DIR)/../../../core_driver)
CINCDIR := $(DIR)/../include $(DRVDIR)/include $(DRVDIR)/common $(DRVDIR)/src 
CSRCDIR := $(DIR)
LIBDIR  := $(TMPDIR)/lib
CFLAGS  += $(addprefix -I,$(CINCDIR))
LDFLAGS := -L$(LIBDIR) -l$(COMPONENT_NAME)
CSRCS   := $(wildcard $(CSRCDIR)/*.c) 

MECHANICAL_BINARY := mechanical_test

###############################################################################
# Targets
###############################################################################

.PHONY: all build run clean lib libclean

all: $(MECHANICAL_BINARY) run

lib:
	make -C $(DRVDIR) TGTDIR=$(TMPDIR) CROSS_COMPILE=$(CROSS_COMPILE) all

libclean:
	make -C $(DRVDIR) TGTDIR=$(TMPDIR) clean

$(MECHANICAL_BINARY): lib
	gcc -o $(@) -pthread $(CFLAGS) $(CSRCS) $(LDFLAGS)

build: $(MECHANICAL_BINARY)

run: build
	./$(MECHANICAL_BINARY)

clean: libclean
	$(RM) $(MECHANICAL_BINARY)
	$(RM) -r $(TMPDIR)
