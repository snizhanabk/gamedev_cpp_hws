#include <iostream>

const int ROWS = 4;
const int COLUMNS = 4;

bool find(int arr_2d[ROWS][COLUMNS], int toFind)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (arr_2d[i][j] == toFind)
			{
				return true;
			}
		}
	}
	return false;
}

bool isSorted(const int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}
	return true;
}

void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
	for (int i = COLUMNS - 1; i >= 0; i--)
	{
		for (int j = 0; j < ROWS; j++)
		{
			std::cout << arr_2d[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
	for (int i = ROWS - 1; i >= 0; i--)
	{
		if ((ROWS - 1 - i) % 2 == 0)
		{
			for (int j = 0; j < COLUMNS; j++)
			{
				std::cout << arr_2d[i][j] << " ";
			}

		}
		else {  
			for (int j = COLUMNS - 1; j >= 0; j--) {
				std::cout << arr_2d[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
}

int main() 
{

	int arr_2d[ROWS][COLUMNS] = 
	{ 
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	int searchNum;
	std::cout << "Please enter the Number you want to find in array: ";
	std::cin >> searchNum;

	if (find(arr_2d, searchNum)) 
	{
		std::cout << "Your number is a part of the array." << std::endl;
	}
	else	
	{
		std::cout << "Your number is not a part of the array." << std::endl;
		std::cout << "Please enter the Number you want to find in array: ";
		std::cin >> searchNum;	
	}
	std::cout << std::endl;

	const int size = 6;

	int arr[size] = { 113,212,333,412,531,680 };
	int arr1[size] = { 467,121,111,34553,988 };

	if (isSorted(arr, size) == true)
	{
		std::cout << "This array is sorted." << std::endl;
	}
	else
	{
		std::cout << "This array isn't sorted." << std::endl;
	}

	if (isSorted(arr1, size) == true)
	{
		std::cout << "This array is sorted." << std::endl;
	}
	else
	{
		std::cout << "This array isn't sorted." << std::endl;
	}
	std::cout << std::endl;

	traverseTopDownRightLeftByColumns(arr_2d);

	std::cout << std::endl;

	traverseLeftRightDownTopSwitchingByRows(arr_2d);

	return 0;
}