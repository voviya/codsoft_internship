



#include <iostream>
#include <cstdlib>  
#include <ctime>    

int main() {
    
    std::srand(static_cast<unsigned int>(std::time(0)));

    
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0; 

    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "I've chosen a number between 1 and 100." << std::endl;

    
    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++; 

        if (userGuess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number: " 
                      << randomNumber << std::endl;
            std::cout << "It took you " << attempts << " attempts." << std::endl;
        }
    }

    return 0;
}
