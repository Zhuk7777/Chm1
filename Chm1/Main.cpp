#include"Vector.h"
#include "Matrix.h"

int main()
{
	setlocale(0, "rus");
	std::string path = "MyFile.txt";

	Matrix a(5, 1);
	a.matrFill();

	Vector b(5), c(5);

	b.fill();
	c = a.multipliByVectorOnLeft(b, b.getSize());

	c.printVec();

	//Vector v(3);


	return 0;
}