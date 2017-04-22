#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>
#include <string.h>
#include <ctype.h>

#include "readJson.h"
#include "display.h"
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
			char countryCode[4];
			strcpy(countryCode,argv[2]);
			index = countryCommand(root,countryCode);
			display(root, index, argv, argc);
		}
		else if(strcmp(argv[1], "--region") == 0)
		{
			char countryCode[4];
			strcpy(countryCode,argv[2]);
			int result = regionCommand(root,countryCode, argv, argc, 0);
			if(result == -2){
				fprintf(stderr,"error: the region must be between [africa,americas,asia,europe,oceania]\n");
			}
		}
	}

	json_decref(root);

	return 0;
}