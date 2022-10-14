#pragma once
#include"Matrix.h"

class System : public Matrix
{
	Vector f;

	void accordance(int i)
	{
		//для k-го столбца
		if (i == size + 1 - k)
			b[i] = p[i];
		if (i == size - k)
			c[i] = p[i];
		if (i == size + 2 - k)
			a[i] = p[i];

		//для к+1-го столбца
		if (i == size - k)
			b[i] = q[i];
		if (i == size - k - 1)
			c[i] = q[i];
		if (i == size + 1 - k)
			a[i] = q[i];

	}

public:
	System(int _size, int _k) :Matrix(_size, _k)
	{
		f.setSize(size);
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

	void systemTransformation()
	{
		double r = 0.0;

		for (int i = 1; i <= size - k; i++)//шаг 1
		{
			r = 1 / b[i];
			b[i] = 1;
			c[i] = r * c[i];
			q[i] = r * q[i];
			p[i] = r * p[i];
			f[i] = r * f[i];

			accordance(i);

			r = a[i + 1];
			a[i + 1] = 0;
			b[i + 1] = b[i + 1] - r * c[i];
			q[i + 1] = q[i + 1] - r * q[i];
			p[i + 1] = p[i + 1] - r * p[i];
			f[i + 1] = f[i + 1] - r * f[i];

			accordance(i + 1);


			if (i == size - k)//bi пересекает K+1-ый столбец(вектор q)
			{

				for (int j = 1; j <= size; j++)
				{
					if (j == i)
						continue;
					r = q[j];
					q[j] = 0;
					p[j] = p[j] - c[i] * r;
					f[j] = f[j] - f[i] * r;

					accordance(j);

				}
			}
		}

		for (int i = size; i >= size + 1 - k; i--)//шаг2
		{
			r = 1 / b[i];
			b[i] = 1;
			a[i] = r * a[i];
			q[i] = r * q[i];
			p[i] = r * p[i];
			f[i] = r * f[i];

			accordance(i);

			r = c[i - 1];
			c[i - 1] = 0;
			b[i - 1] = b[i - 1] - r * a[i];
			p[i - 1] = p[i - 1] - r * p[i];
			q[i - 1] = q[i - 1] - r * q[i];
			f[i - 1] = f[i - 1] - r * f[i];

			accordance(i + 1);

			if (i == size + 1 - k)//bi пересекает k-ый столбец(вектор p)
			{

				for (int j = 1; j <=size; j++)
				{
					if (j == i)
						continue;

					r = p[j];
					p[j] = 0;
					f[j] = f[j] - r * f[i];

					accordance(j);

				}
			}
		}

	}

	Vector solution()
	{
		systemTransformation();
		Vector x(size);
		x[k] = f[size + 1 - k];

		for (int i = k + 1; i <= size; i++)
		{
			x[i] = f[size + 1 - i] - c[size + 1 - i] * x[i - 1];
		}

		for (int i = k - 1; i >= 1; i--)
		{
			x[i] = f[size + 1 - i] - a[size + 1 - i] * x[i + 1];
		}

		return x;
	}
};
