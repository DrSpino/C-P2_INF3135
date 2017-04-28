//#include <stdlib.h>
//#include <stdio.h>
//#include <jansson.h>
//#include <string.h>
//#include <ctype.h>

#include "readJson.h"
#include "display.h"
#include "command.h"

int main(int argc, char* argv[])
{	
	if(argc < 2 || argc > 6)
	{
		fprintf(stderr,"error : the number of arguments must be between 1 and 5 \n");
		return -1;
	}
	
	json_t *root;
	char *text_root = "../data/countries.json";
	
	root = openJsonFile(text_root, 1);

	if(root != NULL)
	{
		if(strcmp(argv[1], "--country") == 0)
		{
			int result = countryCommand(root,argv[2], 1);
			display(root, result, argv, argc, 1);
		}
		else if(strcmp(argv[1], "--region") == 0)
		{
			int result = regionCommand(root, argv, argc, 1);
			if(result == -2)
			{
				fprintf(stderr,"error : the region must be between [africa,americas,asia,europe,oceania]\n");
			}
		}
		else if(strcmp(argv[1], "--same-language") == 0)
		{
			int result = sameLanguageCommand(root, argv, argc);
			if(result == 1)
			{
				printf("no\n");
			}
		}
		else if(strcmp(argv[1], "--same-borders") == 0)
		{
			int result = sameBordersCommand(root, argv, argc);
			if(result == 1)
			{
				printf("no\n");
			}
			else if(result == 0)
			{
				printf("yes\n");
			}
		}
		else
		{
			fprintf(stderr,"error : command invalid \n");
		}
	}
	
	json_decref(root);
	return 0;
}