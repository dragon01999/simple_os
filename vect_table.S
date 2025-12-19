/* Handle exceptions */
.section  .vectors, "ax"
.global    __interrupt_vect

__interrupt_vect:
/* At curr Exception lvl when using Sp_el1 */
    bl      save_reg
    ldr     x0, =panik
    br      x0          // Handle sync exceptions

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_irq
    br      x0          // Handle irq exceptions

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_fiq
    br      x0          // Handle fiq exceptions

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_syserror
    br      x0          // Handle syserrors  
/* At curr Exception lvl using Sp_el0 */
    bl      save_reg
    ldr     x0, =__handle_sync
    br      x0          // Handle sync exceptions

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_irq
    br      x0          // Handle irq exceptions

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_fiq
    br      x0          // Handle fiq exceptions

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_syserror
    br      x0          // Handle syserrors

/* Exception taken from El0 */
    bl      save_reg
    ldr     x0, =__handle_sync
    br      x0          // Handle sync exceptions

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_irq
    br      x0          // Handle irq exceptions

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_fiq
    br      x0          // Handle fiq exceptions

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_syserror
    br      x0          // Handle syserrors
/* Exceptions from El0 in aarch-32 mode */
    .balign 128
    bl      save_reg
    ldr     x0, =__handle_illegal_exception
    br      x0

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_illegal_exception
    br      x0

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_illegal_exception
    br      x0

    .balign 128
    bl      save_reg
    ldr     x0, =__handle_illegal_exception
    br      x0
save_reg:
  	sub    sp, sp, #16
  	stp    x29, x30, [sp, #0]
  	ret
