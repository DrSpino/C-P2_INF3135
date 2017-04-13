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

void cca3_test_1(void){
	json_t *root;
	char *text_root = "data/countries.json";
	root = openJsonFile(text_root);

	json_t *data;
	data = getData(root,0);

	const char *cca3_string = getCca3(data);
   const char *string_test = "ABW";

   printf("\n%s\n",cca3_string );
   printf("%s\n",string_test );

	CU_ASSERT_TRUE(strcmp(cca3_string, string_test) == 0);

   json_decref(root);
}

void cca3_test_2(void){
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
   if ( (NULL == CU_add_test(pSuite, "cca3_test_1", cca3_test_1)) ||
        (NULL == CU_add_test(pSuite, "cca3_test_2", cca3_test_2)) 
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