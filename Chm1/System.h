#pragma once
#include"Matrix.h"

class System : public Matrix
{
	Vector f;

public:
	System(int _size, int _k) :Matrix(_size, _k)
	{
		f.setSize(_size);
	}

	void fillVecF()
	{
		f.fill();
	}
	void fillVecFFromFile(std::string path)
	{
		std::ifstream fin;
		fin.open(path);

		if (!fin.is_open())
		{
			std::cout << "Ошибка открытия файла\n";
			return;
		}

		f.fillFromFile(fin);
		fin.seekg(0, std::ios::beg);
		fin.close();

	}

	void printVecF()
	{
		f.printVec();
	}

	Vector solution()
	{
		double r;

		for (int i = 0; i < size; i++)
		{
			r = 1 / b[i];
			b[i] = 1;
			c[i] = r * c[i];
			f[i] = r * f[i];

			r = a[i + 1];
			a[i + 1] = 0;
			b[i + 1] = b[i + 1] - r * c[i];
			f[i + 1] = f[i + 1] - r * f[i];

			if (i = size + 1 - k - 1)//bi пересекает столбец к+1(вектор q)
			{
				for (int j = i; j < 1; j--)
				{

				}
			}
		}
	}
};
