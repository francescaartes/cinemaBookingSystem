#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

void viewMovies();
void viewAvailableTickets();
void reserveTicket();

map<string, map<string, vector<int>>> seats;
map<string, map<string, string>> movies;

void init() {
    movies["1"] = {{"title", "Ant-Man And The Wasp: Quantumania"}, {"price", "680"}};
    movies["2"] = {{"title", "Avatar: The Way Of Water         "}, {"price", "680"}};
    movies["3"] = {{"title", "Sound Of Silence                 "}, {"price", "540"}};
    movies["4"] = {{"title", "The First Slam Dunk              "}, {"price", "480"}};
    movies["5"] = {{"title", "Oras De Peligro                  "}, {"price", "380"}};

    for (auto it = movies.begin(); it != movies.end(); it++) {
        int price = stoi(it->second["price"]);
        map<string, vector<int>> rows;
        rows["A"] = {1, 2, 3, 4, 5};
        rows["B"] = {1, 2, 3, 4, 5};
        rows["C"] = {1, 2, 3, 4, 5};
        rows["D"] = {1, 2, 3, 4, 5};
        rows["E"] = {1, 2, 3, 4, 5};
        seats[it->first] = rows;
    }
}

int main() {
    init();

    while (true) {
        cout << "\nWelcome to Cinema Booking System!" << endl;
        cout << "1. Reserve Ticket" << endl;
        cout << "2. View Movies" << endl;
        cout << "3. Cancel" << endl;
        cout << "Enter choice (1-3): ";
        string choice;
        getline(cin, choice);
        if (choice == "1") {
            reserveTicket();
            cin.ignore();
        }
        else if (choice == "2") {
            viewMovies();
        }
        else if (choice == "3") {
            cout << "\nThank you for using Cinema Booking System!" << endl;
            break;
        }
        else {
            cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}

void viewMovies() {
    cout << "\nAvailable movies:\n";
    cout << "  |                Title               | Price\n";
    cout << "==+====================================+=======\n";
    for (auto it = movies.begin(); it != movies.end(); it++) {
        string title = it->second["title"];
        int price = stoi(it->second["price"]);
        cout << it->first << " |  " << title << " | " << price << endl;
    }
}

void viewAvailableTickets() {
    cout << "\nAvailable tickets for each movie:\n";
    for (auto it = movies.begin(); it != movies.end(); it++) {
        string movie_num = it->first;
        string movie_title = it->second["title"];
        int price = stoi(it->second["price"]);
        cout << "\nMOVIE " << movie_num << " - $" << price << ":\n";
        cout << "    |  1  |  2  |  3  |  4  |  5  |\n";
        cout << "====+=====+=====+=====+=====+======\n";
        map<string, vector<int>> rows = seats[movie_num];
        for (auto it2 = rows.begin(); it2 != rows.end(); it2++) {
            string row = it2->first;
            cout << row << "   |";
            for (int i = 1; i <= 5; i++) {
                cout << "  " << (find(it2->second.begin(), it2->second.end(), i) != it2->second.end() ? to_string(i) : " ") << "  |";
            }
            cout << endl;
            cout << "----+-----+-----+-----+-----+------\n";
        }
    }
}

void reserveTicket() {
    cout << "\nPlease select a movie to book tickets for:\n";
    viewMovies();
    cout << "Enter movie number (1-5): ";
    string movie_num;
    getline(cin, movie_num);
    if (movies.find(movie_num) == movies.end()) {
        cout << "Invalid movie number. Please try again." << endl;
        return;
    }
    string movie_title = movies[movie_num]["title"];
    int price = stoi(movies[movie_num]["price"]);
    cout << "\nYou have selected " << movie_title << " - $" << price << endl;

    cout << "Enter number of tickets to book: ";
    int num_tickets;
    cin >> num_tickets;
    cin.ignore();
    if (num_tickets <= 0) {
        cout << "Invalid number of tickets. Please try again." << endl;
        return;
    }

    map<string, vector<int>> rows = seats[movie_num];
    cout << "\nAvailable seats for the movie:\n";
    cout << "    |  1  |  2  |  3  |  4  |  5  |\n";
    cout << "====+=====+=====+=====+=====+=====+\n";
    for (auto const& [row, cols] : rows) {
        cout << row << "   |";
        for (int i = 1; i <= 5; i++) {
            cout << "  " << (find(cols.begin(), cols.end(), i) != cols.end() ? to_string(i) : " ") << "  |";
        }
        cout << endl;
        cout << "----+-----+-----+-----+-----+-----+\n";
    }

    vector<string> selected_seats;
    for (int i = 1; i <= num_tickets; i++) {
        cout << "Enter seat number for ticket " << i << " (e.g. A1): ";
        string seat;
        cin >> seat;
        seat[0] = toupper(seat[0]);
        int col = stoi(seat.substr(1));
        if (rows.find(seat.substr(0, 1)) == rows.end() || find(rows[seat.substr(0, 1)].begin(), rows[seat.substr(0, 1)].end(), col) == rows[seat.substr(0, 1)].end()) {
            cout << "Invalid seat. Please try again." << endl;
            i--;
            continue;
        }
        string seat_num = seat.substr(0, 1) + to_string(col);
        selected_seats.push_back(seat_num);
        rows[seat.substr(0, 1)].erase(find(rows[seat.substr(0, 1)].begin(), rows[seat.substr(0, 1)].end(), col));
    }

        cout << "\nDo you want to confirm the booking? (Y/N): ";
        string confirm;
        cin >> confirm;
        transform(confirm.begin(), confirm.end(), confirm.begin(), ::toupper);
    if (confirm == "N") {
        cout << "Booking cancelled." << endl;
    return;
}
    if (confirm == "Y") {
        cout << "\nYou have reserved the following seats for " << movie_title << ":\n";
        for (auto const& seat : selected_seats) {
        cout << seat << endl;
    }
}
    seats[movie_num] = rows;
    cout << "\nTotal price: $" << num_tickets * price << endl;
}