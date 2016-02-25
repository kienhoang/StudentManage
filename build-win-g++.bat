g++ -std=c++11 -c StringProcess.cpp -fpic
g++ -std=c++11 -shared -o StringProcess.dll StringProcess.o
g++ -std=c++11 -c Student.cpp -fpic
g++ -std=c++11 -shared -o Student.dll -L. -lStringProcess  Student.o
g++ -std=c++11 -c StudentConsole.cpp -fpic
g++ -std=c++11 -shared -o StudentConsole.dll -L. -lStudent -lStringProcess StudentConsole.o
g++ -std=c++11 -o StudentManagement -L. Main.cpp -lStudentConsole