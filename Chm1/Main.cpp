#include"Matrix.h"
#include"Vector.h"

int main()
{
	setlocale(0, "rus");
	std::string path = "MyFile.txt";
	Vector a(5);
	a.fillFromFile(path);
	a.printVec();
	a.fill();
	a.outputToFile(path);
	a.fillFromFile(path);
	a.printVec();
	return 0;
}