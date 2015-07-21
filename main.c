#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "fileManager.h"
#include "statistics.h"

/**
 * documentation function
 *
 * param : .
 * Valeur de retour :  .*/
void validateArgs(int argc, char **argv);

/**
 * documentation function
 *
 * param : .
 * Valeur de retour :  .*/
Node_t fillTheList(FILE *ptrFile, int nbrWordsInFile);

int main(int argc, char** argv)
{
  FILE *file;
  int  nbrWordsInFile;
  Node_t listNodes = NULL;

  validateArgs(argc, argv);

  file = readFile(argv[1]);

  nbrWordsInFile = stat_nbrWords(file);

  listNodes = fillTheList(file, nbrWordsInFile);

  list_printNode(listNodes);

  if(argv[2])
  {
    stat_printStatToFile(listNodes, file, argv[3]);
  }

  list_distroyNodes(listNodes);
  fclose(file);

  return  0;
}

Node_t fillTheList(FILE *ptrFile, int nbrWordsInFile)
{
  int i, wordLength;
  char string[80];
  Node_t  newNode, listNodes;
  listNodes = NULL;

  for (i = 0; i < nbrWordsInFile; ++i)
  {
    fscanf(ptrFile, " %s", string);
    wordLength = (int) strlen(string) + 1;
    string[wordLength] = '\0';

    if (listNodes == NULL)
    {
      listNodes = list_createNode(string);
    }else if (!list_existNode(listNodes, string)){
      newNode = list_createNode(string);
      listNodes = list_addNode(listNodes, newNode);
    }
  }
  fseek(ptrFile, 0, SEEK_SET);
  return listNodes;
}

void validateArgs(int argc, char **argv)
{
  if (argc == 3 || argc < 2 || argc > 4)
  {
    printf("\n------------------------------------------------------------------\n"
             "Erreur: \n"
             "L'Utilisation du programme main.c :\n\n"
             "./Tri <fichier source> -S <fichier de sortie>\n"
             "\n------------------------------------------------------------------\n");
    exit(1);
  }

  if(argc == 4)
  {
    if(strcmp(argv[2] ,"-S") != 0 )
    {
      printf("\n------------------------------------------------------------------\n"
               "Erreur: \n"
               "pour accumuler les statistiques sur les données du fichier utiliser  \n"
               "invoqué le logiciel avec l'option < -S >\n\n"
               "./Tri <fichier source>.txt -S <fichier de sortie>.txt\n"
               "\n------------------------------------------------------------------\n");
      exit(1);
    }
  }
}




