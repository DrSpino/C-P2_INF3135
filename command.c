/**
 * command.h est un fichier qui contient les fonctions de commandes.
 **/

#include "command.h"

int countryCommand(json_t *root, char *in)
{
	if(in == NULL)
	{
		fprintf(stderr, "error : country argument invalid\n");
		return -1;
	}
	
	char *s = in;
  	while (*s) 
	{
    	*s = toupper((unsigned char) *s);
    	s++;
  	}
  	
	int i;
	for(i = 0; i < (int)json_array_size(root); i++)
	{
		json_t *data = getData(root,i);
		const char *cca3 = getCca3(data);

		if (cca3 != NULL && strcmp(in, cca3) == 0)
		{
			return i;
		}
	}

	fprintf(stderr, "Country not found\n");
	return -2;
}

int regionCommand(json_t *root,  char* argv[], int argc, int affichage)
{
	char *regionArray[] = {"Africa","Americas","Asia","Europe","Oceania"};

	if(argv[2] == NULL)
	{
		fprintf(stderr,"error: the country code is not a string \n");
		return -1;	
	}
		
	char regionCode[4];
	strcpy(regionCode,argv[2]);
	/* oceania --> Oceania */
	char *region = regionCode;
	region[0] = toupper(region[0]);
			
	int j;
	int regionObtainedValid = 1;
	for(j=0; j< 5; j++)
	{
		if(strcmp(region, regionArray[j]) == 0)
		{
			regionObtainedValid--;
			int i;
			/* display each data if data.getRegion equals region)*/
			for(i = 0; i < (int)json_array_size(root); i++)
			{
				json_t *data;
				data = getData(root,i);
				const char *regionObtained = getRegion(data);
					if(strcmp(region,regionObtained) == 0 && affichage == 0)
					{
						display(root, i, argv, argc, 1);
						printf("\n");
					}
			}
		}
	}
	/* validate the region inside the regionArray */
	if(regionObtainedValid)
	{
		return -2;	
	}else
	{
		return 0;
	}
			
}

int sameLanguageCommand(json_t *root, char* argv[],int argc)
{
	int result = 0;

	if(argc < 4 || argc > 5)
	{
		fprintf(stderr,"number of argument invalid for command --same.\n");
		return -1;
	}

	if(countryCommand(root, argv[2]) == -2){
		return -2;
	}				
	json_t *c1 = getLanguages(
					getData(root, 
						countryCommand(root, argv[2])));

		
	if(countryCommand(root, argv[3]) == -2){
		return -2;
	}					
	json_t *c2 = getLanguages(
						getData(root, 
							countryCommand(root, argv[3])));

	if(argc == 5)
	{
		if(countryCommand(root, argv[4]) == -2){
			return -2;
		}	
		json_t *c3 = getLanguages(
						getData(root, 
							countryCommand(root, argv[4])));

		result = sameLanguage3(c1, c2, c3);
	}
	else
	{
		result = sameLanguage2(c1, c2);
	}

	return result;
}

int sameLanguage2(json_t *c1, json_t *c2)
{
	int result = 1;

	if(c1 == NULL || c2 == NULL)
	{
		return -1;
	}
	
	const char *key1;
	json_t *val1;
	json_object_foreach(c1, key1, val1) 
	{
		const char *key2;
		json_t *val2;
		json_object_foreach(c2, key2, val2) 
		{	
			if(strcmp(json_string_value(val1), json_string_value(val2)) == 0)
			{
				if(result == 1)
				{
					printf("yes %s",json_string_value(val1));
					result = 0;
				}
				else
				{
					printf(" %s",json_string_value(val1));
				}
			}
		}
	}

	if(result == 0)
	{
		printf("\n");
	}

	return result;
}

int sameLanguage3(json_t *c1, json_t *c2, json_t *c3)
{
	int result = 1;

	if(c1 == NULL || c2 == NULL || c3 == NULL)
	{
		return -1;
	}
	
	const char *key1;
	json_t *val1;
	json_object_foreach(c1, key1, val1) 
	{
		const char *key2;
		json_t *val2;
		json_object_foreach(c2, key2, val2) 
		{	
			const char *key3;
			json_t *val3;
			json_object_foreach(c3, key3, val3) 
			{	
				if((strcmp(json_string_value(val1), json_string_value(val2)) == 0) &&
					(strcmp(json_string_value(val2), json_string_value(val3)) == 0))
				{
					if(result == 1)
					{
						printf("yes %s",json_string_value(val1));
						result = 0;
					}
					else
					{
						printf(" %s",json_string_value(val1));
					}
				}
			}
		}
	}

	if(result == 0)
	{
		printf("\n");
	}

	return result;
}

int sameBordersCommand(json_t *root, char* argv[],int argc)
{
	int result = 0; 
	if(argc < 4 || argc > 5)
	{
		fprintf(stderr,"number of argument invalid for command --same.\n");
		return -1;
	}
	
	if(countryCommand(root, argv[2]) == -2 || countryCommand(root, argv[3]) == -2){
		return -2;
	}
	json_t *c1_data = getData(root, countryCommand(root, argv[2]));
	json_t *c1 = getBorders(c1_data);
	char pays1[3];
	strcpy(pays1, getCca3(c1_data)); 
	
	json_t *c2_data = getData(root, countryCommand(root, argv[3]));
	json_t *c2 = getBorders(c2_data);
	char pays2[3];
	strcpy(pays2, getCca3(c2_data));
	
	if(argc == 5)
	{
		if(countryCommand(root, argv[4]) == -2)
		{
			return -2;
		}
	    json_t *c3_data = getData(root, countryCommand(root, argv[4]));
		json_t *c3 = getBorders(c3_data);
		char pays3[3];
		strcpy(pays3, getCca3(c3_data)); 
		
		result = sameBorder3(c1, c2, c3, pays1, pays2, pays3);
	}
	else		
	{
		result = sameBorder2(c1, c2, pays1, pays2);
	}

	return result;
}

int sameBorder2(json_t *c1, json_t *c2, char* pays1, char* pays2)
{
	int result = 1;

	if(c1 == NULL || c2 == NULL)
	{
		return -1;
	}
	
	size_t index1 = json_array_size(c1); 
	json_t *val1;
	json_array_foreach(c1, index1, val1) 
	{
		size_t index2 = json_array_size(c2);
		json_t *val2;
		json_array_foreach(c2, index2, val2) 
		{	
			int cmp_pays1_c2 = strcmp(pays1, json_string_value(val2));
			int cmp_pays2_c1 = strcmp(pays2, json_string_value(val1));
			if((cmp_pays1_c2 == 0 && cmp_pays2_c1 == 0) && result == 1) 
			{
				result = 0;
			}
		}
	}
	return result;
}

int sameBorder3(json_t *c1, json_t *c2, json_t *c3, char* pays1, char* pays2, char* pays3)
{
	int result = 1;
	if(c1 == NULL || c2 == NULL || c3 == NULL)
	{
		return -1;
	}
	
	if((sameBorder2(c1, c2, pays1, pays2) == 0) && (sameBorder2(c1, c3, pays1, pays3) == 0) &&
		(sameBorder2(c2, c3, pays2, pays3) == 0))
	{
		if(result == 1)
		{
			result = 0;
		}
	}
	return result;
}