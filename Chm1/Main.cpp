#include"Matrix.h"
#include"Vector.h"
#include"System.h"

int main()
{
	setlocale(0, "rus");

	std::string path = "MyFile.txt", path2 = "MyFile2.txt";
	System a(12, 4);//при втором значении=1/12 ошибки
	a.fillVecFFromFile(path2);
	a.matrFillFromFile(path);
	a.solution();
	a.matrPrint();
	a.printVecF();
	return 0;
}