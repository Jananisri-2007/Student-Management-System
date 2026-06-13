# Student Management System
The Student Management System is a console-based application developed in C++. It allows users to manage student records efficiently using file handling. The application provides functionalities to add, display, search, update, and delete student records.

Student data is stored permanently in a binary file (`students.dat`), ensuring that records remain available even after the program is closed.

---

## Features

* Add new student records
* Display all student records
* Search student by Roll Number
* Update existing student information
* Delete student records
* Permanent data storage using file handling
* Menu-driven interface

---

## Student Details Stored

Each student record contains:

* Roll Number
* Student Name
* Father Name
* Mother Name
* Mobile Number
* Marks

---

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* File Handling
* Classes and Objects
* Functions
* Binary Files

---

## File Structure

```text
StudentManagementSystem/
│
├── student_management.cpp
├── students.dat
├── temp.dat
└── README.md
```

### File Description

| File                   | Description                         |
| ---------------------- | ----------------------------------- |
| student_management.cpp | Source code of the project          |
| students.dat           | Stores student records permanently  |
| temp.dat               | Temporary file used during deletion |
| README.md              | Project documentation               |

---

## Program Menu

```text
========== STUDENT MANAGEMENT SYSTEM ==========
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

---

## Functions Used

### addStudent()

Adds a new student record and saves it to the file.

### displayStudents()

Displays all student records stored in the file.

### searchStudent()

Searches for a student using the Roll Number.

### updateStudent()

Updates the details of an existing student.

### deleteStudent()

Deletes a student record from the file.

---

## Sample Input

```text
Enter Roll Number: 1
Enter Student Name: S.Aakash
Enter Father Name: R.Moorthi
Enter Mother Name: S.Vani
Enter Mobile Number: 8680890821
Enter Marks: 97
```

---

## Sample Output

```text
RollNo    Name                Father              Mother              Mobile         Marks
1      S.Aakash              R.Moorthi            S.Vani              8680890821      97
```

---

## How to Compile

Using GCC Compiler:

```bash
g++ student_management.cpp -o student
```

---

## How to Run

### Windows

```bash
student.exe
```

### Linux / macOS

```bash
./student
```

---



