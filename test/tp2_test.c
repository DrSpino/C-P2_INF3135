#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <jansson.h>

#include "CUnit/Basic.h"
#include "../src/readJson.h"

/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/

void getCca3_test_true(void){
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root);

   json_t *data;
   data = getData(root,0);

   const char *cca3_string = getCca3(data);
   const char *string_test = "ABW";

   CU_ASSERT_TRUE(strcmp(cca3_string, string_test) == 0);

   json_decref(root);
}

void geCca3_test_false(void){
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root);

   json_t *data;
   data = getData(root,1);

   const char *cca3_string = getCca3(data);
   const char *string_test = "ABW";

   CU_ASSERT_FALSE(strcmp(cca3_string, string_test) == 0);

   json_decref(root);
}

void getCapital_test_true(void){
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root);

   json_t *data;
   data = getData(root,0);

   const char *capital_string = getCapital(data);
   const char *string_test = "Oranjestad";

   CU_ASSERT_TRUE(strcmp(capital_string, string_test) == 0);

   json_decref(root);
}

void getCapital_test_false(void){
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root);

   json_t *data;
   data = getData(root,0);

   const char *capital_string = getCapital(data);
   const char *string_test = "Ottawa";
   
   CU_ASSERT_FALSE(strcmp(capital_string, string_test) == 0);

   json_decref(root);
}


int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "jsonRead_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "getCca3_test_true", getCca3_test_true)) ||
         (NULL == CU_add_test(pSuite, "getCca3_test_true", getCca3_test_true)) ||
         (NULL == CU_add_test(pSuite, "getCapital_test_true", getCapital_test_true)) ||
         (NULL == CU_add_test(pSuite, "getCapital_test_false", getCapital_test_false))  
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}