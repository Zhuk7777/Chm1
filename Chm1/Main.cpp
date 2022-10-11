#include"Matrix.h"
#include"Vector.h"
#include"System.h"

int main()
{
	setlocale(0, "rus");

	std::string path = "MyFile.txt", path2 = "MyFile2.txt";
	System a(12, 2);
	a.fillVecFFromFile(path2);
	a.matrFillFromFile(path);

	return 0;
}