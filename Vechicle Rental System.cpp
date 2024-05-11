#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Forward declarations
class RentalAgency;

class Vehicle {
protected:
    string vehicleID;
    string model;
    string manufacturer;
    double rentalCostPerDay;

public:
    Vehicle(string ID, string mdl, string man, double cost)
        : vehicleID(ID), model(mdl), manufacturer(man), rentalCostPerDay(cost) {}

    virtual ~Vehicle() {} // Virtual destructor for correct deletion of derived objects

    virtual void displayDetails() const {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Model: " << model << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Rental Cost per Day: $" << rentalCostPerDay << endl;
    }

    virtual double calculateRentalCost(int days) const {
        return rentalCostPerDay * days;
    }

    string getVehicleID() const {
        return vehicleID;
    }
};

class Car : public Vehicle {
private:
    int numberOfSeats;
    string fuelType;

public:
    Car(string ID, string mdl, string man, double cost, int seats, string fuel)
        : Vehicle(ID, mdl, man, cost), numberOfSeats(seats), fuelType(fuel) {}

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Number of Seats: " << numberOfSeats << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Bike : public Vehicle {
private:
    int engineCapacity;
    string bikeType;

public:
    Bike(string ID, string mdl, string man, double cost, int capacity, string type)
        : Vehicle(ID, mdl, man, cost), engineCapacity(capacity), bikeType(type) {}

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Engine Capacity: " << engineCapacity << " cc" << endl;
        cout << "Bike Type: " << bikeType << endl;
    }
};

class Customer {
private:
    string customerID;
    string name;
    string contactInfo;
    Vehicle* rentedVehicle;
    int rentalDuration;

public:
    Customer(string ID, string nm, string info)
        : customerID(ID), name(nm), contactInfo(info), rentedVehicle(nullptr), rentalDuration(0) {}

    void rentVehicle(Vehicle* vehicle, int duration) {
        rentedVehicle = vehicle;
        rentalDuration = duration;
    }

    void returnVehicle() {
        delete rentedVehicle; // Deallocate memory
        rentedVehicle = nullptr;
        rentalDuration = 0;
    }

    void displayRentalDetails() const {
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << name << endl;
        cout << "Contact Information: " << contactInfo << endl;
        if (rentedVehicle != nullptr) {
            cout << "Rented Vehicle Details:" << endl;
            rentedVehicle->displayDetails();
            cout << "Rental Duration: " << rentalDuration << " days" << endl;
            cout << "Total Rental Cost: $" << rentedVehicle->calculateRentalCost(rentalDuration) << endl;
        } else {
            cout << "No vehicle rented." << endl;
        }
    }
};

class RentalAgency {
private:
    vector<Vehicle*> inventory;

public:
    // Function to add a vehicle to the inventory
    void addVehicleToInventory() {
        string ID, model, manufacturer;
        double cost;
        int seats, capacity;
        string fuelType, bikeType;
        char vehicleType;

        cout << "Enter Vehicle ID: ";
        cin >> ID;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Manufacturer: ";
        cin >> manufacturer;
        cout << "Enter Rental Cost per Day: ";
        cin >> cost;

        cout << "Is it a car or bike? (c/b): ";
        cin >> vehicleType;

        if (vehicleType == 'c') {
            cout << "Enter Number of Seats: ";
            cin >> seats;
            cout << "Enter Fuel Type: ";
            cin >> fuelType;
            Car* car = new Car(ID, model, manufacturer, cost, seats, fuelType);
            inventory.push_back(car);
        } else if (vehicleType == 'b') {
            cout << "Enter Engine Capacity (in cc): ";
            cin >> capacity;
            cout << "Enter Bike Type: ";
            cin >> bikeType;
            Bike* bike = new Bike(ID, model, manufacturer, cost, capacity, bikeType);
            inventory.push_back(bike);
        } else {
            cout << "Invalid vehicle type. Please enter 'c' for car or 'b' for bike." << endl;
        }
    }

    // Function to rent a vehicle
    void rentVehicle() {
        string customerID, name, contactInfo;
        int rentalDuration;
        string vehicleID;

        cout << "Enter Customer ID: ";
        cin >> customerID;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Contact Information: ";
        cin >> contactInfo;
        cout << "Enter Rental Duration (in days): ";
        cin >> rentalDuration;

        cout << "Enter Vehicle ID to Rent: ";
        cin >> vehicleID;

        // Find the vehicle in inventory
        Vehicle* vehicle = nullptr;
        for (auto& v : inventory) {
            if (v->getVehicleID() == vehicleID) {
                vehicle = v;
                break;
            }
        }

        if (vehicle != nullptr) {
            // Create a new customer and rent the vehicle to them
            Customer customer(customerID, name, contactInfo);
            customer.rentVehicle(vehicle, rentalDuration);
            cout << "Vehicle rented successfully!" << endl;
        } else {
            cout << "Vehicle not found in inventory." << endl;
        }
    }


    // Inside the RentalAgency class definition
    void displayInventory() const {
        if (inventory.empty()) {
            cout << "Inventory is empty." << endl;
        } else {
            cout << "Inventory:\n";
            for (const auto& vehicle : inventory) {
                vehicle->displayDetails();
                cout << endl;
            }
        }
    }
};

int main() {
    RentalAgency agency;

    char choice;
    do {
        cout << "Welcome to the Vehicle Rental System!" << endl;
        cout << "---------------------------------------" << endl;
        cout << "1. View Inventory" << endl;
        cout << "2. Add a Vehicle to Inventory" << endl;
        cout << "3. Rent a Vehicle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                agency.displayInventory();
                break;
            case '2':
                agency.addVehicleToInventory();
                break;
            case '3':
                agency.rentVehicle();
                break;
            case '4':
                cout << "Exiting the Vehicle Rental System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != '4');

    return 0;
}
