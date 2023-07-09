#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct {
	int prodID;
	char prodName[20];
	int prodQty;
	float prodPrice;
} Product;

typedef struct node {
	Product data;
	struct node *left;
	struct node *right;	
} NodeType, *NodePtr, BST, *BSTPtr;

// Add element to BST based on product ID
BSTPtr addElement(BSTPtr list, Product item); // using recursive method
void insertBST(BSTPtr *list, Product item); // using iterative method

// Delete element in the BST base on the product ID
void removeElement(BSTPtr *list, int prodID); // using iterative method
BSTPtr deleteElement(BSTPtr list, int prodID); // using recursive method

// Display BST all in recursive method
void inorderBST(BSTPtr list);
void preorderBST(BSTPtr list);
void postorderBST(BSTPtr list);

// Other functions
BSTPtr newBST();
void initBST(BSTPtr *list);
bool isEmpty(BSTPtr list);
Product createProduct(int id, char *name, int qty, float price);
// use the following format {<id> | <prodName} replacing the angular brackets with data
void displayProduct(Product prod); 
BSTPtr max(BSTPtr list);
BSTPtr min(BSTPtr list);
bool isMember(BSTPtr list, int prodID);

#endif
