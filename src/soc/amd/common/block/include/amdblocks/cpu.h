/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef AMD_BLOCK_CPU_H
#define AMD_BLOCK_CPU_H

#include <acpi/acpi.h>
#include <cpu/x86/msr.h>
#include <types.h>

#define MAX_CSTATE_COUNT	8

void early_cache_setup(void);
int get_cpu_count(void);
unsigned int get_threads_per_core(void);
void set_cstate_io_addr(void);
void write_resume_eip(void);

uint32_t get_pstate_core_freq(msr_t pstate_def);
uint32_t get_pstate_core_power(msr_t pstate_def);
const acpi_cstate_t *get_cstate_config_data(size_t *size);

#endif /* AMD_BLOCK_CPU_H */
