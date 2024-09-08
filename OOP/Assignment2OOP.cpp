/*
Develop a program in C++ to create a database of student's information system containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, contact address, Telephone number, Driving license no. and other.
*
Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.

*/
#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
    // static count[];
    string name;
    int roll_number;
    int class_number;
    string division;
    string date_of_birth;
    string blood_group;
    double telephone_number;
    double driving_license_number;
    // Default Constructor
    Student()
    {
        // cout << "Default Constructor is called" << endl;
    }

    Student(string Name, int RollNum, int Class, string Div, string DOB, string BG, double tel, double DriLicen)
    {
        this->name = Name;
        this->roll_number = RollNum;
        this->class_number = Class;
        this->division = Div;
        this->date_of_birth = DOB;
        this->blood_group = BG;
        this->telephone_number = tel;
        this->driving_license_number = DriLicen;
        Student *next;
    }
    ~Student()
    {
        cout << "Default Destructor is called" << endl;
    }
};

int main()
{
    // Vector to store students
    vector<Student> students;
    int choice;
    while (true)
    {
        cout << "\nMenu: \n";
        cout << "1. Create new Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Students\n";
        cout << "4. Exit Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 4)
        {
            cout << "Exiting Database...." << endl;
            return 0;
        }
        else if (choice == 1)
        {
            Student s;
            cout << "Enter Student Name: " << endl;
            cin >> s.name;
            cout << "Enter Student Roll Number of Student " << s.name << ":" << endl;
            cin >> s.roll_number;
            cout << "Enter Student Class Number of Student " << s.name << ":" << endl;
            cin >> s.class_number;
            cout << "Enter Student Division Number of Student " << s.name << ":" << endl;
            cin >> s.division;
            cout << "Enter Student Date of Birth of Student " << s.name << ":" << endl;
            cin >> s.date_of_birth;
            cout << "Enter Student Blood Group of Student " << s.name << ":" << endl;
            cin >> s.blood_group;
            cout << "Enter Student Driving License Number of Student " << s.name << ":" << endl;
            cin >> s.driving_license_number;
            cout << "Enter Student Telephone Number  of Student " << s.name << ":" << endl;
            cin >> s.telephone_number;
            students.push_back(s);
        }
        else if (choice == 3)
        {
            if (students.size())
            {
                for (int i = 0; i < students.size(); i++)
                {
                    cout << "-----------------------------------------------------" << endl;
                    cout << "1. Student Name: " << students[i].name << endl;
                    cout << "2. Student Roll Number: " << students[i].roll_number << endl;
                    cout << "3. Student Class Number: " << students[i].class_number << endl;
                    cout << "4. Student Division Number: " << students[i].division << endl;
                    cout << "5. Student Date of Birth: " << students[i].date_of_birth << endl;
                    cout << "6. Student Blood Group: " << students[i].blood_group << endl;
                    cout << "7. Student Driving License Number: " << students[i].driving_license_number << endl;
                    cout << "8. Student Telephone  Number: " << students[i].telephone_number << endl;
                    cout << "-----------------------------------------------------" << endl;
                }
            }
            else
            {
                cout << "No Students in database" << endl;
            }
        }
        else if (choice == 2)
        {
            int rn;
            cout << "Enter Student Roll Number of Student to delete: " << endl;
            cin >> rn;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].roll_number == rn)
                {
                    students.erase(students.begin() + i);
                    cout << "The Student " << students[i].name << " and roll number" << students[i].roll_number << " has been deleted from Students database." << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}