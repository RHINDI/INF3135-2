#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "fileManager.h"


FILE *readFile(char *argv)
{
  FILE *file;
  file = fopen(argv, "r");
  if (!file)
  {
    printf("\n------------------------------------------------------------------\n"
             "Erreur fichier source %d : \n"
             "\n------------------------------------------------------------------\n", errno);
    exit(1);
  }
  return file;
}

FILE *writFile(char  *argv)
{
  FILE *file;
  file = fopen(argv, "w");
  if (!file)
  {
    printf("\n------------------------------------------------------------------\n"
             "Erreur fichier sortie %d : \n"
             "\n------------------------------------------------------------------\n", errno);
    exit(1);
  }
  return file;
}
