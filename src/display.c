/**
 * display.h est un fichier qui contient les fonctions d'affichage'.
 **/

#include "display.h"

int display(json_t *root, int index, char* argv[], int argc, int affichage)
{
	if(root == NULL){
		return -1;
	}
	
	if(index >= 0)
	{
		json_t *data;
		data = getData(root, index);

		displayName(data, affichage);
		displayCode(data, affichage);

		if (argc > 2)
		{
			int i;
			for(i = 3; i < argc; i++)
			{
				if(strcmp(argv[i], "--show-capital") == 0)
				{
					displayCapital(data,affichage);

				}
				else if(strcmp(argv[i], "--show-languages") == 0)
				{
					displayLanguages(data,affichage);

				}
				else if(strcmp(argv[i], "--show-borders") == 0)
				{
					displayBorders(data,affichage);

				}
				else
				{
					if(affichage)
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

int displayName(json_t * data, int affichage)
{
	const char *name = getName(data);
	if (name != NULL)
	{
		if(affichage)
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

int displayCode(json_t *data, int affichage)
{
	const char *cca3 = getCca3(data);
	if (cca3 != NULL)
	{
		if(affichage)
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

int displayCapital(json_t *data, int affichage)
{
	const char *capital = getCapital(data);
	if (capital != NULL)
	{
		if(affichage)
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

int displayLanguages(json_t *data, int affichage)
{
	if(affichage)
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
			if(affichage)
			{
				printf("%s, ",json_string_value(value));	
			}
		}
	
		if(affichage)
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

int displayBorders(json_t *data, int affichage)
{
	if(affichage)
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
				if(affichage)
				{
					printf("%s, ",json_string_value(json_array_get(borders,i)));
				}
			}
		}
		if(affichage)
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