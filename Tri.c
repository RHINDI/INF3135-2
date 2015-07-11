#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void validerUsage(int argc);

int nbrWords(FILE *ptrFile);

int nbrOfLines(FILE *pFILE);

void buildArray(char **pString, FILE *pFILE, int nbrWordsInfile);

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
  int nbrLineInFile, nbrWordsInFile;
  char **array;
  int i;

  //---------------------------------ARGUMENTS--------------------------------
  validerUsage(argc);

  //----OPEN THE FILE
  //----GET THE NUMBER OF LINES IN THE INPUT FILE
  //----GET THE NUMBER OF WORDS IN THE INPUT FILE
  file = fopen(argv[1], "r");
  nbrLineInFile = nbrOfLines(file);
  printf("le nombre de lignes dans le fichier d'entrée : %d\n", nbrLineInFile);
  fseek(file, 0, SEEK_SET);
  nbrWordsInFile = nbrWords(file);
  printf("le nombre de mots avec doublons : %d\n", nbrWordsInFile);

  //----CREATE THE ARRAY AND ALLOCATE THE MEMORY BASED OF THE NUMBER OF WORDS
  array = (char **)calloc((nbrWordsInFile - 1) , sizeof(char *));
  if( !array )
  {
    printf("Erreur d'allocation de mémoire : %s\n", strerror(errno));
    exit(1);
  }


  //----BUILD THE ROWS IN THE ARRAY AND FILL IT WETHEN THE WORDS
  //----PRINT THE WORDS TO THE CONSOLE FOR THE TEST => TO BE DELETED
  fseek(file, 0, SEEK_SET);
  buildArray(array, file, nbrWordsInFile);
  for (i = 0; i < nbrWordsInFile; ++i)
    printf("%s\n", array[i]);

  //----SORT THE WORDS IN THE ARRAY
  int j;
  char temp[50];

  for(i=0;i<nbrWordsInFile;++i)
  {
    for (j = i + 1; j < nbrWordsInFile ; ++j)
    {
      if (strcmp(array[i], array[j]) > 0)
      {
        strcpy(temp, array[i]);
        strcpy(&(array[i][0]), array[j]);
        strcpy(&(array[j][0]), temp);
//        strcpy(&(pString[i][0]), word);

      }
    }
    printf("%d =>%s\n",i , array[i]);
  }
  printf("In lexicographical order: \n");
  for (i = 0; i < nbrWordsInFile; ++i)
    printf("%s\n", array[i]);


  //----FREE THE MEMORY ALOCATED
  for(i = 0; i < nbrWordsInFile; i++)
  {
    free(array[i]);
  }
  free(array);

  // Close the file
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


int nbrOfLines(FILE *pFILE)
{
  int ch, number_of_lines = 0;
  do
  {
    ch = fgetc(pFILE);
    if(ch == '\n')
      number_of_lines++;
  } while (ch != EOF);

// last line doesn't end with a new line!
// but there has to be a line at least before the last line
  if(ch != '\n' && number_of_lines != 0)
    number_of_lines++;

  return number_of_lines;
}


int nbrWords(FILE *ptrFile)
{
  char word[80];
  int nbrWords = 0;

  // read a word (stops at next white space)
  while(fscanf(ptrFile, " %s", word) == 1 )
  {
    ++nbrWords;
  }

  return nbrWords;
  }

void buildArray(char **pString, FILE *pFILE, int nbrWordsInfile)
{
  int i,  wordLength;
  char word[30];

  for ( i = 0; i < nbrWordsInfile; i++ )
  {
    fscanf(pFILE, " %s", word);
    wordLength =  (int) strlen(word) +1;
    word[wordLength] = '\0';
    pString[i] = (char *) calloc(wordLength ,sizeof(char));

    if(!pString[i])
    {
      printf("Erreur d'allocation de mémoire : %s\n", strerror(errno));
      exit(1);
    }

    strcpy(&(pString[i][0]), word);
  }
}


