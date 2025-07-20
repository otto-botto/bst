#include "bin_tree.h"


Nameval* makeNode(char* name, int value) {
  Nameval* node = (Nameval*)malloc(sizeof(Nameval));

  node->name = name;
  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void destroyTree(Nameval* tree) {
  if (tree == NULL) {
    return;
  }
  destroyTree(tree->left);
  destroyTree(tree->right);
  free(tree);
}

Nameval* insertNode(Nameval* treep, Nameval* newp){
  if(treep == NULL){
    return newp;
  }
  int cmp = strcmp(newp->name, treep->name);
  if(cmp == 0){
    fprintf(stderr, "insert duplicate entry %s is ignored", newp->name);
  } else if(cmp < 0){
    treep->left = insertNode(treep->left, newp);
  }else{
    treep->right = insertNode(treep->right, newp);
  }
  return treep;
}

Nameval* nrinsertNode(Nameval* treep, Nameval* newp) {
  if (treep == NULL) {
    treep = newp;
  }else {
    Nameval* tmp = treep;
    int cmp;
    while (tmp) {
      cmp = strcmp(newp->name, tmp->name);
      if (cmp == 0) {
        fprintf(stderr, "Duplicate");
      }else if (cmp < 0) {
        if (tmp->left != NULL) {
          tmp = tmp->left;
        }else {
          tmp->left = newp;
          return treep;
        }
      }else{
        if (tmp->right != NULL) {
          tmp = tmp->right;
        }else {
          tmp->right = newp;
          return treep;
        }
      }
    }
  }
  return treep;

}

Nameval* lookup(Nameval* treep, char* name) {
  int cmp;
  if (treep == NULL) {
    return NULL;
  }
  cmp = strcmp(name, treep->name);
  if (cmp == 0) {
    return treep;
  }else if (cmp < 0) {
    return lookup(treep->left, name);
  }else {
    return lookup(treep->right, name);
  }
}

Nameval* nrlookup(Nameval* treep, char* name) {
  if (treep == NULL) return NULL;

  while (treep != NULL) {
    int cmp = strcmp(name, treep->name);
    if (cmp == 0) return treep;
    if (cmp < 0 ) {
      treep = treep->left;
    }else {
      treep = treep->right;
    }
  }
  return NULL;
}

void applyInorder(Nameval* treep) {
  if (treep == NULL) {
    return;
  }
  applyInorder(treep->left);
  fprintf(stderr, "%s: %d\t", treep->name, treep->value);
  applyInorder(treep->right);
}

void applyPostorder(Nameval* treep) {
  if (treep == NULL) {
    return;
  }
  applyPostorder(treep->left);
  applyPostorder(treep->right);
  fprintf(stderr, "%s: %d\t", treep->name, treep->value);
}

int treeHeight(Nameval* treep) {

  if (treep == NULL) {
    return -1;
  }else {
    int lh = 0;
    int rh = 0;
    int start = 1;
    lh = treeHeight(treep->left);
    rh = treeHeight(treep->right);
    return start + (lh > rh ? lh : rh);
  }
}

int totalStorage(Nameval* treep) {
  if (treep == NULL) {
    return 0;
  }else {
    int start = treep->value;
    int lh = 0;
    int rh = 0;
    lh = lh + totalStorage(treep->left);
    rh = rh + totalStorage(treep->right);
    return start + lh + rh;
  }
}