/**
 * @Fichier        main.c fileManager.c linkedList.c statistics.c
 *
 *  @Description     Trier une liste de mots provenant d'un fichier.
 *
 *  Ce fichier contient la fonction main() du programme Trier.
 *
 *
 *  @Cours          : INF3135
 *  @Group          : 50
 *  @prof           : Jacques Berger
 *  @auteur         : Rhindi Youssef
 *  @code Permanent : RHIY20087605
 */




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "fileManager.h"
#include "statistics.h"

/**
 * Valider les arguments passer en paramètre durant l'exécution du programme
 *
 * argc : le nombre des paramétré passer ou logiciel pendant l’exécution
 * argv : Une référence vers le tableau contenant les noms des arguments
 * Valeur de retour : non applicable  .*/
void validateArgs(int argc, char **argv);

/**
 * crée la liste chaîne avec les mots (sans doublon et triée )
 * lits dans le fichier retourne un pointeur vers la liste
 *
 * ptrFile : pointeur vers le debut de fichier.
 * Valeur de retour : non applicable  .*/
void fillTheList(FILE *ptrFile, Node_t *listNodes);

int main(int argc, char** argv)
{
  FILE *file;
  Node_t listNodes = NULL;

  validateArgs(argc, argv);
  file = readFile(argv[1]);
  fillTheList(file, &listNodes);
  list_printNode(&listNodes);

  if(argv[2])
  {
    stat_printStatToFile(&listNodes, file, argv[3]);
  }

  list_distroyNodes(&listNodes);
  fclose(file);

  return  0;
}

void fillTheList(FILE *ptrFile, Node_t *listNodes)
{
  char word[81];
  Node_t  newNode;

    while(fscanf(ptrFile, " %s", word) != EOF)
    {
      if (*listNodes == NULL)
      {
        *listNodes = list_createNode(word);
      }else if (!list_existNode(listNodes, word)){
        newNode = list_createNode(word);
        list_addNode(listNodes, newNode);
      }
    }
  fseek(ptrFile, 0, SEEK_SET);
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




