#ifndef AT89S8253_H
#define AT89S8253_H

#define sfr __sfr
#define sbit __sbit
#define bit __bit

// Порт P0
sfr __at(0x080) P0 ; // reset: 0b'1111'1111
sbit __at(0x080 ^ 0) P0_0 ;
sbit __at(0x080 ^ 1) P0_1 ;
sbit __at(0x080 ^ 2) P0_2 ;
sbit __at(0x080 ^ 3) P0_3 ;
sbit __at(0x080 ^ 4) P0_4 ;
sbit __at(0x080 ^ 5) P0_5 ;
sbit __at(0x080 ^ 6) P0_6 ;
sbit __at(0x080 ^ 7) P0_7 ;

// Порт P1
sfr __at(0x090) P1 ; // reset: 0b'1111'1111
sbit __at(0x090 ^ 0) P1_0 ;
sbit __at(0x090 ^ 1) P1_1 ;
sbit __at(0x090 ^ 2) P1_2 ;
sbit __at(0x090 ^ 3) P1_3 ;
sbit __at(0x090 ^ 4) P1_4 ;
sbit __at(0x090 ^ 5) P1_5 ;
sbit __at(0x090 ^ 6) P1_6 ;
sbit __at(0x090 ^ 7) P1_7 ;

// Порт P2
sfr __at(0x0A0) P2 ; // reset: 0b'1111'1111
sbit __at(0x0A0 ^ 0) P2_0 ;
sbit __at(0x0A0 ^ 1) P2_1 ;
sbit __at(0x0A0 ^ 2) P2_2 ;
sbit __at(0x0A0 ^ 3) P2_3 ;
sbit __at(0x0A0 ^ 4) P2_4 ;
sbit __at(0x0A0 ^ 5) P2_5 ;
sbit __at(0x0A0 ^ 6) P2_6 ;
sbit __at(0x0A0 ^ 7) P2_7 ;

// Порт P3
sfr __at(0x0B0) P3 ; // reset: 0b'1111'1111
sbit __at(0x0B0 ^ 0) P3_0 ;
sbit __at(0x0B0 ^ 1) P3_1 ;
sbit __at(0x0B0 ^ 2) P3_2 ;
sbit __at(0x0B0 ^ 3) P3_3 ;
sbit __at(0x0B0 ^ 4) P3_4 ;
sbit __at(0x0B0 ^ 5) P3_5 ;
sbit __at(0x0B0 ^ 6) P3_6 ;
sbit __at(0x0B0 ^ 7) P3_7 ;


// Таймеры
sfr __at(0x088) TCON; // reset: 0b'0000'0000  
sbit __at(0x088 ^ 0) IT0 ;
sbit __at(0x088 ^ 1) IE0 ;
sbit __at(0x088 ^ 2) IT1 ;
sbit __at(0x088 ^ 3) IE1 ;
sbit __at(0x088 ^ 4) TR0 ;
sbit __at(0x088 ^ 5) TF0 ;
sbit __at(0x088 ^ 6) TR1 ;
sbit __at(0x088 ^ 7) TF1 ;

sfr __at(0x089) TMOD; // reset: 0b'0000'0000  
// sbit __at(0x089 ^ 0) TMOD_0 ; // T0: M0
// sbit __at(0x089 ^ 1) TMOD_1 ; // T0: M1
// sbit __at(0x089 ^ 2) TMOD_2 ; // T0: C/T
// sbit __at(0x089 ^ 3) TMOD_3 ; // T0: GATE
// sbit __at(0x089 ^ 4) TMOD_4 ; // T1: M0
// sbit __at(0x089 ^ 5) TMOD_5 ; // T1: M1
// sbit __at(0x089 ^ 6) TMOD_6 ; // T1: C/T
// sbit __at(0x089 ^ 7) TMOD_7 ; // T1: GATE
#define TMOD_MASK0 0x0F
#define TMOD_MASK1 0xF0

sfr __at(0x08A) TL0;  // reset: 0b'0000'0000  
sfr __at(0x08B) TL1;  // reset: 0b'0000'0000  
sfr __at(0x08C) TH0;  // reset: 0b'0000'0000  
sfr __at(0x08D) TH1;  // reset: 0b'0000'0000  


// Прерывания и приоритеты
sfr __at(0x0A8) IE; // reset: 0b'0x00'0000
sbit __at(0x0A8 ^ 0) EX0 ;
sbit __at(0x0A8 ^ 1) ET0 ;
sbit __at(0x0A8 ^ 2) EX1 ;
sbit __at(0x0A8 ^ 3) ET1 ;
sbit __at(0x0A8 ^ 4) ES  ;
// sbit __at(0x0A8 ^ 5)     ; // не используется
// sbit __at(0x0A8 ^ 6)     ; // не используется
sbit __at(0x0A8 ^ 7) EA  ;

sfr __at(0x0B8) IP; // reset: 0b'xx00'0000
sbit __at(0x0B8 ^ 0) PX0 ;
sbit __at(0x0B8 ^ 1) PT0 ;
sbit __at(0x0B8 ^ 2) PX1 ;
sbit __at(0x0B8 ^ 3) PT1 ;
sbit __at(0x0B8 ^ 4) PS  ;
// sbit __at(0x0B8 ^ 5)     ; // не используется
// sbit __at(0x0B8 ^ 6)     ; // не используется
// sbit __at(0x0B8 ^ 7)     ; // не используется


// Последовательный порт
sfr __at(0x087) PCON; // reset: 0b'0xxx'0000
// sbit __at(0x087 ^ 0) PCON_0 ;
// sbit __at(0x087 ^ 1) PCON_1 ;
// sbit __at(0x087 ^ 2) PCON_2 ;
// sbit __at(0x087 ^ 3) PCON_3 ;
// sbit __at(0x087 ^ 4) PCON_4 ;
// sbit __at(0x087 ^ 5) PCON_5 ;
// sbit __at(0x087 ^ 6) PCON_6 ;
// sbit __at(0x087 ^ 7) PCON_7 ;

sfr __at(0x098) SCON; // reset: 0b'0000'0000
sbit __at(0x098 ^ 0) SCON_0 ;
sbit __at(0x098 ^ 1) SCON_1 ;
sbit __at(0x098 ^ 2) SCON_2 ;
sbit __at(0x098 ^ 3) SCON_3 ;
sbit __at(0x098 ^ 4) SCON_4 ;
sbit __at(0x098 ^ 5) SCON_5 ;
sbit __at(0x098 ^ 6) SCON_6 ;
sbit __at(0x098 ^ 7) SCON_7 ;

sfr __at(0x099) SBUF; // reset: 0b'xxxx'xxxx



// Прерывания
#define ADD_RST   0x0000  /* Системный сброс */
#define ADD_IE0   0x0003  /* Внешнее прерывание 0 */
#define ADD_TF0   0x000B  /* Переполнение счетчика Т/С0 */
#define ADD_IE1   0x0013  /* Внешнее прерывание 1 */
#define ADD_TF1   0x001B  /* Переполнение счетчика Т/С1 */
#define ADD_RI_TI 0x0023  /* Последовательный порт UART или SPI */
#define ADD_TF2   0x002B  /* Переполнение счетчика Т/С2 */

#define N_IE0   0  /* Внешнее прерывание 0 */
#define N_TF0   1  /* Переполнение счетчика Т/С0 */
#define N_IE1   2  /* Внешнее прерывание 1 */
#define N_TF1   3  /* Переполнение счетчика Т/С1 */
#define N_RI_TI 4  /* Последовательный порт UART или SPI */
#define N_TF2   5  /* Переполнение счетчика Т/С2 */

#endif // AT89S8253_H