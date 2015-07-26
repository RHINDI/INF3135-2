
#ifndef STATISTICS_H
#define STATISTICS_H

#include "linkedList.h"
/**
 * écrire les statistiques accumuler sur le fichier d'entre
 * et les résulta  du triée  dans un fichier
 *
 * ptrFile : pointeur vers le debut de fichier.
 * listNodes : Une référence vers la liste des noeuds.
 * Valeur de retour : non applicable  .*/
void stat_printStatToFile(Node_t *listNodes, FILE *ptrFile, char *argv);

/**
 * Calcule le nombre des mots dans un fichier
 *
 * param : pointeur vers le debut de fichier .
 * Valeur de retour : le nombre des mots dans le fichier .*/
int stat_nbrWords(FILE *ptrFile);

/**
 * Calcule le nombre des ligne dans un fichier
 *
 * ptrFile : pointeur vers le debut de fichier.
 * Valeur de retour :  le nombre des lignes dans le fichier.*/
int stat_nbrOfLines(FILE *ptrFile);

/**
 * Calcule le nombre des caractère dans une liste
 *
 * listNodes : Une référence vers la liste des noeuds.
 * Valeur de retour :  le nombre total des caractère dans la liste .*/
int stat_getTotChars(Node_t *listNodes);

/**
 * Recherche  dans la liste la lettre la plus fréquente
 *
 * listNodes : Une référence vers la liste des noeuds.
 * totChar : le nombre total des caractère.
 * Valeur de retour :  la lettre la plus fréquente dans la liste .*/
char stat_letterMostUsed(Node_t *listNodes, int totChar);

#endif //STATISTICS_H
