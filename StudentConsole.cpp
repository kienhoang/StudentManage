#include "StudentConsole.h"

StudentConsole::StudentConsole() {
	isSave_ = true;
	fname_ = "";
}
StudentConsole::StudentConsole(Student * student) {
	if (student == 0) {
		setName("", "");
		setCode(0);
		setNext(0);
	}
	else {
		setName(student->getFirstName(), student->getLastName());
		setCode(student->getCode());
		setNext(student->getNext());
		fname_ = "";
		isSave_ = false;
	}
}
StudentConsole::~StudentConsole(){
}

int StudentConsole::Menu_console() {
	std::cout << "============MENU===========" << std::endl;
	std::cout << "  1. Add A student" << std::endl;
	std::cout << "  2. View list" << std::endl;
	std::cout << "  3. Sort List ->" << std::endl;
	std::cout << "  4. Find Student ->" << std::endl;
	std::cout << "  5. Edit Student ->" << std::endl;
	std::cout << "  6. Delete Student ->" << std::endl;
	std::cout << "  7. Save List to File ->" << std::endl;
	std::cout << "  8. Add List from File" << std::endl;
	std::cout << "  9. Open List From File" << std::endl;
	std::cout << " 10. Close List." << std::endl;
	std::cout << "  0. Exit" << std::endl;
	std::cout << std::endl << "Input your choice: ";
	int c = 0;
	std::cin >> c;
	std::cin.ignore(1);
	return c;
}
int StudentConsole::FindMenu_console() {
	std::cout << "=========Find Menu=========" << std::endl;
	std::cout << "  1. Find by Name" << std::endl;
	std::cout << "  2. Find by Code" << std::endl;
	std::cout << "  0. Back to Main Menu" << std::endl;
	std::cout << std::endl << "Input your choice: ";
	int c = 0;
	std::cin >> c;
	std::cin.ignore(1);
	return c;
}
int StudentConsole::SortListMenu_console() {
	std::cout << "=========Sort Menu=========" << std::endl;
	std::cout << "  1. Sort by Name" << std::endl;
	std::cout << "  2. Sort by Code" << std::endl;
	std::cout << "  0. Back to Main Menu" << std::endl;
	std::cout << std::endl << "Input your choice: ";
	int c = 0;
	std::cin >> c;
	std::cin.ignore(1);
	return c;
}
int StudentConsole::DeleteMenu_console() {
	std::cout << "========Delete Menu========" << std::endl;
	std::cout << "  1. Delete by Name" << std::endl;
	std::cout << "  2. Delete by Code" << std::endl;
	std::cout << "  0. Back to Main Menu" << std::endl;
	std::cout << std::endl << "Input your choice: ";
	int c = 0;
	std::cin >> c;
	std::cin.ignore(1);
	return c;
}
int StudentConsole::SaveMenu_console() {
	std::cout << "=========Save Menu=========" << std::endl;
	std::cout << "  1. Save" << std::endl;
	std::cout << "  2. Save As" << std::endl;
	std::cout << "  0. Back to Main Menu" << std::endl;
	std::cout << std::endl << "Input your choice: ";
	int c = 0;
	std::cin >> c;
	std::cin.ignore(1);
	return c;
}
int StudentConsole::EditMenu_console() {
	std::cout << "=========Edit Menu=========" << std::endl;
	std::cout << "  1. Edit Name" << std::endl;
	std::cout << "  2. Edit Code" << std::endl;
	std::cout << "  3. OK" << std::endl;
	std::cout << "  4. Cancel" << std::endl;
	std::cout << std::endl << "Input your choice: ";
	int c = 0;
	std::cin >> c;
	std::cin.ignore(1);
	return c;
}

void StudentConsole::AddStudent_console() {
	std::string firstname = "";
	std::string lastname = "";
	int code = 0;
	std::string name = "";
	std::cout << "Enter name: ";
	std::getline(std::cin, name);
	if (name.compare("") != 0) {
		Seperate(name, firstname, lastname);
		std::cout << "Enter code: ";
		std::cin >> code;
		std::cin.ignore(1);
		switch (this->AddStudent(firstname, lastname, code))
		{
		case 0:
			std::cout << "Done. " << std::endl;
			isSave_ = false;
			break;
		case -1:
			std::cout << "ERROR: Code is exist." << std::endl;
			break;
		case 2:
			std::cout << "Cannot access memory. Check your memory." << std::endl;
			break;
		default:
			break;
		}
	}
	else {
		std::cout << "Canceled." << std::endl;
	}
}
void StudentConsole::ViewList_console() {
	std::cout << "========Result List========" << std::endl;
	if (getFirstName().compare("") == 0 && getCode() == 0 && getLastName().compare("") == 0) {
		std::cout << "List Empty." << std::endl;
	}
	else {
		Student *p = this;
		while (true) {
			if (p->getNext() != 0) {
				std::cout << p->getFirstName() <<" "<< p->getLastName() << " | " << p->getCode() << std::endl;
				p = p->getNext();
			}
			else {
				std::cout << p->getFirstName() <<" "<< p->getLastName() << " | " << p->getCode() << std::endl;
				break;
			}
		}
	}
}
void StudentConsole::SortList_console() {
	switch (SortListMenu_console())
	{
	case 1:
		SortList(1);
		std::cout << "Done." << std::endl;
		isSave_ = false;
		break;
	case 2:
		SortList(2);
		std::cout << "Done." << std::endl;
		isSave_ = false;
	case 0:
		break;
	default:
		std::cout << "ERROR: You have enter invalid option. Back to Main Menu." << std::endl;
		break;
	}
}
void StudentConsole::Find_console() {
	Student * p = 0;
	StudentConsole  * ps = 0;
	std::string name = "";
	int code = 0;
	switch (FindMenu_console())
	{
	case 1:
		std::cout << "Enter name or subname to Search: ";
		std::getline(std::cin, name);
		NameProcess(name);
		p = FindName(name);
		ps = new StudentConsole(p);
		ps->ViewList_console();
		break;
	case 2:
		std::cout << "Enter code to Search: ";
		std::cin >> code;
		std::cin.ignore(1);
		p = FindCode(code);
		std::cout << "========Result List========" << std::endl;
		if (p == 0) {
			std::cout << "<Not Found>" << std::endl;
		}
		else {
			std::cout << p->getFirstName() << " " << p->getLastName() << " | " << p->getCode() << std::endl;
		}
		break;
	case 0:
		break;
	default:
		std::cout << "ERROR: You have enter invalid option. Back to Main Menu." << std::endl;
		break;
	}
}
void StudentConsole::Delete_console() {
	std::string name = "";
	int code = 0;
	StudentConsole * p = 0, *q = 0;
	switch (DeleteMenu_console())
	{
	case 1:
		std::cout << "Enter name to Delete: ";
		std::getline(std::cin, name);
		NameProcess(name);
		p = new StudentConsole(FindName(name));
		p->ViewList_console();
		std::cout << "Enter code of Student in in that list to delete: ";
		std::cin >> code;
		std::cin.ignore(1);
		if (p->FindCode(code) != 0) {
			Student *q = FindCode(code);
			std::string tmpname = q->getFirstName() + " " + q->getLastName();
			int tmpcode = q->getCode();
			DeleteStudent(q);
			std::cout << "Deleted " << tmpname << " | " << tmpcode <<"."<< std::endl;
			isSave_ = false;
		}
		else {
			std::cout << "ERROR: You have entered invalid code" << std::endl;
		}
		break;
	case 2:
		std::cout << "Enter code of Student to delete: ";
		std::cin >> code;
		std::cin.ignore(1);
		if (FindCode(code) != 0) {
			Student *q = FindCode(code);
			std::string tmpname = q->getFirstName() + " " + q->getLastName();
			int tmpcode = q->getCode();
			DeleteStudent(q);
			std::cout << "Deleted " << tmpname << " | " << tmpcode << "."<<std::endl;
			isSave_ = false;
		}
		else {
			std::cout << "ERROR: You have entered invalid code. " << std::endl;
		}
		break;
	default:
		break;
	}
}
void StudentConsole::Edit_console(){
	int code;
	std::cout << "Enter code of Student to edit: ";
	std::cin >> code;
	std::cin.ignore(1);
	Student * p = FindCode(code);
	if (p == 0) {
		std::cout << "Code not found." << std::endl;
	}
	else {
		bool isEdit = false;
		int newcode = p->getCode();
		int tmpcode = 0;
		std::string newnfirstname = p->getFirstName();
		std::string newlastname = p->getLastName();
		std::string newname = newnfirstname + newlastname;
		bool t = true;
		std::cout << "Edit infomation of Student :" << std::endl;
		std::cout << "Name='" << p->getFirstName() << " " << p->getLastName() << "'" << std::endl;
		std::cout << "Code=" << p->getCode() << std::endl;
		while (t) {
			switch (EditMenu_console())
			{
			case 1:
				std::cout << "Enter new Name of Student: ";
				std::getline(std::cin, newname);
				NameProcess(newname);
				Seperate(newname, newnfirstname, newlastname);
				break;
			case 2:
				std::cout << "Enter new Code of Student: ";
				std::cin >> tmpcode;
				std::cin.ignore(1);
				if (FindCode(tmpcode) == 0) {
					newcode = tmpcode;
				}
				else {
					std::cout << "ERROR: You have entered an exist code." << std::endl;
				}
				break;
			case 3:
				isSave_ = false;
				t = false;
				isEdit = true;
				break;
			case 4:
				t = false;
				isEdit = false;
				break;
			default:
				break;
			}
			std::cout << "New name: " << newname << std::endl;
			std::cout << "New code: " << newcode << std::endl;
		}
		if (isEdit) {
			p->setName(newnfirstname, newlastname);
			p->setCode(newcode);
		}
	}
}
void StudentConsole::PrintErrorList(Student * &error, std::string &fname){
	if(error->getFirstName().compare("") != 0 || error->getLastName().compare("") !=0 
		|| error->getCode() != 0) {
		std::cout << "**ERROR List on '"<<fname <<"'"<< " Code may be exist on before list :"<< std::endl;
		while (true) {
			if (error->getNext() != 0) {
				std::cout <<"E: "<< error->getFirstName() << " " << error->getLastName() << " | " 
					<< error->getCode() << std::endl;
				error = error->getNext();
			}
			else {
				std::cout << "E: " << error->getFirstName() << " " << error->getLastName()
					<< " | " << error->getCode() << std::endl;
				break;
			}
		}
	}
}
void StudentConsole::Save_console() {
	std::string fname = "";
	switch (SaveMenu_console())
	{
	case 1:
		if (fname_.compare("") == 0) {
			std::cout << "Enter file name to save: ";
			std::getline(std::cin, fname);
			if (SaveToFile(fname) == 0) {
				std::cout << "Done. Saved to "<< fname << std::endl;
				fname_ = fname;
				isSave_ = true;
			}
			else {
				std::cout << "ERROR: Failed to save." << std::endl;
			}
		}
		else {
			if (SaveToFile(fname_) == 0) {
				std::cout << "Done. Saved to " << fname_ << std::endl;
				isSave_ = true;
			}
			else {
				std::cout << "ERROR: Failed to save." << std::endl;
			}
		}
		break;
	case 2:
		std::cout << "Enter file name to save: ";
		std::getline(std::cin, fname);
		if (SaveToFile(fname) == 0) {
			std::cout << "Done. Saved to " << fname << std::endl;
			fname_ = fname;
			isSave_ = true;
		}
		else {
			std::cout << "ERROR: Failed to save." << std::endl;
		}
		break;
	default:
		break;
	}
}
void StudentConsole::AddList_console() {
	std::string fname = "";
	Student * error = new Student;
	std::cout << "Enter file name to add list: ";
	std::getline(std::cin, fname);
	if (AddFromFile(fname, error) == 0) {
		std::cout << "Added List." << std::endl;
		PrintErrorList(error,fname);
		isSave_ = false;
	}
	else {
		std::cout << "ERROR: Failed to open file " << fname << std::endl;
	}
}
void StudentConsole::AddList_console(char * path){
	std::string fname = CharToString(path);
	Student * error = new Student;
	if (AddFromFile(fname,error) == 0) {
		std::cout << "Added List from " << fname << std::endl;
		PrintErrorList(error,fname);
		isSave_ = false;
	}
	else {
		std::cout << "ERROR: Failed to open file " << fname << std::endl;
	}
}
void StudentConsole::OpenList_console() {
	if (isSave_ == false) {
		std::cout << "Current List is not saved. Do you want to save it (Y/n) ??";
		char cofirm;
		std::cin >> cofirm;
		std::cin.ignore(1);
		std::string fname;
		if (cofirm == 'y' || cofirm == 'Y') {
			if (fname_.compare("") == 0) {
				std::cout << "Enter file name to save: ";
				std::getline(std::cin, fname);
				if (SaveToFile(fname) == 0) {
					std::cout << "Done. Saved to " << fname << std::endl;
				}
				else {
					std::cout << "ERROR: Failed to save." << std::endl;
				}
			}
			else {
				if (SaveToFile(fname_) == 0) {
					std::cout << "Done. Saved to " << fname_ << std::endl;
				}
				else {
					std::cout << "ERROR: Failed to save." << std::endl;
				}
			}
		}
	}
	fname_ = "";
	std::string fname = "";
	Student * error = new Student;
	std::cout << "Enter file name to Open: ";
	std::getline(std::cin, fname);
	if (ImportFromFile(fname, error) == 0) {
		std::cout << "Done. Open from " << fname << std::endl;
		PrintErrorList(error,fname);
		fname_ = fname;
		isSave_ = true;
	}
	else {
		std::cout << "ERROR: Fail to open " << fname << std::endl;
	}
}
void StudentConsole::OpenList_console(char * path){
	fname_ = "";
	Student * error = new Student;
	std::string fname = CharToString(path);
	if (ImportFromFile(fname, error) == 0) {
		std::cout << "Done. Open from " << fname << std::endl;
		PrintErrorList(error,fname);
		fname_ = fname;
		isSave_ = true;
	}
	else {
		std::cout << "ERROR: Fail to open " << fname << std::endl;
	}
}
void StudentConsole::CloseList_console() {
	if (isSave_ == false) {
		std::cout << "List is not save. Are you want to save? (Y/n)";
		std::string fname="";
		switch (getchar())
		{
		case 'y':
		case 'Y':
			if (fname_.compare("") == 0) {
				std::cout << "Enter file name to save: ";
				std::getline(std::cin, fname);
				if (SaveToFile(fname) == 0) {
					std::cout << "Done. Saved to " << fname << std::endl;
					fname_ = fname;
				}
				else {
					std::cout << "ERROR: Failed to save." << std::endl;
				}
			}
			else {
				if (SaveToFile(fname_) == 0) {
					std::cout << "Done. Saved to " << fname_ << std::endl;
				}
				else {
					std::cout << "ERROR: Failed to save." << std::endl;
				}
			}
			break;
		default:
			break;
		}
	}
	isSave_ = true;
	std::cout << "Close." << std::endl;
	Release();
}

void StudentConsole::start_console() {
	bool t = true;
	while (t) {
		switch (Menu_console())
		{
		case 1:
			AddStudent_console();
			break;
		case 2:
			ViewList_console();
			break;
		case 3:
			SortList_console();
			break;
		case 4:
			Find_console();
			break;
		case 5: 
			Edit_console();
			break;
		case 6:
			Delete_console();
			break;
		case 7:
			Save_console();
			break;
		case 8:
			AddList_console();
			break;
		case 9:
			OpenList_console();
			break;
		case 10:
			CloseList_console();
			break;
		case 0:
			CloseList_console();
			t = false;
			break;
		default:
			break;
		}
	}
}