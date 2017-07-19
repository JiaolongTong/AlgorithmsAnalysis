
    /* led_on.S */
    /* #define CTRL_BASE         0x44E10000   */
    /* #define GPIO3_BASE        0x481AE000*/
    /* TEXT_BESE                 0x80800000 */
    /* SPL_BESE                  0x402f0400  */
.text
.global _start

_start:
        ldr r0, =0x44E10994       /* GPMC_A0(GPIO3_18)寄存器 */
        ldr r1, =0x0000001F        /* GPMC_A0(GPIO3_18)寄存器，模式7 */
        str r1, [r0]               /* GPMC_A0(GPIO3_18)寄存器，上拉[4:3]=0b11,模式7,[2:0] = 0b111 */

        ldr r0, =0x481AE134     /* GPIO3 OE*/
        ldr r1, #0x00000000         
        str r1, [r0]            /* 设置为输出 ， 0 为输出 */

        ldr r0, =0x481AE13C        /* GPIO3 DATAOUT寄存器 */
        ldr r1, #0x00040000        // 0000_0000_0000_0100_0000_0000_0000_0000
        str r1, [r0]            /* 设置为高电平 */

    halt:
        b halt                    /* 死循环 */


