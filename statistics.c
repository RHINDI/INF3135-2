#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "statistics.h"
#include "fileManager.h"



char findLetter(char *array);

void stat_printStatToFile(Node_t *listNodes, FILE *ptrFile, char *argv)
{

  FILE *outPutFile;
  char charMax ;
  int totChars , totWords, nbrLineInFile, nbrWordsInFile;

  nbrLineInFile = stat_nbrOfLines(ptrFile);
  nbrWordsInFile = stat_nbrWords(ptrFile);
  totWords = list_getLength(listNodes);
  totChars = stat_getTotChars(listNodes);
  charMax = stat_letterMostUsed(listNodes, totChars);
  outPutFile = writFile(argv);


  fprintf(outPutFile, "le nombre de lignes dans le fichier d'entrée : %d\n", nbrLineInFile);
  fprintf(outPutFile, "le nombre de mots sans doublons : %d\n", totWords);
  fprintf(outPutFile, "le nombre de mots avec doublons : %d\n", nbrWordsInFile);
  fprintf(outPutFile, "le nombre de lettres dans la liste de mots (sans doublons) : %d\n",totChars );
  fprintf(outPutFile, "la lettre la plus fréquente : %c\n", charMax);


  fclose(outPutFile);

}



char stat_letterMostUsed(Node_t *listNodes, int totChars)
{
  char *array;
  array = (char *) calloc(totChars, sizeof(char));
  assert(array != NULL);

  Node_t head;
  head = *listNodes;

  while (head != NULL)
  {
    strcat(array, head->word);
    head = head->nextNode;
  }
  return findLetter(array);
}

char findLetter(char *arrayIn)
{
  int array[255] = {0};
  int i, max ;
  char carac;

  for(i = 0; arrayIn[i] != 0; i++)
  {
    ++array[(int)arrayIn[i]];
  }

  max = array[0];
  for(i = 0; arrayIn[i] != 0; i++)
  {
    if( array[(int)arrayIn[i]] > max)
    {
      max = array[(int)arrayIn[i]];
      carac = arrayIn[i];
    }
  }
  free(arrayIn);
  return carac;
}


int stat_nbrOfLines(FILE *ptrFile)
{
  int ch, number_of_lines = 0;
  do
  {
    ch = fgetc(ptrFile);
    if(ch == '\n')
      ++number_of_lines;
  } while (ch != EOF);

  fseek(ptrFile, 0, SEEK_SET);

  return number_of_lines;
}


int stat_getTotChars(Node_t *listNodes)
{
  Node_t  head;
  head = *listNodes;
  int totChars = 0;
  while (head != NULL)
  {
    totChars += strlen(head->word);
    head = head->nextNode;
  }
  return totChars;
}


int stat_nbrWords(FILE *ptrFile)
{
  char word[81];
  int nbrWords = 0;

  while(fscanf(ptrFile, " %s", word) > 0 )
  {
    ++nbrWords;
  }

  fseek(ptrFile, 0, SEEK_SET);
  return nbrWords;
}






























