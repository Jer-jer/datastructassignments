#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash.h"

void initDict(Dictionary *d, int size){
	d->students = malloc(sizeof(SPointer) * size);
	d->count = 0;
	d->max = size;

	for(int i = 0; i < d->max; i++){
		d->students[i] = NULL;
	}
}
// Use first letter of last name
int hash(String lastName, int size){
	return lastName[0] % size;
}
FullName addName();
Birthdate addBday();
Student addStudent();
bool insertStudent(Dictionary *d, Student s){
	int key = hash(s.name.lastName, d->max);
	SPointer newStudent = malloc(sizeof(SType));
	
	newStudent->student.name = s.name;
	newStudent->student.bDate = s.bDate;
	newStudent->student.gender = s.gender;
	strcpy(newStudent->student.idNUmber, s.idNUmber);
	strcpy(newStudent->student.program, s.program);
	newStudent->student.year = s.year;
	newStudent->next = NULL;
	
//	strmp(d->students[key]->student.name.lastName, newStudent->student.name.lastName) < 0 || 
//	strmp(d->students[key]->student.name.lastName, newStudent->student.name.lastName) == 0 &&
//	strmp(d->students[key]->student.name.firstname, newStudent->student.name.firstname) < 0 ||
//	strmp(d->students[key]->student.name.firstname, newStudent->student.name.firstname) == 0 &&
//	strmp(d->students[key]->student.name.middleName, newStudent->student.name.middleName) < 0 ||
//	strmp(d->students[key]->student.name.middleName, newStudent->student.name.middleName) == 0 &&
//	strmp(d->students[key]->student.idNUmber, newStudent->student.idNUmber) < 0 ||
//	strmp(d->students[key]->student.idNUmber, newStudent->student.idNUmber) == 0 
	
	if(d->students[key] != NULL){
		SPointer head = d->students[key];
		
		if(strcmp(head->student.name.lastName, newStudent->student.name.lastName) < 0 
			|| strcmp(head->student.name.firstname, newStudent->student.name.firstname) < 0
			|| strcmp(head->student.name.middleName, newStudent->student.name.middleName) < 0
			|| strcmp(head->student.idNUmber, newStudent->student.idNUmber) < 0){
				newStudent->next = head->next;
				head->next = newStudent;
				return true;
		}else if(strcmp(head->student.name.lastName, newStudent->student.name.lastName) >= 0 
			|| strcmp(head->student.name.firstname, newStudent->student.name.firstname) >= 0
			|| strcmp(head->student.name.middleName, newStudent->student.name.middleName) >= 0
			|| strcmp(head->student.idNUmber, newStudent->student.idNUmber) >= 0){
				newStudent->next = head;
				d->students[key] = newStudent;
				return true;
		}
		
		while(head->next != NULL && strcmp(head->next->student.name.lastName, newStudent->student.name.lastName) < 0 || strcmp(head->next->student.name.lastName, newStudent->student.name.lastName) != 0){
			head = head->next;
		}
		
		while(head->next != NULL && strcmp(head->next->student.name.lastName, newStudent->student.name.lastName) == 0 && 
			strcmp(head->next->student.name.firstname, newStudent->student.name.firstname) < 0 || strcmp(head->next->student.name.firstname, newStudent->student.name.firstname) != 0){
			head = head->next;
		}
		
		while(head->next != NULL && strcmp(head->next->student.name.firstname, newStudent->student.name.firstname) == 0 && 
			strcmp(head->next->student.name.middleName, newStudent->student.name.middleName) < 0 || strcmp(head->next->student.name.middleName, newStudent->student.name.middleName) != 0){
			head = head->next;
		}
		
		while(head->next != NULL && strcmp(head->next->student.name.middleName, newStudent->student.name.middleName) == 0 && 
			strcmp(head->next->student.idNUmber, newStudent->student.idNUmber) < 0 || strcmp(head->next->student.idNUmber, newStudent->student.idNUmber) != 0){
			head = head->next;
		}
		
		newStudent->next = head->next;
		head->next = newStudent;
	}else {
		newStudent->next = d->students[key];
		d->students[key] = newStudent;
	}
	
	return true;
}
void deleteStudent(Dictionary *, Student);
void findStudent(Dictionary, Student);
void displayStudents(Dictionary d){
	for(int i = 0; i < d.max; i++){
		printf("%s", d.students[i]->student.idNUmber);
	}
}
void visualize(Dictionary d){
	
}

