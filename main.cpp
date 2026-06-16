// Created by Alec Vokral 06/15/26

#include <iostream>
#include <string>
#include "GroceryTracker.h"
using namespace std;

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    int choice = 0;

    while (true) {
        cout << "\n1. Search item frequency\n";
        cout << "2. Print all item frequencies\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n";
            continue;
        }

        if (choice == 1) {
            string item;
            cout << "Enter item name: ";
            cin >> item;
            cout << item << " " << tracker.GetItemFrequency(item) << endl;
        }
        else if (choice == 2) {
            tracker.PrintAllFrequencies();
        }
        else if (choice == 3) {
            tracker.PrintHistogram();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Please choose 1–4.\n";
        }
    }

    return 0;
}
