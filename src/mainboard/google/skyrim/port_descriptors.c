/* SPDX-License-Identifier: GPL-2.0-only */

#include <baseboard/variants.h>
#include <gpio.h>
#include <soc/platform_descriptors.h>
#include <types.h>

#if CONFIG(USE_VARIANT_DXIO_DESCRIPTOR)
static const fsp_dxio_descriptor skyrim_mdn_dxio_descriptors[] = {};
#else
static const fsp_dxio_descriptor skyrim_mdn_dxio_descriptors[] = {
	{ /* WLAN */
		.engine_type = PCIE_ENGINE,
		.port_present = true,
		.start_logical_lane = 0,
		.end_logical_lane = 0,
		.device_number = PCI_SLOT(WLAN_DEVFN),
		.function_number = PCI_FUNC(WLAN_DEVFN),
		.link_speed_capability = GEN3,
		.turn_off_unused_lanes = true,
		.link_aspm = ASPM_L1,
		.link_aspm_L1_1 = true,
		.link_aspm_L1_2 = true,
		.clk_req = CLK_REQ2,
	},
	{ /*  SD */
		.engine_type = PCIE_ENGINE,
		.port_present = true,
		.start_logical_lane = 1,
		.end_logical_lane = 1,
		.device_number = PCI_SLOT(SD_DEVFN),
		.function_number = PCI_FUNC(SD_DEVFN),
		.link_speed_capability = GEN3,
		.turn_off_unused_lanes = true,
		.link_aspm = ASPM_L1,
		.link_aspm_L1_1 = true,
		.link_aspm_L1_2 = true,
		.gpio_group_id = GPIO_27,
		.clk_req = CLK_REQ1,
	},
	{ /* SSD */
		.engine_type = PCIE_ENGINE,
		.port_present = true,
		.start_logical_lane = 2,
		.end_logical_lane = 3,
		.device_number = PCI_SLOT(NVME_DEVFN),
		.function_number = PCI_FUNC(NVME_DEVFN),
		.link_speed_capability = GEN3,
		.turn_off_unused_lanes = true,
		.link_aspm = ASPM_L1,
		.link_aspm_L1_1 = true,
		.link_aspm_L1_2 = true,
		.gpio_group_id = GPIO_6,
		.clk_req = CLK_REQ0,
	},
};
#endif

static const fsp_ddi_descriptor skyrim_mdn_ddi_descriptors[] = {
	{ /* DDI0 - eDP */
		.connector_type = DDI_EDP,
		.aux_index = DDI_AUX1,
		.hdp_index = DDI_HDP1
	},
	{ /* DDI1 - HDMI/DP */
		.connector_type = DDI_HDMI,
		.aux_index = DDI_AUX2,
		.hdp_index = DDI_HDP2
	},
	{ /* DDI2 - DP (type C) */
		.connector_type = DDI_DP_W_TYPEC,
		.aux_index = DDI_AUX3,
		.hdp_index = DDI_HDP3,
	},
	{ /* DDI3 - DP (type C) */
		.connector_type = DDI_DP_W_TYPEC,
		.aux_index = DDI_AUX4,
		.hdp_index = DDI_HDP4,
	},
	{ /* DDI4 - Unused */
		.connector_type = DDI_UNUSED_TYPE,
		.aux_index = DDI_AUX5,
		.hdp_index = DDI_HDP5,
	},
};

void mainboard_get_dxio_ddi_descriptors(
		const fsp_dxio_descriptor **dxio_descs, size_t *dxio_num,
		const fsp_ddi_descriptor **ddi_descs, size_t *ddi_num)
{
	if (CONFIG(USE_VARIANT_DXIO_DESCRIPTOR)) {
		variant_get_dxio_descriptor(dxio_descs, dxio_num);
	} else {
		*dxio_descs = skyrim_mdn_dxio_descriptors;
		*dxio_num = ARRAY_SIZE(skyrim_mdn_dxio_descriptors);
	}

	*ddi_descs = skyrim_mdn_ddi_descriptors;
	*ddi_num = ARRAY_SIZE(skyrim_mdn_ddi_descriptors);
}
