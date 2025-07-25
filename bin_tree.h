#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Nameval{
  char* name;
  int value;
  struct Nameval* left;
  struct Nameval* right;
}Nameval;

typedef struct Node {
  struct Node* left;
  struct Node* right;
  int value;
}Node;

Node* makeNodeVal(int value);
Node* insertNodeVal(Node* treep, int value);
void applyPreorderVal(Node* treep);

Nameval* makeNode(char* name, int value);
Nameval* insertNode(Nameval* treep, Nameval* newp);
Nameval* nrinsertNode(Nameval* treep, Nameval* newp);
Nameval* lookup(Nameval* treep, char* name);
Nameval* nrlookup(Nameval* treep, char* name);

void applyInorder(Nameval* treep);
void applyPostorder(Nameval* treep);
int treeHeight(Nameval* treep);
int totalStorage(Nameval* treep);
void destroyTree(Nameval* tree);
void destroyTreeVal(Node* treep);

void printRangeRecursiveSplit(int start, int stop);

#endif