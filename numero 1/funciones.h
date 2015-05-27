#include <stdio.h>

#define MAX_SEGUNDOS 10

#define gotoxy(x,y) printf("%c[%d;%df",0x1B,y,x);

#define clear() system("clear");

#define generar_aleatorio(limite) rand()%limite

#define generar_tiempo()  generar_aleatorio(MAX_SEGUNDOS) 
