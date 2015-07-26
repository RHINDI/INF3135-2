
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

/**
 * Ouvrire un fichier pour la lecture
 *
 * param : pointeur vers chaîne de caractère du nom du fichier a lire.
 * Valeur de retour : pointeur vers le debut de fichier  .*/
FILE *readFile(char  *argv);

/**
 * Ouvrire un fichier pour l'écriture
 *
 * param : pointeur vers la chaîne de caractère  du nom du fichier a écrire.
 * Valeur de retour : pointeur vers le debut de fichier  .*/
FILE *writFile(char  *argv);

#endif //FILEMANAGER_H

