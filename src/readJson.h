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

#include "display.h"
#include "command.h"

//Fonction appelée pour ouvrir un fichier Json.
json_t * openJsonFile(char *text_root, int affichage);

//Fonction appelée pour obtenir un objet contenant les attributs du country a l'index.
json_t * getData(json_t *root, int index);

//Fonction appelée pour obtenir le nom d'un country.
const char *getName(json_t *data);

//Fonction appelée pour obtenir le cca3 d'un country.
const char *getCca3(json_t *data);

//Fonction appelée pour obtenir la capitale d'un country.
const char *getCapital(json_t *data);

//Fonction appelée pour obtenir la region d'un country.
const char *getRegion(json_t *data);

//Fonction appelée pour obtenir les languages d'un country.
json_t *getLanguages(json_t *data);

//Fonction appelée pour obtenir les frontieres d'un country.
json_t *getBorders(json_t *data);

#endif