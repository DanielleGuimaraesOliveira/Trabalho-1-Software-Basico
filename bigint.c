
#include <stdio.h>
#include <string.h>

#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

// função temporária/não oficial para imprimir o BigInt em hexadecimal
void big_print(const BigInt num) {
    
 
    for (int i = 0; i < NUM_BITS/8; i++) {
        printf("%02X", num[i]);
    }
    printf("\n");
}

void big_val (BigInt res, long val){
    memset(res, 0, sizeof(BigInt)); // inicializa o BigInt com zeros
    unsigned indice = 0;
    unsigned qt_bytes = NUM_BITS / 8;

    while(val && indice < qt_bytes){
       unsigned ultimoByte = val & 0xff;
       res[indice] = ultimoByte;
       val = val>>8;
       indice++;

    }

    big_print(res);
}




int main (){
    // teste da função big_val
    long num = 123;
    BigInt bigint;
    big_val(bigint, num);

    
    return 0;
}