#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

std::string getRandomWord() {
    std::vector<std::string> database = { "ARIAL", "ARREA", "CREAM", "DREAM", "FLAME" };
    srand(time(0));
    return database[rand() % database.size()];
}

std::string checkWord(const std::string& guessed, const std::string& secret) {
    std::string result = "*****";
    for (size_t i = 0; i < guessed.size(); i++) {
        if (guessed[i] == secret[i]) {
            result[i] = toupper(guessed[i]);
        }
        else if (secret.find(guessed[i]) != std::string::npos) {
            result[i] = tolower(guessed[i]);
        }
    }
    return result;
}

int main() {
    std::string secretWord = getRandomWord();
    std::string guessedWord;
    int attempts = 0;

    std::cout << "Welcome to Wordle! Can you guess a secret 5-letter word that is hidden in this game? Well, let's try and find out." << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guessedWord;

        if (guessedWord.length() != 5) {
            std::cout << "Please enter a 5-letter word." << std::endl;
            continue;
        }

        std::transform(guessedWord.begin(), guessedWord.end(), guessedWord.begin(), ::toupper);
        attempts++;

        std::string feedback = checkWord(guessedWord, secretWord);
        std::cout << "Result: " << feedback << std::endl;

        if (guessedWord == secretWord) {
            std::cout << "Congratulations! You guessed the word in " << attempts << " attempts." << std::endl;
            break;
        }
    }
    return 0;
}
