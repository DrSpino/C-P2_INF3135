#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>

json_t * openJsonFile(char *text_root);
json_t * getData(json_t *root, int index);
const char * getCca3(json_t *data);

json_t * openJsonFile(char *text_root)
{
	
	json_error_t error;
	json_t *root = json_load_file(text_root, 0, &error);

	if(!root)
	{
		fprintf(stderr,"error: wrong path\n");
		exit(1);
	}

	if(!json_is_array(root))
	{
		fprintf(stderr,"error: root is not an array\n");
		json_decref(root);
		exit(1);
	}

	return root;
}

json_t * getData(json_t *root, int index)
{
	json_t *data = json_array_get(root, index);

	if(!json_is_object(data))
	{
		fprintf(stderr,"error: data is not an object\n");
		json_decref(root);
		exit(1);
	}

	return data;
}

const char * getCca3(json_t *data)
{
	json_t *cca3;

	cca3 = json_object_get(data, "cca3");

	if(!json_is_string(cca3))
	{
		fprintf(stderr,"error: commit: cca3 is not a string\n");
		exit(1);
	}

	const char *cca3_string;

	cca3_string = (char *) malloc(15);

	cca3_string = json_string_value(cca3);

	return cca3_string;
}