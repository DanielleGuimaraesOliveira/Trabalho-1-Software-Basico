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

    // Teste 1: Converter um número positivo que cabe em um byte
    big_val(resultado, 23);
    memset(esperado, 0, sizeof(BigInt));
    esperado[0] = 23;
    
    CU_ASSERT_EQUAL(memcmp(resultado, esperado, sizeof(BigInt)), 0);

    // Teste 2: Converter um número negativo que cabe em um byte
    big_val(resultado, -2);
    memset(esperado, 0, sizeof(BigInt));
    esperado[0] = -2;
    
    for (int i = 1; i < sizeof(BigInt); i++) {
        esperado[i] = 255;
    }

    CU_ASSERT_EQUAL(memcmp(resultado, esperado, sizeof(BigInt)), 0);

    // Teste 3: Converter o número zero
    big_val(resultado, 0);
    memset(esperado, 0, sizeof(BigInt));

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
    
    if ((CU_add_test(suite, "Teste do big_val()", testa_big_val) == NULL)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return CU_get_number_of_failures();
}