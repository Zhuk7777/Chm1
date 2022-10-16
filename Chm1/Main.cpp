#include"Matrix.h"
#include"Vector.h"
#include"System.h"
#include<ctime>

int main()
{
	setlocale(0, "rus");
	std::string path = "MyFile.txt", path2 = "MyFile2.txt";

	std::cout << "������� ����������� �������\n";
	int size;
	std::cin >> size;

	std::cout << "������� �������� k\n";
	int k;
	std::cin >> k;
	System syst(size,k);

	std::cout << "������� ������� ���������� �� �������� ����� �������������� �������� ��������� ������� � ������� X\n";
	int left, right;
	std::cin >> left;
	std::cin >> right;
	Vector xBefore(size);
	Vector xNow(size);
	Vector diff(size);
	Vector f(size);


	std::cout << "������� ���������� ��������\n";
	int count;
	std::cin >> count;

	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		syst.matrFillRandom(left, right);
		xBefore.randomFill(left, right);
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
		xBefore.printVec();
		xNow.printVec();
		std::cout << "����������� ����� " << diff.normOfVec() << "\n\n";
	}

	return 0;
}