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

void getCca3_test_true(void)
{
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

void getCca3_test_false(void)
{
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

void getCca3_test_null(void)
{
   const char *cca3_string = getCca3(NULL);

   CU_ASSERT_PTR_NULL(cca3_string);
}

void getCapital_test_true(void)
{
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

void getCapital_test_false(void)
{
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

void getCapital_test_null(void)
{
   const char *capital_string = getCapital(NULL);

   CU_ASSERT_PTR_NULL(capital_string);
}

void getLanguages_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root);

   json_t *data;
   data = getData(root,2);

   json_t *languages = getLanguages(data);

   const char *string_test = "Portuguese";

   const char *key;
   json_t *value;
   json_object_foreach(languages, key, value) 
   {
      CU_ASSERT_TRUE(strcmp(string_test, json_string_value(value)) == 0);
   }

   json_decref(root);
}

void getLanguages_test_false(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root);

   json_t *data;
   data = getData(root,2);

   json_t *languages = getLanguages(data);

   const char *string_test = "English";

   const char *key;
   json_t *value;
   json_object_foreach(languages, key, value) 
   {
      CU_ASSERT_TRUE(strcmp(string_test, json_string_value(value)) == 0);
   }

   json_decref(root);
}

void getLanguages_test_null(void)
{
   json_t *languages = getLanguages(NULL);

   CU_ASSERT_PTR_NULL(languages);
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
         (NULL == CU_add_test(pSuite, "getCca3_test_false", getCca3_test_false)) ||
         (NULL == CU_add_test(pSuite, "getCca3_test_null", getCca3_test_null)) ||
         (NULL == CU_add_test(pSuite, "getCapital_test_true", getCapital_test_true)) ||
         (NULL == CU_add_test(pSuite, "getCapital_test_false", getCapital_test_false)) ||
         (NULL == CU_add_test(pSuite, "getCapital_test_null", getCapital_test_null)) ||
         (NULL == CU_add_test(pSuite, "getLanguages_test_true", getLanguages_test_true)) ||
         (NULL == CU_add_test(pSuite, "getLanguages_test_false", getLanguages_test_false)) ||
         (NULL == CU_add_test(pSuite, "getLanguages_test_null", getLanguages_test_null))
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