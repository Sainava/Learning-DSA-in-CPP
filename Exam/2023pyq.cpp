#include <iostream>
#include <string>
using namespace std;

class Electricity {
protected:
    double total_cost;  // Stores the total cost before surcharge
public:
    // Function to calculate the electricity charges
    virtual void calculateCharges(int units) {
        total_cost = 0;
        
        // Calculate charges based on units consumed
        if (units <= 100) {
            total_cost = units * 0.50; // 50 paise per unit for first 100 units
        } else if (units <= 300) {
            total_cost = 100 * 0.50 + (units - 100) * 0.60; // 60 paise for next 200 units
        } else {
            total_cost = 100 * 0.50 + 200 * 0.60 + (units - 300) * 1.50; // 1.50 Rs for beyond 300 units
        }

        // Ensure the minimum charge is Rs. 3000
        if (total_cost < 3000) {
            total_cost = 3000;
        }

        // Apply a surcharge of 20% if the total cost exceeds Rs. 2000
        if (total_cost > 2000) {
            total_cost *= 1.20;  // Adding 20% surcharge
        }
    }

    // Virtual function to display the charges (to be overridden in derived class)
    virtual void display() const {
        cout << "Total Charge: Rs. " << total_cost << endl;
    }
};

class Bill : public Electricity {
private:
    string name;
    int units;

public:
    // Function to read name and units consumed from the user
    void readData() {
        cout << "Enter the name of the user: ";
        cin.ignore();  // To ignore the newline character before string input
        getline(cin, name);
        cout << "Enter the number of units consumed: ";
        cin >> units;
        cin.ignore();  // To ignore the newline character after integer input
        Electricity::calculateCharges(units);
    }

    // // Function to calculate charges (inherited from base class)
    // void calculateCharges(int units) {
        
    // }
    // int getUnits() const {
    //     return units;
    // }
    // Display user details and charges
    void display() const {
        cout << "User: " << name << endl;
        cout << "Units Consumed: " << units << endl;
        Electricity::display();
    }
};

int main() {
     int N ;
    cout<<"Input the number of users: " ;// Number of users
    cin>>N;
    Bill *users=new Bill[N];

    // Read data and display charges for all users
    for (int i = 0; i < N; i++) {
        users[i].readData();
       // users[i].calculateCharges(users[i].getUnits());
        users[i].display();
    }

    return 0;
}
