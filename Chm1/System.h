#pragma once
#include"Matrix.h"

class System : public Matrix
{
	Vector f;

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
			std::cout << "������ �������� �����\n";
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

	void solution()
	{
		double r;

		for (int i = 1; i <= size + 1 - k - 1; i++)//��� 1
		{
			r = 1 / b[i];
			b[i] = 1;
			c[i] = r * c[i];
			f[i] = r * f[i];

			r = a[i + 1];
			a[i + 1] = 0;
			b[i + 1] = b[i + 1] - r * c[i];
			f[i + 1] = f[i + 1] - r * f[i];

			if (i == size + 1 - k - 1)//bi ���������� K+1-�� �������(������ q)
			{
				q[i] = 1;
				if (i != 1)
					c[i - 1] = 0;
				q[i + 1] = 0;

				for (int j = 1; j <=size; j++)
				{
					if (j == i)
						continue;
					r = q[j];
					q[j] = 0;
					//p[j] = p[j] - c[i] * r;
					f[j] = f[j] - f[i] * r;

				}
			}
		}

		for (int i = size; i >= size + 1 - k; i--)//���2
		{
			r = 1 / b[i];
			b[i] = 1;
			a[i] = r * a[i];
			f[i] = r * f[i];

			r = c[i - 1];
			c[i - 1] = 0;
			b[i - 1] = b[i - 1] - r * a[i];
			f[i - 1] = f[i - 1] - r * f[i];

			if (i == size + 1 - k)//bi ���������� k-�� �������(������ p)
			{
				p[i] = 1;
				p[i - 1] = 0;
				if (i != size)
					a[i + 1] = 0;

				for (int j = 1; j <=size; j++)
				{
					if (j == i)
						continue;

					r = p[j];
					p[j] = 0;
					f[j] = f[j] - r * f[i];

				}
			}
		}
	}
};
