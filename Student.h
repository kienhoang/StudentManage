#pragma once
#include <string>
#include <fstream>
#include "StringProcess.h"

class Student {
private:
	std::string firstname_;
	std::string lastname_;
	int code_;
	Student *next_;
public:
	Student();
	~Student();
public:
	void setName(std::string &firstname,std::string &lastname);
	void setName(const std::string &firstname,const std::string &lastname);
	std::string getFirstName();
	std::string getLastName();
	void setCode(int code);
	int getCode();
	void setNext(Student* next);
	Student * getNext();

	int AddStudent(std::string &FirstName,std::string &LastName, int code);
	int AddStudent(const std::string &FirstName,const std::string &LastName, int code);
	int DeleteStudent(Student * p);
	void Release();
	int SaveToFile(const std::string &fname);
	int SaveToFile(std::string &fname);
	int AddFromFile(const std::string &fname, Student * &error);
	int AddFromFile(std::string &fname, Student * &error);
	int ImportFromFile(const std::string &fname, Student * & error );
	int ImportFromFile(std::string &fname, Student * & error);
	void SortList(int mode = 1);

	Student * FindCode(int code);
	Student * FindName(std::string &name);
	Student * FindName(const std::string &name);
	Student * LastPoint();
};
