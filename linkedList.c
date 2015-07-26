#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "linkedList.h"



Node_t list_createNode(char *word)
{
  Node_t node;
  node =  malloc(sizeof(struct Node));
  assert(node != NULL);

  node->word = (char*) calloc(strlen(word), sizeof(char));
  assert(node->word != NULL);

  strcpy(node->word , word);
  node->nextNode = NULL;

  return node;
}

void list_addNode(Node_t *listNodes, Node_t newNode)
{
    Node_t  previous = NULL;
    Node_t current = *listNodes;

    while (current != NULL && strcmp(newNode->word, current->word) > 0)
    {
      previous = current;
      current = current->nextNode;
    }

    if (current == NULL)
    {
        previous->nextNode = newNode;

    } else if (previous == NULL) {
      newNode->nextNode = *listNodes;
      *listNodes = newNode;

    } else {
      newNode->nextNode = current;
      previous->nextNode = newNode;
    }
}

int list_existNode(Node_t *listNodes, char *word)
  {
    Node_t head;
    head = *listNodes;
    while (head != NULL)
    {
      if (strcmp(word,head->word) == 0)
      {
        return 1;
      }
      head = head->nextNode;
    }

    return 0;
  }


void list_printNode(Node_t *listNodes)
{
  Node_t  head;
  head = *listNodes;
  while (head != NULL)
  {
    printf("%s\n", head->word);
    head = head->nextNode;
  }
}

int list_getLength(Node_t *listNodes)
{
  Node_t  head;
  head = *listNodes;
  int length = 0;
  while (head != NULL)
  {
    ++length;
    head = head->nextNode;
  }
  return length;
}

void list_distroyNodes(Node_t *listNodes)
{
  Node_t  head, courant;
  head = *listNodes;
  courant = head->nextNode;
  while (courant != NULL)
  {
    free( head->word);
    free(head);
    courant = courant->nextNode;
    head = courant;
  }

}

