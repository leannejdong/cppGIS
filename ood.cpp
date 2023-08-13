#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;
    std::string model;
    int year;

public:
    Vehicle(const std::string& _brand, const std::string& _model, int _year)
        : brand(_brand), model(_model), year(_year) {}

    void displayInfo() {
        std::cout << year << " " << brand << " " << model << std::endl;
    }
};

class Car : public Vehicle {
    int numSeats;

public:
    Car(const std::string& _brand, const std::string& _model, int _year, int _numSeats)
        : Vehicle(_brand, _model, _year), numSeats(_numSeats) {}

    void displayInfo() {
        Vehicle::displayInfo();
        std::cout << "Seats: " << numSeats << std::endl;
    }
};

class Shuttle : public Vehicle {
    int passengerCapacity;

public:
    Shuttle(const std::string& _brand, const std::string& _model, int _year, int _passengerCapacity)
        : Vehicle(_brand, _model, _year), passengerCapacity(_passengerCapacity) {}

    void displayInfo() {
        Vehicle::displayInfo();
        std::cout << "Passenger Capacity: " << passengerCapacity << std::endl;
    }
};

class Bus : public Vehicle {
    int numSeats;
    int standingCapacity;

public:
    Bus(const std::string& _brand, const std::string& _model, int _year, int _numSeats, int _standingCapacity)
        : Vehicle(_brand, _model, _year), numSeats(_numSeats), standingCapacity(_standingCapacity) {}

    void displayInfo() {
        Vehicle::displayInfo();
        std::cout << "Seats: " << numSeats << ", Standing Capacity: " << standingCapacity << std::endl;
    }
};

int main() {
    Car car("Toyota", "Camry", 2022, 5);
    Shuttle shuttle("Ford", "Transit", 2023, 15);
    Bus bus("Volvo", "XCelsior", 2021, 40, 20);

    car.displayInfo();
    shuttle.displayInfo();
    bus.displayInfo();

    return 0;
}

/*
In this example, we have a base class Vehicle with common attributes like brand, model, and year. 
Then, we have three derived classes: Car, Shuttle, and Bus, each with their specific attributes. The displayInfo() method is overridden 
in each derived class to display the relevant information.
*/