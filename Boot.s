/*
 *	========================================================
 *
 *	Wayland
 * 	Copyright PlayXPlicit, all rights reserved.
 *
 * 	========================================================
 */

.section .init
.align 4

.extern __start

.option norvc

__mach_start:
	.cfi_startproc

.option push
.option norelax
	la gp, __sys_global_pointer

.option pop

	la sp, __sys_stack_end

	la t5, _bss_start
	la t6, _bss_end

__crt0_bss_clear:
	sd zero, (t5)
	addi t5, t5, 8
	bgeu t5, t6, __crt0_bss_clear

	csrr a0, mhartid
	bnez a0, __hang

	j __start
	j __hang

	.cfi_endproc

__hang:
    wfi
	j __hang

.section .data
.align 4
__sys_hart_present:
	.long 0

	