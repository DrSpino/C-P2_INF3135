/**
 * command.h est un fichier qui contient les entetes des fonctions de commandes.
 **/
#ifndef COMMAND_H
#define COMMAND_H


#include <stdio.h>
#include <jansson.h>
#include <string.h>
#include <ctype.h>

#include "readJson.h"
#include "display.h"

//Fonction appelée lorsque --country est utilisé lors de l'exécution.
int countryCommand(json_t *root, char *in, int display_test);

//Fonction appelée par le main lorsque --region est utilisé lors de l'exécution.
int regionCommand(json_t *root,  char* argv[], int argc, int display_test);

//Fonction appelée par le main lorsque --same-language est utilisé lors de l'exécution.
int sameLanguageCommand(json_t *root, char* argv[], int argc);

//Fonction appelée par sameLanguageCommand lorsque --same-language est utilisé avec 2 arguments.
int sameLanguage2(json_t *c1, json_t *c2);

//Fonction appelée par sameLanguageCommand lorsque --same-language est utilisé avec 3 arguments.
int sameLanguage3(json_t *c1, json_t *c2, json_t *c3);

//Fonction appelée par le main lorsque --same-borders est utilisé lors de l'exécution.
int sameBordersCommand(json_t *root, char* argv[],int argc);

//Fonction appelée par sameBordersCommand lorsque --same-borders est utilisé avec 2 arguments.
int sameBorder2(json_t *c1, json_t *c2, char* pays1, char* pays2);

//Fonction appelée par sameBordersCommand lorsque --same-borders est utilisé avec 3 arguments.
int sameBorder3(json_t *c1, json_t *c2, json_t *c3, char* pays1, char* pays2, char* pays3);

#endif