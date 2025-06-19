#include <stdio.h>

union conversionbytes {
    int num;
    char bytes[4];
};

int main() {
    union conversionbytes ac;
    printf("Ingrese un numero en hexadecimal\n");
    scanf("%X", &ac.num);
    printf("Byte 0: %X\n", ac.bytes[0]);
    printf("Byte 1: %X\n", ac.bytes[1]);
    printf("Byte 2: %X\n", ac.bytes[2]);
    printf("Byte 3: %X\n", ac.bytes[3]);
}