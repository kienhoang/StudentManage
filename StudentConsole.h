#pragma once
#include "Student.h"
#include <iostream>

class StudentConsole : public Student {
private: 
	bool isSave_ ;
	std::string fname_;
public:
	StudentConsole();
	StudentConsole(Student * student);
	~StudentConsole();
protected:
	int Menu_console();
	int FindMenu_console();
	int SortListMenu_console();
	int DeleteMenu_console();
	int SaveMenu_console();
	int EditMenu_console();

	void AddStudent_console();
	void ViewList_console();
	void SortList_console();
	void Find_console();
	void Delete_console();
	void Edit_console();
	void Save_console();
	void AddList_console();
	void OpenList_console();
	void CloseList_console();
public :
	void start_console();
};