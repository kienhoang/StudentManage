#pragma once
#include "Student.h"
#include <iostream>

class StudentConsole : public Student {
public:
	StudentConsole();
	~StudentConsole();
	int Menu_console();
	int FindMenu_console();
	void AddStudent_console();
	void viewlist_console();
};