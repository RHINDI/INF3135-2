#include <stdio.h>
#include <stdlib.h>


void validerUsage(int argc);


void loadWords(FILE *ptrFile);

/** @Fichier        Tri.c
 *  @Description     Résolution de mots caches
 *
 *  Ce fichier contient la fonction main() du programme motcache.
 *
 *
 *  @Cours          : INF3135
 *  @Group          : 50
 *  @prof           : Jacques Berger
 *  @auteur         : Rhindi Youssef
 *  @code Permanent : RHIY20087605
 */

int main(int argc, char **argv)
{
  FILE *file;
  int oneChar;
  int i  = 0;
  int j  = 0;
  char words[80][20];

  validerUsage(argc);

  file = fopen(argv[1], "r");
  loadWords(file);


  if (fclose(file) == EOF)
  {
    printf("Erreur lors de la fermeture du fichier.\n");
    return 1;
  }
  return 0;
}


/** @Description  validation des arguments
 *
 *  validerUsage()
 *  valide que le programme a bien reçu en paramètre une fichier.txt
 *
 *
 *  @param argc     => paramètre qu'a reçu le programme
 *  @retour rien
 */


void validerUsage(int argc)
{
  if (argc != 2)
  {
    printf("Utilisation du programme main.c :\nmain.c <fichier source>\n");
    exit(1);
  }
}


void loadWords(FILE *ptrFile)
{
  int oneChar;
  int i = 0 ;
  int j = 0;
  char words [80][20];

  while (1)
  {
    oneChar = fgetc(ptrFile);
    if (feof(ptrFile))
    {
      words[j][i] = '\n';
      break;
    }
    if (oneChar != ' ' && oneChar != '\n')
    {
      words[j][i] = oneChar;
      ++i;
    } else
    {
      words[j][i] = '\0';
      words[j][i] = '\n';
      ++j;
      i = 0;
    }
  }
int k, l;
  for ( k = 0; words[k][0] != '\n'; ++k)
  {
    printf("%s",words[k]);

  }


  }




