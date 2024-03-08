/***************************************************************************
 *   Copyright (C) 2021 by Terraneo Federico                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   As a special exception, if other files instantiate templates or use   *
 *   macros or inline functions from this file, or you compile this file   *
 *   and link it with other works to produce a work based on this file,    *
 *   this file does not by itself cause the resulting work to be covered   *
 *   by the GNU General Public License. However the source code for this   *
 *   file must still be made available in accordance with the GNU General  *
 *   Public License. This exception does not invalidate any other reasons  *
 *   why a work based on this file might be covered by the GNU General     *
 *   Public License.                                                       *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/

#include "kernel/kernel.h"
#include "interfaces/os_timer.h"
#include "interfaces/arch_registers.h"

namespace miosix {

void TIM0_Routine() __attribute__ ((interrupt("IRQ"),naked));

class GBATimer0 : public TimerAdapter<GBATimer0, 32>
{
public:
    static inline unsigned int IRQgetTimerCounter() {  return 0;}
    static inline void IRQsetTimerCounter(unsigned int v) { }

    static inline unsigned int IRQgetTimerMatchReg() {return 0; }
    static inline void IRQsetTimerMatchReg(unsigned int v) {}

    static inline bool IRQgetOverflowFlag() {return 0;}
    static inline void IRQclearOverflowFlag() {}
    
    static inline bool IRQgetMatchFlag() { return 0; }
    static inline void IRQclearMatchFlag() { }
    
    static inline void IRQforcePendingIrq() { }

    static inline void IRQstopTimer() { }
    static inline void IRQstartTimer() { }
    
    static unsigned int IRQTimerFrequency() { return 0;}
    
    static void IRQinitTimer() {
    }
};

static GBATimer0 timer;
DEFAULT_OS_TIMER_INTERFACE_IMPLMENTATION(timer);

void TIM0_Routine() {
}

void __attribute__((noinline)) osTimerImpl() {
}

} //namespace miosix
