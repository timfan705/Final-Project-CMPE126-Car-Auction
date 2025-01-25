#include <string>
#include "Linked_List.h"


struct bidder{
  string name;  
  double bid_amount;

  bidder(const string& name, double amount) : name(name), bid_amount(amount) {}

  //operator overload to print
  friend ostream& operator<<(ostream& os, const bidder& b) {
      os << b.name << ": $" << b.bid_amount;
      return os;
  }
};

class Car {
private:
    string brand;
    string model;
    int year; 
    int ID;
    double starting_bid;
    int count = 0;
    LinkedList<bidder> bidders;

public:
    Car(const string& brand, const string& model, int year, int ID, double starting_bid)
        : brand(brand), model(model), year(year), ID(ID), starting_bid(starting_bid) {}

    int getID() const {
        return ID;
    }

    string getBrand() const {
        return brand;
    }

    string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    int getStartingBid() const {
        return starting_bid;
    }

    int getCount(){
      return count;
    }

bool addBid(const string& name, double bid_amount) {
    // Stop bidding when a match is found or if the count exceeds 5
    if (count >= 5) {
        return false;
    }

    // Accept the bid if it's greater than or equal to the starting bid
    if ((bidders.getFront() == nullptr || bid_amount > bidders.getFront()->data.bid_amount) &&
        bid_amount >= starting_bid) {
        bidders.addSorted(bidder(name, bid_amount));
        count++;
        return true;
    }

    return false;
}



    void printBidders() {
        cout << "Bidders for vehicle: " << year << " " << brand << " " << model << " --- " << ID << endl;
        bidders.print();
    }
};
