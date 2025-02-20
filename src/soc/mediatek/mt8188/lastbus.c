/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/console.h>
#include <device/mmio.h>
#include <soc/addressmap.h>
#include <soc/lastbus_v2.h>

const struct lastbus_config lastbus_cfg = {
	.latch_platform = "MT8188",
	.timeout_ms = 200,
	.timeout_type = 0,
	.num_used_monitors = 6,
	.monitors = {
		{
			.name = "debug_ctrl_ao_INFRA_AO",
			.base = INFRA_AO_DBUG_BASE,
			.num_ports = 34,
			.num_idle_mask = 2,
			.idle_masks = {
				{
					.reg_offset = 0x04,
					.reg_value = 0x2,
				},
				{
					.reg_offset = 0x08,
					.reg_value = 0x10000,
				},
			},
			.bus_freq_mhz = 78,
		},
		{
			.name = "debug_ctrl_ao_INFRA2_AO",
			.base = INFRA2_AO_DBUG_BASE,
			.num_ports = 9,
			.num_idle_mask = 0,
			.bus_freq_mhz = 78,
		},
		{
			.name = "debug_ctrl_ao_PERI_AO",
			.base = PERI_AO_BASE,
			.num_ports = 25,
			.num_idle_mask = 1,
			.idle_masks = {
				{
					.reg_offset = 0x04,
					.reg_value = 0x20000,
				},
			},
			.bus_freq_mhz = 78,
		},
		{
			.name = "debug_ctrl_ao_PERI_AO2",
			.base = PERI_AO2_BASE,
			.num_ports = 20,
			.num_idle_mask = 0,
			.bus_freq_mhz = 78,
		},
		{
			.name = "debug_ctrl_ao_PERI_PAR_AO",
			.base = PERI_PAR_AO_BASE,
			.num_ports = 18,
			.num_idle_mask = 0,
			.bus_freq_mhz = 78,
		},
		{
			.name = "debug_ctrl_ao_FMEM_AO",
			.base = FMEM_AO_BASE,
			.num_ports = 28,
			.num_idle_mask = 1,
			.idle_masks = {
				{
					.reg_offset = 0x14,
					.reg_value = 0x204,
				},
			},
			.bus_freq_mhz = 78,
		},
	},
};
