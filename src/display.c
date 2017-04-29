/**
 * display.c est un fichier qui contient les fonctions d'display_test.
 **/

#include "display.h"

int display(json_t *root, int index, char* argv[], int argc, int display_test)
{
	if(root == NULL){
		return -1;
	}
	
	if(index >= 0)
	{
		json_t *data;
		data = getData(root, index);

		displayName(data, display_test);
		displayCode(data, display_test);

		if (argc > 2)
		{
			int i;
			for(i = 3; i < argc; i++)
			{
				if(strcmp(argv[i], "--show-capital") == 0)
				{
					displayCapital(data,display_test);

				}
				else if(strcmp(argv[i], "--show-languages") == 0)
				{
					displayLanguages(data,display_test);

				}
				else if(strcmp(argv[i], "--show-borders") == 0)
				{
					displayBorders(data,display_test);

				}
				else
				{
					if(display_test)
					{
						printf("arg %i invalid !\n", i);
					}
					return -2;
				}
			}
		}
		else
		{
			return -3;
		}
	}
	else
	{
		return -4;
	}
	return 0;
}

int displayName(json_t * data, int display_test)
{
	const char *name = getName(data);
	if (name != NULL)
	{
		if(display_test)
		{
			printf("Name : %s \n", name);
		}
		return 0;
	}
	else
	{
		return -1;
	}	
}

int displayCode(json_t *data, int display_test)
{
	const char *cca3 = getCca3(data);
	if (cca3 != NULL)
	{
		if(display_test)
		{
			printf("Code : %s\n", cca3);
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

int displayCapital(json_t *data, int display_test)
{
	const char *capital = getCapital(data);
	if (capital != NULL)
	{
		if(display_test)
		{
			printf("Capital : %s\n", capital);
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

int displayLanguages(json_t *data, int display_test)
{
	if(display_test)
	{
		printf("Languages : ");	
	}
		
	json_t *languages = getLanguages(data);

	if (languages != NULL)
	{
		const char *key;
		json_t *value;
		json_object_foreach(languages, key, value) 
		{
			if(display_test)
			{
				printf("%s, ",json_string_value(value));	
			}
		}
	
		if(display_test)
		{
			printf("\n");
		}
		
		return 0;
	}
	else
	{
		return -1;
	}
}

int displayBorders(json_t *data, int display_test)
{
	if(display_test)
	{
		printf("Borders : ");
	}
	
	json_t *borders = getBorders(data);
	
	if(borders != NULL)
	{
		if (json_array_size(borders) != 0)
		{
			int i;
			for (i = 0; i < (int)json_array_size(borders); i++)
			{
				if(display_test)
				{
					printf("%s, ",json_string_value(json_array_get(borders,i)));
				}
			}
		}
		if(display_test)
		{
			printf("\n");
		}

		return 0;
	}
	else
	{
		return -1;
	}
}