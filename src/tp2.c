#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>

#include "readJson.h"

int main(void)
{

	json_t *root;
	char *text_root = "../data/countries.json";

	root = openJsonFile(text_root);

	json_t *data;
	data = getData(root,1);

	/*Utilisation du getCca3 de readJson.h*/
	const char *cca3 = getCca3(data);
	if (cca3 != NULL)
	{
		printf("%s\n", cca3);
	}

	/*Utilisation du getCapital de readJson.h*/
	const char *capital = getCapital(data);
	if (capital != NULL)
	{
		printf("%s\n", capital);
	}

	/*Utilisation du getLanguages de readJson.h*/
	json_t *languages = getLanguages(data);
	const char *key;
	json_t *value;
	json_object_foreach(languages, key, value) 
	{
		printf("%s\n",json_string_value(value));
	}


	json_decref(root);

	return 0;
}