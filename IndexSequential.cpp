#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    int employeeID;
    string name;
    string designation;
    double salary;
};

void addEmployee() {
    ofstream file("employees.txt", ios::app);
    
    Employee employee;
    
    cout << "Enter Employee ID: ";
    cin >> employee.employeeID;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, employee.name);
    cout << "Enter Designation: ";
    getline(cin, employee.designation);
    cout << "Enter Salary: ";
    cin >> employee.salary;
    
    file << employee.employeeID << "," << employee.name << "," << employee.designation << "," << employee.salary << endl;
    
    file.close();
    
    cout << "Employee added successfully!" << endl;
}

void deleteEmployee() {
    ifstream inFile("employees.txt");
    ofstream outFile("temp.txt");
    
    int employeeID;
    bool found = false;
    
    cout << "Enter Employee ID to delete: ";
    cin >> employeeID;
    
    Employee employee;
    string line;
    
    while (getline(inFile, line)) {
        size_t pos = line.find(",");
        employee.employeeID = stoi(line.substr(0, pos));
        line = line.substr(pos + 1);
        
        pos = line.find(",");
        employee.name = line.substr(0, pos);
        line = line.substr(pos + 1);
        
        pos = line.find(",");
        employee.designation = line.substr(0, pos);
        line = line.substr(pos + 1);
        
        employee.salary = stod(line);
        
        if (employee.employeeID != employeeID) {
            outFile << line << endl;
        } else {
            found = true;
        }
    }
    
    inFile.close();
    outFile.close();
    
    remove("employees.txt");
    rename("temp.txt", "employees.txt");
    
    if (found) {
        cout << "Employee deleted successfully!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

void displayEmployee() {
    ifstream file("employees.txt");
    
    int employeeID;
    bool found = false;
    
    cout << "Enter Employee ID to display: ";
    cin >> employeeID;
    
    Employee employee;
    string line;
    
    while (getline(file, line)) {
        size_t pos = line.find(",");
        employee.employeeID = stoi(line.substr(0, pos));
        line = line.substr(pos + 1);
        
        pos = line.find(",");
        employee.name = line.substr(0, pos);
        line = line.substr(pos + 1);
        
        pos = line.find(",");
        employee.designation = line.substr(0, pos);
        line = line.substr(pos + 1);
        
        employee.salary = stod(line);
        
        if (employee.employeeID == employeeID) {
            found = true;
            break;
        }
    }
    
    file.close();
    
    if (found) {
        cout << "Employee Details:" << endl;
        cout << "Employee ID: " << employee.employeeID << endl;
        cout << "Name: " << employee.name << endl;
        cout << "Designation: " << employee.designation << endl;
        cout << "Salary: " << employee.salary << endl;
    }else {
        cout << "Employee not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "-------------------------" << endl;
        cout << "Company Employee System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }while (choice != 4);

    return 0;
}