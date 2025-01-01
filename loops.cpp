#include <iostream>
#include <cctype>

int main() {

	//Task 1. 

	int a1; // a1 - the fisrt term in the sequence
	int d; // d - the common difference between terms
	int n; // n - the number of terms in the sequence

	std::cout << "Enter the first term in the sequence: " << std::endl;
	std::cin >> a1;
	std::cout << "Enter the common difference between terms: " << std::endl;
	std::cin >> d;
	std::cout << "Enter the number of terms in the sequence: " << std::endl;
	std::cin >> n;
	std::cout << std::endl;


	int last_num = (a1 + (n - 1) * d)
	for (int an = a1; an <= last_num; an += d) {
		std::cout << an << std::endl;
	}
	std::cout << std::endl;

	//Task 2.

	int length;
	int width;
	char symbol;

	//triangle
	std::cout << "Enter length: " << std::endl;
	std::cin >> length;
	std::cout << "Enter symbol: " << std::endl;
	std::cin >> symbol;


	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= i; j++) {
			std::cout << symbol;
		}
		std::cout << std::endl;
	}

	//reversed triangle
	std::cout << "Enter length: " << std::endl;
	std::cin >> length;
	std::cout << "Enter symbol: " << std::endl;
	std::cin >> symbol;

	for (int i = 1; i <= length; i++) {
		for (int j = i; j <= length; j++) {
			std::cout << symbol;
		}
		std::cout << std::endl;
	}

	//rectangle
	std::cout << "Enter length: " << std::endl;
	std::cin >> length;
	std::cout << "Enter width: " << std::endl;
	std::cin >> width;
	std::cout << "Enter symbol: " << std::endl;
	std::cin >> symbol;

	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= width; j++) {
			std::cout << symbol;
		}
		std::cout << std::endl;
	}

	//paralelogram
	std::cout << "Enter length: " << std::endl;
	std::cin >> length;
	std::cout << "Enter symbol: " << std::endl;
	std::cin >> symbol;

	for (int i = 1; i <= length; ++i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << " ";
		}
		for (int j = 1; j <= length; ++j) {
			std::cout << symbol;
		}
		std::cout << std::endl;
	}

	//triangle with numbers
	std::cout << "Enter length: " << std::endl;
        std::cin >> length;
        for (int i = 0; i < length; i++) {
	        for (int j = 0; j <= i; j++) {
		        j % 2 == 0 ? std::cout << "1" : std::cout << "0";
	        }
	        std::cout << std::endl;
        }

	//Task 3.

	char s;
	int sum = 0;

	std::cout << "Enter a character: " << std::endl;
	std::cin >> s;

	while (s != '.'){
		if (islower(s)) { 
			s = toupper(s); std::cout << s << std::endl; }
		else if (isdigit(s)) {
			sum += s - '0'; 
			std::cout << "Current sum: " << sum << std::endl; } 
		else if (ispunct(s) || !isalnum(s)) {
			std::cout << "This character can't be processed by the program! Please, choose another character." << std::endl; 
		} 
		std::cin >> s;
	}

	return 0;
}
