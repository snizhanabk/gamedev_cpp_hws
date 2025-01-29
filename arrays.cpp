#include <iostream>

void translateArray(int numbers[], int size)
{
	int multiply = 0;

	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > 0)
		{
			multiply = 2 * numbers[i];
			std::cout << multiply << std::endl;
		}
		else if (numbers[i] <= 0)
		{ 
		  std::cout << 0 << std::endl;
		}
	}
}

void toUppercase(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = (str[i] - 'a' + 'A');
		}
	}
}

bool isPalindrom(const char str[])
{
	int len = 0;

	while (str[len] != 0)
	{
		len++;
	}
	for (int i = 0; i < len/2 ; i++)
	{
		if (str[i] != str[len - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	
	const int arraySize = 10;
	int array[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Please enter a number: ";
		std::cin >> array[i];
	}

	translateArray(array, arraySize);


	const int stringSize = 100;

	char string[stringSize];

	std::cout << "Enter an array of random characters: " << std::endl;
	std::cin >> string;

	toUppercase(string);
	
	std::cout << "Your string in uppercase: " << string << std::endl;

	if (isPalindrom(string))
	{
		std::cout << "The word you entered is palindrome!" << std::endl;
	}
	else
	{
		std::cout << "The word you entered is not a palindrome." << std::endl;
	}

	return 0;
}