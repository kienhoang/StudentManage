#include "Student.h"

Student::Student(){
	firstname_ = "";
	lastname_ = "";
	code_ = 0;
	next_ = 0;
}
Student::~Student(){
}
void Student::setName(std::string &firstname, std::string &lastname) {
	NameProcess(firstname);
	NameProcess(lastname);
	firstname_ = firstname;
	lastname_ = lastname;
}
void Student::setName(const std::string &firstname, const std::string &lastname) {
	firstname_ = firstname;
	lastname_ = lastname;
}
std::string Student::getFirstName() {
	return firstname_;
}
std::string Student::getLastName() {
	return lastname_;
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

int Student::AddStudent(std::string &FirstName,std::string &LastName, int code) {
	NameProcess(FirstName);
	NameProcess(LastName);

	if (FindCode(code) != 0 || code <=0 ) {
		return -1;
	}
	else {
		Student * p = LastPoint();
		if (this->getFirstName().compare("") == 0 && this->getCode() == 0 && this->getLastName().compare("") == 0) {
			this->setName(FirstName,LastName);
			this->setCode(code);
			return 0;
		}
		else {
			Student * n = new Student;
			n->setName(FirstName, LastName);
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
int Student::AddStudent(const std::string &FirstName, const std::string &LastName, int code) {
	if (FindCode(code) != 0 || code <= 0) {
		return -1;
	}
	else {
		Student * p = LastPoint();
		if (this->getFirstName().compare("") == 0 && this->getCode() == 0 && this->getLastName().compare("") == 0) {
			this->setName(FirstName, LastName);
			NameProcess(this->firstname_);
			NameProcess(this->lastname_);
			this->setCode(code);
			return 0;
		}
		else {
			Student * n = new Student;
			n->setName(FirstName, LastName);
			NameProcess(n->firstname_);
			NameProcess(n->firstname_);
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
int Student::DeleteStudent(Student * p) {
	if (p == this) {
		if (p->getNext() != 0) {
			p->setName(p->getNext()->getFirstName(), p->getNext()->getLastName());
			p->setCode(p->getNext()->getCode());
			Student *tmp = p->getNext();
			p->setNext(p->getNext()->getNext());
			delete tmp;
		}
		else {
			p->setName("","");
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
	if (p != 0) {
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
	}
	this->setName("","");
	this->setCode(0);
	this->setNext(0);
}
int Student::SaveToFile(const std::string &fname) {
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
				f << p->getFirstName() << std::endl;
				f << p->getLastName() << std::endl;
				f << p->getCode() << std::endl;
				p = p->getNext();
			}
			else {
				f << p->getFirstName() << std::endl;
				f << p->getLastName() << std::endl;
				f << p->getCode() << std::endl;
				break;
			}
		}
		f.close();
		return 0;
	}
}
int Student::SaveToFile(std::string &fname) {
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
				f << p->getFirstName() << std::endl;
				f << p->getLastName() << std::endl;
				f << p->getCode() << std::endl;
				p = p->getNext();
			}
			else {
				f << p->getFirstName() << std::endl;
				f << p->getLastName() << std::endl;
				f << p->getCode() << std::endl;
				break;
			}
		}
		f.close();
		return 0;
	}
}
int Student::AddFromFile(const std::string &fname) {
	std::fstream f;
	f.open(fname, std::ios::in);
	if (f.fail()) {
		return -1;
	}
	else {
		std::string firstname = "",lastname="", scode = "";
		int code = 0;
		Student * p = this;
		while (std::getline(f, firstname)){
			std::getline(f, lastname);
			std::getline(f, scode);
			code = StringToInt(scode);
			AddStudent(firstname, lastname, code);
		}
	}
	f.close();
	return 0;
}
int Student::AddFromFile(std::string &fname) {
	std::fstream f;
	f.open(fname, std::ios::in);
	if (f.fail()) {
		return -1;
	}
	else {
		std::string firstname = "", lastname = "", scode = "";
		int code = 0;
		Student * p = this;
		while (std::getline(f, firstname)) {
			std::getline(f, lastname);
			std::getline(f, scode);
			code = StringToInt(scode);
			AddStudent(firstname, lastname, code);
		}
	}
	f.close();
	return 0;
}
int Student::ImportFromFile(const std::string &fname) {
	Release();
	return AddFromFile(fname);
}
int Student::ImportFromFile(std::string &fname) {
	Release();
	return AddFromFile(fname);
}
void Student::SortList(int mode) {
	Student * p = this;
	switch (mode)
	{
	case 1:
		while (p->getNext() != 0) {
			Student * q = p->getNext();
			while (true) {
				if (q->getNext() != 0) {
					if (q->getLastName().compare(p->getLastName()) < 0) {
						std::string tmp_lastname = q->getLastName();
						std::string tmp_firstname = q->getFirstName();
						q->setName(p->getFirstName(),p->getLastName());
						p->setName(tmp_firstname, tmp_lastname);
						int tmp_code = q->getCode();
						q->setCode(p->getCode());
						p->setCode(tmp_code);
					}
					q = q->getNext();
				}
				else {
					if (q->getLastName().compare(p->getLastName()) < 0) {
						std::string tmp_lastname = q->getLastName();
						std::string tmp_firstname = q->getFirstName();
						q->setName(p->getFirstName(), p->getLastName());
						p->setName(tmp_firstname, tmp_lastname);
						int tmp_code = q->getCode();
						q->setCode(p->getCode());
						p->setCode(tmp_code);
					}
					break;
				}
			}
			p = p->getNext();
		}
		break;
	case 2:
		while (p->getNext() != 0) {
			Student * q = p->getNext();
			while (true) {
				if (q->getNext() != 0) {
					if (q->getCode() < p->getCode()) {
						std::string tmp_lastname = q->getLastName();
						std::string tmp_firstname = q->getFirstName();
						q->setName(p->getFirstName(), p->getLastName());
						p->setName(tmp_firstname, tmp_lastname);
						int tmp_code = q->getCode();
						q->setCode(p->getCode());
						p->setCode(tmp_code);
					}
					q = q->getNext();
				}
				else {
					if (q->getCode() < p->getCode()) {
						std::string tmp_lastname = q->getLastName();
						std::string tmp_firstname = q->getFirstName();
						q->setName(p->getFirstName(), p->getLastName());
						p->setName(tmp_firstname, tmp_lastname);
						int tmp_code = q->getCode();
						q->setCode(p->getCode());
						p->setCode(tmp_code);
					}
					break;
				}
			}
			p = p->getNext();
		}
		break;
	default:
		break;
	}
}

Student * Student::FindCode(int code) {
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
Student * Student::FindName(std::string &name) {
	NameProcess(name);
	Student * first = new Student;
	Student * p = this;
	while (true) {
		if (p->getNext() != 0) {
			if (IsIn(p->getFirstName(), name) || IsIn(p->getLastName(), name)
				|| IsIn(p->getFirstName()+" "+p->getLastName(),name)) {
				first->AddStudent(p->getFirstName(), p->getLastName(), p->getCode());
			}
			p = p->getNext();
		}
		else {
			if (IsIn(p->getFirstName(), name) || IsIn(p->getLastName(), name) 
				|| IsIn(p->getFirstName() + " " + p->getLastName(), name)) {
				first->AddStudent(p->getFirstName(), p->getLastName(), p->getCode());
			}
			break;
		}
	}
	if (first->getFirstName().compare("") == 0 && first->getCode() == 0
		&& first->getLastName().compare("") == 0) {
		return 0;
	}
	else {
		return first;
	}
}
Student * Student::FindName(const std::string &name) {
	std::string pName = name;
	NameProcess(pName);
	Student * first = new Student;
	Student * p = this;
	while (true) {
		if (p->getNext() != 0) {
			if (IsIn(p->getFirstName(), pName) || IsIn(p->getLastName(), pName)) {
				first->AddStudent(p->getFirstName(), p->getLastName(), p->getCode());
			}
			p = p->getNext();
		}
		else {
			if (IsIn(p->getFirstName(), pName) || IsIn(p->getLastName(), pName)) {
				first->AddStudent(p->getFirstName(), p->getLastName(), p->getCode());
			}
			break;
		}
	}
	if (first->getFirstName().compare("") == 0 && first->getCode() == 0
		&& first->getLastName().compare("") == 0) {
		return 0;
	}
	else {
		return first;
	}
}
Student * Student::LastPoint() {
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