#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "GRAPHS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary newGraph;
	bool checker;
	
	printf("ADDING VERTICES!!!!\n\n\n");
	
	initGraph(newGraph);
	
	addVertex(newGraph, "Japan");
	addVertex(newGraph, "Philippines");
	addVertex(newGraph, "China");
	addVertex(newGraph, "USA");
	addVertex(newGraph, "Great Britain");
	addVertex(newGraph, "Russia");
	addVertex(newGraph, "Brazil");
	addVertex(newGraph, "Spain");
	addVertex(newGraph, "Egypt");
	addVertex(newGraph, "Nigeria");
	addVertex(newGraph, "Uganda");
	addVertex(newGraph, "Argentina");
	addVertex(newGraph, "Korea");
	addVertex(newGraph, "Guam");
	addVertex(newGraph, "India");
	addVertex(newGraph, "Saudi Arabia");
	
	displayGraph(newGraph);
	
	printf("\n\n\nADDING EDGES!!!!\n\n\n");
	
	addEdge(newGraph, "Japan", "Philippines");
	addEdge(newGraph, "Philippines", "China");
	addEdge(newGraph, "Philippines", "Guam");
	addEdge(newGraph, "Philippines", "Korea");
	checker = addEdge(newGraph, "Mongolia", "Philippines");
	printf("One of the locations isn't registered yet!!!!\n\n");
	checker = addEdge(newGraph, "Japan", "Philippines");
	printf("It already has a connection!!!!\n\n");
	addEdge(newGraph, "Russia", "China");
	addEdge(newGraph, "India", "Russia");
	addEdge(newGraph, "Saudi Arabia", "Russia");
	
	displayGraph(newGraph);
	
	printf("\n\n\nDELETETING EDGES!!!!\n\n\n");
	
	deleteEdge(newGraph, "China", "Philippines");
	deleteEdge(newGraph, "Philippines", "Japan");
	deleteEdge(newGraph, "India", "Russia");
	checker = deleteEdge(newGraph, "Argentina", "Brazil");
	printf("There's no connection in the first place!!!!\n\n");
	checker = deleteEdge(newGraph, "Philippines", "Russia");
	printf("There's no connection in the first place!!!!\n\n");
	
	displayGraph(newGraph);
	
	printf("\n\n\nDELETETING VERTICES!!!!\n\n\n");
	
	deleteVertex(newGraph, "Philippines");
	deleteVertex(newGraph, "Russia");
	
	displayGraph(newGraph);
	
	return 0;
}
