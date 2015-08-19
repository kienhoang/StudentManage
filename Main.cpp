#include <iostream>
#include "Student.h"
#include "StudentConsole.h"

int main() {	
	StudentConsole student;
	student.AddStudent("Hoang Van", "Kien", 20142397);
	student.AddStudent("Nguyen Thi", "Nhai", 20143274);
	student.AddStudent("Le Van", "Hoang", 20154236);
	student.AddStudent_console();
	student.SortList(1);
	student.viewlist_console();
	student.FindName("Hoang");
	return 0;
}