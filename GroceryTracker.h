// Created by Alec Vokral 06/15/26

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>
using namespace std;

class GroceryTracker {
public:
    GroceryTracker(const string& inputFile, const string& backupFile);

    int GetItemFrequency(const string& item) const;
    void PrintAllFrequencies() const;
    void PrintHistogram() const;

private:
    map<string, int> freqMap;

    void LoadData(const string& inputFile);
    void WriteBackup(const string& backupFile) const;
};

#endif
