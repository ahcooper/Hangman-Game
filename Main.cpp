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

int main()
{

    int choice = 0;
    int playAgain = 0;
    string secretWord;
    string displayWord;
    int diff = 0;

    srand(time(nullptr));

    std::ifstream is("WordBank.txt");
    std::istream_iterator<string> start(is), end;
    std::vector<string> wordBank(start, end);

    while (true)
    {
        clearScreen();
        getMenu(choice);

        switch (choice)
        {
        case 1:
            //std::cout << "STuff\n";
            difficultyMenu(diff);
            secretWord = selectWord(wordBank);
            displayWord = string(secretWord.length(), '_');
            std::cout << secretWord << endl;
            std::cout << displayWord << endl;

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