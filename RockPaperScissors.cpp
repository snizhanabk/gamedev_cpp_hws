#include <iostream>
#include <ctime>
#include <string>

enum class Symbols
{
	Rock = 1, 
	Paper = 2, 
	Scissors = 3
};

std::string Winner(char PC, int PCC) // PC - player's choice, PCC - PC's choice
{
	if ((PC == 'r' && PCC == 3) ||
		(PC == 'p' && PCC == 1) ||
		(PC == 's' && PCC == 2)) 
	{
		return "You win this round!";
	}
	else if ((PCC == 1 && PC == 's') ||
		(PCC == 2 && PC == 'r') ||
		(PCC == 3 && PC == 'p')) 
	{
		return "Computer wins this round!";
	}
	return "It's a tie!";
}

int main() {

	//МІНІ - ГРА в консолі : Камінь Ножиці Папір

	int N; // N - number of rounds
	char S; // S - player's choice
	std::srand((unsigned)std::time(NULL));
	int PS = 0, PCS = 0; // PS - Player's Score, PCS - PC's Score;
	

	std::cout << "Hello! Welcome to 'Rock, Paper, Scissors' game!\nTo start the game, please, enter the number of rounds you want to play (enter '-1' if you want to quit the game): ";
	std::cin >> N;
	std::cout << std::endl;

	while (N != -1) // game ends if player inputs '-1' as number of rounds he wants to play the game
	{ 
		if (N <= 0) // game won't start unless player enters a valid number of rounds which is => 1
		{
			std::cout << "Please, enter a valid number of rounds (number must be bigger than 0): ";
			std::cin >> N;
			std::cout << std::endl;
			continue;
		}
		else // if number of rounds is => 1, player recieves further instructions 
		{
			for (int i = 0; i < N; i++) // this 'for loop' runs the game exact amount of rounds player entered
			{
				std::cout << "Round " << i + 1 << std::endl;
				std::cout << "To start your turn enter one of the possible symbols:" << std::endl; 
				std::cout << "r - rock p - paper s - scissors" << std::endl;
				std::cin >> S;
				std::cout << std::endl;

				if (S != 'r' && S != 'p' && S != 's') // to check if the character entered is valid, if not player should make another choice
				{
					std::cout << "This character can't be processed by the program!" << std::endl;
					std::cout << "Please, enter one of the following characters: 'r', 'p' or 's' to continue playing." << std::endl;
					--i;
					std::cout << std::endl;
					continue;
				}

				// shows players choice
				std::string Psymbol = (S == 'r') ? "Rock" : (S == 'p') ? "Paper" : "Scissors";
				std::cout << "You choose: " << Psymbol;
				std::cout << std::endl;

				// shows PC's choice
				int RN = 1 + rand() % 3; // RN - random number, this int is used to generate PC's random choice
				std::string PCsymbol = (RN == 1) ? "Rock" : (RN == 2) ? "Paper" : "Scissors";
				std::cout << "Computer's choice is: " << PCsymbol << std::endl;

				// shows who won the round
				std::string result = Winner(S, RN);
				std::cout << result << std::endl;
				if (result == "You win this round!") PS++;
				else if (result == "Computer wins this round!") PCS++;
				std::cout << std::endl;
			}
			// shows final scores
			std::cout << "Final Score - You: " << PS << ", Computer: " << PCS << std::endl;
			if (PS > PCS)
			{
				std::cout << "Congratulations, you win the game!" << std::endl;
			}
			else if (PS < PCS)
			{
				std::cout << "Computer wins the game. Better luck next time!" << std::endl;
			}
			else
			{
				std::cout << "It's a tie overall!" << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << "Enter the number of rounds for a new game (or '-1' to quit): ";
		std::cin >> N;
	}
	return 0;
}