# binary search tree
A BST written in C with C++ (google test) unit tests

Node is a struct Nameval*, a char* name and int value. 
Insertion is based on string comparison. 

Functions:
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