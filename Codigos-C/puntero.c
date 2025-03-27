#include <stdio.h>

int main() {
    int num;
    char *punt;
    printf("Ingrese un numero en hexadecimal\n");
    scanf("%X", &num);
    punt=(char*)&num;
    printf("Byte 0: %X\n",punt[0]);
    printf("Byte 1: %X\n",punt[1]);
    printf("Byte 2: %X\n",punt[2]);
    printf("Byte 3: %X\n",punt[3]);
}