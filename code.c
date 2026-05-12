
union PORT {
  struct {
    char b0 :1;
    char b1 :1;
    char b2 :1;
    char b3 :1;
    char b4 :1;
    char b5 :1;
    char b6 :1;
    char b7 :1;
  };
  char byte;
};

// #define P0 (*(volatile union PORT*) 0x080)
// #define P1 (*(volatile union PORT*) 0x090)
// #define P2 (*(volatile union PORT*) 0x0A0)
// #define P3 (*(volatile union PORT*) 0x0B0)



union PORT P0_dummy;
union PORT P1_dummy;
union PORT P2_dummy;
union PORT P3_dummy;

#define P0 (*(volatile union PORT*) &P0_dummy)
#define P1 (*(volatile union PORT*) &P1_dummy)
#define P2 (*(volatile union PORT*) &P2_dummy)
#define P3 (*(volatile union PORT*) &P3_dummy)

void reset();
void initialise_LCD();
char listen_UART();
char listen_buttons();

int main() {
  while (1) {
    reset();

  }
}






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