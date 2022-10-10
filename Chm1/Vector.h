#pragma once
#include<ctime>
#include<iostream>
#include<string>
#include<fstream>

class Vector
{
	double* elements;
	int size = 0;

public:
	Vector(int obj_size = 0) :size(obj_size)
	{
		elements = new double[size];
	}
	~Vector()
	{
		delete[]elements;
	}
	Vector(const Vector& obj)
	{
		size = obj.size;
		elements = new double[size];
		for (int i = 0; i < size; i++)
			elements[i] = obj.elements[i];
	}

	int getSize()
	{
		return size;
	}
	void setSize(int value)
	{
		if (size != 0)
			throw "Запрещено менять размер вектора,он уже задан и отличен от нуля\n";
		
		delete[]elements;
		elements = new double[value];
		size = value;
	}
	double getVecComponent(int ind)
	{
		if (ind <1 || ind > size)
			throw "Индекс выходит за пределы вектора\n";
		return elements[ind - 1];

	}
	void setVecComponent(int ind, double value)
	{
		if (ind <1 || ind > size)
			throw "Индекс выходит за пределы вектора\n";
		elements[ind - 1] = value;
	}

	double normOfVec()
	{
		double max = abs(elements[0]);
		for (int i = 1; i < size; i++)
			if (abs(elements[i]) > max)
				max = abs(elements[i]);

		return max;
	}
	void randomFill(int a,int b)
	{
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			if (a > 0)
				elements[i] = a + rand() % (b + 1 - a);
			else
				if (b > 0)
					elements[i] = a + rand() % (abs(a) + 1 + b);
				else
					elements[i] = a + rand() % (abs(a) + b - 1);
		}

	}
	void fill()
	{
		std::cout << "Заполните вектор\n";
		for (int i = 0; i < size; i++)
			std::cin >> elements[i];
	}
	void fillFromVec(const Vector& obj)
	{
		size = obj.size;
		delete[]elements;
		elements = new double[size];

		for (int i = 0; i < size; i++)
			elements[i] = obj.elements[i];
	}
	void fillFromFile(std::string path)
	{
		std::ifstream fin;
		fin.open(path);

		if (!fin.is_open())
		{
			std::cout << "Ошибка открытия файла\n";
			return;
		}

		double value;
		int i = 0;
		while (!fin.eof())
		{
			if (i < size)
			{
				fin >> value;
				elements[i] = value;
			}
			else
				break;
			i++;

		}
		fin.seekg(0, std::ios::beg);
		fin.close();
	}

	void printVec()
	{
		for (int i = 0; i < size; i++)
			std::cout << elements[i] << " ";
		std::cout << std::endl;
	}
	void outputToFile(std::string path)
	{
		std::ofstream fout(path, std::ios::app);
		if (!fout.is_open())
		{
			std::cout << "Ошибка открытия файла\n";
			return;
		}

		fout << "\n";
		for (int i = 0; i < size; i++)
			fout << elements[i] << " ";

		fout.close();
	}


	Vector additionVec(Vector obj)
	{
		Vector result(size);
		for (int i = 0; i < size; i++)
			result.elements[i] = obj.elements[i] + this->elements[i];
		return result;

	}
	Vector differenceVec(Vector obj)
	{
		Vector result(size);
		for (int i = 0; i < size; i++)
			result.elements[i] = obj.elements[i] - this->elements[i];
	}
	double scalarMultiplication(Vector obj)
	{
		double result=0;
		for (int i = 0; i < size; i++)
			result += obj.elements[i] * this->elements[i];
		return result;
	}

	double& operator[](int ind)
	{
		return elements[ind - 1];
	}

	Vector& operator=(const Vector& obj)
	{
		size = obj.size;
		for (int i = 0; i < size; i++)
			elements[i] = obj.elements[i];

		return *this;
	}

};