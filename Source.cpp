#include <iostream>
#include <locale.h>
#include <math.h>
#include "Polyline.h"

template<class T>
void CheckInputValue(T& value)
{
    while(true)
    {
        std::cin >> value;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "The input value is incorrect! " << std::endl;
            system("pause");
        }
        else
        {
            return;
        }
    }
}


int Menu1()
{
	std::cout << "\nEdit first polyline - 1\nEdit second polyline - 2\nSum of two polylines - 3\nShow polylines - 4\nCheck polylines for equality - 5\nExit - 0" << std::endl;
    while (true)
    {
        int value;
        CheckInputValue(value);
        if (value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 0) return value;
    }
}

int Menu2()
{
	std::cout << "\nAdd point at the begin of polyline - 1\nAdd point at the end of polyline - 2\nEdit point by index - 3\nLength of polyline - 4\nExit - 0" << std::endl;
    while (true)
    {
        int value;
        CheckInputValue(value);
        if (value == 1 || value == 2 || value == 3 || value == 4 || value == 0) return value;
    }
}

int MainMenu()
{
	std::cout << "Select the type of points in the polyline:" << std::endl;
	std::cout << "\nIntPoint2 - 1\nDoublePoint3 - 2\nstd::complex<double> - 3\nExit - 0" << std::endl;
	while (true)
	{
		int value;
        CheckInputValue(value);
        if (value == 1 || value == 2 || value == 3 || value == 0) return value;
	}
}

template <class T>
void EditPolyline(Polyline<T>& polyline, int option)
{
    bool repeat = true;
    while(repeat)
    {
        system("clear");
        system("clear");
        std::cout << polyline << std::endl;
        int m2 = Menu2();
        switch (m2) {
            case 1: {
                T point;
                std::cout << "Enter coordinates of the point: " << std::endl;
                std::cin >> point;
                /*if (option == 0) {
                    std::cout << "x: ";
                    std::cin >> x;
                    std::cout << "y: ";
                    std::cin >> y;

                } else {
                    std::cout << "x: ";
                    std::cin >> point._x;
                    std::cout << "\ny: ";
                    std::cin >> point._y;
                    std::cout << "\nz: ";
                    std::cin >> point._z;
                }*/
                try {
                    polyline.AddToBegin(point);
                }
                catch (const char *err) {
                    std::cout << err << std::endl;
                    system("pause");
                }
                break;
            }

            case 2: {
                T point;
                std::cout << "Enter coordinates of the point:" << std::endl;
                std::cin >> point;
                /*if (option == 0) {
                    std::cout << "x: ";
                    std::cin >> point._x;
                    std::cout << "y: ";
                    std::cin >> point._y;
                } else {
                    std::cout << "x: ";
                    std::cin >> point._x;
                    std::cout << "\ny: ";
                    std::cin >> point._y;
                    std::cout << "\nz: ";
                    std::cin >> point._z;
                }*/
                try {
                    polyline.AddToEnd(point);
                }
                catch (std::exception& err) {
                    std::cout << err.what() << std::endl;
                    system("pause");
                }
                break;
            }
            case 3: {
                std::cout << "Enter index: ";
                int index = 0;
                CheckInputValue(index);
                try {
                    std::cout << polyline[index] << std::endl;
                    T point;
                    std::cout << "Enter coordinates of the point:" << std::endl;
                    std::cin >> point;
                    polyline[index] = point;
                    /*if (option == 0) {
                        std::cout << "x: ";
                        std::cin >> polyline[index]._x;
                        std::cout << "y: ";
                        std::cin >> polyline[index]._y;
                    } else {
                        std::cout << "x: ";
                        std::cin >> polyline[index]._x;
                        std::cout << "\ny: ";
                        std::cin >> polyline[index]._y;
                        std::cout << "\nz: ";
                        std::cin >> polyline[index]._z;
                    }*/
                }
                catch (std:: exception& err) {
                    std::cout << err.what() << std::endl;
                    system("pause");
                }
                break;
            }
            case 4: {
                try {
                    system("clear");
                    std::cout << "Length of polyline: " << polyline.Length() << std::endl;
                    std::cout << typeid(polyline.Length()).name() << std::endl;
                    system("pause");
                }
                catch (std::exception& err) {
                    std::cout << err.what() << std::endl;
                    system("pause");
                }
                break;
            }
            case 0: {
                repeat = false;
                break;
            }
            default:
                break;

        }
    }
}



//----------------------


void EditPolyline(Polyline<std::complex<double>>& polyline)
{
    bool repeat = true;
    while(repeat)
    {
        system("clear");
        std::cout << polyline << std::endl;
        int m2 = Menu2();
        switch (m2) {
            case 1: {
                double im = 0, re = 0;
                std::cout << "Enter coordinates of the point:" << std::endl;
                std::cout << "re: ";
                std::cin >> re;
                std::cout << "im: ";
                std::cin >> im;
                std::complex<double> point(re, im);
                try {
                    polyline.AddToBegin(point);
                }
                catch (std::exception& err) {
                    std::cout << err.what() << std::endl;
                    system("pause");
                }
                break;
            }

            case 2: {
                double im = 0, re = 0;
                std::cout << "Enter coordinates of the point:" << std::endl;
                std::cout << "re: ";
                std::cin >> re;
                std::cout << "im: ";
                std::cin >> im;
                std::complex<double> point(re, im);
                try {
                    polyline.AddToEnd(point);
                }
                catch (std::exception& err) {
                    std::cout << err.what() << std::endl;
                    system("pause");
                }
                break;
            }
            case 3: {
                std::cout << "Enter index: ";
                int index = 0;
                CheckInputValue(index);
                try {
                    std::cout << polyline[index] << std::endl;
                    double im = 0, re = 0;
                    std::cout << "Enter coordinates of the point:" << std::endl;
                    std::cout << "re: ";
                    std::cin >> re;
                    std::cout << "im: ";
                    std::cin >> im;
                    std::complex<double> point(re, im);
                    polyline[index] = point;
                }
                catch (std::exception& err) {
                    std::cout << err.what() << std::endl;
                    system("pause");
                }
                break;
            }
            case 4: {
                try {
                    system("clear");
                    std::cout << "Length of polyline: " << polyline.Length() << std::endl;
                    std::cout << typeid(polyline.Length()).name() << std::endl;
                    system("pause");
                }
                catch (std::exception& err) {
                    std::cout << err.what() << std::endl;
                    system("pause");
                }
                break;
            }
            case 0: {
                repeat = false;
                break;
            }
            default:
                break;

        }
    }
}

//--------------------


int main()
{
	setlocale(LC_ALL, "Russian");
    bool end = false;
	while (!end)
	{
		system("clear");
		int option = MainMenu();
        switch(option)
        {
            case 1: {
                bool repeat = true;
                Polyline<IntPoint2> polyline1;
                Polyline<IntPoint2> polyline2;
                while(repeat) {
                    int m1 = Menu1();
                    switch (m1) {
                        case 1: {
                            EditPolyline(polyline1, 0);
                            break;
                        }
                        case 2: {
                            EditPolyline(polyline2, 0);
                            break;
                        }
                        case 3: {
                            Polyline<IntPoint2> res;
                            res = polyline1 + polyline2;
                            std::cout << res << std::endl;
                            system("pause");
                            break;
                        }
                        case 4: {
                            std::cout << polyline1 << std::endl;
                            std::cout << polyline2 << std::endl;
                            system("pause");
                            break;
                        }
                        case 5: {
                            if (polyline1 == polyline2) std::cout << "Polylines are equal" << std::endl;
                            else std::cout << "Polylines are not equal" << std::endl;
                            break;
                        }
                        case 0: {
                            repeat = false;
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            case 2: {
                bool repeat = true;
                Polyline<DoublePoint3> polyline1;
                Polyline<DoublePoint3> polyline2;
                while(repeat) {
                    int m1 = Menu1();
                    switch (m1) {
                        case 1: {
                            EditPolyline(polyline1, 0);
                            break;
                        }
                        case 2: {
                            EditPolyline(polyline2, 0);
                            break;
                        }
                        case 3: {
                            Polyline<DoublePoint3> res;
                            res = polyline1 + polyline2;
                            std::cout << res << std::endl;
                            system("pause");
                            break;
                        }
                        case 4: {
                            std::cout << polyline1 << std::endl;
                            std::cout << polyline2 << std::endl;
                            system("pause");
                            break;
                        }
                        case 5: {
                            if (polyline1 == polyline2) std::cout << "Polylines are equal" << std::endl;
                            else std::cout << "Polylines are not equal" << std::endl;
                            break;
                        }
                        case 0: {
                            repeat = false;
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            case 3: {
                bool repeat = true;
                Polyline<std::complex<double>> polyline1;
                Polyline<std::complex<double>> polyline2;
                while(repeat) {
                    int m1 = Menu1();
                    switch (m1) {
                        case 1: {
                            EditPolyline(polyline1, 0);
                            break;
                        }
                        case 2: {
                            EditPolyline(polyline2, 0);
                            break;
                        }
                        case 3: {
                            Polyline<std::complex<double>> res;
                            res = polyline1 + polyline2;
                            std::cout << res << std::endl;
                            system("pause");
                            break;
                        }
                        case 4: {
                            std::cout << polyline1 << std::endl;
                            std::cout << polyline2 << std::endl;
                            system("pause");
                            break;
                        }
                        case 5: {
                            if (polyline1 == polyline2) std::cout << "Polylines are equal" << std::endl;
                            else std::cout << "Polylines are not equal" << std::endl;
                            break;
                        }
                        case 0: {
                            repeat = false;
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            case 0: {
                end = true;
                break;
            }

            default: break;
        }
	}
	return 0;
}