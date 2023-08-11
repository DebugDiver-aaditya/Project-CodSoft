#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie {
private:
    string title;
    float price;

public:
    Movie(string _title, float _price) : title(_title), price(_price) {}

    string getTitle() const {
        return title;
    }

    float getPrice() const {
        return price;
    }
};

class Theater {
private:
    vector<bool> seats;
    Movie currentMovie;

public:
    Theater(int numSeats) : seats(numSeats, true), currentMovie("", 0.0) {}

    void showSeats() const {
        cout << "Current movie: " << currentMovie.getTitle() << "\n\n";
        for (int i = 0; i < seats.size(); ++i) {
            cout << (seats[i] ? " O " : " X ");
        }
        cout << "\n";
    }

    bool isSeatAvailable(int seat) const {
        return seat >= 0 && seat < seats.size() && seats[seat];
    }

    bool bookSeat(int seat) {
        if (isSeatAvailable(seat)) {
            seats[seat] = false;
            return true;
        }
        return false;
    }

    void selectMovie(Movie movie) {
        currentMovie = movie;
    }

    float calculateTotalCost(int numSeats) const {
        return numSeats * currentMovie.getPrice();
    }

    int getRemainingSeats() const {
        int count = 0;
        for (bool seat : seats) {
            if (seat) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int totalSeats = 80;
    Theater theater(totalSeats);

    Movie movie1("Avengers: Endgame", 250.0);
    Movie movie2("Inception", 250.0);

    char choice;
    do {
        int movieChoice;
        cout << "Select a movie:\n";
        cout << "1. " << movie1.getTitle() << " (Price: Rs " << movie1.getPrice() << ")\n";
        cout << "2. " << movie2.getTitle() << " (Price: Rs " << movie2.getPrice() << ")\n";
        cout << "Enter your choice:  ";
        cin >> movieChoice;

        if (movieChoice == 1) {
            theater.selectMovie(movie1);
        } else if (movieChoice == 2) {
            theater.selectMovie(movie2);
        } else {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        theater.showSeats();

        int numBookedSeats = 0;
        cout << "Enter the number of seats to book: ";
        cin >> numBookedSeats;

        if (numBookedSeats > theater.getRemainingSeats()) {
            cout << "Not enough available seats. Remaining seats: " << theater.getRemainingSeats() << "\n";
            continue;
        }

        for (int i = 0; i < numBookedSeats; ++i) {
            int seat;
            cout << "Enter seat number for seat " << i + 1 << ": ";
            cin >> seat;

            if (theater.bookSeat(seat - 1)) {
                cout << "Seat booked successfully.\n";
            } else {
                cout << "Invalid seat selection. Please choose another seat.\n";
                --i;
            }
        }

        float totalCost = theater.calculateTotalCost(numBookedSeats);
        cout << "Total cost: Rs " << totalCost << "\n";

        totalSeats -= numBookedSeats;
        cout << "Remaining available seats: " << totalSeats << "\n";

        if (totalSeats == 0) {
            cout << "All seats have been booked.\n";
            break;
        }

        cout << "Do you want to book tickets for another movie? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            cout << "Thank you for booking tickets. Enjoy the movie!\n";
            break;
        }
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
