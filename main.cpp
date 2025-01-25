#include "auction.h"

int main() {
    Auction auction;
    string command;

    cout << "Welcome to the Car Auction Program!" << endl;

    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Add a car to the auction (enter 'add')" << endl;
        cout << "2. Start the auction (enter 'auction')" << endl;
        cout << "3. Exit the program (enter 'exit')" << endl;
        cout << "4. Search vehicle by ID# (enter 'ID')" << endl;
        cout << "Command: ";
        cin >> command;

        if (command == "add") {
            string brand, model;
            int year, ID;
            double starting_bid;

            cout << endl;
            cout << "Enter car brand: ";
            cin >> brand;
            cout << "Enter car model: ";
            cin >> model;
            cout << "Enter car year: ";
            cin >> year;
            cout << "Enter car ID: ";
            cin >> ID;
            cout << "Enter starting bid: ";
            cin >> starting_bid;
            cout << endl;

            auction.addCar(brand, model, year, ID, starting_bid);
        } 
        else if (command == "auction") {
            cout << "\nStarting the auction!" << endl;

            while (true) {
                auction.printQueue();
                if (auction.isQueueEmpty()) {
                    cout << "All vehicles have been sold. Auction is over." << endl;
                    return 0; // End program
                }

                Car& currentCar = auction.getNextCar();
                cout << "Auctioning vehicle: " << currentCar.getYear() << " " << currentCar.getBrand() << " " 
                        << currentCar.getModel() << " (ID: " << currentCar.getID() << ")" << endl;

                while (currentCar.getCount() < 5) { 
                    cout << "Enter bidder's name (or 'done' to stop bidding on this car): ";
                    string bidderName;
                    cin >> bidderName;

                    if (bidderName == "done") break; 

                    cout << "Enter bid amount: ";
                    double bidAmount;
                    cin >> bidAmount;
                    cout << endl;

                    if (currentCar.addBid(bidderName, bidAmount)) {
                        cout << "Bid accepted!" << endl;
                        cout << endl;
                    } else {
                        cout << "Bid too low, Invalid!" << endl;
                    }
                 }

                currentCar.printBidders();
                cout << "This vehicle is sold!" << endl;

                auction.removeNextCar();  // Remove the car from auction after sale
            }
        }
        else if (command == "exit") {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else if (command == "ID"){
            int ID;
            cout << "Enter the ID of the vehicle you would like to look up: " << endl;
            cin >> ID;
            auction.searchByID(ID);
        }
        else {
            cout << "Invalid command. Please try again." << endl;
        }
    }

    return 0;
}
