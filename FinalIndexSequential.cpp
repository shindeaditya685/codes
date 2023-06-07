#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

struct Employee {
    int employeeID;
    string name;
    string designation;
    double salary;
};

void addEmployee(map<int, streampos>& index) {
    ofstream dataFile("employees.txt", ios::app);
    ofstream indexFile("index.txt", ios::app);
    
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
    
    dataFile.seekp(0, ios::end);
    streampos position = dataFile.tellp();
    
    dataFile << employee.employeeID << "," << employee.name << "," << employee.designation << "," << employee.salary << endl;
    index[employee.employeeID] = position;
    
    indexFile << employee.employeeID << "," << position << endl;
    
    dataFile.close();
    indexFile.close();
    
    cout << "Employee added successfully!" << endl;
}

void deleteEmployee(map<int, streampos>& index) {
    ifstream dataFile("employees.txt");
    ofstream tempDataFile("temp.txt");
    ofstream tempIndexFile("temp_index.txt");
    
    int employeeID;
    bool found = false;
    
    cout << "Enter Employee ID to delete: ";
    cin >> employeeID;
    
    Employee employee;
    string line;
    
    while (getline(dataFile, line)) {
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
            tempDataFile << line << endl;
            tempIndexFile << employee.employeeID << "," << index[employee.employeeID] << endl;
        } else {
            found = true;
        }
    }
    
    dataFile.close();
    tempDataFile.close();
    tempIndexFile.close();
    
    remove("employees.txt");
    remove("index.txt");
    rename("temp.txt", "employees.txt");
    rename("temp_index.txt", "index.txt");
    
    if (found) {
        cout << "Employee deleted successfully!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

void displayEmployee(const map<int, streampos>& index) {
    ifstream dataFile("employees.txt");
    
    int employeeID;
    bool found = false;
    
    cout << "Enter Employee ID to display: ";
    cin >> employeeID;
    
    Employee employee;
    string line;
    
    if (index.find(employeeID) != index.end()) {
        dataFile.seekg(index.at(employeeID));
        
        getline(dataFile, line);
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
        
        found = true;
    }
    
    dataFile.close();
    
    if (found) {
        cout << "Employee Details:" << endl;
        cout << "Employee ID: " << employee.employeeID << endl;
        cout << "Name: " << employee.name << endl;
        cout << "Designation: " << employee.designation << endl;
        cout << "Salary: " << employee.salary << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

int main() {
    map<int, streampos> index;
    
    // Load index from file
    ifstream indexFile("index.txt");
    string line;
    while (getline(indexFile, line)) {
        size_t pos = line.find(",");
        int employeeID = stoi(line.substr(0, pos));
        streampos position = stoll(line.substr(pos + 1));
        index[employeeID] = position;
    }
    indexFile.close();
    
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
                addEmployee(index);
                break;
            case 2:
                deleteEmployee(index);
                break;
            case 3:
                displayEmployee(index);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
