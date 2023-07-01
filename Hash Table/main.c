#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary dictionary;
	
	initDict(&dictionary, 26);
	
	insertStudent(&dictionary, addStudent("18101799", addName("Allan", "Jericho", "Bargamento"), 'm', 4, "BSIT", addBday(6, 28, 1999)));
	insertStudent(&dictionary, addStudent("16100512", addName("Princess", "Aliza", "Bargamento"), 'f', 4, "BSN", addBday(9, 3, 1997)));
	insertStudent(&dictionary, addStudent("16100523", addName("Princess", "Jasmine", "Bargamento"), 'f', 4, "BSN", addBday(9, 3, 1997)));		
	insertStudent(&dictionary, addStudent("21125568", addName("Princess", "Jasmine", "Bargamento"), 'f', 3, "BSN", addBday(12, 3, 1998)));
	insertStudent(&dictionary, addStudent("22123456", addName("Summer", "Therese", "Ferrer"), 'f', 2, "BSN", addBday(12, 3, 2001)));
	
	visualize(dictionary);
	
	Student student = findStudent(dictionary, addName("Summer", "Therese", "Ferrer"));

	printf("\n\nStudent Found: %5s, %5s %5s\n\n", student.name.lastName, student.name.firstname, student.name.middleName);
	
	deleteStudent(&dictionary, addName("Princess", "Aliza", "Bargamento"));
	
	visualize(dictionary);
	
	return 0;
}
