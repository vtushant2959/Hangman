#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

// Function to draw the hangman figure
void drawHangman(int lives) {
    switch (lives) {
        case 6:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 5:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 4:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << " |   |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 3:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << "/|   |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 2:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << "/|\\  |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 1:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << "/|\\  |\n";
            std::cout << "/    |\n";
            std::cout << "     |\n";
            break;
        case 0:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << "/|\\  |\n";
            std::cout << "/ \\  |\n";
            std::cout << "     |\n";
            break;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    // List of words to guess from
    std::vector<std::string> words = {"apple", "banana", "cherry", "date", "elderberry"};

    // Select a random word
    std::string chosenWord = words[rand() % words.size()];

    // Initialize the guessed word with underscores
    std::string guessedWord(chosenWord.size(), '_');

    int lives = 6; // Number of lives

    std::cout << "Welcome to Hangman!\n";

    while (lives > 0 && guessedWord != chosenWord) {
        std::cout << "\nCurrent Word: " << guessedWord << "\n";
        drawHangman(lives);

        char guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        bool correctGuess = false;

        for (int i = 0; i < chosenWord.size(); ++i) {
            if (chosenWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            lives--;
            std::cout << "Incorrect guess. Lives remaining: " << lives << "\n";
        }
    }

    if (guessedWord == chosenWord) {
        std::cout << "Congratulations! You guessed the word: " << chosenWord << "\n";
    } else {
        std::cout << "Game Over! The word was: " << chosenWord << "\n";
    }

    return 0;
}

