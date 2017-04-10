#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	json_t *root;
	json_error_t error;

	root = json_load_file("../data/countries.json", 0, &error);

	if(!root)
	{
    	printf("error: fichier json introuvable\n");
		return 1;
	}

	if(!json_is_array(root))
	{
    	printf("error: root is not an array\n");
    	json_decref(root);
    	return 1;
	}

	json_t *data, *cca3;

	data = json_array_get(root, 0);

	if(!json_is_object(data))
	{
        printf("error: commit data is not an object\n");
        json_decref(root);
        return 1;
    }

	cca3 = json_object_get(data, "cca3");

	if(!json_is_string(cca3))
    {
        printf("error: commit: cca3 is not a string\n");
        json_decref(root);
        return 1;
    }

	const char *cca3_string;

	cca3_string = (char *) malloc(15);

	cca3_string = json_string_value(cca3);

	printf("%s\n", cca3_string);

	json_decref(root);

	return 0;
}