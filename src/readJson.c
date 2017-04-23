/**
 * readJson.h est un fichier qui contient :
 * -toutes les fonctions qui permettent d'ouvrir le fichier Json
 * -les fonctions qui permettent d'extraire les valeurs du fichier Json
 **/

#include "readJson.h"

json_t *openJsonFile(char *text_root)
{
	json_error_t error;
	json_t *root = json_load_file(text_root, 0, &error);

	if(!root)
	{
		fprintf(stderr,"error: wrong path\n");
		return NULL;
	}

	if(!json_is_array(root))
	{
		fprintf(stderr,"error: root is not an array\n");
		json_decref(root);
		return NULL;
	}

	return root;
}

json_t *getData(json_t *root, int index)
{
	json_t *data = json_array_get(root, index);

	if(!json_is_object(data))
	{
		json_decref(root);
		return NULL;
	}

	return data;
}

/*Get des string du fichier JSON*/
const char *getName(json_t *data)
{
	json_t *name = json_object_get(data, "name");
	json_t *common_name = json_object_get(name, "common");

	if(!json_is_string(common_name))
	{
		return NULL;
	}

	return json_string_value(common_name);
}

const char *getCca3(json_t *data)
{
	json_t *cca3 = json_object_get(data, "cca3");

	if(!json_is_string(cca3))
	{
		return NULL;
	}

	return json_string_value(cca3);
}

const char *getCapital(json_t *data)
{
	json_t *capital = json_object_get(data, "capital");

	if(!json_is_string(capital))
	{
		return NULL;
	}

	return json_string_value(capital);
}

const char *getRegion(json_t *data)
{
	json_t *region = json_object_get(data, "region");

	if(!json_is_string(region))
	{
		return NULL;
	}

	return json_string_value(region);
}

json_t *getLanguages(json_t *data)
{
	json_t *languages = json_object_get(data, "languages");

	if(!json_is_object(languages))
	{
		return NULL;
	}

	return languages;
}

json_t *getBorders(json_t *data)
{
	json_t *borders = json_object_get(data, "borders");
	
	if(!json_is_array(borders))
	{
		return NULL;
	}

	return borders;
}