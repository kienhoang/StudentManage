#include <iostream>
#include "Student.h"

int main() {	
	Student first;
	first.AddStudent("Hoang Kien", 20142397);
	first.AddStudent("Nguyen Nhai", 20143274);
	first.AddStudent("Hoang Kien", 1234);
	first.ImportFromFile("List.txt");
 	return 0;
}