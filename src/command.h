/**
 * command.h est un fichier qui contient les fonctions de commandes.
 **/

int countryCommand(json_t *root, char *in);

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