#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int guess;
    int difference;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I've picked a random number between 1 and 100. Try to guess it!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Calculate the absolute difference between the guess and the random number
        difference = std::abs(randomNumber - guess);

        if (difference > 10) {
            std::cout << "Too far off! Try a ";
            if (randomNumber > guess)
                std::cout << "higher";
            else
                std::cout << "lower";
            std::cout << " number." << std::endl;
        } else if (difference > 5) {
            std::cout << "Getting closer! Try a ";
            if (randomNumber > guess)
                std::cout << "higher";
            else
                std::cout << "lower";
            std::cout << " number." << std::endl;
        } else {
            std::cout << "Very close! Try a ";
            if (randomNumber > guess)
                std::cout << "higher";
            else
                std::cout << "lower";
            std::cout << " number." << std::endl;
        }

    } while (guess != randomNumber);

    std::cout << "Congratulations! You guessed the correct number (" << randomNumber << ")!" << std::endl;

    return 0;
}
