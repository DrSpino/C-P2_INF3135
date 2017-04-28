/**
 * display.h est un fichier qui contient les fonctions d'affichage'.
 **/
#ifndef DISPLAY_H
#define DISPLAY_H

//#include <stdlib.h>
//#include <stdio.h>
//#include <jansson.h>
//#include <string.h>
//#include <ctype.h>

#include "readJson.h"
//#include "command.h"

int display(json_t *root, int index, char* argv[], int argc, int affichage);
int displayName(json_t *data, int affichage);
int displayCode(json_t *data, int affichage);
int displayCapital(json_t *data, int affichage);
int displayLanguages(json_t *data, int affichage);
int displayBorders(json_t *data, int affichage);

#endif

