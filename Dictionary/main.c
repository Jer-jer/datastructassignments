#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "MyHeader.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VSpace vs = newSpace(10);
	
	visualize(vs);
	
//	addElement(&vs, 5);
//	addElement(&vs, 25);
//	addElement(&vs, 3);
//	addElement(&vs, 15);
//	addElement(&vs, 8);
//	addElement(&vs, 23);
//	addElement(&vs, 4);
//
//	visualize(vs);
//	
//	removeElement(&vs, 5);
//	removeElement(&vs, 23);

	addElement(&vs, 5);
	addElement(&vs, 25);
	addElement(&vs, 15);
	addElement(&vs, 105);
	
	visualize(vs);
	
	addElement(&vs, 10);
	addElement(&vs, 20);
	
	visualize(vs);
	return 0;
}
