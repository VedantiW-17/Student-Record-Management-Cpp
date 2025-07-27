#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll;
    float marks;

    void input() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Name: " << name << "\n";
        cout << "Roll No: " << roll << "\n";
        cout << "Marks: " << marks << "\n";
        cout << "--------------------------\n";
    }
};

// Array-based storage
Student students[100]; // supports up to 100 students
int studentCount = 0;

// Function to add a new student
void addStudent() {
    if (studentCount < 100) {
        students[studentCount].input();
        studentCount++;
        cout << "Student added successfully.\n";
    } else {
        cout << "Student limit reached!\n";
    }
}

// Function to display all students
void displayAll() {
    if (studentCount == 0) {
        cout << "No student records found.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        students[i].display();
    }
}

// Function to search student by roll number
void searchStudent() {
    int r;
    cout << "Enter Roll No to search: ";
    cin >> r;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == r) {
            students[i].display();
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to modify student details
void modifyStudent() {
    int r;
    cout << "Enter Roll No to modify: ";
    cin >> r;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == r) {
            cout << "Enter new details:\n";
            students[i].input();
            cout << "Student modified successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to delete a student
void deleteStudent() {
    int r;
    cout << "Enter Roll No to delete: ";
    cin >> r;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == r) {
            // shift all elements left
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Modify Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
