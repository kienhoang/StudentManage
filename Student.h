#pragma once
#include <string>
#include <fstream>
#include "StringProcess.h"

class Student {
private:
	std::string name_;
	int code_;
	Student *next_;
public:
	Student();
	~Student();
	void setName(std::string name);
	std::string getName();
	void setCode(int code);
	int getCode();
	void setNext(Student* next);
	Student *getNext();

	Student *LastPoint();
	int AddStudent(std::string name, int code);
	Student * FindCode(int code);
	Student * FindName(std::string name);
	int DeleteStudent(Student * p);
	void Release();
	int SaveToFile(std::string fname);
	int AddFromFile(std::string fname);
	int ImportFromFile(std::string fname);
};
