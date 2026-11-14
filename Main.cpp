#include <cctype>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "beacon.h"

using namespace std;

void checkInput(int& i)
{
    while (!(std::cin >> i) || i < 1 || i > 2)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid choice. Please enter 1 or 2: ";
    }
}

void checkBigInput(int& i)
{
    while (!(std::cin >> i) || i < 1 || i > 3)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid choice. Please enter 1 through 3: ";
    }
}

void getMenu(int& choice)
{
    std::cout << "------------------------------------\n";
    std::cout << "======== Welcome To Hangman ========\n";
    std::cout << "------------------------------------\n";
    std::cout << "What would you like to do?\n";
    std::cout << "1) New Game\n";
    std::cout << "2) Exit\n";
    
    checkInput(choice);
    
}

void clearScreen()
{
    system("cls");
}

void anotherGame(int& playAgain)
{
    std::cout << "Would you like to play again \n";
    std::cout << "1) Yes\n";
    std::cout << "2) No\n";

    checkInput(playAgain);

}

string selectWord(vector<string>& words)
{
    int randomIndex = rand() % words.size();
        
    return words[randomIndex];
}

void difficultyMenu(int& diff)
{
    std::cout << "---------------------------------\n";
    std::cout << "======== DIFFICULTY MENU ========\n";
    std::cout << "---------------------------------\n";
    std::cout << "Please select the difficulty\n";
    std::cout << "1. Easy (10 Guesses)\n";
    std::cout << "2. Normal (6 Guesses)\n";
    std::cout << "3. Hard (4 Guesses)\n";

    checkBigInput(diff);
}

void displayCurrentWord(string& displayWord)
{
    for (char letter : displayWord)
    {
        std::cout << letter << ' ';
    }
    std::cout << endl;
}

void checkWord(string& secretWord, string& displayWord, char& guess)
{
    for (int j = 0; j < secretWord.length(); j++)
    {
        if (secretWord[j] == guess)
        {
            displayWord[j] = guess;
        }
    }

}

int main()
{

    int choice = 0;
    int playAgain = 0;
    string secretWord;
    string displayWord;
    int diff = 0;
    char guess;

    srand(time(nullptr));

    std::ifstream is("WordBank.txt");
    if (!is)
    {
        cout << "Unable to open WordBank.txt\n";
        return 1;
    }
    std::istream_iterator<string> start(is), end;
    std::vector<string> wordBank(start, end);

    while (true)
    {
        clearScreen();
        getMenu(choice);
        clearScreen();
        switch (choice)
        {
        case 1:
            //std::cout << "STuff\n";
            difficultyMenu(diff);
            clearScreen();
            secretWord = selectWord(wordBank);
            displayWord = string(secretWord.length(), '_');
            //std::cout << secretWord << endl;
            //std::cout << displayWord << endl;
            while (displayWord != secretWord)
            {
                displayCurrentWord(displayWord);

                std::cout << "Please guess a letter: ";
                std::cin >> guess;

                guess = std::tolower(guess);

                //std::cout << "You guessed: " << guess << '\n';

                checkWord(secretWord, displayWord, guess);
            }
            std::cout << "----------------------------\n";
            std::cout << "======== YOU WIN!!! ========\n";
            std::cout << "You guessed " << secretWord << endl;
            std::cout << "----------------------------\n";

           break;

        case 2:
            std::cout << "Thank you for playing. Goodbye :)\n";
            return 0;

        default:
            std::cout << "Invalid option.\n";
            break;
        }
        anotherGame(playAgain);
        if (playAgain == 2)
        {
            return 0;
        }
    }    
}