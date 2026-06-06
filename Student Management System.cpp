#include <iostream>    //For input and output
#include <fstream>     //For File Handling
#include <iomanip>     //For Formatting output
#include <cstring>     //For String Operations

using namespace std;
//Student Class to Store Student Information

class Student {
public:
    int rollNo;             //Student Roll number
    char name[50];          //Student Name
    char fatherName[50];    //Father's Name
    char motherName[50];    //Mother's Name
    char mobile[15];        //Mobile Number
    float marks;            //Student Mark

    //Function to Take Input from User
    void input() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;
        cin.ignore();

        cout << "Enter Student Name: ";
        cin.getline(name, 50);

        cout << "Enter Father Name: ";
        cin.getline(fatherName, 50);

        cout << "Enter Mother Name: ";
        cin.getline(motherName, 50);

        cout << "Enter Mobile Number: ";
        cin.getline(mobile, 15);

        cout << "Enter Marks: ";
        cin >> marks;
    }

//Function to Display Student Details in Table Format
    void display() {
        cout << left
             << setw(10) << rollNo
             << setw(20) << name
             << setw(20) << fatherName
             << setw(20) << motherName
             << setw(15) << mobile
             << setw(10) << marks
             << endl;
    }
};

//Function to add a new Student Record
void addStudent() {
    Student s;

    //Open File in Append mode
    ofstream file("students.dat", ios::binary | ios::app);

    s.input();
    //Write Object into File
    file.write((char*)&s, sizeof(s));

    file.close();

    cout << "\nStudent Added Successfully!\n";
}

//Function to display all Student records
void displayStudents() {
    Student s;

    //Open File for reading
    ifstream file("students.dat", ios::binary);

    cout << "\n=========================================================================================\n";
    cout << left
         << setw(10) << "RollNo"
         << setw(20) << "Name"
         << setw(20) << "Father"
         << setw(20) << "Mother"
         << setw(15) << "Mobile"
         << setw(10) << "Marks"
         << endl;

    cout << "=========================================================================================\n";

    //Read records one by one
    while (file.read((char*)&s, sizeof(s))) {
        s.display();
    }

    file.close();
}

//Function to Search a Student Using Roll number
void searchStudent() {
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    ifstream file("students.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {

        //Check if Roll number matches
        if (s.rollNo == roll) {
            cout << "\nStudent Found:\n\n";

            cout << "Roll Number : " << s.rollNo << endl;
            cout << "Name        : " << s.name << endl;
            cout << "Father Name : " << s.fatherName << endl;
            cout << "Mother Name : " << s.motherName << endl;
            cout << "Mobile No   : " << s.mobile << endl;
            cout << "Marks       : " << s.marks << endl;

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nStudent Not Found!\n";
}

//Function to Update an existing Student Record
void updateStudent() {
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    //Open File in Read and write mode
    fstream file("students.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&s, sizeof(s))) {
        //Search for Matching roll number
        if (s.rollNo == roll) {

            cout << "\nEnter New Details:\n";

            s.input();

            //Move File pointer back to Current record position
            file.seekp(-sizeof(s), ios::cur);

            //Overwrite old record
            file.write((char*)&s, sizeof(s));

            cout << "\nRecord Updated Successfully!\n";

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nStudent Not Found!\n";
}

//Function to delete a Student record
void deleteStudent() {
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    ifstream file("students.dat", ios::binary);

    //Temporary file
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {

        //Skip record to be deleted
        if (s.rollNo == roll) {
            found = true;
        } else {
            //Copy remaining records
            temp.write((char*)&s, sizeof(s));
        }
    }

    file.close();
    temp.close();

    //Replace Original file with temp File
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "\nStudent Deleted Successfully!\n";
    else
        cout << "\nStudent Not Found!\n";
}

//Main Function
int main() {
    int choice;

    do {
        cout << "\n\n========== STUDENT MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
