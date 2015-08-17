#include "StringProcess.h"

void Trim_left(std::string & c)
{
	std::string s="";
	bool t = false;
	int j = 0;
	for (int i = 0; i < (int)c.length(); i++) {
		if (c[i] != ' ') {
			t = true;
		}
		if (t) {
			s = s + c[i];
		}
	}
	c = s;
}
void Trim_right(std::string &c) {
	std::string s = "";
	bool t = false;
	for (int i = (int)c.length() - 1; i >=0 ; i--) {
		if (c[i] != ' ') {
			t = true;
		}
		if (t) {
			s = s + c[i];
		}
	}
	c = "";
	for (int i = (int)s.length() - 1; i >= 0; i--) {
		c = c + s[i];
	}
}
void Trim(std::string &c) {
	Trim_left(c);
	Trim_right(c);
}
void ToLowerString(std::string &c) {
	for (int i = 0; i <(int)c.length(); i++) {
		c[i] = tolower(c[i]);
	}
}
void UpcaseFirstSpace(std::string &c)
{
	c[0] = toupper(c[0]);
	for (int i = 1; i < (int)c.length(); i++) {
		if (i != c.length() - 1) {
			if (c[i - 1] == ' ') {
				c[i] = toupper(c[i]);
			}
		}
	}
}
void NameProcess(std::string &c) {
	Trim(c);
	ToLowerString(c);
	UpcaseFirstSpace(c);
}
int StringToInt(std::string s) {
	const char* c_s = s.c_str();
	return atoi(c_s);
	delete[] c_s;
}
