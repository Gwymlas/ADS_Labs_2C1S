#include <conio.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include "Polyline.h"

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}


int Menu_1()
{
	std::cout << "\n�������� ������ ������ - 1\n�������� ������ ������ - 2\n�������� ������ - 3\n��������� ������ �� ��������� - 4\n��������� ������ �� ����������� - 5\n�������� ���� ������ - 6\n����� - Esc" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 27)) return key;
	}
}

int Menu_2()
{
	std::cout << "\n�������� ����� � ������ ������ - 1\n�������� ����� � ����� ������ - 2\n�������� ������� �� ������� - 3\n����� - Esc" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 27)) return key;
	}
}


int main() {
	
	setlocale(LC_ALL, "Russian");
	Polyline line_1, line_2;
	while (true)
	{
		system("cls");
		int m1 = Menu_1();
		if (m1 == 49)
		{
			while (true)
			{
				system("cls");
				std::cout << line_1 << std::endl;
				int m2 = Menu_2();
				if (m2 == 49)
				{
					Point p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p.x >> p.y;
					try
					{
						line_1.AddToBegin(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					Point p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p.x >> p.y;
					try
					{
						line_1.AddToEnd(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					int index = 0;
					std::cout << "������� ������ ����������" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_1[index].x << "," << line_1[index].y << ")" << std::endl;
						Point p;
						std::cout << "������� ����������� ���������� �������" << std::endl;
						std::cin >> p.x >> p.y;
						line_1[index].x = p.x;
						line_1[index].y = p.y;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 27) break;
			}
		}

		if (m1 == 50) 
		{
			while (true)
			{
				system("cls");
				std::cout << line_2 << std::endl;
				int m2 = Menu_2();
				if (m2 == 49)
				{
					Point p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p.x >> p.y;
					try
					{
						line_2.AddToBegin(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 50)
				{
					Point p;
					std::cout << "������� ���������� �����" << std::endl;
					std::cin >> p.x >> p.y;
					try
					{
						line_2.AddToEnd(p);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 51)
				{
					int index = 0;
					std::cout << "������� ������ ����������" << std::endl;
					std::cin >> index;
					try
					{
						std::cout << "(" << line_2[index].x << "," << line_2[index].y << ")" << std::endl;
						Point p;
						std::cout << "������� ����������� ���������� �������" << std::endl;
						std::cin >> p.x >> p.y;
						line_2[index].x = p.x;
						line_2[index].y = p.y;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
				}
				if (m2 == 27) break;
			}
		}

		if (m1 == 51)
		{
			system("cls");
			std::cout << line_1 << std::endl;
			std::cout << line_2 << std::endl;
			system("pause");
		}

		if (m1 == 52)
		{
			system("cls");
			if (line_1 == line_2) std::cout << "�����" << std::endl;
			else std::cout << "�������" << std::endl;
			system("pause");
		}

		if (m1 == 53)
		{
			system("cls");
			if (line_1 != line_2) std::cout << "�����" << std::endl; 
			else std::cout << "�������" << std::endl;
			system("pause");
		}

		if (m1 == 54)
		{
			system("cls");
			Polyline result = line_1 + line_2;
			std::cout << result << std::endl;
			system("pause");
		}

		if (m1 == 27) break;
	}
	return 0;
}
