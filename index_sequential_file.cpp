#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    char division;
    string address;
};

// structure for the index
struct Index {
    int rollNo;
    int offset;
};

// function to add a new student record
void addStudent() {
    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Division: ";
    cin >> student.division;
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, student.address);

    // append new record to file
    ofstream outFile("students.dat", ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error: Could not open file for writing" << endl;
        return;
    }
    outFile.write((char*)&student, sizeof(Student));
    outFile.close();

    // update the index
    ofstream indexFile("index.dat", ios::binary | ios::app);
    if (!indexFile) {
        cerr << "Error: Could not open index file for writing" << endl;
        return;
    }
    Index index;
    index.rollNo = student.rollNo;
    index.offset = sizeof(Student);
    indexFile.write((char*)&index, sizeof(Index));
    indexFile.close();

    cout << "Record added successfully!" << endl;
}

// function to display a student record
void displayStudent(int rollNo) {
    ifstream indexFile("index.dat", ios::binary);
    Index index;
    bool found = false;
    while (indexFile.read((char*)&index, sizeof(Index))) {
        if (index.rollNo == rollNo) {
            found = true;
            break;
        }
    }
    indexFile.close();

    if (found) {
        ifstream dataFile("students.dat", ios::binary);
        dataFile.seekg(index.offset, ios::beg);
        Student student;
        dataFile.read((char*)&student, sizeof(Student));
        dataFile.close();

        cout << "Roll Number: " << student.rollNo << endl;
        cout << "Name: " << student.name << endl;
        cout << "Division: " << student.division << endl;
        cout << "Address: " << student.address << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}

// function to delete a student record
void deleteStudent(int rollNo) {
    ifstream indexFile("index.dat", ios::binary);
    Index index;
    bool found = false;
    while (indexFile.read((char*)&index, sizeof(Index))) {
        if (index.rollNo == rollNo) {
            found = true;
            break;
        }
    }
    indexFile.close();

    if (found) {
        ifstream dataFile("students.dat", ios::binary);
        ofstream tempFile("temp.dat", ios::binary);
        int recordOffset = 0;
        while (dataFile.read((char*)&index, sizeof(Index))) {
            if (index.rollNo != rollNo) {
                tempFile.write((char*)&index, sizeof(Index));
            } else {
                recordOffset = index.offset;
            }
        }
        dataFile.close();
        tempFile.close();

        // update the index after deletion
        ofstream updatedIndexFile("index.dat", ios::binary);
        dataFile.open("temp.dat", ios::binary);
    while (dataFile.read((char*)&index, sizeof(Index))) {
        if (index.offset > recordOffset) {
            index.offset -= sizeof(Student);
        }
        updatedIndexFile.write((char*)&index, sizeof(Index));
    }
    dataFile.close();
    updatedIndexFile.close();

    // delete the temporary file
    remove("temp.dat");

    cout << "Record deleted successfully!" << endl;
} else {
    cout << "Record not found!" << endl;
}
}

int main() {
int choice, rollNo;
while (true) {
    cout << "1. Add Student" << endl;
    cout << "2. Display Student" << endl;
    cout << "3. Delete Student" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            displayStudent(rollNo);
            break;
        case 3:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            deleteStudent(rollNo);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
    }
}

return 0;
}