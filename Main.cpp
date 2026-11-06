#include <iostream>
#include <fstream>
#include <vector>

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

void getMenu(int& chose)
{
    std::cout << "What would you like to do?\n";
    std::cout << "1) New Game\n";
    std::cout << "2) Exit\n";
    
    checkInput(chose);
    
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

string SelectWord(vector<string>& words)
{
    
    int randomIndex = rand() % words.size();

    std::string secretWord = words[randomIndex];
    return secretWord;
}

int main()
{

    int chose = 0;
    int playAgain = 1;
    string secretWord;

    srand(time(nullptr));

    std::ifstream is("WordBank.txt");
    std::istream_iterator<string> start(is), end;
    std::vector<string> wordBank(start, end);

    while (true)
    {
        clearScreen();
        getMenu(chose);
                
        switch (chose)
        {
        case 1:
            //std::cout << "STuff\n";
            secretWord=SelectWord(wordBank);
            std::cout << secretWord << endl;
            break;

        case 2:
            std::cout << "Thank you for playing. Goodbye :)\n";
            return 0;

        default:
            std::cout << "Invalid option.\n";
            break;
        }

        anotherGame(playAgain);

        
    }
}
