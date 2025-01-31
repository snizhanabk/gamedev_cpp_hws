#include <iostream>

void swap(int& a, int& b)
{
	int tempVar = a;
	a = b;
	b = tempVar;
}

void swap1(int* a, int* b)
{
	int tempVar = *a;
		*a = *b;
		*b = tempVar;
}

bool find(const int* arr, int size, int elem)
{
	const int* end = arr + size;
	for (; arr < end; arr++)
	{
		if (*arr == elem) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	int val = 0;
	int val1 = 0;

	std::cout << "Please enter two numbers: " << std::endl;
	std::cin >> val >> val1;
	std::cout << std::endl;

	std::cout << "Your value 1 is " << val << " value 2 is " << val1 << std::endl;
	swap(val, val1);
	std::cout << "Your values were swapped. Now value 1 is " << val << " and value 2 is " << val1 << std::endl;

	std::cout << "Please enter two numbers: " << std::endl;
	std::cin >> val >> val1;
	std::cout << std::endl;

	std::cout << "Your value 1 is " << val << " value 2 is " << val1 << std::endl;
	swap1(&val,&val1);
	std::cout << "Your values were swapped. Now value 1 is " << val << " and value 2 is " << val1 << std::endl;


	const int arraySize = 10;
	int array[arraySize];
	int elemNum;

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Please enter a number: ";
		std::cin >> array[i];
	}

	std::cout << "Enter number of element in array: " << std::endl;
	std::cin >> elemNum;

	
	if (find(array, arraySize, elemNum) ==  true)
	{
		std::cout << "Element was found in array" << std::endl;
	}
	else if (find(array, arraySize, elemNum) == false)
	{
		std::cout << "Element can't be found in array. Please choose another element: " << std::endl;
		std::cin >> elemNum;
	}
	
	return 0;
}