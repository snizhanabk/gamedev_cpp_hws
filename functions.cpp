#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

static void countNum(int num)
{
	int positive = 0, negative = 0, zeroes = 0;

	std::cout << "Enter " << num << " numbers: " << std::endl;

	for (int i = 0; i < num; ++i)
	{
		int n;

		std::cin >> n;

		if (n > 0)
		{
			++positive;
		}
		else if (n < 0)
		{
			++negative;
		}
		else
		{
			++zeroes;
		}
	}

	std::cout << "Positive: " << positive << std::endl;
	std::cout << "Negative: " << negative << std::endl;
	std::cout << "Zeroes: " << zeroes << std::endl;

}

static int factorial(int count)
{
	if (count == 0)
	{
		return 1;
	}
	else
	{
		return count * factorial(count - 1);
	}
}

static float getArea(float radius)
{
	float area = pow(radius, 2) * M_PI;

	return area;
}

static float getCircumference(float radius)
{
	float circumference = 2 * radius * M_PI;

	return circumference;
}

int main() 
{
	//1. numbers counter
	int count;

	std::cout << "Enter the number of inputs: ";
	std::cin >> count;

	countNum(count);

	
	int n;

	//2.1 factorial calculated through recursive function
	std::cout << "Please, enter a non-negative number of your choice: " << std::endl;
	std::cin >> n;

	if (n < 0) 
	{
       std::cout << "Factorial of a negative number doesn't exist" << std::endl;
	}
	else if (n >= 0)
	{
		std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;
	}

	//2.2 factorial calculated through 'for' loop
	std::cout << "Please, enter a non-negative number of your choice: " << std::endl;
	std::cin >> n;

	long f = 1;

	if (n < 0)
	{
		std::cout << "Factorial of a negative number doesn't exist" << std::endl;
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			f *= i;
		}
		std::cout << "Factorial of " << n << " is " << f << std::endl;
	}

	
	//3. Area and Circumference
	
	float r;

	std::cout << "Please enter the radius " << std::endl;
	std::cin >> r;

	std::cout << "The area of the circle is: " << getArea(r) << std::endl;
	std::cout << "The circumference of the circle is: " << getCircumference(r) << std::endl;


	return 0;
}