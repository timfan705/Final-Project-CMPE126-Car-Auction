#ifndef AUCTION_H
#define AUCTION_H

#include <queue>
#include <iostream>
#include "car.h"
#include "BST.h"

class Auction {
private:
    queue<Car> carQueue;
    BST<Car> carBST; 

public:

    string Tbrand;
    string Tmodel;
    int Tyear;


    void addCar(const string& brand, const string& model, int year, int ID, double starting_bid) {

        Tbrand = brand;
        Tmodel = model;
        Tyear = year;

        Car newCar(brand, model, year, ID, starting_bid);
        carQueue.push(newCar);   
        carBST.insert(newCar);  
        cout << "Car added: " << year << " " << brand << " " << model << " (ID: " << ID << ")" << endl;
    }

    void searchByID(int ID) {
        if (carBST.search(ID)) {
            cout << "Car with ID " << ID << " found in the auction system: " << Tyear << " " << Tbrand << " " << Tmodel << endl;
        } else {
            cout << "Car with ID " << ID << " not found." << endl;
        }
    }

    void printQueue() {
        cout << "\nCars in Auction Queue:" << endl;
        if (carQueue.empty()) {
            cout << "No cars in the queue." << endl;
            return;
        }

        queue<Car> tempQueue = carQueue; 
        while (!tempQueue.empty()) {
            Car car = tempQueue.front();
            tempQueue.pop();
            cout << car.getYear() << " " << car.getBrand() << " " << car.getModel()
                 << " (ID: " << car.getID() << "), Starting Bid: $" << car.getStartingBid() << endl;
            cout << endl;
        }
    }

    Car& getNextCar() {
        return carQueue.front();  
    }

    void removeNextCar() {
        carQueue.pop();  
    }

    bool isQueueEmpty() {
        return carQueue.empty();
    }
};

#endif
