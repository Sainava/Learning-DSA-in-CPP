#include <iostream>
using namespace std;

// Base class
class Employee {
protected:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}
    virtual bool isTargetAchieved() ; // Pure virtual function
    virtual void displayDetails() {
        cout << "Employee Name: " << name << ", ID: " << id << endl;
    }
    virtual ~Employee() {}
};

// Derived class for Manager
class Manager : public Employee {
    double funds;
public:
    Manager(string n, int i, double f) : Employee(n, i), funds(f) {}
    bool isTargetAchieved() override {
        return funds >= 2000000; // Target is 20 lakh
    }
    void displayDetails() override {
        Employee::displayDetails();
        cout << "Funds Maintained: " << funds << " INR" << endl;
    }
};

// Derived class for MarketingOfficer
class MarketingOfficer : public Employee {
    int accountsOpened;
public:
    MarketingOfficer(string n, int i, int a) : Employee(n, i), accountsOpened(a) {}
    bool isTargetAchieved() override {
        return accountsOpened >= 10; // Target is 10 accounts
    }
    void displayDetails() override {
        Employee::displayDetails();
        cout << "Accounts Opened: " << accountsOpened << endl;
    }
};

int main() {
    // Array of pointers to Employee (fixed size, e.g., 4 employees)
    const int numEmployees = 4;
    Employee* employees[numEmployees];

    // Populate the array with different types of employees
    employees[0] = new Manager("Alice", 101, 2500000);  // Achieved
    employees[1] = new Manager("Bob", 102, 1500000);    // Not achieved
    employees[2] = new MarketingOfficer("Charlie", 201, 12); // Achieved
    employees[3] = new MarketingOfficer("Daisy", 202, 8);     // Not achieved

    // Display employees to be terminated
    cout << "Employees to be terminated:\n";
    for (int i = 0; i < numEmployees; i++) {
        if (!employees[i]->isTargetAchieved()) {
            employees[i]->displayDetails();
            cout << "Reason: Target not achieved.\n\n";
        }
    }

    // Cleanup
    for (int i = 0; i < numEmployees; i++) {
        delete employees[i];
    }

    return 0;
}
