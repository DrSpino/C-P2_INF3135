/**
 * display.h est un fichier qui contient les entetes des fonctions d'affichage'.
 **/
#ifndef DISPLAY_H
#define DISPLAY_H


#include <stdio.h>
#include <jansson.h>
#include <string.h>

#include "readJson.h"
#include "command.h"

//Fonction appelée pour afficher les attributs choisie du country a l'index.
int display(json_t *root, int index, char* argv[], int argc, int display_test);

//Fonction appelée pour afficher le nom d'un country.
int displayName(json_t *data, int display_test);

//Fonction appelée pour afficher le Code(cca3) d'un country.
int displayCode(json_t *data, int display_test);

//Fonction appelée pour afficher la capitale d'un country.
int displayCapital(json_t *data, int display_test);

//Fonction appelée pour afficher les languages d'un country.
int displayLanguages(json_t *data, int display_test);

//Fonction appelée pour afficher les frontieres d'un country.
int displayBorders(json_t *data, int display_test);

#endif

