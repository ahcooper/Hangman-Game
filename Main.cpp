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
        std::cout << "Invalid choice. Please enter 1 or 2: \n";
    }
}

void checkBigInput(int& i)
{
    while (!(std::cin >> i) || i < 1 || i > 3)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid choice. Please enter 1 through 3: \n";
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

string selectWord(const vector<string>& words)
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

void displayCurrentWord(const string& displayWord)
{
    for (char letter : displayWord)
    {
        std::cout << letter << ' ';
    }
    std::cout << endl;
}

bool checkWord(const string& secretWord, string& displayWord, char guess)
{
    bool found=false;

    for (size_t j = 0; j < secretWord.length(); j++)
    {
        if (secretWord[j] == guess)
        {
            displayWord[j] = guess;
            found = true;
        }
    }
    return found;

}

void checkGuess(char& guess)
{
   //char previousGuess;
    while (!(std::cin >> guess) || !isalpha(guess))
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid choice. Please guess a letter!  \n";
    }

    //if(guess==previousGuess)
    

}

int getGuessCount(int diff)
{
    switch (diff)
    {
    case 1:
        return 10;

    case 2:
        return 6;

    case 3:
        return 4;

    default:
        return 6;
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
    int guessesRemaining = 0;

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
            guessesRemaining = getGuessCount(diff);
            clearScreen();
            secretWord = selectWord(wordBank);
            displayWord = string(secretWord.length(), '_');
            //std::cout << secretWord << endl;
            //std::cout << displayWord << endl;
            while (displayWord != secretWord || guessesRemaining > 0)
            {
                
                clearScreen();
                displayCurrentWord(displayWord);

                cout << "Guesses Remaining: "
                    << guessesRemaining
                    << endl;
                std::cout << "Please guess a letter: ";
                checkGuess(guess);

                guess = std::tolower(guess);

                std::cout << "You guessed: " << guess << '\n';

                bool correct = checkWord(secretWord, displayWord, guess);

                if (!correct)
                {
                    guessesRemaining--;
                }

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

//==========================
//== Things I need to add ==
//==========================
/*

* Implement difficulty settings
* Add guess counter
* Save and display guessed letters
* Add losing condition
* Add beacon condition
* Remove commented-out debug code
*/