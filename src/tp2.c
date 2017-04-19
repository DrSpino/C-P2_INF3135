#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>
#include <string.h>
#include <ctype.h>

#include "readJson.h"
#include "command.h"

int main(int argc, char* argv[])
{
	
	if(argc < 2 || argc > 6)
	{
		fprintf(stderr,"error: the number of arguments must be between 1 and 5 \n");
		exit(1);
	}
	
	json_t *root;
	char *text_root = "../data/countries.json";
	
	root = openJsonFile(text_root);

	int index = -1;
	if(root != NULL)
	{
		if(strcmp(argv[1], "--country") == 0)
		{
			index = countryCommand(root,argv[2]);
		}
	}
	
	if(index >= 0)
	{
		json_t *data;
		data = getData(root, index);

		/*Utilisation du getName de readJson.h*/
		const char *name = getName(data);
		if (name != NULL)
		{
			printf("Name : %s\n", name);
		}

		/*Utilisation du getCca3 de readJson.h*/
		const char *cca3 = getCca3(data);
		if (cca3 != NULL)
		{
			printf("Code : %s\n", cca3);
		}

		/*Utilisation du getCapital de readJson.h*/
		const char *capital = getCapital(data);
		if (capital != NULL)
		{
			printf("Capital : %s\n", capital);
		}

		/*Utilisation du getLanguages de readJson.h*/
		printf("Languages : ");
		json_t *languages = getLanguages(data);
		const char *key;
		json_t *value;
		json_object_foreach(languages, key, value) 
		{
			printf("%s, ",json_string_value(value));
		}
		printf("\n");

		/*Utilisation du getBorders de readJson.h*/
		printf("Borders : ");
		json_t *borders = getBorders(data);
		int i;
		for(i = 0; i < (int)json_array_size(borders); i++)
		{
			printf("%s, ",json_string_value(json_array_get(borders,i)));
		}
		printf("\n");
	}
	
	json_decref(root);

	return 0;
}