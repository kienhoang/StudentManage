#include "StringProcess.h"

void Trim_left(std::string &c)
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
int StringToInt(std::string &s) {
	const char* c_s = s.c_str();
	return atoi(c_s);
	delete[] c_s;
}
bool IsIn(std::string &str,std::string &substr) {
	if (substr.length() > str.length()) {
		return false;
	}
	else {
		int i = 0;
		bool isTrue = true;
		while (i <=(int) (str.length()-substr.length())) {
			isTrue = true;
			for (int j = 0; j <(int) substr.length(); j++) {
				if (substr[j] != str[i + j]) {
					isTrue = false;
					break;
				}
			}
			if (isTrue) {
				break;
			}
			else {
				i++;
			}
		}
		return isTrue;
	}
}
void Seperate(std::string & name, std::string & firstname, std::string & lastname){
	int i = name.length() - 1;
	lastname = "";
	firstname = "";
	while (name[i] != ' ') {
		lastname = lastname + name[i];
		i--;
		if (i < 0) {
			break;
		}
	}
	for (i = 0; i < (int)(name.length() - lastname.length() - 1); i++) {
		firstname = firstname + name[i];
	}
	std::string reserver="";
	for (i =(int) lastname.length() - 1; i >= 0; i--) {
		reserver = reserver + lastname[i];
	}
	lastname = reserver;
}
std::string CharToString(char ch[]) {
	std::string s = "";
	int i = 0;
	while (ch[i] != 0) {
		s = s + ch[i];
		i++;
	}
	return s;
}