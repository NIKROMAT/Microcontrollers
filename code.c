#include "include/at89s8253.h"
// #include "at89s8253.h"

#define LCD_BYTE P0
#define LCD_RS P3_7
#define LCD_E P3_6

#define UART P2
#define MATRIX P1


void init();
void input_uart()   __interrupt(2);    // ПК in
void input_matrix() __interrupt(0); // МК in
void delay(); // T0

void lcd_cmd(int);
void lcd_send(int);

void update_A(int);
void update_B(int);

volatile int F0, F1;
volatile int A, B;
volatile int rst;

void main() {
  while(1) {
  reset:
    init();

    while (!(F0 & F1)) {
      if (rst == 1) goto reset;
      // char c = input_matrix();
      // if (c == -1) {
      //   goto reset;
      // }
      // else update_A(c);

      // char c = input_matrix();
      // if (c == -1) {
      //   goto reset;
      // }
      // else update_A(c);
    }

    // printf("1");
    // reset();

  }
}


void init() {
  F0 = 0;
  F1 = 0;
  A = 0;
  B = 0;
  rst = 0;

  lcd_cmd(0x0F);
  lcd_cmd(0x01);

  return;
}

void input_uart() __interrupt(2) { // По внешнему прерыванию 1
  int num = -1;

  /*
    Реализовать чтение с UART
  */

  update_B(num);
  return;
}

void input_matrix() __interrupt(0) { // По внешнему прерыванию 0
  int num = -1;
  switch (MATRIX & 0x0F) {
  case 0x01: {
    num = 7;
    break;
  }
  case 0x02: {
    num = 4;
    break;
  }
  case 0x04: {
    num = 1;
    break;
  }
  case 0x08: {
    num = 0;
    break;
  }
  };

  switch (MATRIX & 0xF0) {
  case 0x20: {
    if (num != 0) {
      num += 1;
    }
    break;
  } 
  case 0x40: {
    if (num != 0) {
      num += 2;
    }
    else num = -1;
    break;
  } 
  case 0x80: {
    if (num != 0) {
      num += 3;
    }
    else num = 10;
    break;
  } 
  };


  if (num == -1) {
    rst = 1;
    return;
  }
  update_A(num);
  return;
}
  
void delay() {
  TMOD = (TMOD & ~TMOD_MASK0) | (0b0001 & TMOD_MASK0);
  TH0 = 0xB1;
  TL0 = 0xE0;

  TR0 = 1;
  while(!TF0) {

  }
  TR0 = 0;
  TF0 = 0;
  return;
}
  
void lcd_cmd(int cmd) {
  LCD_RS = 0;
  LCD_BYTE = cmd;
  delay();
  LCD_E = 1;
  delay();
  LCD_E = 0;
  return;
}
  
void lcd_send(int cmd) {
  LCD_RS = 1;
  LCD_BYTE = cmd;
  delay();
  LCD_E = 1;
  delay();
  LCD_E = 0;
  return;
}
  
void update_A(int c) {
  
}

void update_B(int c) {

}

// Мусор
  // union PORT {
  //   struct {
  //     char b0 :1;
  //     char b1 :1;
  //     char b2 :1;
  //     char b3 :1;
  //     char b4 :1;
  //     char b5 :1;
  //     char b6 :1;
  //     char b7 :1;
  //   };
  //   char byte;
  // };
  
  // #define P0 (*(volatile union PORT*) 0x080)
  // #define P1 (*(volatile union PORT*) 0x090)
  // #define P2 (*(volatile union PORT*) 0x0A0)
  // #define P3 (*(volatile union PORT*) 0x0B0)
  
  
  
  // union PORT P0_dummy;
  // union PORT P1_dummy;
  // union PORT P2_dummy;
  // union PORT P3_dummy;
  
  // #define P0 (*(volatile union PORT*) &P0_dummy)
  // #define P1 (*(volatile union PORT*) &P1_dummy)
  // #define P2 (*(volatile union PORT*) &P2_dummy)
  // #define P3 (*(volatile union PORT*) &P3_dummy)
  
  // void reset();
  // void initialise_LCD();
  // char listen_UART();
  // char listen_buttons();
  
  // sbit P0 = 0x80;
  
  // union PORT a;
  // printf("%p\n", &a);
  // union PORT P1;
  // P1.byte = 'a';
  // P1.b1 = 1;
  // printf("%c\n", P1.byte);
  // printf("%d\n", sizeof(P1));
// struct PORT &P1 = *(0x080);
// auto i = 0X080;
// printf("123");
// return 0;