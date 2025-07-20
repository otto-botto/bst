#include "gtest/gtest.h"

extern "C"{
#include "bin_tree.h"
}


TEST(BinTree, InsertNodeTest) {

    clock_t start_time = clock(); // Record start time
    char name[] = "Lora";
    Nameval* node = makeNode(name, 39);
    Nameval* treep = nullptr;
    treep = insertNode(treep, node);
    char nameJ[] = "Josie";
    Nameval* newpJ = makeNode(nameJ, 17);
    treep = insertNode(treep, newpJ);
    char nameO[] = "Otto";
    Nameval* newpO = makeNode(nameO, 10);
    treep = insertNode(treep, newpO);
    char nameA[] = "Anne";
    Nameval* newpA = makeNode(nameA, 10);
    treep = insertNode(treep, newpA);

    char nameAb[] = "Abe";
    Nameval* newpAb = makeNode(nameAb, 3);
    treep = insertNode(treep, newpAb);

    clock_t end_time = clock(); // Record end time
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate elapsed time in seconds
    printf("my_function took %f seconds to execute.\n", elapsed_time);


    EXPECT_EQ(treep->name, name);
    EXPECT_EQ(treep->right->name, nameO);
    EXPECT_EQ(treep->left->name, nameJ);
    EXPECT_EQ(treep->left->left->name, nameA);
    EXPECT_EQ(treep->left->left->left->name, nameAb);

    destroyTree(treep);
}

TEST(BinTree, NrInsertNodeTest) {
    clock_t start_time = clock(); // Record start time
    char name[] = "Lora";
    Nameval* node = makeNode(name, 39);
    Nameval* treep = nullptr;
    treep = nrinsertNode(treep, node);

    char nameJ[] = "Josie";
    Nameval* newpJ = makeNode(nameJ, 17);
    treep = nrinsertNode(treep, newpJ);

    char nameO[] = "Otto";
    Nameval* newpO = makeNode(nameO, 10);
    treep = nrinsertNode(treep, newpO);
    char nameA[] = "Anne";
    Nameval* newpA = makeNode(nameA, 10);
    treep = nrinsertNode(treep, newpA);

    char nameAb[] = "Abe";
    Nameval* newpAb = makeNode(nameAb, 3);
    treep = nrinsertNode(treep, newpAb);

    clock_t end_time = clock(); // Record end time
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate elapsed time in seconds
    printf("my_function took %f seconds to execute.\n", elapsed_time);

    EXPECT_EQ(treep->name, name);
    EXPECT_EQ(treep->right->name, nameO);
    EXPECT_EQ(treep->left->name, nameJ);
    EXPECT_EQ(treep->left->left->name, nameA);
    EXPECT_EQ(treep->left->left->left->name, nameAb);

    destroyTree(treep);
}

TEST(BinTree, LookupTest) {
    char name[] = "Lora";
    Nameval* node = makeNode(name, 39);
    Nameval* treep = nullptr;
    treep = insertNode(treep, node);
    char nameL[] = "Josie";
    Nameval* newpL = makeNode(nameL, 17);
    treep = insertNode(treep, newpL);
    char nameR[] = "Otto";
    Nameval* newpR = makeNode(nameR, 10);
    treep = insertNode(treep, newpR);
    char nameN[] = "Susie";

    EXPECT_EQ(treep->left, lookup(treep, nameL));
    EXPECT_EQ(treep->right, lookup(treep, nameR));
    EXPECT_EQ(nullptr, lookup(treep, nameN));

    destroyTree(treep);
}

TEST(BinTree, NRLookupTest) {
    char name[] = "Lora";
    Nameval* node = makeNode(name, 39);
    Nameval* treep = nullptr;
    treep = insertNode(treep, node);
    char nameL[] = "Josie";
    Nameval* newpL = makeNode(nameL, 17);
    treep = insertNode(treep, newpL);
    char nameR[] = "Otto";
    Nameval* newpR = makeNode(nameR, 10);
    treep = insertNode(treep, newpR);
    char nameN[] = "Susie";

    EXPECT_EQ(treep->left, nrlookup(treep, nameL));
    EXPECT_EQ(treep->right, nrlookup(treep, nameR));
    EXPECT_EQ(nullptr, lookup(treep, nameN));

    destroyTree(treep);
}

TEST(BinTree, InorderTest) {
    /* Note that the BST is based on name, not value*/
    char name[] = "Lora";
    Nameval* node = makeNode(name, 38);
    Nameval* treep = nullptr;
    treep = insertNode(treep, node);
    char nameJ[] = "Josie";
    Nameval* newpJ = makeNode(nameJ, 5);
    treep = insertNode(treep, newpJ);
    char nameO[] = "Otto";
    Nameval* newpO = makeNode(nameO, 1);
    treep = insertNode(treep, newpO);
    char nameA[] = "Anne";
    Nameval* newpA = makeNode(nameA, 9);
    treep = insertNode(treep, newpA);
    char nameAb[] = "Abe";
    Nameval* newpAb = makeNode(nameAb, 8);
    treep = insertNode(treep, newpAb);
    char nameB[] = "Bin";
    Nameval* newpB = makeNode(nameB, 15);
    treep = insertNode(treep, newpB);
    char nameC[] = "Sam";
    Nameval* newpC = makeNode(nameC, 13);
    treep = insertNode(treep, newpC);
    char nameD[] = "Dam";
    Nameval* newpD = makeNode(nameD, 45);
    treep = insertNode(treep, newpD);
    char nameE[] = "Ed";
    Nameval* newpE = makeNode(nameE, 47);
    treep = insertNode(treep, newpE);
    char nameF[] = "Fun";
    Nameval* newpF = makeNode(nameF, 46);
    treep = insertNode(treep, newpF);


    applyInorder(treep);

    destroyTree(treep);
}

TEST(BinTree, PostorderTest) {
    /* Note that the BST is based on name, not value*/
    char name[] = "Lora";
    Nameval* node = makeNode(name, 38);
    Nameval* treep = nullptr;
    treep = insertNode(treep, node);
    char nameJ[] = "Josie";
    Nameval* newpJ = makeNode(nameJ, 5);
    treep = insertNode(treep, newpJ);
    char nameO[] = "Otto";
    Nameval* newpO = makeNode(nameO, 1);
    treep = insertNode(treep, newpO);
    char nameA[] = "Anne";
    Nameval* newpA = makeNode(nameA, 9);
    treep = insertNode(treep, newpA);
    char nameAb[] = "Abe";
    Nameval* newpAb = makeNode(nameAb, 8);
    treep = insertNode(treep, newpAb);
    char nameB[] = "Bin";
    Nameval* newpB = makeNode(nameB, 15);
    treep = insertNode(treep, newpB);
    char nameC[] = "Sam";
    Nameval* newpC = makeNode(nameC, 13);
    treep = insertNode(treep, newpC);
    char nameD[] = "Dam";
    Nameval* newpD = makeNode(nameD, 45);
    treep = insertNode(treep, newpD);
    char nameE[] = "Ed";
    Nameval* newpE = makeNode(nameE, 47);
    treep = insertNode(treep, newpE);
    char nameF[] = "Fun";
    Nameval* newpF = makeNode(nameF, 46);
    treep = insertNode(treep, newpF);


    applyPostorder(treep);

    destroyTree(treep);
}

TEST(BinTree, TreeHeightTest) {
    char name[] = "Lora";
    Nameval* node = makeNode(name, 39);
    Nameval* treep = nullptr;
    treep = nrinsertNode(treep, node);

    char nameJ[] = "Josie";
    Nameval* newpJ = makeNode(nameJ, 17);
    treep = nrinsertNode(treep, newpJ);

    char nameO[] = "Otto";
    Nameval* newpO = makeNode(nameO, 10);
    treep = nrinsertNode(treep, newpO);
    char nameA[] = "Anne";
    Nameval* newpA = makeNode(nameA, 18);
    treep = nrinsertNode(treep, newpA);

    char nameAb[] = "Abe";
    Nameval* newpAb = makeNode(nameAb, 3);
    treep = nrinsertNode(treep, newpAb);

    char nameYuk[] = "Yuk";
    Nameval* newpYuk = makeNode(nameYuk, 45);
    treep = nrinsertNode(treep, newpYuk);

    EXPECT_EQ(3, treeHeight(treep));

    destroyTree(treep);
}

TEST(BinTree, TreeHeightZeroTest) {
    Nameval* treep = nullptr;
    int height = treeHeight(treep);
    if (height == -1) {
        height = 0;
    }

    EXPECT_EQ(0, height);
    destroyTree(treep);
}

TEST(BinTree, TotalStorageTest) {
    char name[] = "Lora";
    Nameval* node = makeNode(name, 39);
    Nameval* treep = nullptr;
    treep = nrinsertNode(treep, node);

    char nameJ[] = "Josie";
    Nameval* newpJ = makeNode(nameJ, 17);
    treep = nrinsertNode(treep, newpJ);

    char nameO[] = "Otto";
    Nameval* newpO = makeNode(nameO, 10);
    treep = nrinsertNode(treep, newpO);
    char nameA[] = "Anne";
    Nameval* newpA = makeNode(nameA, 18);
    treep = nrinsertNode(treep, newpA);

    char nameAb[] = "Abe";
    Nameval* newpAb = makeNode(nameAb, 3);
    treep = nrinsertNode(treep, newpAb);

    char nameYuk[] = "Yuk";
    Nameval* newpYuk = makeNode(nameYuk, 45);
    treep = nrinsertNode(treep, newpYuk);

    int storage = totalStorage(treep);

    EXPECT_EQ(132, storage);

    destroyTree(treep);
}

TEST(BinTree, TotalStorageZeroTest) {
    Nameval* treep = nullptr;
    int storage = totalStorage(treep);

    EXPECT_EQ(0, storage);

    destroyTree(treep);
}