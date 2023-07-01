#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

typedef char String[80];

typedef struct {
	int month;
	int day;
	int year;
} Birthdate;

typedef struct {
	String firstname;
	String middleName;
	String lastName;
} FullName;

typedef struct {
	String idNUmber;	
	FullName name;
	char gender;
	int year;
	String program;
	Birthdate bDate;
	
} Student;

typedef struct node{
	Student student;
	struct node *next;	
} SType, *SPointer;

typedef struct {
	SPointer *students;
	int count;
	int max;
} Dictionary; //Max is 26


void initDict(Dictionary *, int);
// Use first letter of last name
int hash(String, int);
FullName addName(String, String, String);
Birthdate addBday(int, int, int);
Student addStudent(String, FullName, char, int, String, Birthdate);
bool insertStudent(Dictionary *, Student);
bool deleteStudent(Dictionary *, FullName);
Student findStudent(Dictionary, FullName);
void displayStudents(Dictionary);
void visualize(Dictionary);


#endif
