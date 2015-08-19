#include "StudentConsole.h"

StudentConsole::StudentConsole(){
}
StudentConsole::~StudentConsole(){
}

int StudentConsole::Menu_console() {
	std::cout << "============MENU===========" << std::endl;
	std::cout << "  1. Add A student" << std::endl;
	std::cout << "  2. View list" << std::endl;
	std::cout << "  3. Sort List ->" << std::endl;
	std::cout << "  4. Find Student ->" << std::endl;
	std::cout << "  5. Delete Student ->" << std::endl;
	std::cout << "  6. Save List to File" << std::endl;
	std::cout << "  7. Add List from File" << std::endl;
	std::cout << "  8. Import from File" << std::endl;
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
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstname);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastname);
	std::cout << "Enter code: ";
	std::cin >> code;
	std::cin.ignore(1);
	switch (this->AddStudent(firstname, lastname, code))
	{
	case 0:
		std::cout << "Done. " << std::endl;
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
void StudentConsole::viewlist_console() {
	if (this->getFirstName().compare("") && this->getCode() == 0 && this->getLastName().compare("")) {
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