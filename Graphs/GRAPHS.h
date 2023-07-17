#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define MAX 26

typedef char String[20];

typedef struct{
	String value;
}Data;

typedef struct{
	Data *data;
	int count;
	int max;
}Value;

typedef struct{
	String key;
	Value value;
}ArrayList;

typedef ArrayList Dictionary[MAX];

void initGraph(Dictionary graph);
Value initValue();
bool valueChecker(Value *val);
int hash(String loc, int increment);
bool addVertex(Dictionary graph, String loc);
bool addEdge(Dictionary graph, String loc1, String loc2);
bool deleteVertex(Dictionary graph, String loc);
bool deleteEdge(Dictionary graph, String loc1, String loc2);
void displayGraph(Dictionary graph);

#endif
