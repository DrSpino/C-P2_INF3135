#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>

#include "readJson.c"

int main(int argc, char *argv[])
{

	json_t *root;
	char *text_root = "data/countries.json";

	root = openJsonFile(text_root);

	json_t *data;
	data = getData(root,0);

	const char *cca3_string = getCca3(data);

	printf("%s\n", cca3_string);

	json_decref(root);

	return 0;
}