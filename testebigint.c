/* Danielle Guimarães 2320336 33C */
/* Matheus Oliveira 2320452 33C */

#include "bigint.h"
#include <stdio.h>
#include <string.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

void testa_big_val (void) {
    BigInt resultado;
    BigInt esperado;
    
    // Teste 1: Converter um número pequeno (23)
    big_val(resultado, 23);
    
    // O valor esperado para 23 em um BigInt de 16 bytes (128 bits)
    // é 0x17 (23 em hexadecimal) no primeiro byte e o restante zero.
    memset(esperado, 0, sizeof(BigInt));
    esperado[0] = 23;
    
    // CU_ASSERT_EQUAL compara dois valores. Para arrays, você precisa de um loop ou memcmp
    // Para arrays, memcmp é uma ótima opção para comparar o conteúdo de memória
    CU_ASSERT_EQUAL(memcmp(resultado, esperado, sizeof(BigInt)), 0);

    // Teste 2: Converter um número maior que cabe em um byte (256)
    big_val(resultado, 256); // 0x100
    memset(esperado, 0, sizeof(BigInt));
    esperado[1] = 1; // 256 é 1 << 8, então o segundo byte será 1
    
    CU_ASSERT_EQUAL(memcmp(resultado, esperado, sizeof(BigInt)), 0);
}


int main (void) {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    CU_pSuite suite = CU_add_suite("BigIntTestSuite", 0, 0);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if ((CU_add_test(suite, "Test of big_val()", testa_big_val) == NULL)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return CU_get_number_of_failures();
}