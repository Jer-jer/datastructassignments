#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "BST_HEADER.h"

// Add element to BST based on product ID
BSTPtr addElement(BSTPtr list, Product item){ // using recursive method
	
	if(isEmpty(list)){
		BSTPtr newNode = malloc(sizeof(NodeType));
	
		newNode->data = item;
		newNode->left = NULL;
		newNode->right = NULL;
		list = newNode;
	}else {
		if(list->data.prodID > item.prodID){
			list->left = addElement(list->left, item);

		}else if(list->data.prodID < item.prodID){
			list->right = addElement(list->right, item);
		}
	}
	
	return list;

}
void insertBST(BSTPtr *list, Product item){ // using iterative method
	BSTPtr *head = list,
	newNode = malloc(sizeof(NodeType));
	
	newNode->data = item;
	newNode->left = NULL;
	newNode->right = NULL;
	
	while(!isEmpty(*head)){
		if((*head)->data.prodID > item.prodID){
			head = &(*head)->left;
			
		}else if((*head)->data.prodID < item.prodID){
			head = &(*head)->right;
		}
	}
	
	*head = newNode;
}
// Delete element in the BST base on the product ID
void removeElement(BSTPtr *list, int prodID){ // using iterative method
	BSTPtr *head = list, *temp = NULL;
	
	while(!isEmpty(*head) && (*head)->data.prodID != prodID){
		if((*head)->data.prodID > prodID){
			head = &(*head)->left;
		}else if((*head)->data.prodID < prodID){
			head = &(*head)->right;
		}
	}
	
	if((*head)->data.prodID == prodID){
		// Node with only right child or no child 
		if((*head)->left == NULL) {
			temp = head;
			head = &(*head)->right;
		}
		// Node with only left child 
		else if((*head)->right == NULL) {
			temp = head;
			head = &(*head)->left;
		}
		// node with two children: get the inorder successor 
		else {
			BSTPtr *current = &(*head)->right;
			
			while((*current)->left != NULL && (*current)->left->left != NULL){
				current = &(*current)->left;
			}
			
			// Copy the inorder successor's data to this node 
			(*head)->data = (*current)->left != NULL ? (*current)->left->data : (*current)->data;

			// Delete the inorder successor
			temp = (*current)->left != NULL ? &(*current)->left : current;
			*temp = (*current)->right;
		}
		
		free(*temp);
	}

}
BSTPtr deleteElement(BSTPtr list, int prodID){ // using recursive method
	if(isEmpty(list)){
		printf("Nothing to delete really\n");
	}else{
		if(list->data.prodID > prodID){
			list->left = deleteElement(list->left, prodID);
		}else if(list->data.prodID < prodID){
			list->right = deleteElement(list->right, prodID);
		}else {
			BSTPtr temp = NULL;
				if(list->left == NULL){
					temp = list->right;
			        free(list);
			        
			        return temp;
				}else if(list->right == NULL){
					temp = list->left;
			        free(list);
			        
			        return temp;
				}else{		
					temp = min(list);
					list->data = temp->data;
					temp = deleteElement(list->right, temp->data.prodID);
				}

		}
	}
	
	return list;
}

// Display BST all in recursive method
void inorderBST(BSTPtr list){
	if(!isEmpty(list)){
		inorderBST(list->left);
		displayProduct(list->data);
		inorderBST(list->right);
	}

}
void preorderBST(BSTPtr list){
	if(!isEmpty(list)){
		displayProduct(list->data);
		preorderBST(list->left);
		preorderBST(list->right);
	}
	
}
void postorderBST(BSTPtr list){
	if(!isEmpty(list)){
		postorderBST(list->left);
		postorderBST(list->right);
		displayProduct(list->data);
	}
}

// Other functions
BSTPtr newBST(){
	BSTPtr newTree = NULL;
	
	return newTree;
}
void initBST(BSTPtr *list){
	*list = NULL;
}
bool isEmpty(BSTPtr list){
	return list == NULL;
}
Product createProduct(int id, char *name, int qty, float price){
	Product newProduct;
	
	newProduct.prodID = id;
	strcpy(newProduct.prodName, name);
	newProduct.prodQty = qty;
	newProduct.prodQty = price;
}
// use the following format {<id> | <prodName} replacing the angular brackets with data
void displayProduct(Product prod){
	printf("{%5s %5d | %s\n}", " ", prod.prodID, prod.prodName);
	printf("{%5s %5d | %f\n\n}", " ", prod.prodQty, prod.prodPrice);
}
BSTPtr max(BSTPtr list){ // in-order predecessor 
	NodePtr head = list;
	
	if(isEmpty(head)){
		printf("Tree is empty\n");
	}else{
		if(head->left != NULL){
			head = head->left;
			
			while(head->right != NULL){
				head = head->right;
			}
		}
		
	}
	
	return head;

}
BSTPtr min(BSTPtr list){ // in-order successor
	NodePtr head = list;
	
	if(isEmpty(head)){
		printf("Tree is empty\n");
	}else{
		if(head->right != NULL){
			head = head->right;
			
			while(head->left != NULL){
				head = head->left;
			}
		}
		
	}
	
	return head;
}
bool isMember(BSTPtr list, int prodID){
	bool checker = false;
	
	if(!isEmpty(list)){
		if(list->data.prodID > prodID){
			checker = isMember(list->left, prodID);
		}else if(list->data.prodID < prodID){
			checker = isMember(list->right, prodID);
		}else{
			return list->data.prodID == prodID ? true : false;
		}
	}
	
	return checker;
}
