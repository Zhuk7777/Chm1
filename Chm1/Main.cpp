#include"Matrix.h"
#include"Vector.h"
#include"System.h"

int main()
{
	setlocale(0, "rus");

	std::string path = "MyFile.txt", path2 = "MyFile2.txt";

	System a(7, 2), b(7, 2);
	Vector x(7);

	a.fillVecFFromFile(path2);
	a.matrFillFromFile(path);
	b.matrFillFromFile(path);

	a.matrPrint();
	x = a.solution();
	a.matrPrint();
	b.multipliByVectorOnRight(x, x.getSize());
	b.matrPrint();
	return 0;
}