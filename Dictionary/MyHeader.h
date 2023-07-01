#ifndef MYHEADER_H
#define MYHEADER_H
#include <stdbool.h>

#define EMPTY 0
#define DELETED -1

typedef struct {
	int elem;
	int link;
} Data;

typedef struct {
	Data *data;
	int avail;
	int max;
	int count;
} VSpace; //AKA Dictionary

VSpace newSpace(int max);
int allocSpace(VSpace *vs);
void freeSpace(VSpace *vs, int node);
int hash(int data, int size);
VSpace rehash(VSpace vs);
bool addElement(VSpace *vs, int data);
bool removeElement(VSpace *vs, int data);
void visualize(VSpace vs);

#endif
