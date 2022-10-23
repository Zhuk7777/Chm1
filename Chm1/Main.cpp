#include"Matrix.h"
#include"Vector.h"
#include"System.h"
#include<ctime>

int main()
{
	setlocale(0, "rus");
	std::string path = "MyFile.txt", path2 = "MyFile2.txt";

	int size = 8;

	std::cout << "Введите значение k\n";
	int k;
	std::cin >> k;
	System syst(size,k);

	Vector xBefore(size);
	Vector xNow(size);
	Vector diff(size);
	Vector f(size);

	std::cout << "Размер матрицы     Погрешность\n";
	srand(time(NULL));
	for (int i = 0; i < 8; i++)
	{
		System syst(size, k);

		Vector xBefore(size);
		Vector xNow(size);
		Vector diff(size);
		Vector f(size);

		syst.randomFillVecA(20, 25);
		syst.randomFillVecB(300, 400);
		syst.randomFillVecC(20, 25);
		syst.randomFillVecP(30, 40);
		syst.randomFillVecQ(30, 40);

		//syst.matrPrint();

		xBefore.randomFill(4, 100);
		f = syst.multipliByVectorOnRight(xBefore, size);
		syst.fillVecFFromVec(f);
		
		try {
			xNow = syst.solution();
		}
		catch(const char* ex)
		{
			std::cout << ex << "\n";
		}
		
		diff = xNow.differenceVec(xBefore);
		//xBefore.printVec();
		//xNow.printVec();
		//std::cout << "Погрешность равна " << diff.normOfVec() << "\n\n";
		std::cout << "    " << size << "        " << diff.normOfVec() << "\n";
		size *= 2;
	}

	return 0;
}