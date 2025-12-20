/* Handle exceptions */
.section  .vectors, "ax"
.global    __interrupt_vect

.macro SAVE_REG
/* Save calle saved, X19 to X28, X29(fp) & X30(lr) */
    stp     x19, x20, [sp, #00]
    stp     x21, x22, [sp, #16]
    stp     x23, x24, [sp, #32]
    stp     x25, x26, [sp, #48]
    stp     x27, x28, [sp, #64]
.endm

.macro RESTORE_REG
    ldp     x19, x20, [sp, #00]
    ldp     x21, x22, [sp, #16]
    ldp     x23, x24, [sp, #32]
    ldp     x25, x26, [sp, #48]
    ldp     x27, x28, [sp, #64]
    ldp     x29, x30, [sp, #80]   
    add     sp, sp, #96
.endm

__interrupt_vect:
	sub     sp, sp, #96
	stp     x29, x30, [sp, #80]
	mov		x29, sp
    SAVE_REG
    bl      __handle_sync          // Handle sync exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl       __handle_irq
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_fiq          // Handle fiq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_sys_err          // Handle syserrors  
	RESTORE_REG
    eret

/* At curr Exception lvl using Sp_elx */

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_sync          // Handle sync exceptions
	RESTORE_REG
    mrs x0, elr_el1
    add x0, x0, #4
    msr elr_el1, x0
    eret

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_irq          // Handle irq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_fiq          // Handle fiq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_sys_err         // Handle syserrors
	RESTORE_REG
    eret

/* Exception taken from El0 */

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_sync          // Handle sync exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_irq          // Handle irq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_fiq          // Handle fiq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    stp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_sys_err          // Handle syserrors
	RESTORE_REG
    eret

/* Exceptions from El0 in aarch-32 mode */

    .balign 128
    bl      __handle_illegal_exception

    .balign 128
    bl      __handle_illegal_exception

    .balign 128
    bl      __handle_illegal_exception

    .balign 128
    bl      __handle_illegal_exception


