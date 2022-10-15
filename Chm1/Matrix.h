#pragma once
#include"Vector.h"

class Matrix
{
protected:
	Vector c, a, b, p, q;
	int size = 0;
	int k = 0;

public:
	Matrix(int sizeMatr, int _k) :size(sizeMatr)
	{
		if (_k > size - 1)
			k = size - 1;
		else
			if (_k < 1)
				k = 1;
			else
				k = _k;

		a.setSize(size);
		b.setSize(size);
		c.setSize(size);
		p.setSize(size);
		q.setSize(size);
	}

	int getSizeMatr()
	{
		return size;
	}
	int getK()
	{
		return k;
	}

	void matrFill ()
	{
		a[1] = 0, c[size] = 0;

		std::cout << "Заполните верхнюю диагональ\n";
		for (int i = 1; i < size; i++)
			std::cin >> c[i];

		std::cout << "Заполните диагональ\n";
		for (int i = 1; i <= size; i++)
			std::cin >> b[i];

		std::cout << "Заполните нижнюю диагональ\n";
		for (int i = 2; i <= size; i++)
			std::cin >> a[i];

		std::cout << "Заполните k-ый столбец\n";
		for (int i = 1; i <= size; i++)
		{
			if (i == size + 1 - k)
				p[i] = b[i];
			else
				if (i == size - k)
					p[i] = c[i];
				else
					if (i == size + 2 - k)
						p[i] = a[i];
					else
					{
						std::cout << "Введите значение в " << i << "-ой строке\n";
						std::cin >> p[i];
					}
		}

		std::cout << "Заполните k+1 столбец\n";
		for (int i = 1; i <= size; i++)
		{
			if (i == size - k)
				q[i] = b[i];
			else
				if (i == size - k - 1)
					q[i] = c[i];
				else
					if (i == size + 1 - k)
						q[i] = a[i];
					else
					{
						std::cout << "Введите значение в " << i << "-ой строке\n";
						std::cin >> q[i];
					}
		}

	}
	void matrFillFromFile(std::string path)
	{
		std::ifstream fin;
		fin.open(path);

		if (!fin.is_open())
		{
			std::cout << "Ошибка открытия файла\n";
			return;
		}

		a.fillFromFile(fin);
		b.fillFromFile(fin);
		c.fillFromFile(fin);
		p.fillFromFile(fin);
		q.fillFromFile(fin);

		fin.seekg(0, std::ios::beg);
		fin.close();
	}
	void matrFillRandom(int left, int right)
	{
		a.randomFill(left, right);
		b.randomFill(left, right);
		c.randomFill(left, right);
		p.randomFill(left, right);
		q.randomFill(left, right);

		p[size + 1 - k] = b[size + 1 - k];
		p[size - k] = c[size - k];
		p[size + 2 - k] = a[size + 2 - k];

		q[size - k] = b[size - k];
		q[size - k - 1] = c[size - k - 1];
		q[size + 1 - k] = a[size + 1 - k];
	}

	void matrPrint()
	{
		for (int i = 1; i <= size; i++)
		{
			std::cout << "\n";

			for (int j = 1; j <= size; j++)
			{
				if (j == size - i)
					std::cout << c[i] << " ";
				else
					if (j == size + 1 - i)
						std::cout << b[i] << " ";
					else
						if (j == size + 2 - i)
							std::cout << a[i] << " ";
						else
							if (j == k)
								std::cout << p[i] << " ";
							else
								if (j == k + 1)
									std::cout << q[i] << " ";
								else
									std::cout << "  ";
			}
		}
	}
	void matrOutputToFile(std::string path)
	{
		std::ofstream fout(path, std::ios::app);
		if (!fout.is_open())
		{
			std::cout << "Ошибка открытия файла\n";
			return;
		}
		a.vecOutputToFile(fout);
		b.vecOutputToFile(fout);
		c.vecOutputToFile(fout);
		p.vecOutputToFile(fout);
		q.vecOutputToFile(fout);

		fout.close();
	}

	Matrix matrAdd(Matrix obj)
	{
		Matrix result(size, k);

		result.a = a.additionVec(obj.a);
		result.b = b.additionVec(obj.b);
		result.c = c.additionVec(obj.c);
		result.p = p.additionVec(obj.p);
		result.q = q.additionVec(obj.q);

		return result;
	}

	Matrix matrDifference(Matrix obj)
	{
		Matrix result(size, k);

		result.a = a.differenceVec(obj.a);
		result.b = b.differenceVec(obj.b);
		result.c = c.differenceVec(obj.c);
		result.p = p.differenceVec(obj.p);
		result.q = q.differenceVec(obj.q);

		return result;
	}

	Vector multipliByVectorOnRight(Vector obj, int sizeVec)
	{
		if (sizeVec<size || sizeVec>size)
			throw "Размерности не совпадают\n";
		Vector cur(size), result(size);

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)//i-строки, j-столбцы
			{
				if (j == size - i)
					cur[j] = c[i];
				else
					if (j == size + 1 - i)
						cur[j] = b[i];
					else
						if (j == size + 2 - i)
							cur[j] = a[i];
						else
							if (j == k)
								cur[j] = p[i];
							else
								if (j == k + 1)
									cur[j] = q[i];
								else
									cur[j] = 0;
			}
			result[i] = cur.scalarMultiplication(obj);
		}
		return result;
	}

	Vector multipliByVectorOnLeft(Vector obj, int sizeVec)
	{
		if (sizeVec<size || sizeVec>size)
			throw "Размерности не совпадают\n";

		Vector cur(size), result(size);

		for (int i = 1; i <= size; i++)
		{
			for (int j = 1; j <= size; j++)//i-столбцы, j-строки
			{
				if (j == size - i)
					cur[j] = c[j];
				else
					if (j == size + 1 - i)
						cur[j] = b[j];
					else
						if (j == size + 2 - i)
							cur[j] = a[j];
						else
							if (i == k)
								cur[j] = p[j];
							else
								if (i == k + 1)
									cur[j] = q[j];
								else
									cur[j] = 0;
			}
			result[i] = cur.scalarMultiplication(obj);
		}
		return result;


	}

};