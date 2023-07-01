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

int hash(String lastName, int size){
	return lastName[0] % size;
}
FullName addName(String fName, String mName, String lName){
	FullName fullname;
	
	strcpy(fullname.firstname, fName);
	strcpy(fullname.middleName, mName);
	strcpy(fullname.lastName, lName);
	
	return fullname;
}
Birthdate addBday(int month, int day, int year){
	Birthdate bday;
	
	bday.month = month;
	bday.day = day;
	bday.year = year;
	
	return bday;
}
Student addStudent(String idNumber, FullName name, char gender, int year, String program, Birthdate bDate){
	Student newStudent;
	
	strcpy(newStudent.idNUmber, idNumber);
	newStudent.name = name;
	newStudent.gender = gender;
	newStudent.year = year;
	strcpy(newStudent.program, program);
	newStudent.bDate = bDate;
	
	return newStudent;
}
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
	
	if(d->students[key] != NULL){
		
		SPointer head = d->students[key];
		
		if(head->next == NULL){
			
			if(strcmp(d->students[key]->student.name.lastName, newStudent->student.name.lastName) > 0){
				newStudent->next = d->students[key];
				d->students[key] = newStudent;
			}else if(strcmp(d->students[key]->student.name.lastName, newStudent->student.name.lastName) == 0){
				if(strcmp(d->students[key]->student.name.firstname, newStudent->student.name.firstname) > 0){
					newStudent->next = d->students[key];
					d->students[key] = newStudent;
				}else if(strcmp(d->students[key]->student.name.firstname, newStudent->student.name.firstname) == 0){
					if(strcmp(d->students[key]->student.name.middleName, newStudent->student.name.middleName) > 0){
						newStudent->next = d->students[key];
						d->students[key] = newStudent;
					}else if(strcmp(d->students[key]->student.name.middleName, newStudent->student.name.middleName) == 0){
						if(strcmp(d->students[key]->student.idNUmber, newStudent->student.idNUmber) > 0){
							newStudent->next = d->students[key];
							d->students[key] = newStudent;
						}else if(strcmp(d->students[key]->student.idNUmber, newStudent->student.idNUmber) < 0){
							d->students[key]->next = newStudent;
						}
					}else{
						d->students[key]->next = newStudent;
					}
				}else{
					d->students[key]->next = newStudent;
				}
			}else{
				d->students[key]->next = newStudent;
			}
			
			return true;
		}
		
		while(head->next != NULL && strcmp(head->next->student.name.lastName, newStudent->student.name.lastName) < 0){
			head = head->next;
		}
		
		if(strcmp(head->next->student.name.lastName, newStudent->student.name.lastName) == 0){
			
			while(head->next != NULL && strcmp(head->next->student.name.firstname, newStudent->student.name.firstname) < 0){
				head = head->next;
			}
			
			if(head->next != NULL && strcmp(head->next->student.name.firstname, newStudent->student.name.firstname) == 0){

				while(head->next != NULL && strcmp(head->next->student.name.middleName, newStudent->student.name.middleName) < 0){
					head = head->next;
				}
				
				if(head->next != NULL && strcmp(head->next->student.name.middleName, newStudent->student.name.middleName) == 0){
					
					while(head->next != NULL && strcmp(head->next->student.idNUmber, newStudent->student.idNUmber) < 0){
						head = head->next;
					}
				}
			}
		}
		
		newStudent->next = head->next;
		head->next = newStudent;
		
	}else{
		newStudent->next = d->students[key];
		d->students[key] = newStudent;
	}
	
	d->count++;
	return true;
}
bool deleteStudent(Dictionary *d, FullName student){
	int key = hash(student.lastName, d->max);
	SPointer holder;
	
	if(strcmp(d->students[key]->student.name.lastName, student.lastName) == 0){
		if(strcmp(d->students[key]->student.name.firstname, student.firstname) == 0){
			if(strcmp(d->students[key]->student.name.middleName, student.middleName) == 0){
				holder = d->students[key];
				d->students[key] = d->students[key]->next;
				free(holder);
				
				return true;
			}
		}
	}
	
	SPointer head = d->students[key];
	
	while(head->next != NULL && strcmp(head->next->student.name.lastName, student.lastName) != 0){
		head = head->next;
	}
		
	if(strcmp(head->next->student.name.lastName, student.lastName) == 0){
			
		while(head->next != NULL && strcmp(head->next->student.name.firstname, student.firstname) != 0){
			head = head->next;
		}
			
		if(head->next != NULL && strcmp(head->next->student.name.firstname, student.firstname) == 0){

			while(head->next != NULL && strcmp(head->next->student.name.middleName, student.middleName) != 0){
				head = head->next;
			}
		}
	}
	
	if(head->next == NULL){
		return false;
	}
	
	holder = head->next;
	head->next = holder->next;
	free(holder);
	
	return true;
		
}
Student findStudent(Dictionary d, FullName fullname){
	int key = hash(fullname.lastName, d.max);
	SPointer head = d.students[key];
	
	while(head != NULL && 
		head->student.name.lastName == fullname.lastName &&
		head->student.name.firstname == fullname.firstname &&
		head->student.name.middleName == fullname.middleName){
		head = head->next;
	}
	
	return head->student;
}
void displayStudents(Dictionary d){
	for(int i = 0; i < d.max; i++){
		SPointer head = d.students[i];
		if(head != NULL){
			printf("INDEX ----- %2d \n", i);
			while(head != NULL){
				printf("-------------------- %5s %5s, %5s %5s\n", head->student.idNUmber, head->student.name.lastName, head->student.name.firstname, head->student.name.middleName);
				printf("-------------------- %5s %5s %5d\n", head->student.gender == 'f' ? "Female" : "Male", head->student.program, head->student.year);
				printf("-------------------- Birthdate: %d %5d %5d\n\n", head->student.bDate.day, head->student.bDate.month, head->student.bDate.year);
				head = head->next;
			}
		}
		
	}
}
void visualize(Dictionary d){
	for(int i = 0; i < d.max; i++){
		SPointer head = d.students[i];
		printf("INDEX ----- %2d \n", i);
		while(head != NULL){
			printf("-------------------- %5s %5s, %5s %5s\n", head->student.idNUmber, head->student.name.lastName, head->student.name.firstname, head->student.name.middleName);
			printf("-------------------- %5s %5s %5d\n", head->student.gender == 'f' ? "Female" : "Male", head->student.program, head->student.year);
			printf("-------------------- Birthdate: %d %5d %5d\n\n", head->student.bDate.day, head->student.bDate.month, head->student.bDate.year);
			head = head->next;
		}
		
	}
}

