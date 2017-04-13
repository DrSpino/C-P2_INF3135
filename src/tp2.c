#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>

#include "readJson.h"

int main(int argc, char *argv[])
{
	/* utilisé juste pour enlever les warning
	 * du argc et argv non utilisé.
	 */
	if(argc < 1)
	{
		printf("error1");
		exit(1);
	}
	char* arg1 = argv[1];
	printf("%s\n",arg1);
	/***** ******   *******  ****/

	json_t *root;
	char *text_root = "../data/countries.json";

	root = openJsonFile(text_root);

	json_t *data;
	data = getData(root,0);

	const char *cca3_string = getCca3(data);

	printf("%s\n", cca3_string);

	json_decref(root);

	return 0;
}