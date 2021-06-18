/*
 * $FILE: partition0.c
 *
 * Fent Innovative Software Solutions
 *
 * $LICENSE:
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#include <string.h>
#include <stdio.h>
#include <xm.h>
#include <irqs.h>

#ifdef CONFIG_MMU
#define SHARED_ADDRESS  0x1C000000
#endif

#define PRINT(...) do { \
 printf("[P%d] ", XM_PARTITION_SELF); \
 printf(__VA_ARGS__); \
} while (0)

void HwTimerHandler(trapCtxt_t *ctxt)                                       /* XAL trap API */
{
    xmTime_t hw;
	xm_u32_t value = *(volatile xm_u32_t *)SHARED_ADDRESS;

    XM_get_time(XM_HW_CLOCK, &hw);
    PRINT("[%ld] IRQ HW Timer, value read: %#08x\n", (xm_u32_t) hw, value);
}

void PartitionMain(void)
{
    xmTime_t hwClock;
    
    PRINT("Starting CPU benchmark...\n");

#ifdef CONFIG_LEON3FT    
	InstallTrapHandler(XAL_XMEXT_TRAP(XM_VT_EXT_HW_TIMER), HwTimerHandler); /* Install timer handler */
#elif CONFIG_ARM
	InstallIrqHandler(XAL_XMEXT_TRAP(XM_VT_EXT_HW_TIMER), HwTimerHandler); /* Install timer handler */
	HwSti();                                                                /* Enable irqs */
#else
	#error No valid architecture
#endif

	XM_clear_irqmask(0, (1<<XM_VT_EXT_HW_TIMER));                           /* Unmask timer irqs */

	XM_get_time(XM_HW_CLOCK, &hwClock);                                     /* Read hardware clock */

	PRINT("Setting HW timer at 1 sec period\n");
	XM_set_timer(XM_HW_CLOCK, hwClock+5000LL, 1000000LL);                /* Set hardware time driven timer */

	while (1)
#ifdef CONFIG_ARM
		__asm__ __volatile__("wfe\n\t":::)
#endif
			;

	PRINT("Halting\n");
	XM_halt_partition(XM_PARTITION_SELF);
}
