#include <iostream>
#include <vector>
#include <iomanip>

// Constants for the number of rows and columns in the theater
const int NUM_ROWS = 5;
const int NUM_COLS = 10;

// Class to represent a seat in the theater
class Seat {
public:
    Seat() : booked(false) {}
    bool isBooked() const { return booked; }
    void book() { booked = true; }
    void unbook() { booked = false; }
private:
    bool booked;
};

// Class to represent a movie
class Movie {
public:
    Movie(const std::string& title, const std::string& time, double price)
        : title(title), time(time), price(price) {}

    const std::string& getTitle() const { return title; }
    const std::string& getTime() const { return time; }
    double getPrice() const { return price; }
private:
    std::string title;
    std::string time;
    double price;
};

// Function to display the seating chart
void displaySeatingChart(const std::vector<std::vector<Seat>>& seats) {
    std::cout << "Seating Chart:\n";
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            std::cout << (seats[row][col].isBooked() ? 'X' : 'O') << ' ';
        }
        std::cout << '\n';
    }
}

// Function to book a seat
void bookSeat(std::vector<std::vector<Seat>>& seats) {
    int row, col;
    std::cout << "Enter the row and column of the seat you want to book (e.g., 2 3): ";
    std::cin >> row >> col;

    if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS) {
        std::cout << "Invalid seat selection.\n";
        return;
    }

    if (seats[row - 1][col - 1].isBooked()) {
        std::cout << "Seat is already booked.\n";
    } else {
        seats[row - 1][col - 1].book();
        std::cout << "Seat booked successfully.\n";
    }
}

// Function to calculate and display the total cost
void calculateTotalCost(const std::vector<std::vector<Seat>>& seats, const Movie& movie) {
    double totalCost = 0.0;
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            if (seats[row][col].isBooked()) {
                totalCost += movie.getPrice();
            }
        }
    }

    std::cout << "Total cost for " << movie.getTitle() << " at " << movie.getTime()
              << " is $" << std::fixed << std::setprecision(2) << totalCost << '\n';
}

int main() {
    // Create a vector of vectors to represent the theater seats
    std::vector<std::vector<Seat>> seats(NUM_ROWS, std::vector<Seat>(NUM_COLS));

    // Create movie listings
    std::vector<Movie> movies;
    movies.emplace_back("Movie 1", "10:00 AM", 10.0);
    movies.emplace_back("Movie 2", "1:00 PM", 12.0);
    movies.emplace_back("Movie 3", "4:00 PM", 15.0);

    // Main loop
    int choice;
    while (true) {
        std::cout << "\nMovie Ticket Booking System\n";
        std::cout << "1. View Movie Listings\n";
        std::cout << "2. View Seating Chart\n";
        std::cout << "3. Book a Seat\n";
        std::cout << "4. Calculate Total Cost\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nMovie Listings:\n";
                for (size_t i = 0; i < movies.size(); ++i) {
                    std::cout << i + 1 << ". " << movies[i].getTitle() << " at " << movies[i].getTime()
                              << " ($" << std::fixed << std::setprecision(2) << movies[i].getPrice() << ")\n";
                }
                break;
            case 2:
                displaySeatingChart(seats);
                break;
            case 3:
                bookSeat(seats);
                break;
            case 4:
                std::cout << "Enter the movie number (1-" << movies.size() << "): ";
                int movieNumber;
                std::cin >> movieNumber;
                if (movieNumber >= 1 && movieNumber <= movies.size()) {
                    calculateTotalCost(seats, movies[movieNumber - 1]);
                } else {
                    std::cout << "Invalid movie selection.\n";
                }
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
