#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;
    int className;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    int marks[3];

public:
    Student() {
        rollNumber = 0;
        for (int i = 0; i < 3; i++) {
            marks[i] = 0;
        }
    }
    
    Student(string n, int r, int c, string d, string bg, string addr, string tel, int m1, int m2, int m3) {
        name = n;
        rollNumber = r;
        className = c;
        dob = d;
        bloodGroup = bg;
        contactAddress = addr;
        telephoneNumber = tel;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    void getdata()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Class: ";
        cin >> className;
        cout << "Enter Date of Birth: ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter Contact Address: ";
        cin.ignore();
        getline(cin, contactAddress);
        cout << "Enter Telephone Number: ";
        cin >> telephoneNumber;
        cout << "Enter Marks in 3 Subjects: ";
        cin >> marks[0] >> marks[1] >> marks[2];
    }

    static void showdata(const Student &s)
    {
        cout << "Name: " << s.name << "\nRoll Number: " << s.rollNumber << "\nClass: " << s.className
             << "\nDate of Birth: " << s.dob << "\nBlood Group: " << s.bloodGroup
             << "\nContact Address: " << s.contactAddress << "\nTelephone Number: " << s.telephoneNumber
             << "\nMarks in 3 Subjects: " << s.marks[0] << ", " << s.marks[1] << ", " << s.marks[2] << "\n-------------------------\n";
    }

    ~Student(){};
    
    friend class Database;
};

class Database
{
public:
    static void addStudent(Student *students[], int &count, const Student &s)
    {
        students[count++] = new Student(s);
        cout << "Student added successfully.\n";
    }

    static void displayAllStudents(Student *students[], int count)
    {
        if (count == 0)
        {
            cout << "No students in the database.\n";
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                Student::showdata(*students[i]);
            }
        }
    }

    static void deleteStudent(Student *students[], int &count, int rollNumber)
    {
        int index = -1;
        for (int i = 0; i < count; i++)
        {
            if (students[i]->rollNumber == rollNumber)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            delete students[index];
            for (int i = index; i < count - 1; i++)
            {
                students[i] = students[i + 1];
            }
            count--;
            cout << "Student deleted successfully.\n";
        }
        else
        {
            cout << "Student not found.\n";
        }
    }

    static void searchStudent(Student *students[], int &count, int rollNumber)
    {
        int index = -1;
        for (int i = 0; i < count; i++)
        {
            if (students[i]->rollNumber == rollNumber)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
            {
                Student::showdata(*students[index]);
            }
        else
            {
                cout << "Student not found.\n";
            }
    }
};

void displayMenu()
{
    cout << "\nMenu:\n1. Add Student\n2. Display All Students\n3. Delete Student\n4. Search for Student\n5. Display Number of Students\n6. Exit\n";
}

int main()
{
    const int maxStudents = 100;
    Student *students[maxStudents];
    int studentCount = 0;
    int choice;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Student newStudent;
            newStudent.getdata();
            Database::addStudent(students, studentCount, newStudent);
            break;
        }
        case 2:
            Database::displayAllStudents(students, studentCount);
            break;
        case 3:
        {
            int rollNumber;
            cout << "Enter Roll Number of the student to delete: ";
            cin >> rollNumber;
            Database::deleteStudent(students, studentCount, rollNumber);
            break;
        }
        case 4:
        {
            int rollNumber;
            cout << "Enter Roll Number of the student to search: ";
            cin >> rollNumber;
            Database::searchStudent(students, studentCount, rollNumber);
            break;
        }
        case 5:
            cout << "Number of students in the database: " << studentCount << "\n";
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
