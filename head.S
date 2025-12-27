/* Handle exceptions */
.section  .vectors, "ax"
.global    __interrupt_vect

.macro SAVE_REG
    sub     sp,  sp,  #256
    stp     x0,  x1,  [sp, #00]
    stp     x2,  x3,  [sp, #16]
    stp     x4,  x5,  [sp, #32]
    stp     x6,  x7,  [sp, #48]
    stp     x8,  x9,  [sp, #64]
    stp     x10, x11, [sp, #80]
    stp     x12, x13, [sp, #96]
    stp     x14, x15, [sp, #112]
    stp     x16, x17, [sp, #128]
    stp     x18, x19, [sp, #144]
    stp     x20, x21, [sp, #160]
    stp     x22, x23, [sp, #176]
    stp     x24, x25, [sp, #192]
    stp     x26, x27, [sp, #208]
    stp     x28, x29, [sp, #224]
    str     x30,      [sp, #232]
.endm

__interrupt_vect:
    .balign 128
    SAVE_REG
    bl      __handle_sync          // Handle sync exceptions
	b 		begin_return		
    .balign 128
    SAVE_REG
    bl       __handle_irq
	b       begin_return
    .balign 128
    SAVE_REG
    bl      __handle_fiq
	b       begin_return          // Handle fiq exceptions
    .balign 128
    SAVE_REG
    bl      __handle_sys_err          // Handle syserrors  
	b       begin_return

/* At curr Exception lvl using Sp_elx */

	.balign 128
    SAVE_REG
    bl      __handle_sync          // Handle sync exceptions
    mrs x0, elr_el1
    add x0, x0, #4
    msr elr_el1, x0
	b       begin_return
    .balign 128
    SAVE_REG
    bl      __handle_irq          // Handle irq exceptions
	b       begin_return
    .balign 128
    SAVE_REG
    bl      __handle_fiq          // Handle fiq exceptions
	b       begin_return
    .balign 128
    SAVE_REG
    bl      __handle_sys_err         // Handle syserrors
	b       begin_return

/* Exception taken from El0 */

    .balign 128
    SAVE_REG
    bl      __handle_sync          // Handle sync exceptions
	b       begin_return
    .balign 128
    SAVE_REG
    bl      __handle_irq          // Handle irq exceptions
	b       begin_return
    .balign 128
    SAVE_REG
    bl      __handle_fiq          // Handle fiq exceptions
	b       begin_return
    .balign 128
    SAVE_REG
    bl      __handle_sys_err      // Handle syserrors
	b       begin_return

/* Exceptions from El0 in aarch-32 mode */

    .balign 128
    bl      __handle_illegal_exception
    .balign 128
    bl      __handle_illegal_exception
    .balign 128
    bl      __handle_illegal_exception
    .balign 128
    bl      __handle_illegal_exception

begin_return:
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
    ldr     x30,      [sp, #232]
    add     sp,  sp,  #256
    eret

