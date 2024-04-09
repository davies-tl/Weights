/*
Analysis-> Take a file from the user, and read a list of weights in pounds (integer) and coresponding names; store this information
           in two different arrays (CAP 10) and output both. Then calculate the weight in kilograms with two decimals (1kg = 2.2lbs)
           for a third array. Print the Average (two decimals), the High, and the Low; print the arrays in a table format;
           then print the arrays sorted from least to heaviest weight
Design:
   Input-> This problem might seem like it should read information from a file to store in three different arrays. Instead, I will be using one
           array of type struct; this will be much clearer.
   Process-> OpenFile Function
             ReadArray Function
             WriteToArray Function
             CalculateAverage Function
             CalculateHighest Function
             CalculateLowest Function
             OutputArray Function
             SortArray Function
*/

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#define CAP 10

using namespace std;

struct personWeight {
    string name;
    int lbs;
    float kg;
};

bool OpenFile(ifstream& inFS);
int ReadArray(personWeight userArray[], int size);
void ReadPerson(personWeight& currentUser, ifstream& inFS);
void ProcessArray(personWeight userArray[], int size);
float PoundsToKilograms(int userPounds);
void PrintAverage(personWeight userArray[], int size);
void PrintHighest(personWeight userArray[], int size);
void PrintLowest(personWeight userArray[], int size);
void ListInput(personWeight userArray[], int size);
void OutputArray(personWeight userArray[], int size);
void SortArray(personWeight userArray[], int size);

int main() {
    personWeight userArray[CAP];
    int size;
    string fileName;
    ifstream inFS;

    cout << "Enter file name:" << endl;
    cin >> fileName;
    
    inFS.open(fileName.c_str());

    size = ReadArray(userArray, CAP);
    ReadArray(userArray, size);
    ListInput(userArray, size);
    cout << left << fixed << showpoint << setprecision(2) << endl;
    ProcessArray(userArray, size);
    PrintAverage(userArray, size);
    PrintHighest(userArray, size);
    PrintLowest(userArray, size);
    cout << endl;
    OutputArray(userArray, size);
    cout << endl;

    exit(0);
}

int ReadArray(personWeight userArray[], int size) {
    ifstream	inFS;
    int i = 0;
    if (OpenFile(inFS)) {
        while (!inFS.eof()) {
            ReadPerson(userArray[i], inFS);
            ++i;
        }
        inFS.close();
    }
    return i;
}

void ReadPerson(personWeight& currentUser, ifstream& inFS) {
    getline(inFS, currentUser.name);
    inFS >> currentUser.lbs;
    inFS.ignore(10, '\n');
}

void ProcessArray(personWeight userArray[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        userArray[i].kg = PoundsToKilograms(userArray[i].lbs);
    }
}

float PoundsToKilograms(int userPounds) {
    float userKilograms;
    userKilograms = userPounds / 2.2;
    return userKilograms;
}

void PrintAverage(personWeight userArray[], int size) {
    float averageLBS, averageKG, numSum = 0.0;
    int i;
    for (i = 0; i < size; ++i) {
        numSum = numSum + userArray[i].lbs;
    }
    averageLBS = numSum / size;
    averageKG = PoundsToKilograms(averageLBS);
    cout << setw(15) << "Average:" << averageLBS << setw(10) << " lbs" << averageKG << " Kilograms" << endl;
}

void PrintHighest(personWeight userArray[], int size) {
    int i, highLBS, highKG;
    highLBS = userArray[0].lbs;
    for (i = 1; i < size; ++i) {
        if (highLBS < userArray[i].lbs) {
            highLBS = userArray[i].lbs;
        }
    }
    highKG = PoundsToKilograms(highLBS);
    cout << setw(15) << "High:" << highLBS << setw(10) << " lbs" << highKG << " Kilograms" << endl;
}

void PrintLowest(personWeight userArray[], int size) {
    int i, lowLBS, lowKG;
    lowLBS = userArray[0].lbs;
    for (i = 1; i < size; ++i) {
        if (lowLBS > userArray[i].lbs) {
            lowLBS = userArray[i].lbs;
        }
    }
    lowKG = PoundsToKilograms(lowLBS);
    cout << setw(15) << "Low:" << lowLBS << setw(10) << " lbs" << lowKG << " Kilograms" << endl;
}

void ListInput(personWeight userArray[], int size) {
    int i;
    cout << "Weights: ";
    for (i = 0; i < size; ++i) {
        cout << userArray[i].lbs << " ";
    }
    cout << endl << "Names: ";
    for (i = 0; i < size; ++i) {
        cout << userArray[i].name << " ";
    }
    cout << endl;
}

void OutputArray(personWeight userArray[], int size) {
    int i;
    cout << setw(15) << "Name" << setw(15) << "Lbs" << "Kilograms" << endl;
    for (i = 0; i < size; ++i) {
        cout << setw(15) << userArray[i].name << setw(15) << userArray[i].lbs << userArray[i].kg << endl;
    }
}


void SortArray(personWeight userArray[], int size) {}