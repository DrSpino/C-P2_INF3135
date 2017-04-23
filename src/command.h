/**
 * command.h est un fichier qui contient les fonctions de commandes.
 **/
#ifndef COMMAND_H
#define COMMAND_H

#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>
#include <string.h>
#include <ctype.h>

#include "readJson.h"
#include "display.h"

int countryCommand(json_t *root, char *in);
int regionCommand(json_t *root,  char* argv[], int argc, int affichage);
int sameLanguageCommand(json_t *root, char* argv[], int argc);
int sameLanguage2(json_t *c1, json_t *c2);
int sameLanguage3(json_t *c1, json_t *c2, json_t *c3);

#endif