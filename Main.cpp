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

void validateDiff(int& i)
{
    while (!(std::cin >> i) || i < 1 || i > 4)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid choice. Please enter 1 through 4: \n";
    }
}

void showMenu(int& choice)
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

void showDifficultyMenu(int& diff)
{
    std::cout << "---------------------------------\n";
    std::cout << "======== DIFFICULTY MENU ========\n";
    std::cout << "---------------------------------\n";
    std::cout << "Please select the difficulty\n";
    std::cout << "1. Easy (10 Guesses)\n";
    std::cout << "2. Normal (6 Guesses)\n";
    std::cout << "3. Hard (4 Guesses)\n";
    std::cout << "4. Back\n";

    validateDiff(diff);
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
    while (!(std::cin >> guess) || !isalpha(guess))
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid choice. Please guess a letter!  \n";
    }        
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

bool isLetterAlreadyGuessed(const vector<char>& guessedLetters, char guess)
{
    for (size_t i = 0; i < guessedLetters.size(); i++)
    {
        if (guessedLetters[i] == guess)
        {           
            return true;
        }
    }

    return false;
}

void displayAlphabetBoard(const vector<char>& guessedLetters)
{
    for (char letter = 'A'; letter <= 'Z'; letter++)
    {
        if (isLetterAlreadyGuessed(guessedLetters,
            std::tolower(letter)))
        {
            std::cout << "- ";
        }
        else
        {
            std::cout << letter << " ";
        }

        if (letter == 'M')
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
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
    vector<char>guessedLetters;

    srand(time(nullptr));

    std::ifstream is("WordBank.txt");
    if (!is)
    {
        cout << "Unable to open WordBank.txt\n";
        return 1;
    }
    std::istream_iterator<string> start(is), end;
    std::vector<string> wordBank(start, end);

    showMenu(choice);

    while (true)
    {
        clearScreen();
       
        switch (choice)
        {
        case 1:
            
            showDifficultyMenu(diff);
            if (diff == 4)
            {
                showMenu(choice);
                continue;
            }

            guessesRemaining = getGuessCount(diff);
            clearScreen();
            secretWord = selectWord(wordBank);
            displayWord = string(secretWord.length(), '_');
            
            while (displayWord != secretWord && guessesRemaining > 0)
            {                          
                displayCurrentWord(displayWord);
                displayAlphabetBoard(guessedLetters);

                std::cout << "Guesses Remaining: " << guessesRemaining << endl;
                std::cout << "Please guess a letter: ";
                checkGuess(guess);
                clearScreen();
                guess = std::tolower(guess);

                if (!isLetterAlreadyGuessed(guessedLetters, guess))
                {
                    guessedLetters.push_back(guess);

                    bool correct = checkWord(secretWord, displayWord, guess);

                    if (!correct)
                    {   
                        guessesRemaining--;
                    }
                
                }
                else 
                {
                    std::cout << "Already guessed letter. Please guess a different letter.\n";
                }

                

            }
            
            if (displayWord == secretWord)
            {
                std::cout << "----------------------------\n";
                std::cout << "======== YOU WIN!!! ========\n";
                std::cout << "Your word was " << secretWord << endl;
                std::cout << "----------------------------\n";
            }
            else
            {
                std::cout << "----------------------------\n";
                std::cout << "======== YOU Lose!!! ========\n";
                std::cout << "Your word was " << secretWord << endl;
                std::cout << "----------------------------\n";
            }

            guessedLetters.clear();
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
* Add beacon condition
* Remove commented-out debug code
*/