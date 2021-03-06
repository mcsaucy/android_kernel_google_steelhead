/*
 * Copyright (C) 2011 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _MACH_OMAP2_BOARD_STEELHEAD_H_
#define _MACH_OMAP2_BOARD_STEELHEAD_H_

#include <linux/serial_core.h> /* for struct uart_port */

struct steelhead_gpio_reservation {
	unsigned gpio_id;
	const char *gpio_name;
	const char *mux_name;
	int pin_mode;
	int init_state;
};

extern int __init steelhead_reserve_gpios(
				struct steelhead_gpio_reservation *data,
				int count,
				const char *log_tag,
				int do_gpio_request);

extern void __init steelhead_platform_init_counter(void);
extern int __init steelhead_init_wlan(void);
extern int __init steelhead_init_bluetooth(void);
extern void __init omap4_steelhead_emif_init(void);
extern void __init omap4_steelhead_ehci_init(void);

/* in board-tuna-bluetooth.c, which we share */
extern void bcm_bt_lpm_exit_lpm_locked(struct uart_port *uport);

extern s64 steelhead_get_raw_counter(void);
extern u32 steelhead_get_raw_counter_nominal_freq(void);
extern void steelhead_set_counter_slew_rate(s32 correction);

extern void steelhead_log_mcasp_underflow(int dev_id);
extern void steelhead_log_mcbsp_underflow(int dev_id);

enum {
	STEELHEAD_REV_ALPHA  = 0x0,
	STEELHEAD_REV_EVT    = 0x1,
	STEELHEAD_REV_EVT2   = 0x2,
	STEELHEAD_REV_DVT    = 0x3,
	STEELHEAD_REV_DVT1_5 = 0x4,
	STEELHEAD_REV_DVT2   = 0x5,
	STEELHEAD_REV_DVT3   = 0x6,
	STEELHEAD_REV_DVT4   = 0x7,
	STEELHEAD_REV_DVT5   = 0x8,
	STEELHEAD_REV_DVT6   = 0x9,
	STEELHEAD_REV_PROD   = 0xA,
	STEELHEAD_REV_PROD1  = 0xB,
	STEELHEAD_REV_PROD2  = 0xC,
	STEELHEAD_REV_PROD3  = 0xD,
};


extern int steelhead_hw_rev;

extern void steelhead_set_tas5713_interface_en(int enabled);

#ifdef CONFIG_AAH_TIMESYNC_DEBUG
extern void steelhead_register_timesync_event_handler(
		void *d, void (*handler)(void *d, u64));
#endif

#if 0 /* TBD */
extern int platform_set_counter_slew_rate(int ppm);
#endif

extern struct mmc_platform_data steelhead_wifi_data;

#endif
