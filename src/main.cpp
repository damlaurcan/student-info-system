#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    string department;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter student id: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, s.name);
    cout << "Enter department: ";
    getline(cin, s.department);
    students.push_back(s);
    cout << "Student added successfully.\n";
}

void listStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    for (const auto& s : students) {
        cout << "ID: " << s.id
             << ", Name: " << s.name
             << ", Department: " << s.department << endl;
    }
}

void updateStudent() {
    int id;
    cout << "Enter student id to update: ";
    cin >> id;
    cin.ignore();

    for (auto& s : students) {
        if (s.id == id) {
            cout << "Enter new name: ";
            getline(cin, s.name);
            cout << "Enter new department: ";
            getline(cin, s.department);
            cout << "Student updated successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    int id;
    cout << "Enter student id to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\nStudent Information System\n";
        cout << "1. Add Student\n";
        cout << "2. List Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
