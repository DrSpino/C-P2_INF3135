/**
 * display.h est un fichier qui contient les fonctions d'affichage'.
 **/

void display(json_t *root, int index, char* argv[], int argc);
void displayName(json_t *data);
void displayCode(json_t *data);
void displayCapital(json_t *data);
void displayLanguages(json_t *data);
void displayBorders(json_t *data);

void display(json_t *root, int index, char* argv[], int argc)
{
	if(index >= 0)
	{
		json_t *data;
		data = getData(root, index);

		displayName(data);
		displayCode(data);

		if (argc > 2)
		{
			int i;
			for(i = 3; i < argc; i++)
			{
				if(strcmp(argv[i], "--show-capital") == 0)
				{
					displayCapital(data);

				}else if(strcmp(argv[i], "--show-languages") == 0)
				{
					displayLanguages(data);

				}else if(strcmp(argv[i], "--show-borders") == 0)
				{
					displayBorders(data);

				}else
				{
					printf("arg %i invalid !\n", i);
				}
			}
		}
	}
}


void displayName(json_t * data)
{
	printf("Name : ");
	const char *name = getName(data);
	if (name != NULL)
	{
		printf("%s", name);
	}

	printf("\n");
}

void displayCode(json_t *data)
{
	const char *cca3 = getCca3(data);
	if (cca3 != NULL)
	{
		printf("Code : %s\n", cca3);
	}
}

void displayCapital(json_t *data)
{
	printf("Capital : ");
	const char *capital = getCapital(data);
	if (capital != NULL)
	{
		printf("%s", capital);
	}

	printf("\n");
}


void displayLanguages(json_t *data)
{
	printf("Languages : ");
	json_t *languages = getLanguages(data);

	if (languages != NULL)
	{
		const char *key;
		json_t *value;
		json_object_foreach(languages, key, value) 
		{
			printf("%s, ",json_string_value(value));
		}
	}

	printf("\n");
}

void displayBorders(json_t *data)
{
	printf("Borders : ");
	json_t *borders = getBorders(data);
	if(borders != NULL)
	{
		if (json_array_size(borders) != 0)
		{
			int i;
			for (i = 0; i < (int)json_array_size(borders)-1; i++)
			{
				printf("%s, ",json_string_value(json_array_get(borders,i)));
			}

			printf("%s ",json_string_value(json_array_get(borders,i)));
		}

		printf("\n");
	}
}