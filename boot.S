.section    .text
.global     _start

_start:
    msr     spsel, #1         // We wanna use Spel_1 since we are at el1
    msr     daifset, #15      // Disable any type of interrupts until we set vect table
    ldr     x1, =__kernel_top
    mov     sp, x1
    ldr     x1, =__bss_start
    ldr     x2, =__bss_end
    cmp     x1, x2
    bl      zero_bss
    ldr     x1, =__interrupt_vect
    msr     vbar_el1, x1      // set vect table address
    isb     sy                // Sync
    mrs     x1, sctlr_el1
    // Disable M, A, C, SA, SAO, I, WXN, EE & EOE
    mov     x2, #0x1f         
    mvn     x2, x2  
    and     x1, x1, x2        // Disable 0-4 bits
    mov     x2, #0x1
    lsl     x2, x2, #12 
    mvn     x2, x2
    and     x1, x1, x2        // Disable 12th bit
    mov     x2, #0x1
    lsl     x2, x2, #19       
    mvn     x2, x2
    and     x1, x1, x2        // Disable 19th bit
    mov     x2, #0x3
    lsl     x2, x2, #25
    mvn     x2, x2
    and     x1, x1, x2        // Disable 24th & 25th bit
    msr     sctlr_el1, x1     // Write back our modified sctlr 
    isb     sy
    b       kernel_main       // Jump to main


zero_bss:
    str     xzr, [x1]
    add     x1, x1, #8
    cmp     x1, x2
    b.lt    zero_bss
    ret
