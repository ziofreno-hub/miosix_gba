/* *****************************************************
Miosix boot system V2.0
Stage 1 boot process
This code will set up the stacks, initialize global
variables and jump to stage_2_boot.
C and C++ are supported.
Also includes the interrupt table.
***************************************************** */

/* Mode bits and Interrupt (I & F) flags in PSRs (program status registers) */
.set  MODE_USR, 0x10  /* User Mode                      */
.set  MODE_FIQ, 0x11  /* FIQ Fast Interrupt Mode        */
.set  MODE_IRQ, 0x12  /* IRQ Interrupt Mode             */
.set  MODE_SVC, 0x13  /* Supervisor Call Interrupt Mode */
.set  MODE_ABT, 0x17  /* Abort (memory fault) Mode      */
.set  MODE_UND, 0x1B  /* Undefined Instructions Mode    */
.set  MODE_SYS, 0x1F  /* System Mode                    */
.set  I_BIT, 0x80     /* if I bit set, IRQ is disabled  */
.set  F_BIT, 0x40     /* if F bit set, FIQ is disabled  */

.text
.arm

.global  _startup
.func    _startup

_startup:
        .ALIGN
        .CODE 32
    @ Start Vector

        b       _vectors

    @ Nintendo Logo Character Data (8000004h)
@        .fill   156,1,0
	.long 0x51aeff24,0x21a29a69,0x0a82843d
	.long 0xad09e484,0x988b2411,0x217f81c0,0x19be52a3
	.long 0x20ce0993,0x4a4a4610,0xec3127f8,0x33e8c758
	.long 0xbfcee382,0x94dff485,0xc1094bce,0xc08a5694
	.long 0xfca77213,0x734d849f,0x619acaa3,0x27a39758
	.long 0x769803fc,0x61c71d23,0x56ae0403,0x008438bf
	.long 0xfd0ea740,0x03fe52ff,0xf130956f,0x85c0fb97
	.long 0x2580d660,0x03be63a9,0xe2384e01,0xff34a2f9
	.long 0x44033ebb,0xcb900078,0x943a1188,0x637cc065
	.long 0xaf3cf087,0x8be425d6,0x72ac0a38,0x07f8d421

    @ Game Title (80000A0h)
        .byte   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        .byte   0x00,0x00,0x00,0x00

 .ifdef __MultibootDedicated
    @ Game Code (80000ACh)
        .ascii  "MB  "
 .else
    @ Game Code (80000ACh)
        .byte   0x00,0x00,0x00,0x00
 .endif

    @ Maker Code (80000B0h)
        .byte   0x30,0x31

    @ Fixed Value (80000B2h)
        .byte   0x96

    @ Main Unit Code (80000B3h)
        .byte   0x00

    @ Device Type (80000B4h)
        .byte   0x00

    @ Unused Data (7Byte) (80000B5h)
        .byte   0x00,0x00,0x00,0x00,0x00,0x00,0x00

    @ Software Version No (80000BCh)
        .byte   0x00

    @ Complement Check (80000BDh)
        .byte   0xf0

    @ Checksum (80000BEh)
        .byte   0x00,0x00

    .ALIGN
    .ARM                                @ ..or you can use CODE 32 here


/* Interrupt vectors */

_vectors:
    ldr     pc, Reset_Addr
    ldr     pc, Undef_Addr
    ldr     pc, SWI_Addr
    ldr     pc, PAbt_Addr
    ldr     pc, DAbt_Addr
    nop                      /* Reserved for ISP checksum  */
    ldr     pc, [pc,#-0xFF0] /* Jump to VIC                */
    ldr     pc, FIQ_Addr

Reset_Addr: .word   Reset_Handler  /* defined below                          */
Undef_Addr: .word   UNDEF_Routine  /* defined in interrupts.cpp              */
SWI_Addr:   .word   kernel_SWI_Routine /* defined in kernel/portability.cpp  */
PAbt_Addr:  .word   PABT_Routine   /* defined in interrupts.cpp              */
DAbt_Addr:  .word   DABT_Routine   /* defined in interrupts.cpp              */
FIQ_Addr:   .word   FIQ_Routine    /* defined in interrupts.cpp              */
            .word   0              /* rounds the interrupt vector to 64Bytes */

/* Reset Handler */

Reset_Handler:  
    /* Setup a stack for each mode */
    msr     CPSR_c, #MODE_UND|I_BIT|F_BIT  /* Undef      (IRQ Off, FIQ Off) */
    ldr     sp, =_und_stack_top

    msr     CPSR_c, #MODE_ABT|I_BIT|F_BIT  /* Abort      (IRQ Off, FIQ Off) */
    ldr     sp, =_abt_stack_top

    msr     CPSR_c, #MODE_FIQ|I_BIT|F_BIT  /* FIQ        (IRQ Off, FIQ Off) */
    ldr     sp, =_fiq_stack_top

    msr	    CPSR_c, #MODE_IRQ|I_BIT        /* IRQ        (IRQ Off, FIQ On ) */
    ldr     sp, =_irq_stack_top

    msr	    CPSR_c, #MODE_SVC|I_BIT        /* Supervisor (IRQ Off, FIQ On ) */
    ldr     sp, =_svc_stack_top

    msr	    CPSR_c, #MODE_SYS|I_BIT|F_BIT  /* System     (IRQ Off, FIQ Off) */
    ldr	    sp, =_sys_stack_top

    /* copy .data section from ROM to IWRAM */
    ldr     r1, =_etext
    ldr     r2, =_data
    ldr	    r3, =_edata
1:  cmp	    r2, r3
    ldrlo   r0, [r1], #4
    strlo   r0, [r2], #4
    blo	    1b
    /* clear .bss section */
    mov	    r0, #0
    ldr	    r1, =_bss_start
    ldr	    r2, =_bss_end
2:  cmp	    r1, r2
    strlo    r0, [r1], #4
    blo	    2b
    /* enter stage_2_boot. the lr (return address) is set to 0x00000000, so
    if main returns, it will jump to the reset vector, rebooting the system.
    Using bx instead of b to support thumb mode */
    ldr     r12, =_init
    ldr	    lr, =0xc0
    bx      r12

.endfunc
	
.end
