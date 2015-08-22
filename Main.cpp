#include <iostream>
#include "StudentConsole.h"

int main(int argc, char **argv) {
	StudentConsole student;
	switch (argc){
	case 1:
		student.start_console();
		break;
	case 2:
		student.OpenList_console(argv[1]);
		student.start_console();
		break;
	default:
		for (int i = 1; i < argc; i++) {
			student.AddList_console(argv[i]);
		}
		student.start_console();
		break;
	}
	return 0;
}