/******************************************************************************
 *
 * Copyright (C) 2012-2023 Cadence Design Systems, Inc.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/
#include <cdn_stdtypes.h>
#include <cdn_errno.h>
#include <map_system_memory.h>
#include <csp.h>
#include <csp_sysregs.h>
#include "cps_drv.h"
#include <cps.h>

#define _HAVE_DBG_LOG_INT_ 1
#include "cdn_log.h"

extern uint32_t ASF_RunFunctionalTests();
extern void ASF_Isr1();

// This test should be used only for ASF self tests!
// It is a template for other projects/ip where ASF is used. 
int main(int argc, char *argv[]) {

    DbgMsgSetLvl(DBG_FYI);
    DbgMsgEnableModule(DBG_GEN_MSG);

    csp_test_start();
    csp_set_irq_handler(csp_get_irq(I3C_MST0_ASF_IRQ), ASF_Isr1);
    csp_set_irq_on(csp_get_irq(I3C_MST0_ASF_IRQ));

    // Reset devices
    reset_devices(0xFF);
    
    if (ASF_RunFunctionalTests() != EOK) {
        return EINVAL;
    }

    return EOK;
}

