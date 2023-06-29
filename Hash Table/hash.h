#ifndef HASH_H
#define HASH_H

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
} SType;

typedef struct {
	SType *stype;
	int count;
	int max;
} *Dictionary; //Max is 26


void initDict(Dictionary *, int);
// Use first letter of last name
int hash(String, int);
FullName addName();
Birthdate addBday();
Student addStudent();
void insertStudent(Dictionary *, Student);
void deleteStudent(Dictionary *, Student);
void findStudent(Dictionary, Student);
void displayStudents(Dictionary);
void visualize(Dictionary);


#endif
