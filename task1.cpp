/*
#include <iostream>
#include <string>
using namespace std;

struct Course
{
    string name;
    string grade;
    int credit;
    double gradePoint;
};

struct Semester
{
    Course courses[10];
    int numCourses;
    double gpa;
    int totalCredits;
    double totalPointsEarned;
};

struct Student
{
    string name;
    Semester semesters[10];
    int numSemesters;
    double cgpa;
};

double calculateGradePoint(string grade)
{
    if (grade == "A+" || grade == "A")
    {
        return 4.0;
    }
    else if (grade == "A-")
    {
        return 3.67;
    }
    else if (grade == "B+")
    {
        return 3.33;
    }
    else if (grade == "B")
    {
        return 3.0;
    }
    else if (grade == "B-")
    {
        return 2.67;
    }
    else if (grade == "C+")
    {
        return 2.33;
    }
    else if (grade == "C")
    {
        return 2.0;
    }
    else if (grade == "C-")
    {
        return 1.67;
    }
    else if (grade == "D+")
    {
        return 1.33;
    }
    else if (grade == "D")
    {
        return 1.0;
    }
    else
    {
        return 0.0;
    }
}

void calculateCGPA(Student& student)
{
    double cumulativePointsEarned = 0.0;
    int cumulativeCredits = 0;

    for (int sem = 0; sem < student.numSemesters; sem++)
    {
        cumulativePointsEarned += student.semesters[sem].totalPointsEarned;
        cumulativeCredits += student.semesters[sem].totalCredits;
    }

    student.cgpa = cumulativePointsEarned / cumulativeCredits;
}

int main()
{
    int option = 0;
    Student students[10];
    int numStudents = 0;

    cout << "\n\t\t\t\t\t=============================== " << endl;
    cout << "\t\t\t\t\t|       GPA CALCULATOR        |" << endl;
    cout << "\t\t\t\t\t===============================" << endl << endl;

    while (true)
    {
        cout << "Which option would you perform ?" << endl;
        cout << "1- Calculate GPA" << endl;
        cout << "2- Grading Policy" << endl;
        cout << "3- See All Students' CGPAs" << endl;
        cout << "4- Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Select option: ";
        cin >> option;
        cout << "-------------------------------" << endl;

        if (option == 4)
        {
            cout << "Exiting..." << endl;
            cout << "-------------------------------" << endl;
            break;
        }

        switch (option) {
        case 1:
        {
            cin.ignore();
            Student& student = students[numStudents];
            cout << "Enter student's name: ";
            getline(cin, student.name);
            cout << "-------------------------------" << endl;
            cout << "\nHow many semesters would you like to enter: ";
            cin >> student.numSemesters;
            cout << "------------------------------------------" << endl;
            cin.ignore();

            for (int sem = 0; sem < student.numSemesters; sem++)
            {
                Semester& semester = student.semesters[sem];
                cout << "Enter number of courses for semester " << sem + 1 << ": ";
                cin >> semester.numCourses;
                cout << "----------------------------------------" << endl;
                cin.ignore();

                semester.totalPointsEarned = 0.0;
                semester.totalCredits = 0;

                for (int i = 0; i < semester.numCourses; i++)
                {
                    Course& c = semester.courses[i];
                    cout << "Enter course name: ";
                    getline(cin, c.name);
                    cout << "Enter the Grade: ";
                    getline(cin, c.grade);
                    cout << "Enter the Credit Hours: ";
                    cin >> c.credit;
                    cin.ignore();
                    cout << "----------------------------------------" << endl;

                    c.gradePoint = calculateGradePoint(c.grade);
                    semester.totalPointsEarned += c.gradePoint * c.credit;
                    semester.totalCredits += c.credit;
                }

                semester.gpa = semester.totalPointsEarned / semester.totalCredits;
            }

            calculateCGPA(student);

            cout << "Your CGPA is: " << student.cgpa << endl;
            cout << "----------------------------------------" << endl;

            for (int sem = 0; sem < student.numSemesters; sem++)
            {
                Semester& semester = student.semesters[sem];
                cout << "Semester " << sem + 1 << " SGPA: " << semester.gpa << endl;
                cout << "\nCourses in Semester " << sem + 1 << ":" << endl;
                for (int j = 0; j < semester.numCourses; j++)
                {
                    cout << "Course: " << semester.courses[j].name << ", Grade: " << semester.courses[j].grade << ", Credits: " << semester.courses[j].credit << endl;
                }
                cout << "\nTotal Credits: " << semester.totalCredits << endl;
                cout << "Total Grade Points: " << semester.totalPointsEarned << endl;
                cout << "----------------------------------------" << endl;
            }

            numStudents++;
            break;
        }
        case 2:
        {
            cout << "\n---------------------------------------" << endl;
            cout << "|Grade" << "  |" << " Points per Credit" << " |  " << "Marks  |" << endl;
            cout << "--------|-------------------|---------|" << endl;
            cout << "| A+" << "    |\t" << "4.0" << "\t    |   " << "90+ " << "  | " << endl;
            cout << "| A" << "     |\t" << "4.0" << "\t    |   " << "86+" << "   |" << endl;
            cout << "| A-" << "    |\t" << "3.67" << "\t    |   " << "82-85" << " | " << endl;
            cout << "| B+" << "    |\t" << "3.33" << "\t    |   " << "78-81" << " |" << endl;
            cout << "| B" << "     |\t" << "3.0" << "\t    |   " << "74-77" << " |" << endl;
            cout << "| B-" << "    |\t" << "2.67" << "\t    |   " << "70-73" << " |" << endl;
            cout << "| C+" << "    |\t" << "2.33" << "\t    |   " << "65-68" << " | " << endl;
            cout << "| C" << "     |\t" << "2.0" << "\t    |   " << "61-64" << " |" << endl;
            cout << "| C-" << "    |\t" << "1.67" << "\t    |   " << "57-60" << " |" << endl;
            cout << "| D+" << "    |\t" << "1.33" << "\t    |   " << "53-56" << " |" << endl;
            cout << "| D" << "     |\t" << "1.0" << "\t    |   " << "50-52" << " |" << endl;
            cout << "| F" << "     |\t" << "0.0" << "\t    |   " << "< 50" << "  |" << endl;
            cout << "---------------------------------------" << endl;
            break;
        }
        case 3:
        {
            cout << "-------------------------------" << endl;
            cout << "All Students' CGPAs:" << endl;
            cout << "-------------------------------" << endl;

            for (int i = 0; i < numStudents; i++)
            {
                Student& student = students[i];
                cout << "Student: " << student.name << endl;
                cout << "CGPA: " << student.cgpa << endl;
                cout << "-------------------------------" << endl;
            }
            break;
        }
        default:
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}
*/