#include <iostream>
#include "Student.h"

int main() {	
	Student list;
	list.AddStudent("Hoang Kien", 20142397);
	list.AddStudent("Nguyen Nhai", 20143274);
	list.AddStudent("Hoang Ha", 20143325);
	list.SortList();
	return 0;
}