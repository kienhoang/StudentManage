#include "Student.h"

Student::Student(){
	name_ = "";
	code_ = 0;
	next_ = 0;
}
Student::~Student(){
}
void Student::setName(std::string name) {
	NameProcess(name);
	name_ = name;
}
std::string Student::getName() {
	return name_;
}
void Student::setCode(int code) {
	code_ = code;
}
int Student::getCode() {
	return code_;
}
void Student::setNext(Student* next) {
	next_ = next;
}
Student * Student::getNext() {
	return next_;
}

Student *Student::LastPoint() {
	Student *p = this;
	if (p == 0) {
		return p;
	}
	else {
		while (p->getNext() != 0) {
			p = p->getNext();
		}
		return p;
	}
}
int Student::AddStudent(std::string name, int code) {
	NameProcess(name);
	if (FindCode(code) != 0 || code <=0 ) {
		return -1;
	}
	else {
		Student * p = LastPoint();
		if (this->getName() == "" && this->getCode() == 0) {
			this->setName(name);
			this->setCode(code);
			return 0;
		}
		else {
			Student * n = new Student;
			n->setName(name);
			n->setCode(code);
			p->setNext(n);
			p = n;
			if (n != 0) {
				return 0;
			}
			else {
				return -2;
			}
		}
	}
}
Student * Student::FindCode(int code){
	Student * p = this;
	bool Isfound = false;
	while (true) {
		if (p->getNext() != 0) {
			if (p->getCode() == code) {
				Isfound = true;
				break;
			}
			else {
				p = p->getNext();
			}
		}
		else {
			if (p->getCode() == code) {
				Isfound = true;
				break;
			}
			else {
				break;
			}
		}
	}
	if (Isfound) {
		return p;
	}
	else {
		return 0;
	}
}
Student * Student::FindName(std::string name) {
	NameProcess(name);
	Student * first = new Student;
	Student * p = this;
	while (true) {
		if (p->getNext() != 0) {
			if (p->getName().compare(name) == 0) {
				first->AddStudent(name, p->getCode());
			}
			p = p->getNext();
		}
		else {
			if (p->getName().compare(name) == 0) {
				first->AddStudent(name, p->getCode());
			}
			break;
		}
	}
	if (first->getName().compare("") == 0 && first->getCode() == 0) {
		return 0;
	}
	else {
		return first;
	}
}
int Student::DeleteStudent(Student * p) {
	if (p == this) {
		if (p->getNext() != 0) {
			p->setName(p->getNext()->getName());
			p->setCode(p->getNext()->getCode());
			Student *tmp = p->getNext();
			p->setNext(p->getNext()->getNext());
			delete tmp;
		}
		else {
			p->setName("");
			p->setCode(0);
			p->setNext(0);
		}
	}
	else {
		if (p == LastPoint()) {
			Student * before = this;
			while (before->getNext() != p) {
				before = before->getNext();
			}
			delete p;
			before->setNext(0);
		}
		else {
			Student * before = this;
			while (before->getNext() != p) {
				before = before->getNext();
			}
			Student * after = p->getNext();
			before->setNext(after);
			delete p;
		}
	}
	return 0;
}
void Student::Release() {
	Student * p = this->getNext();
	while (true)
	{
		if (p->getNext() != 0) {
			Student *n = p->getNext();
			delete p;
			p = n;
		}
		else {
			delete p;
			break;
		}
	}
	this->setName("");
	this->setCode(0);
	this->setNext(0);
}
int Student::SaveToFile(std::string fname) {
	std::fstream f;
	f.open(fname, std::ios::out);
	if (f.fail()) {
		return -1;
	}
	else {
		Student *p = this;
		while (true)
		{
			if (p->getNext() != 0) {
				f << p->getName() << std::endl;
				f << p->getCode() << std::endl;
				p = p->getNext();
			}
			else {
				f << p->getName() << std::endl;
				f << p->getCode() << std::endl;
				break;
			}
		}
		f.close();
		return 0;
	}
}
int Student::AddFromFile(std::string fname) {
	std::fstream f;
	f.open(fname, std::ios::in);
	if (f.fail()) {
		return -1;
	}
	else {
		std::string name = "", scode = "";
		int code = 0;
		Student * p = this;
		while (std::getline(f,name)){
			std::getline(f, scode);
			code = StringToInt(scode);
			AddStudent(name, code);
		}
	}
	f.close();
	return 0;
}
int Student::ImportFromFile(std::string fname) {
	Release();
	return AddFromFile(fname);
}
void Student::SortList() {
	Student * p = this;
	while (p->getNext() != 0) {
		Student * q = p->getNext();
		while (true) {
			if (q->getNext() != 0) {
				if (q->getName().compare(p->getName()) < 0) {
					std::string tmp_name = q->getName();
					q->setName(p->getName());
					p->setName(tmp_name);
					int tmp_code = q->getCode();
					q->setCode(p->getCode());
					p->setCode(tmp_code);
				}
				q = q->getNext();
			}
			else {
				if (q->getName().compare(p->getName()) < 0) {
					std::string tmp_name = q->getName();
					q->setName(p->getName());
					p->setName(tmp_name);
					int tmp_code = q->getCode();
					q->setCode(p->getCode());
					p->setCode(tmp_code);
				}
				break;
			}
		}
		p = p->getNext();
	}
}