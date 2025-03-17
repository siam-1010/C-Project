#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

class ContactManager {
private:
    vector<Contact> contacts;
    const string filename = "contacts.txt";

    void loadFromFile() {
        contacts.clear();
        ifstream file(filename);
        if (!file) return;

        Contact temp;
        while (getline(file, temp.name) && getline(file, temp.phone) && getline(file, temp.email)) {
            contacts.push_back(temp);
        }
        file.close();
    }

    void saveToFile() {
        ofstream file(filename, ios::trunc);
        for (const auto &c : contacts) {
            file << c.name << endl;
            file << c.phone << endl;
            file << c.email << endl;
        }
        file.close();
    }

public:
    ContactManager() {
        loadFromFile();
    }

    void addContact() {
        Contact newContact;
        cout << "Enter Name: ";
        getline(cin, newContact.name);
        cout << "Enter Phone: ";
        getline(cin, newContact.phone);
        cout << "Enter Email: ";
        getline(cin, newContact.email);

        contacts.push_back(newContact);
        saveToFile();
        cout << "Contact added successfully.\n";
    }

    void viewContacts() {
        if (contacts.empty()) {
            cout << "No contacts available.\n";
            return;
        }
        cout << "\nContacts List:\n";
        cout << left << setw(20) << "Name" << setw(15) << "Phone" << "Email" << endl;
        cout << string(50, '-') << endl;
        for (const auto &c : contacts) {
            cout << left << setw(20) << c.name << setw(15) << c.phone << c.email << endl;
        }
    }

    void searchContact() {
        cout << "Enter name to search: ";
        string name;
        getline(cin, name);

        for (const auto &c : contacts) {
            if (c.name == name) {
                cout << "Found Contact:\n";
                cout << "Name: " << c.name << "\nPhone: " << c.phone << "\nEmail: " << c.email << "\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void deleteContact() {
        cout << "Enter name to delete: ";
        string name;
        getline(cin, name);
        
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                saveToFile();
                cout << "Contact deleted successfully.\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }
};

int main() {
    ContactManager cm;
    int choice;
    do {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n2. View Contacts\n3. Search Contact\n4. Delete Contact\n5. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: cm.addContact(); break;
            case 2: cm.viewContacts(); break;
            case 3: cm.searchContact(); break;
            case 4: cm.deleteContact(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}