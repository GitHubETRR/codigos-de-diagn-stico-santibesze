#include <stdio.h>

union flag {
    unsigned char num;  
    struct bits {
        unsigned int bit_0 : 1;
        unsigned int bit_1 : 1;
        unsigned int bit_2 : 1;
        unsigned int bit_3 : 1;
        unsigned int bit_4 : 1;
        unsigned int bit_5 : 1;
        unsigned int bit_6 : 1;
        unsigned int bit_7 : 1;
    } bits;
};

void IngresarNum(union flag *estado);
void MuestraBits(union flag estado);

int main() {
    union flag estado;

    IngresarNum(&estado);
    MuestraBits(estado);

    return 0;  
}

void IngresarNum(union flag *estado) {
    printf("Ingrese un número (0-255): ");
    scanf("%hhu", &estado->num);  
}

void MuestraBits(union flag estado) {
    printf("El número en binario es: ");
    printf("%d%d%d%d%d%d%d%d\n", estado.bits.bit_7, estado.bits.bit_6, estado.bits.bit_5, estado.bits.bit_4,estado.bits.bit_3, estado.bits.bit_2, estado.bits.bit_1, estado.bits.bit_0);
}