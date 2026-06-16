// Created by Alec Vokral 06/15/26

#include "GroceryTracker.h"
#include <fstream>
#include <iostream>

GroceryTracker::GroceryTracker(const string& inputFile, const string& backupFile) {
    LoadData(inputFile);
    WriteBackup(backupFile);
}

void GroceryTracker::LoadData(const string& inputFile) {
    ifstream inFile(inputFile);
    string item;

    if (!inFile.is_open()) {
        cout << "Error: Could not open input file." << endl;
        return;
    }

    while (inFile >> item) {
        ++freqMap[item];
    }
}

void GroceryTracker::WriteBackup(const string& backupFile) const {
    ofstream outFile(backupFile);

    for (const auto& pair : freqMap) {
        outFile << pair.first << " " << pair.second << endl;
    }
}

int GroceryTracker::GetItemFrequency(const string& item) const {
    auto it = freqMap.find(item);
    if (it != freqMap.end()) {
        return it->second;
    }
    return 0;
}

void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : freqMap) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void GroceryTracker::PrintHistogram() const {
    for (const auto& pair : freqMap) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}
