/**
 * command.h est un fichier qui contient les fonctions de commandes.
 **/
//#define DISPLAY_INCLUDED



int countryCommand(json_t *root, char *in);
void regionCommand(json_t *root, char* in,  char* argv[], int argc);

const char *regionArray[] = {"Africa","Americas","Asia","Europe","Oceania"};

int countryCommand(json_t *root, char *in)
{
	if(in == NULL)
	{
		fprintf(stderr, "argv[2] null");
		return -1;
	}

	char *s = in;
  	while (*s) {
    	*s = toupper((unsigned char) *s);
    	s++;
  	}
  	
	int i;
	for(i = 0; i < (int)json_array_size(root); i++)
	{
		json_t *data;
		data = getData(root,i);
		const char *cca3 = getCca3(data);

		if (cca3 != NULL && strcmp(in, cca3) == 0)
		{
			return i;
		}
	}

	fprintf(stderr, "Country not found\n");
	return -2;
}

void regionCommand(json_t *root, char* in,  char* argv[], int argc){

			if(in == NULL)
			{
			fprintf(stderr,"error: argv[2] null \n");
			exit(1);	
			}
			
			/* oceania --> Oceania */
			char *region = in;
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
							if(strcmp(region,regionObtained) == 0)
							{
								display(root, i, argv, argc);
								printf("\n");
							}
					}
				}
			}
			/* validate the region inside the regionArray */
			if(regionObtainedValid)
			{
			fprintf(stderr,"error: the region must be between [africa,americas,asia,europe,oceania]\n");
			exit(2);	
			}
			
}