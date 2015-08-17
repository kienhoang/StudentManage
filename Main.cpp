#include <iostream>
#include "Student.h"

int main() {	
	Student first;
	first.AddStudent("Hoang Kien", 20142397);
	first.AddStudent("Nguyen Nhai", 20143274);
	first.AddStudent("Hoang Kien", 1234);
	Student *p = 0;
	p = first.FindCode(1234);
	first.DeleteStudent(p);
 	return 0;
}