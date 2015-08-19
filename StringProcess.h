#pragma once
#include <string>
#include <stdlib.h> 

void Trim_left(std::string &c);
void Trim_right(std::string &c);
void Trim(std::string &c);
void ToLowerString(std::string &c);
void UpcaseFirstSpace(std::string &c);
void NameProcess(std::string &c);
int StringToInt(std::string &s);
bool IsIn(std::string &str, std::string &substr);