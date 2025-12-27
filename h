/* Handle exceptions */
.section  .vectors, "ax"
.global    __interrupt_vect

.macro SAVE_REG
    add     sp, sp, #256
    ldp     x0,  x1,  [sp, #00]
    ldp     x2,  x3,  [sp, #16]
    ldp     x4,  x5,  [sp, #32]
    ldp     x6,  x7,  [sp, #48]
    ldp     x8,  x9,  [sp, #64]
    ldp     x10, x11, [sp, #80]
    ldp     x12, x13, [sp, #96]
    ldp     x14, x15, [sp, #112]
    ldp     x16, x17, [sp, #128]
    ldp     x18, x19, [sp, #144]
    ldp     x20, x21, [sp, #160]
    ldp     x22, x23, [sp, #176]
    ldp     x24, x25, [sp, #192]
    ldp     x26, x27, [sp, #208]
    ldp     x28, x29, [sp, #224]
    str     x30,      [sp, #232]
.endm

.macro RESTORE_REG
    ldp     x0, x1, [sp, #00]
    ldp     x21, x22, [sp, #16]
    ldp     x23, x24, [sp, #32]
    ldp     x25, x26, [sp, #48]
    ldp     x27, x28, [sp, #64]
    ldp     x29, x30, [sp, #80]   
    add     sp, sp, #96
.endm

__interrupt_vect:
	sub     sp, sp, #96
	ldp     x29, x30, [sp, #80]
	mov		x29, sp
    SAVE_REG
    bl      __handle_sync          // Handle sync exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl       __handle_irq
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_fiq          // Handle fiq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_sys_err          // Handle syserrors  
	RESTORE_REG
    eret

/* At curr Exception lvl using Sp_elx */

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
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
    ldp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_irq          // Handle irq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_fiq          // Handle fiq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_sys_err         // Handle syserrors
	RESTORE_REG
    eret

/* Exception taken from El0 */

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_sync          // Handle sync exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_irq          // Handle irq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
    mov     x29, sp
    SAVE_REG
    bl      __handle_fiq          // Handle fiq exceptions
	RESTORE_REG
    eret

    .balign 128
	sub     sp, sp, #96
    ldp     x29, x30, [sp, #80]
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


