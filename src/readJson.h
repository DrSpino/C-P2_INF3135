/* readJson.h est un fichier qui contient :
 * -toutes les fonctions qui permettent d'ouvrir le fichier Json
 * -les fonctions qui permettent d'extraire les valeurs du fichier Json
 **/
#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>

json_t * openJsonFile(char *text_root);
json_t * getData(json_t *root, int index);
const char *getCca3(json_t *data);
const char *getCapital(json_t *data);
json_t *getLanguages(json_t *data);
json_t *getBorders(json_t *data);

json_t *openJsonFile(char *text_root)
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

json_t *getData(json_t *root, int index)
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

/*Get des string du fichier JSON*/
const char *getCca3(json_t *data)
{
	json_t *cca3 = json_object_get(data, "cca3");

	if(!json_is_string(cca3))
	{
		fprintf(stderr,"error: cca3 is not a string\n");
		return NULL;
	}

	return json_string_value(cca3);
}

const char *getCapital(json_t *data)
{
	json_t *capital = json_object_get(data, "capital");

	if(!json_is_string(capital))
	{
		fprintf(stderr,"error: capital is not a string\n");
		return NULL;
	}

	return json_string_value(capital);
}

json_t *getLanguages(json_t *data)
{
	json_t *languages = json_object_get(data, "languages");

	if(!json_is_object(languages))
	{
		fprintf(stderr,"error: languages is not an object\n");
		return NULL;
	}

	return languages;
}