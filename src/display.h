/**
 * display.h est un fichier qui contient les fonctions d'affichage'.
 **/
#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>
#include <string.h>
#include <ctype.h>

#include "readJson.h"
#include "command.h"

void display(json_t *root, int index, char* argv[], int argc);
void displayName(json_t *data);
void displayCode(json_t *data);
void displayCapital(json_t *data);
void displayLanguages(json_t *data);
void displayBorders(json_t *data);

#endif

