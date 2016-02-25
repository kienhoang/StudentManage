mkdir Release
g++ -std=c++11 -c StringProcess.cpp -fpic
g++ -std=c++11 -shared -o Release/StringProcess.dll StringProcess.o
g++ -std=c++11 -c Student.cpp -fpic
g++ -std=c++11 -shared -o Release/Student.dll -L. -lStringProcess  Student.o
g++ -std=c++11 -c StudentConsole.cpp -fpic
g++ -std=c++11 -shared -o Release/StudentConsole.dll -L. -lStudent -lStringProcess StudentConsole.o
g++ -std=c++11 -o Release/StudentManagement -L. Main.cpp -lStudentConsole