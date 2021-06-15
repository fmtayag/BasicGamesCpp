#include <iostream>
#include <ctime>
#include <random>
#include <iterator>

int main()
{   
    srand(time(0));
    int theNumber = rand() % 100;
    int pGuess;
    int tries = 8;
    bool isRunning = true;
    bool isAsking = true;
    char choice;

    while (isRunning)
    {
        std::cout << "Guess my number, human. You have " << tries << " tries. \n";

        while (tries > 0)
        {
            std::cout << "Your guess: ";
            std::cin >> pGuess;

            if (std::cin.good())
            {
                // check answer
                if (pGuess > theNumber)
                {
                    tries--;
                    std::cout << "Your guess is higher than my number. You have " << tries << " tries left!\n";
                }
                else if (pGuess < theNumber)
                {
                    tries--;
                    std::cout << "Your guess is lower than my number. You have " << tries << " tries left!\n";
                }
                else
                {
                    std::cout << "You guessed it, human. Congratulations.\n";
                    isAsking = true;
                    break;
                }

                if (tries == 0 && pGuess != theNumber)
                {
                    std::cout << "Game over, human. I win.\n";
                    isAsking = true;
                }
            }
            else {
                std::cout << "\nThat's not a valid input, dummy.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        while (isAsking)
        {
            std::cout << "Do you want to play again? (y/n)\n";
            std::cout << "Your choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 'y':
                tries = 8;
                srand(time(0));
                theNumber = rand() % 100;
                isAsking = false;
                break;
            case 'n':
                isRunning = false;
                isAsking = false;
                std::cout << "\nGood bye human. \n";
                break;
            default:
                std::cout << "\nThat's not a valid option.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                break;
            }
        }
    }

    return 0;
}