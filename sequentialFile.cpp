#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Student
{
    int rollNo;
    char name[50];
    char division;
    char address[100];
};

void addStudent(){
    ofstream outFile("students.dat", ios::app | ios::binary);

    Student student;
    cout<<"Enter Roll No: ";
    cin>>student.rollNo;

    cout<<"Enter Name: ";
    cin.ignore();
    cin.getline(student.name, 50);

    cout<<"Enter Division: ";
    cin>>student.division;

    cout<<"Enter Address: ";
    cin.ignore();
    cin.getline(student.address, 100);

    outFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    outFile.close();

}

void deleteStudent(){
    int rollNo;
    cout<<"Enter Roll No of the Student to be deleted: ";
    cin>>rollNo;

    fstream file("students.dat", ios::in | ios::out | ios::binary);
    Student student;

    bool found = false;
    while(!file.eof()){
        file.read(reinterpret_cast<char*>(&student), sizeof(Student));
        if(student.rollNo == rollNo){
            found = true;
            break;
        }
    }

    if(found){
        file.seekg(-static_cast<int>(sizeof(Student)), ios::cur);

        student.rollNo = -1;

        file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
        cout<<"Student record deleted successfully.\n";
        
    }else{
        cout<<"Student record not found.\n";
    }
    file.close();
    
}

void displayStudent(){
    int rollNo;
    cout<<"Enter Roll No of the Student to be displayed: ";
    cin>>rollNo;

    ifstream file("students.dat", ios::binary);

    Student student;
    bool found = false;
    while(!file.eof()){
        file.read(reinterpret_cast<char*>(&student), sizeof(Student));
        if(student.rollNo == rollNo){
            found = true;
            break;
        }
    }

    if(found && student.rollNo != -1){
        cout<<"\n\tRecord Found...\n";
		cout<<"\n\tRoll\tName\tDiv\tAddress";
        cout<<"\n\t"<<student.rollNo<<"\t"<<student.name<<"\t"<<student.division<<"\t"<<student.address;
    }else{
        cout<<"Student record not found.\n";
    }\
    file.close();
}


int main(){
    int choice;
    
    do {
    
        cout<<"\n*********  MENU  *********"<<endl;
        cout << "1. Add a new Student\n";
        cout << "2. Delete a Student\n";
        cout << "3. Display a Student's details\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
    
        switch (choice){
            case 1:
            addStudent();
            break;
            case 2:
            deleteStudent();
            break;
            case 3:
            displayStudent();
            break;
            case 4:
            cout << "Exiting...\n";
            break;
            default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    }while (choice != 4);
    return 0;
}