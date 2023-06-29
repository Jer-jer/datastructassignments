#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

void initDict(Dictionary *d, int size){
	d = malloc(sizeof(Dictionary) * size);
	d->max = size;
	d->count = 0;
	
	for(int i = 0, i < d->max; i++){
		d->stype = NULL;
	}
}
// Use first letter of last name
int hash(String lastName, int size){
	return lastName[0] % size;
}
FullName addName();
Birthdate addBday();
Student addStudent();
void insertStudent(Dictionary *d, Student s){
	int key = hash(s.name.lastName);
	SType *newStudent = malloc(sizeof(SType));
	
	newStudent->student.name = s.name;
	newStudent->student.bDate = s.bDate;
	newStudent->student.gender = s.gender;
	strcpy(newStudent->student.idNUmber, s.idNUmber);
	strcpy(newStudent->student.program, s.program);
	newStudent->student.year = s.year;
	newStudent->next = NULL;
	
	SType *head = (*d[key])->stype, *current = NULL;
	while(head != NULL && strcmp(s.name.lastName, head->next->student.name.lastName) > 0 || strcmp(s.name.lastName, head->next->student.name.lastName) != 0){
			head = head->next;
	}
		
	if(strcmp(s.name.lastName, head->next->student.name.lastName) == 0){
		current = head;
		while(current != NULL && strcmp(s.name.firstname, head->next->student.name.firstname) > 0 || strcmp(s.name.firstname, head->next->student.name.firstname) != 0)){
			current = current->next;
		}
	}
	
	if(strcmp(s.name.firstname, head->next->student.name.firstname) == 0){
		current = head;
		while(current != NULL && strcmp(s.name.firstname, head->next->student.name.firstname) > 0 || strcmp(s.name.firstname, head->next->student.name.firstname) != 0)){
			current = current->next;
		}
	}
	
	
	newStudent.next = head;
	(*d[key])->stype = newStudent.next;
}
void deleteStudent(Dictionary *, Student);
void findStudent(Dictionary, Student);
void displayStudents(Dictionary);
void visualize(Dictionary);

