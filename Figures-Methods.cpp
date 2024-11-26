#include <iostream>
#include <string>
#include <Windows.h>

class Figure
{
	protected:
		std::string name, is_correct;
		unsigned int sides_count;
	public:
		virtual bool check()
		{
			if (sides_count == 0)
				return true;

			return false;
		}

		virtual void print_info()
		{
			if (check())
				is_correct = "Правильная";
			else
				is_correct = "Неправильная";

			std::cout << name << ":\n" << is_correct << "\nКоличество сторон: " << sides_count << std::endl;

			std::cout << "\n";
		}

		Figure() : name("Фигура"), sides_count(0) {}
};

// фигуры с 3 углами
class Triangle : public Figure
{
	protected:
		unsigned int a, b, c, A, B, C;
	public:
		bool check() override
		{
			if ((A + B + C) == 180 && (a > 0 && b > 0 && c > 0))
				return true;

			return false;
		}

		void print_info() override
		{
			if (check())
				is_correct = "Правильная";
			else
				is_correct = "Неправильная";

			sides_count = 0;
			if (a > 0)
				sides_count++;
			if (b > 0)
				sides_count++;
			if (c > 0)
				sides_count++;

			std::cout << name << ":\n" << is_correct << "\nКоличество сторон: " << sides_count << std::endl;

			if(a + b + c > 0)
				std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;

			if (A + B + C > 0)
				std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;

			std::cout << "\n";
		}

		Triangle(int sideA = 0, int sideB = 0, int sideC = 0, int angleA = 0, int angleB = 0, int angleC = 0)
		{
			name = "Треугольник";
			a = sideA;
			b = sideB;
			c = sideC;
			A = angleA;
			B = angleB;
			C = angleC;
		}
};

class RectangularTriangle : public Triangle // Прямоугольный треугольник (угол C всегда равен 90)
{
	public:
		bool check() override
		{
			if (A + B == 90 && C == 90 && (a > 0 && b > 0 && c > 0))
				return true;

			return false;
		}

		RectangularTriangle(int sideA = 0, int sideB = 0, int sideC = 0, int angleA = 0, int angleB = 0, int angleC = 0) :
			Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
		{
			name = "Прямоугольный треугольник";
		}
};

class IsoscelesTriangle : public Triangle // Равнобедренный треугольник (стороны a и c равны, углы A и C равны)
{
	public:
		bool check() override
		{
			if ((A + B + C) == 180 && a == c && A == C && (a > 0 && b > 0 && c > 0))
				return true;

			return false;
		}

		IsoscelesTriangle(int sideA = 0, int sideB = 0, int sideC = 0, int angleA = 0, int angleB = 0, int angleC = 0) :
			Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
		{
			name = "Равнобедренный треугольник";
		}
};

class EquilateralTriangle : public Triangle // Равносторонний треугольник (все стороны равны, все углы равны 60)
{
	public:
		bool check() override
		{
			if ((A + B + C) == 180 && (A == B && A == C) && (a == b && a == c) && (a > 0 && b > 0 && c > 0))
				return true;

			return false;
		}

		EquilateralTriangle(int sideA = 0, int sideB = 0, int sideC = 0, int angleA = 0, int angleB = 0, int angleC = 0) :
			Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
		{
			name = "Равносторонний треугольник";
		}
};

// фигуры с 4 углами
class Quadrangle : public Figure // Четырехугольник
{
	protected:
		unsigned int a, b, c, d, A, B, C, D;
	public:
		bool check() override
		{
			if ((A + B + C + D) == 360 && (a > 0 && b > 0 && c > 0 && d > 0))
				return true;

			return false;
		}

		void print_info() override
		{
			if (check())
				is_correct = "Правильная";
			else
				is_correct = "Неправильная";

			sides_count = 0;
			if (a > 0)
				sides_count++;
			if (b > 0)
				sides_count++;
			if (c > 0)
				sides_count++;
			if (d > 0)
				sides_count++;

			std::cout << name << ":\n" << is_correct << "\nКоличество сторон: " << sides_count << std::endl;

			if (a + b + c + d > 0)
				std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;

			if (A + B + C + D > 0)
				std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;

			std::cout << "\n";
		}

		Quadrangle(int sideA = 0, int sideB = 0, int sideC = 0, int sideD = 0, int angleA = 0, int angleB = 0, int angleC = 0, int angleD = 0)
		{
			name = "Четырехугольник";
			a = sideA;
			b = sideB;
			c = sideC;
			d = sideD;
			A = angleA;
			B = angleB;
			C = angleC;
			D = angleD;
		}
};

class Parallelogram : public Quadrangle // Параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
{
	public:
		bool check() override
		{
			if ((A + B + C + D) == 360 && (a == c && b == d) && (A == C && B == D) && (a > 0 && b > 0 && c > 0 && d > 0))
				return true;

			return false;
		}

		Parallelogram(int sideA = 0, int sideB = 0, int sideC = 0, int sideD = 0, int angleA = 0, int angleB = 0, int angleC = 0, int angleD = 0) :
			Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
		{
			name = "Параллелограмм";
		}
};

class Rhombus : public Parallelogram // Ромб (все стороны равны, углы A,C и B,D попарно равны)
{
	public:
		bool check() override
		{
			if ((A + B + C + D) == 360 && (a == b && b == c && c == d) && (A == C && B == D) && (a > 0 && b > 0 && c > 0 && d > 0))
				return true;

			return false;
		}

		Rhombus(int sideA = 0, int sideB = 0, int sideC = 0, int sideD = 0, int angleA = 0, int angleB = 0, int angleC = 0, int angleD = 0) :
			Parallelogram(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
		{
			name = "Ромб";
		}
};

class Rectangles : public Parallelogram // Прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
{
	public:
		bool check() override
		{
			if ((A + B + C + D) == 360 && (a == c && b == d) && (a == 90 && b == 90 && c == 90 && d == 90))
				return true;

			return false;
		}

		Rectangles(int sideA = 0, int sideB = 0, int sideC = 0, int sideD = 0, int angleA = 0, int angleB = 0, int angleC = 0, int angleD = 0) :
			Parallelogram(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
		{
			name = "Прямоугольник";
		}
};

class Square : public Rectangles // Квадрат (все стороны равны, все углы равны 90)
{
	public:
		bool check() override
		{
			if ((A + B + C + D) == 360 && (a == b && b == c && c == d) && (A == 90 && B == 90 && C == 90 && D == 90))
				return true;

			return false;
		}

		Square(int sideA = 0, int sideB = 0, int sideC = 0, int sideD = 0, int angleA = 0, int angleB = 0, int angleC = 0, int angleD = 0) :
			Rectangles(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
		{
			name = "Квадрат";
		}
};

int main() // Задача 3. Фигуры. Методы
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Figure* figure = new Figure;
	Figure* pointer = figure;
	pointer->print_info();

	Triangle* triangle = new Triangle{ 10, 20, 30, 50, 60, 70 };
	RectangularTriangle* rectangularTriangle = new RectangularTriangle{ 10, 20, 30, 40, 50, 90 }; // Прямоугольный треугольник
	IsoscelesTriangle* isoscelesTriangle = new IsoscelesTriangle{ 10, 20, 30, 70, 40, 70 }; // Равнобедренный треугольник
	EquilateralTriangle* equilateralTriangle = new EquilateralTriangle{ 10, 20, 30, 40, 50, 60 }; // Равносторонний треугольник

	pointer = triangle;
	pointer->print_info();

	pointer = rectangularTriangle;
	pointer->print_info();

	pointer = isoscelesTriangle;
	pointer->print_info();

	pointer = equilateralTriangle;
	pointer->print_info();

	delete equilateralTriangle;
	delete isoscelesTriangle;
	delete rectangularTriangle;
	delete triangle;

	Quadrangle* quadrangle = new Quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 }; // Четырехугольник
	Parallelogram* parallelogram = new Parallelogram{ 10, 20, 30, 40, 50, 60, 70, 80 }; // Параллелограмм
	Rhombus* rhombus = new Rhombus{ 15, 15, 15, 15, 50, 130, 50, 130 }; // Ромб
	Rectangles* rectangles = new Rectangles{ 10, 20, 30, 40, 50, 60, 70, 80 }; // Прямоугольник
	Square* square = new Square{ 10, 20, 30, 40, 50, 60, 70, 80 }; // Квадрат

	pointer = quadrangle;
	pointer->print_info();

	pointer = rectangles;
	pointer->print_info();

	pointer = square;
	pointer->print_info();

	pointer = parallelogram;
	pointer->print_info();

	pointer = rhombus;
	pointer->print_info();

	delete square;
	delete rectangles;
	delete rhombus;
	delete parallelogram;
	delete quadrangle;

	delete figure;
}
