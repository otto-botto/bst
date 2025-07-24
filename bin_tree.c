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
void destroyTreeVal(Node* treep) {
  if (treep == NULL) {
    return;
  }
  destroyTreeVal(treep->left);
  destroyTreeVal(treep->right);

  free(treep);
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

Node* makeNodeVal(int value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* insertNodeVal(Node* treep, int value) {
  Node* node = makeNodeVal(value);
  if (treep == NULL) {
    treep = node;
  }else {
    Node* tmp = treep;
    while (tmp) {
      if (node->value == tmp->value) {
        fprintf(stderr, "Ignored duplicate node value %d\t", node->value);
      }else if (node->value < tmp->value){
        if (tmp->left != NULL) {
          tmp = tmp->left;
        }else {
          tmp->left = node;
          return treep;
        }
      }else {
        if (tmp->right != NULL) {
          tmp = tmp->right;
        }else {
          tmp->right = node;
          return treep;
        }
      }
    }
  }
  return treep;
}

void applyPreorderVal(Node* treep) {
  if (treep == NULL) {
    return;
  }
  fprintf(stderr, "%d\t", treep->value);
  applyPreorderVal(treep->left);
  applyPreorderVal(treep->right);
}

void printRangeRecursiveSplit(int start, int stop){
  int mid;

  if(start < stop) {
    mid = (start + stop) / 2;

    printRangeRecursiveSplit(start, mid);
    printf("%d\n", mid);
    printRangeRecursiveSplit(mid+1, stop);
  }
}