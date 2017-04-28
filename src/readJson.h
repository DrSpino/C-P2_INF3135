/**
 * readJson.h est un fichier qui contient :
 * -toutes les fonctions qui permettent d'ouvrir le fichier Json
 * -les fonctions qui permettent d'extraire les valeurs du fichier Json
 **/

#ifndef READJSON_H
#define READJSON_H

#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>
#include <string.h>
#include <ctype.h>

//#include "display.h"
//#include "command.h"

json_t * openJsonFile(char *text_root, int affichage);
json_t * getData(json_t *root, int index);
const char *getName(json_t *data);
const char *getCca3(json_t *data);
const char *getCapital(json_t *data);
const char *getRegion(json_t *data);
json_t *getLanguages(json_t *data);
json_t *getBorders(json_t *data);

#endif