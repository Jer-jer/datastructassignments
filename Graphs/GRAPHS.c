#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "GRAPHS.h"

Value initValue(){
	Value newValue;
	
	newValue.count = 0;
	newValue.max = 0;
	newValue.data = NULL;
	
	return newValue;
} 
void initGraph(Dictionary graph){
	
	for(int i = 0; i < MAX; i++){
		strcpy(graph[i].key, "");
		graph[i].value = initValue();
	}
	
}
bool valueChecker(Value *val){
	return (val) ? true : false;
}
int hash(String loc, int increment){
	return (toupper(loc[0]) + increment) % MAX;
}
bool addVertex(Dictionary graph, String loc){
	int i = 0, count = 0;
	int key = hash(loc, i);
	
	while(count < MAX && strcmp(graph[key].key, "") != 0){
		key = hash(loc, ++i);
		count++;
	}
	
	if(count != MAX){
		strcpy(graph[key].key, loc);
	
		return true;
	}
	
	return false;
	
}

bool deleteVertex(Dictionary graph, String loc){
	int i = 0, count = 0;
	int key = hash(loc, i);
	
	while(count < MAX && strcmp(graph[key].key, loc) != 0){
		key = hash(loc, ++i);
		count++;
	}
	
	if(count == MAX) return false;
	
	if(valueChecker(&graph[key].value)){
		while(strcmp(graph[key].value.data[0].value, "") != 0){
			deleteEdge(graph, loc, graph[key].value.data[i].value);
		}
	}
	
	strcpy(graph[key].key, "");
	graph[key].value.max = 0;
	free(graph[key].value.data);
	graph[key].value.data = NULL;
	
	return true;	
}

bool addEdge(Dictionary graph, String loc1, String loc2){
	int i = 0, count = 0;
	int key1 = hash(loc1, i), key2 = hash(loc2, i);
	
	while(count < MAX && strcmp(graph[key1].key, loc1) != 0){
		key1 = hash(loc1, ++i);
		count++;
	}
	
	if(count == MAX) return false;
	
	for(i = 0, count = 0; count < MAX && strcmp(graph[key2].key, loc2) != 0; key2 = hash(loc2, ++i), count++){}
	
	if(count == MAX) return false;
	
	if(!(graph[key1].value.data)){
		graph[key1].value.max = 5;
		graph[key1].value.data = malloc(sizeof(Data) * graph[key1].value.max);
		
	}else{
		if(graph[key1].value.count == graph[key1].value.max){
			graph[key1].value.data = realloc(graph[key1].value.data, sizeof(Data) * graph[key1].value.max);	
			graph[key1].value.max += graph[key1].value.max;
		}
		
		for(i = 0; i < graph[key1].value.count && strcmp(graph[key1].value.data[i].value, loc2) != 0; i++){}
		
		if(strcmp(graph[key1].value.data[i].value, loc2) == 0) return false;
	}
	
	strcpy(graph[key1].value.data[graph[key1].value.count++].value, loc2);
	
	if(!(graph[key2].value.data)){
		graph[key2].value.max = 5;
		graph[key2].value.data = malloc(sizeof(Data) * graph[key2].value.max);
		
	}else{
		if(graph[key2].value.count == graph[key2].value.max){
			graph[key2].value.data = realloc(graph[key2].value.data, sizeof(Data) * graph[key2].value.max);	
			graph[key2].value.max += graph[key2].value.max;
		}
	}
	
	strcpy(graph[key2].value.data[graph[key2].value.count++].value, loc1);
	
	return true;
}
bool deleteEdge(Dictionary graph, String loc1, String loc2){
	int i = 0, count = 0;
	int key1 = hash(loc1, i), key2 = hash(loc2, i);
	
	while(count < MAX && strcmp(graph[key1].key, loc1) != 0){
		key1 = hash(loc1, ++i);
		count++;
	}
	
	if(count == MAX) return false;
	
	for(i = 0, count = 0; count < MAX && strcmp(graph[key2].key, loc2) != 0; key2 = hash(loc2, ++i), count++){}
	
	if(count == MAX) return false;
	
	if(!(graph[key1].value.data) && !(graph[key2].value.data)) return false;
	
	int o;
		
	for(i = 0; i < graph[key1].value.count && strcmp(graph[key1].value.data[i].value, loc2) != 0; i++){}
	for(o = 0; o < graph[key2].value.count && strcmp(graph[key2].value.data[o].value, loc1) != 0; o++){}
				
	if(i == graph[key1].value.count && o == graph[key2].value.count) return false;

	while(i < graph[key1].value.count){
		strcpy(graph[key1].value.data[i].value, graph[key1].value.data[i+1].value);
		i++;
	}

	while(o < graph[key2].value.count){
		strcpy(graph[key2].value.data[o].value, graph[key2].value.data[o+1].value);
		o++;
	}
			
	graph[key1].value.count--;
	graph[key2].value.count--;
	
	return true;
}
void displayGraph(Dictionary graph){
	for(int i = 0; i < MAX; i++){
		printf("INDEX: %d COUNTER: %d KEY: %s ------ ", i, graph[i].value.count, graph[i].key);
		printf("[%1s", " ");
			if(valueChecker(&graph[i].value)){
				for(int o = 0; graph[i].value.data && o < graph[i].value.count; o++){
					printf("%s, ", graph[i].value.data[o].value);
				}
			}
		printf("]\n\n");
	}
}
