#include <iostream> 
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct Medicine {
    string name;
    double price;
    double cost;
    string company;

// Function to display a single medicine's details
    void display() const {
        cout << left << "| " << setw(15) << name
             << "| " << setw(10) << price
             << "| " << setw(10) << cost
             << "| " << setw(15) << company << " |" << endl;
             
    }
};

// Class to manage the collection of medicines

class MedicineShop {
private:
    vector<Medicine> medicines; // Vector to store medicines

public:
    // Function to add a new medicine to the collection
    void addMedicine(const string& name, double price, double cost, const string& company) {
        medicines.push_back({name, price, cost, company});
    }

    // Function to list all medicines in the collection
    void listMedicines() const {
        cout << "------------------------------------------------------------------" << endl;
        cout << "| " << left << setw(15) << "Name"
             << "| " << setw(10) << "Price"
             << "| " << setw(10) << "Cost"
             << "| " << setw(15) << "Company" << " |" << endl;
        cout << "------------------------------------------------------------------" << endl;
        for (const auto& med : medicines) {
            med.display();
        }
        cout << "------------------------------------------------------------------" << endl;
    }

// Function to search for medicines by cost
    void searchByCost(double cost) const {
        bool found = false;
        cout << "------------------------------------------------------------------" << endl;
        cout << "| " << left << setw(15) << "Name"
             << "| " << setw(10) << "Price"
             << "| " << setw(10) << "Cost"
             << "| " << setw(15) << "Company" << " |" << endl;
        cout << "------------------------------------------------------------------" << endl;
        for (const auto& med : medicines) {
            if (med.cost == cost) {
                med.display();
                found = true;
            }
        }
        if (!found) {
            cout << "| No medicine found with cost: " << setw(40) << cost << " |" << endl;
        }
        cout << "------------------------------------------------------------------" << endl;
    }

 // Function to sort medicines by price

    void sortByPrice() {
        sort(medicines.begin(), medicines.end(), [](const Medicine& a, const Medicine& b) {
            return a.price < b.price;
        });
        cout << "Medicines sorted by price.\n";
    }
};

// Function to display the menu
void displayMenu() {
    cout << "-----------------------------" << endl;
    cout << "|          Menu             |" << endl;
    cout << "-----------------------------" << endl;
    cout << "| 1. List all medicines     |" << endl;
    cout << "| 2. Search medicine by cost|" << endl;
    cout << "| 3. Sort medicines by price|" << endl;
    cout << "| 4. Add new medicine       |" << endl;
    cout << "| 5. Exit                   |" << endl;
    cout << "-----------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    MedicineShop shop;
    int choice;

    do {
        // Display the menu
        displayMenu();
        cin >> choice;

        // Handle invalid input
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
            cin >> choice;
        }

        // Process the user's choice
        switch (choice) {
            case 1:
                shop.listMedicines();
                break;
            case 2: {
                double cost;
                cout << "Enter cost to search: ";
                cin >> cost;
                shop.searchByCost(cost);
                break;
            }
            case 3:
                shop.sortByPrice();
                shop.listMedicines();
                break;
            case 4: {
                string name, company;
                double price, cost;
                cout << "Enter medicine name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, name);
                cout << "Enter medicine price: ";
                cin >> price;
                cout << "Enter medicine cost: ";
                cin >> cost;
                cout << "Enter company name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, company);
                shop.addMedicine(name, price, cost, company);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}