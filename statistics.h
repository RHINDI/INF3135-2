
#ifndef STATISTICS_H
#define STATISTICS_H

#include "linkedList.h"
/**
 * documentation function
 *
 * param : .
 * Valeur de retour :  .*/
void stat_printStatToFile(Node_t listNodes, FILE *ptrFile, char *argv);

/**
 * documentation function
 *
 * param : .
 * Valeur de retour :  .*/
int stat_nbrWords(FILE *ptrFile);

/**
 * documentation function
 *
 * param : .
 * Valeur de retour :  .*/
int stat_nbrOfLines(FILE *ptrFile);

/**
 * documentation function
 *
 * param : .
 * Valeur de retour :  .*/
int stat_getTotChars(Node_t listNodes);

/**
 * documentation function
 *
 * param : .
 * Valeur de retour :  .*/
char stat_letterMostUsed(Node_t listNodes, int totChar);

#endif //STATISTICS_H
