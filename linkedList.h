
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node
{
  char *word;
  struct Node *nextNode;
} ;

typedef struct Node* Node_t;

/* Créer un nouveau noeud.
 * Valeur de retour : Une référence vers le nouveau noeud créé.
 * le noeud devra être libérée avec la fonction node_distroy.
 *
 * word : L'élément à ajouter dans le noeud. */
Node_t list_createNode(char *word);

/**
 * Ajoute un noeud dans la liste chaînée selon son ordre alphabétique.
 * le noeud ne doit pas être ajouté si  :
 *   - Il existe déjà dans la liste
 * listNodes : Une référence vers la liste des noeuds
 * node : Une référence vers le noeud à ajouter.
 * Valeur de retour : Une référence vers la nouvelle liste .*/
Node_t list_addNode(Node_t listNodes, Node_t newNode);

/*Vérifie l'existence de la chaîne de caractères dans un noeud de la liste .
 * nodeList : Une référence vers la liste.
 * word : la chaîne de caractères a chercher
 * Valeur de retour : 1 si exist   0 si n'exist pas . */
int list_existNode(Node_t listNodes, char *word);


/* Libère  la mémoire des éléments contenus dans le noeud .
 * Détruire le noeud.
 * node : Une référence vers le noeud. */
void list_distroyNodes(Node_t node);


/* Afficher le contenu  des noeuds a la consol.
 * node : Une référence vers la tete de la liste. */
void list_printNode(Node_t node);

/* Obtenir le nombre des noeuds présentement dans la liste chaînée .
 * node : Une référence vers la tete de la liste.
 * Valeur de retour : Le nombre des noeuds dans la liste. */
int list_getLength(Node_t listNodes);

#endif //LINKED_LIST_H
