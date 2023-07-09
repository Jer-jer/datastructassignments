#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "MyHeader.h"

VSpace newSpace(int max){
	VSpace vs;
	int i;
	
	vs.data = malloc(sizeof(Data) * max);
	vs.max = max % 2 == 0 ? max : max + 1;
	vs.avail = max / 2;
	vs.count = 0;
	
	for(i = 0; i < max - 1; i++){
		if(i <= vs.avail - 1){
			vs.data[i].elem = EMPTY;
			vs.data[i].link = -1;
		}else if(i > vs.avail - 1){
			vs.data[i].elem = EMPTY;
			vs.data[i].link = i + 1;
		}
	}
	vs.data[i].elem = EMPTY;
	vs.data[i].link = -1;
	
	return vs;
}
int allocSpace(VSpace *vs){
	int retval = -1;
	
	if(vs->avail != -1){
		retval = vs->avail;
		vs->avail = vs->data[vs->avail].link;
	}
	
	return retval;
}
void freeSpace(VSpace *vs, int node){
	vs->data[node].link = vs->avail;
	vs->avail = node;
}
int hash(int data, int size){
	return data % size;
}
VSpace rehash(VSpace vs){
	VSpace newVS = newSpace(vs.max * 2);
	int i;
	
	for(i = 0; i < vs.max; i++){
		if(vs.data[i].elem){	
			addElement(&newVS, vs.data[i].elem);
		}
	}
	
	return newVS;
}
bool addElement(VSpace *vs, int data){
	int key = hash(data, vs->max / 2),
		overallLimit = (int) ((70.0 / 100.0) * vs->max),
		synonymLimit = (int) ((70.0 / 100.0) * ((vs->max / 2) + 1));
	
	if(vs->count == overallLimit || vs->count == synonymLimit){
//		 Rehash function here
		printf("70 percent of either count and synonym \n\n");
		VSpace holder = rehash(*vs);
		Data *arrayHolder = vs->data;
		free(arrayHolder);
		*vs = holder;
	}
	
	if(vs->data[key].elem == EMPTY || vs->data[key].elem == DELETED){
		vs->data[key].elem = data;
	}else{
		int head = key;
		
		while(vs->data[head].link != -1 && vs->data[head].elem != EMPTY && vs->data[head].elem != DELETED){
			head = vs->data[head].link;
		}
			
		int node = allocSpace(vs);
	
		vs->data[node].elem = data;
		vs->data[node].link = -1;
		
		vs->data[head].link = node;
	}
	
	
	vs->count++;
	return true;
}
bool removeElement(VSpace *vs, int data){
	int key = hash(data, vs->max / 2);
	
	if(vs->data[key].elem == data){
		if(vs->data[key].link == -1){
			vs->data[key].elem = EMPTY;
		}else{
			vs->data[key].elem = DELETED;
		}

	}else{
		int holder, head = key;
		
		while(vs->data[head].link != -1 && vs->data[vs->data[head].link].elem != data){
			head = vs->data[head].link;
		}
		
		if(vs->data[head].link != -1){
			holder = vs->data[head].link;
			vs->data[head].link = vs->data[holder].link;
			vs->data[holder].elem = EMPTY;
			freeSpace(vs, holder);
		}

	}
	
	
	return true;
}
void visualize(VSpace vs){
	int half = vs.max/2;
	printf("%5s | %5s | %5s %10s %5s | %5s | %5s \n", "INDEX", "DATA", "LINK", "", "INDEX", "DATA", "LINK");
	printf("-----------------------	         -----------------------\n");
	for(int i = 0; i < half; i++){
		printf("%5d | %5d | %5d %10s %5d | %5d | %5d \n", 
				i, vs.data[i], vs.data[i].link, " ", 
				i + half, vs.data[i + half], vs.data[i + half].link);
	}
	printf("\nAVAILABLE: %d\n\n", vs.avail);
}
