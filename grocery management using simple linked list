#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Node structure
struct Node {
    int id;
    string name;
    int quantity;
    float price;
    Node* next;
};

Node* head = nullptr;

// Add a new grocery item
void addItem() {
    Node* newNode = new Node;

    cout << "\nEnter Item ID: ";
    cin >> newNode->id;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->id == newNode->id) {
            cout << "Item ID already exists!\n";
            delete newNode;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Item Name: ";
    cin >> ws;
    getline(cin, newNode->name);

    cout << "Enter Quantity: ";
    cin >> newNode->quantity;

    cout << "Enter Price per Item: ";
    cin >> newNode->price;

    if (newNode->quantity < 0 || newNode->price < 0) {
        cout << "Quantity and price cannot be negative.\n";
        delete newNode;
        return;
    }

    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Grocery item added successfully!\n";
}

// Display all grocery items
void displayItems() {
    if (head == nullptr) {
        cout << "\nNo grocery items available.\n";
        return;
    }

    Node* temp = head;

    cout << "\n----------- Grocery Inventory -----------\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(12) << "Quantity"
         << "Price\n";

    while (temp != nullptr) {
        cout << left << setw(10) << temp->id
             << setw(20) << temp->name
             << setw(12) << temp->quantity
             << fixed << setprecision(2)
             << temp->price << '\n';

        temp = temp->next;
    }
}

// Search for a grocery item
void searchItem() {
    int id;
    cout << "\nEnter Item ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "\nItem Found!\n";
            cout << "ID: " << temp->id << '\n';
            cout << "Name: " << temp->name << '\n';
            cout << "Quantity: " << temp->quantity << '\n';
            cout << "Price: Rs. " << temp->price << '\n';
            return;
        }
        temp = temp->next;
    }

    cout << "Item not found.\n";
}

// Update a grocery item
void updateItem() {
    int id;
    cout << "\nEnter Item ID to update: ";
    cin >> id;

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Enter new quantity: ";
            cin >> temp->quantity;

            cout << "Enter new price: ";
            cin >> temp->price;

            if (temp->quantity < 0 || temp->price < 0) {
                cout << "Invalid quantity or price.\n";
                return;
            }

            cout << "Item updated successfully!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Item not found.\n";
}

// Delete a grocery item
void deleteItem() {
    int id;
    cout << "\nEnter Item ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* previous = nullptr;

    while (temp != nullptr && temp->id != id) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item not found.\n";
        return;
    }

    if (previous == nullptr) {
        head = temp->next;
    } else {
        previous->next = temp->next;
    }

    delete temp;
    cout << "Item deleted successfully!\n";
}

// Calculate total inventory value
void totalValue() {
    float total = 0;
    Node* temp = head;

    while (temp != nullptr) {
        total += temp->quantity * temp->price;
        temp = temp->next;
    }

    cout << "\nTotal Inventory Value: Rs. "
         << fixed << setprecision(2) << total << '\n';
}

// Free allocated memory
void freeMemory() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== Grocery Item Management System =====\n";
        cout << "1. Add Grocery Item\n";
        cout << "2. Display All Items\n";
        cout << "3. Search Item\n";
        cout << "4. Update Item\n";
        cout << "5. Delete Item\n";
        cout << "6. Calculate Total Inventory Value\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                totalValue();
                break;
            case 0:
                freeMemory();
                cout << "Thank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
