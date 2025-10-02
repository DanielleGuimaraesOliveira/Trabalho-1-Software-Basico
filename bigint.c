/* Danielle Guimarães 2320336 33C */
/* Matheus Oliveira 2320452 33C */

#include <stdio.h>
#include <string.h>
#include "testebigint.c"

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

}

void big_comp2(BigInt res, BigInt a){
    unsigned indice = 0;
    unsigned qt_bytes = NUM_BITS / 8;

    while(indice < qt_bytes){
         res[indice] = ~a[indice];
         indice++;
    }
    // adicionar 1 e caso ocorra overflow, propagar o um pelo vetor
    unsigned um = 1;
    indice = 0;

    while (indice < qt_bytes && um) {
        // salvo em uma variavel maior que char para evitar overflow
        unsigned soma = res[indice] + um;
        //pego o byte menos significativo, e atribuo ao res
        res[indice] = soma & 0xff;
        // o proximo um é o byte mais significativo que restou da soma
        um = soma >> 8;
        indice++;

    }
}

void big_sum(BigInt res, BigInt a, BigInt b){
    unsigned qt_bytes = NUM_BITS / 8;
    unsigned um = 0;
    unsigned indice = 0;

    while(indice < qt_bytes){
        unsigned soma = a[indice] + b[indice] + um;
        res[indice] = soma & 0xff;
        um = soma >> 8;
        indice++;
    }
    big_print(res);
}


void big_sub(BigInt res, BigInt a, BigInt b){
    unsigned um = 0;
    unsigned indice = (NUM_BITS / 8)- 1;

    while(indice >= 0){
        unsigned soma = a[indice] - b[indice] - um;
        res[indice] = soma & 0xff;
        um = (soma >> 8) & 1;
        indice--;
    }
    big_print(res);
}






int main (){
    // teste da função big_val
    long num = 1;
    BigInt bigint;
    BigInt bigint2;
    BigInt bigint3;
    big_val(bigint3, 0);
    big_val(bigint, num);
    big_val(bigint2, 2);

    big_sub(bigint3, bigint, bigint2);
    
    return 0;
}