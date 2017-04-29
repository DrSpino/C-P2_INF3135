/**
 * tp2_test.c est un fichier qui contient les test de tout le projet countries.
**/
 

#include <stdio.h>
#include <string.h>
#include <jansson.h>



#include "CUnit/Basic.h"
#include "../src/readJson.h"
#include "../src/display.h"
#include "../src/command.h"


/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/

void display_test_true(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	char* argv[] = {"tp2","--region","americas","--show-capital"};
	int argc = 4;
	int index = 12;
	
	int result = display(root, index, argv, argc, 0);

	CU_ASSERT_TRUE(result == 0);
   
    json_decref(root);
}

void display_test_false(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	char* argv[] = {"tp2","--region","americas","--show-capital"};
	int argc = 4;
	int index = -2;
	
	int result = display(root, index, argv, argc, 0);

	CU_ASSERT_FALSE(result == 0);

   
    json_decref(root);
}

void display_test_erreur1(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	char* argv[] = {"tp2","--region","americas","--show-location"};
	int argc = 4;
	int index = 7;
	
	int result = display(root, index, argv, argc, 0);

	CU_ASSERT_TRUE(result == -2);
   
    json_decref(root);
}

void display_test_erreur2(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	char* argv[] = {"tp2","--region"};
	int argc = 2;
	int index = 7;
	
	int result = display(root, index, argv, argc, 0);

	CU_ASSERT_TRUE(result == -3);
   
    json_decref(root);
}

void display_test_erreur3(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	char* argv[] = {"tp2","--region","asia","--show-capital"};
	int argc = 4;
	int index = -6;
	
	int result = display(root, index, argv, argc, 0);

	CU_ASSERT_TRUE(result == -4);
   
    json_decref(root);
}

void display_test_null(void)
{
	char* argv[] = {"tp2","--region","americas","--show-capital"};
	int argc = 4;
	int index = 6;
	
	int result = display(NULL, index, argv, argc, 0);

	CU_ASSERT_TRUE(result == -1);
}


void displayName_test_true(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,2);
	int result = displayName(data, 0);

	CU_ASSERT_TRUE(result == 0);
   
    json_decref(root);
}

void displayName_test_false(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,2);
	int result = displayName(data, 0);

	CU_ASSERT_FALSE(result == -1);
   
    json_decref(root);
}

void displayName_test_null(void)
{
	int result = displayName(NULL, 0);

	CU_ASSERT_TRUE(result == -1);
}

void displayCode_test_true(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,4);
	int result = displayCode(data, 0);

	CU_ASSERT_TRUE(result == 0);
   
    json_decref(root);
}

void displayCode_test_false(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,4);
	int result = displayCode(data, 0);

	CU_ASSERT_FALSE(result == -1);
   
    json_decref(root);
}

void displayCode_test_null(void)
{
	int result = displayCode(NULL, 0);

	CU_ASSERT_TRUE(result == -1);
}

void displayCapital_test_true(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,4);
	int result = displayCapital(data, 0);

	CU_ASSERT_TRUE(result == 0);
   
    json_decref(root);
}

void displayCapital_test_false(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,4);
	int result = displayCapital(data, 0);

	CU_ASSERT_FALSE(result == -1);
   
    json_decref(root);
}

void displayCapital_test_null(void)
{
	int result = displayCapital(NULL, 0);

	CU_ASSERT_TRUE(result == -1);
}

void displayLanguages_test_true(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,8);
	int result = displayLanguages(data, 0);

	CU_ASSERT_TRUE(result == 0);
   
    json_decref(root);
}

void displayLanguages_test_false(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,8);
	int result = displayLanguages(data, 0);

	CU_ASSERT_FALSE(result == -1);
   
    json_decref(root);
}

void displayLanguages_test_null(void)
{
	int result = displayLanguages(NULL, 0);

	CU_ASSERT_TRUE(result == -1);
}

void displayBorders_test_true(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,6);
	int result = displayBorders(data, 0);

	CU_ASSERT_TRUE(result == 0);
   
    json_decref(root);
}

void displayBorders_test_false(void)
{
	json_t *root;
    char *text_root = "data/countries.json";
    root = openJsonFile(text_root, 1);
   
	json_t *data = getData(root,4);
	int result = displayBorders(data, 0);

	CU_ASSERT_FALSE(result == -1);
   
    json_decref(root);
}

void displayBorders_test_null(void)
{
	int result = displayBorders(NULL, 0);

	CU_ASSERT_TRUE(result == -1);
}


void openJsonFile_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 0);
   
   CU_ASSERT_TRUE(json_is_array(root));
   
   json_decref(root);
}

void openJsonFile_test_false(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 0);
   
   CU_ASSERT_FALSE(json_is_object(root));
   
   json_decref(root);
}

void openJsonFile_test_null(void)
{
   json_t *root = openJsonFile(NULL, 0);
   
   CU_ASSERT_PTR_NULL(root);
   
}

void getData_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   json_t *data = getData(root,2);

   const char *name_string = getName(data);
   const char *string_test = "Angola";

   CU_ASSERT_TRUE(strcmp(string_test, name_string) == 0);
   
   json_decref(root);
}

void getData_test_false(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   json_t *data = getData(root,2);

   const char *name_string = getName(data);
   const char *string_test = "Andorra";

   CU_ASSERT_FALSE(strcmp(string_test, name_string) == 0);
   
   json_decref(root);
}

void getData_test_null(void)
{
   json_t *data = getData(NULL,2);

   CU_ASSERT_PTR_NULL(data);
}

void getName_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   json_t *data;
   data = getData(root,1);

   const char *name_string = getName(data);
   const char *string_test = "Afghanistan";

   CU_ASSERT_TRUE(strcmp(name_string, string_test) == 0);

   json_decref(root);
}

void getName_test_false(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   json_t *data;
   data = getData(root,0);

   const char *name_string = getName(data);
   const char *string_test = "Afghanistan";

   CU_ASSERT_FALSE(strcmp(name_string, string_test) == 0);

   json_decref(root);
}

void getName_test_null(void)
{
   const char *name_string = getName(NULL);

   CU_ASSERT_PTR_NULL(name_string);
}

void getCca3_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

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
   root = openJsonFile(text_root, 1);

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
   root = openJsonFile(text_root, 1);

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
   root = openJsonFile(text_root, 1);

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

void getRegion_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   json_t *data;
   data = getData(root,0);

   const char *region_string = getRegion(data);
   const char *string_test = "Americas";

   CU_ASSERT_TRUE(strcmp(region_string, string_test) == 0);

   json_decref(root);
}

void getRegion_test_false(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   json_t *data;
   data = getData(root,0);

   const char *region_string = getRegion(data);
   const char *string_test = "Asia";
   
   CU_ASSERT_FALSE(strcmp(region_string, string_test) == 0);

   json_decref(root);
}

void getRegion_test_null(void)
{
   const char *region_string = getRegion(NULL);

   CU_ASSERT_PTR_NULL(region_string);
}

void getLanguages_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

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
   root = openJsonFile(text_root, 1);

   json_t *data;
   data = getData(root,2);

   json_t *languages = getLanguages(data);

   const char *string_test = "English";

   const char *key;
   json_t *value;
   json_object_foreach(languages, key, value) 
   {
      CU_ASSERT_FALSE(strcmp(string_test, json_string_value(value)) == 0);
   }

   json_decref(root);
}

void getLanguages_test_null(void)
{
   json_t *languages = getLanguages(NULL);

   CU_ASSERT_PTR_NULL(languages);
}

void getBorders_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   json_t *data;
   data = getData(root,1);

   json_t *borders = json_object_get(data, "borders");

   const char *string_test = "IRN";
   CU_ASSERT_TRUE(strcmp(string_test,json_string_value(json_array_get(borders,0))) == 0);

   json_decref(root);
}

void getBorders_test_false(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   json_t *data;
   data = getData(root,1);

   json_t *borders = json_object_get(data, "borders");

   const char *string_test = "IRN";
   CU_ASSERT_FALSE(strcmp(string_test,json_string_value(json_array_get(borders,2))) == 0);

   json_decref(root);
}

void getBorders_test_null(void)
{
   json_t *borders = getBorders(NULL);

   CU_ASSERT_PTR_NULL(borders);
}

void countryCommand_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   char in [] = "alb";
   int index = countryCommand(root, in, 0);

   CU_ASSERT_TRUE(index == 5);

   json_decref(root);
}

void countryCommand_test_false(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   char in [] = "CAN";
   int index = countryCommand(root, in, 0);

   CU_ASSERT_FALSE(index == 5);

   json_decref(root);
}

void countryCommand_test_erreur(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   char in [] = "abc";
   int index = countryCommand(root, in, 0);

   CU_ASSERT_TRUE(index == -2);

   json_decref(root);
}

void countryCommand_test_null(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);

   int index = countryCommand(root, NULL, 0);

   CU_ASSERT_TRUE(index == -1);

   json_decref(root);
}

void regionCommand_test_true(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);
   char* argv[] = {"","--region","americas"};
   int result = regionCommand(root, argv, 3, 0);
 
   CU_ASSERT_TRUE(result == 0);

   json_decref(root);
}

void regionCommand_test_false(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);
   char* argv[] = {"tp2","--region","europe"};
   int result = regionCommand(root, argv, 3, 0);

   CU_ASSERT_FALSE(result == -2);

   json_decref(root);
}

void regionCommand_test_erreur(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);
   char* argv[] = {"tp2","--region","ASIA"};
   int result = regionCommand(root, argv, 3, 0);

   CU_ASSERT_TRUE(result == -2);

   json_decref(root);
}

void regionCommand_test_null(void)
{
   json_t *root;
   char *text_root = "data/countries.json";
   root = openJsonFile(text_root, 1);
   char* argv[] = {"","--region",NULL};
   int result = regionCommand(root, argv, 3, 0);

   CU_ASSERT_TRUE(result == -1);

   json_decref(root);
}

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "test_suite", init_suite, clean_suite );
   if ( NULL == pSuite )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if (  (NULL == CU_add_test(pSuite, "display_test_true", display_test_true)) ||
		 (NULL == CU_add_test(pSuite, "display_test_false", display_test_false)) ||
		 (NULL == CU_add_test(pSuite, "display_test_null", display_test_null)) ||
		 (NULL == CU_add_test(pSuite, "display_test_erreur1", display_test_erreur1)) ||
		 (NULL == CU_add_test(pSuite, "display_test_erreur2", display_test_erreur2)) ||
		 (NULL == CU_add_test(pSuite, "display_test_erreur3", display_test_erreur3)) ||
		 (NULL == CU_add_test(pSuite, "displayName_test_true", displayName_test_true)) ||
		 (NULL == CU_add_test(pSuite, "displayName_test_false", displayName_test_false)) ||
		 (NULL == CU_add_test(pSuite, "displayName_test_null", displayName_test_null)) ||
		 (NULL == CU_add_test(pSuite, "displayCode_test_true", displayCode_test_true)) ||
		 (NULL == CU_add_test(pSuite, "displayCode_test_false", displayCode_test_false)) ||
		 (NULL == CU_add_test(pSuite, "displayCode_test_null", displayCode_test_null)) ||
		 (NULL == CU_add_test(pSuite, "displayCapital_test_true", displayCapital_test_true)) ||
		 (NULL == CU_add_test(pSuite, "displayCapital_test_false", displayCapital_test_false)) ||
		 (NULL == CU_add_test(pSuite, "displayCapital_test_null", displayCapital_test_null)) ||
		 (NULL == CU_add_test(pSuite, "displayLanguages_test_true", displayLanguages_test_true)) ||
		 (NULL == CU_add_test(pSuite, "displayLanguages_test_false", displayLanguages_test_false)) ||
		 (NULL == CU_add_test(pSuite, "displayLanguages_test_null", displayLanguages_test_null)) ||
		 (NULL == CU_add_test(pSuite, "displayBorders_test_true", displayBorders_test_true)) ||
		 (NULL == CU_add_test(pSuite, "displayBorders_test_false", displayBorders_test_false)) ||
		 (NULL == CU_add_test(pSuite, "displayBorders_test_null", displayBorders_test_null)) ||
		 (NULL == CU_add_test(pSuite, "openJsonFile_test_true", openJsonFile_test_true)) ||
		 (NULL == CU_add_test(pSuite, "openJsonFile_test_false", openJsonFile_test_false)) ||
		 (NULL == CU_add_test(pSuite, "openJsonFile_test_null", openJsonFile_test_null)) ||
		 (NULL == CU_add_test(pSuite, "getData_test_true", getData_test_true)) ||
         (NULL == CU_add_test(pSuite, "getData_test_false", getData_test_false)) ||
         (NULL == CU_add_test(pSuite, "getData_test_null", getData_test_null)) ||
		 (NULL == CU_add_test(pSuite, "getName_test_true", getName_test_true)) ||
         (NULL == CU_add_test(pSuite, "getName_test_false", getName_test_false)) ||
         (NULL == CU_add_test(pSuite, "getName_test_null", getName_test_null)) ||
         (NULL == CU_add_test(pSuite, "getCca3_test_true", getCca3_test_true)) ||
         (NULL == CU_add_test(pSuite, "getCca3_test_false", getCca3_test_false)) ||
         (NULL == CU_add_test(pSuite, "getCca3_test_null", getCca3_test_null)) ||
         (NULL == CU_add_test(pSuite, "getCapital_test_true", getCapital_test_true)) ||
         (NULL == CU_add_test(pSuite, "getCapital_test_false", getCapital_test_false)) ||
         (NULL == CU_add_test(pSuite, "getCapital_test_null", getCapital_test_null)) ||
		 (NULL == CU_add_test(pSuite, "getRegion_test_true", getRegion_test_true)) ||
         (NULL == CU_add_test(pSuite, "getRegion_test_false", getRegion_test_false)) ||
         (NULL == CU_add_test(pSuite, "getRegion_test_null", getRegion_test_null)) ||
         (NULL == CU_add_test(pSuite, "getLanguages_test_true", getLanguages_test_true)) ||
         (NULL == CU_add_test(pSuite, "getLanguages_test_false", getLanguages_test_false)) ||
         (NULL == CU_add_test(pSuite, "getLanguages_test_null", getLanguages_test_null)) ||
         (NULL == CU_add_test(pSuite, "getBorders_test_true", getBorders_test_true)) ||
         (NULL == CU_add_test(pSuite, "getBorders_test_false", getBorders_test_false)) ||
         (NULL == CU_add_test(pSuite, "getBorders_test_null", getBorders_test_null)) ||
		 (NULL == CU_add_test(pSuite, "countryCommand_test_true", countryCommand_test_true)) ||
		 (NULL == CU_add_test(pSuite, "countryCommand_test_false", countryCommand_test_false)) ||
		 (NULL == CU_add_test(pSuite, "countryCommand_test_erreur", countryCommand_test_erreur)) ||
		 (NULL == CU_add_test(pSuite, "countryCommand_test_null", countryCommand_test_null)) ||
		 (NULL == CU_add_test(pSuite, "regionCommand_test_true", regionCommand_test_true)) ||
		 (NULL == CU_add_test(pSuite, "regionCommand_test_false", regionCommand_test_false)) ||
		 (NULL == CU_add_test(pSuite, "regionCommand_test_erreur", regionCommand_test_erreur)) ||
		 (NULL == CU_add_test(pSuite, "regionCommand_test_null", regionCommand_test_null))
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