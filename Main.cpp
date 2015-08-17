#include <iostream>
#include "Student.h"

int main() {	
	Student first;
	first.AddStudent("Hoang Kien", 20142397);
	first.AddStudent("Nguyen Nhai", 20143274);
	first.AddStudent("Van An", 20142397);
	Student *SV2 = new Student("An", 25362542);
	SV2->AddStudent("lalala", 21652521);
	Student * p = first.FindCode(213);
 	return 0;
}