//
// Created by jdinh on 12/28/2020.
//

#include "Calculator.h"


Calculator::Calculator()
{
    terms = 0;
    courses = 0;
    units = 0;
    calculatedGrades.push_back(0);
    gpa = 0;
    totalUnits = 0;
}


gradeValues Calculator::getGradeValue(char letterGrade)
{
    switch (letterGrade)
    {
        case 'A':
            return A;
        case 'B':
            return B;
        case 'C':
            return C;
        case 'D':
            return D;
        default:
            return F;
    }
}


int Calculator::getTerms()
{
    cout << "Enter total number of academic quarters/semesters (including summer sessions): ";
    cin >> terms;
    return terms;
}


int Calculator::getCoursesPerTerm()
{
    cin >> courses;
    courses = invalidInputs(courses);
    return courses;
}


int Calculator::getUnitsPerCourse()
{
    cin >> units;
    units = invalidInputs(units);
    totalUnits += units;

    return units;
}


string Calculator::getGradePerCourse()
{
    string grade;
    cin >> grade;

    grade = invalidInputs('A', 'F', grade);
    cout << grade << endl;
    return grade;
}


string Calculator::getCourseName()
{
    string name;

    cin.clear();
    excess();
    getline(cin, name);

    for (char& letter : name)
    {
        letter = toupper(letter);
    }
    return name;
}


string Calculator::invalidInputs(char a, char b, string correctInput)
{
    do
    {
        correctInput[0] = toupper(correctInput[0]);
        if (correctInput[0] >= a && correctInput[0] <= b && correctInput.size() == 1)
        {
            return correctInput;
        }
        else if (correctInput[0] >= a && correctInput[0] <= b && correctInput.size() == 2)
        {
            if (correctInput[1] == '-' || correctInput[1] == '+')
            {
                return correctInput;
            }
        }
        cout << "Invalid input! Enter again: ";
        cin >> correctInput;
    } while (true);
}


double Calculator::calculateIndividualGrades(int unitInput, double gradeValue)
{
    double calculatedGrade = unitInput * gradeValue;
    calculatedGrades.push_back(calculatedGrade);

    return calculatedGrade;
}


void Calculator::excess()
{
    char c;

    do
    {
        cin.get(c);
    } while (c != '\n');
}


void Calculator::resetInputs()
{
    courseInfo.clear();
    calculatedGrades.clear();
    courses = 0;
    units = 0;
    totalUnits = 0;
}


void Calculator::calculateGPA()
{
    for (auto grades : calculatedGrades)
    {
        gpa += grades;
    }
    gpa = gpa / totalUnits;
}


int Calculator::displayTermInfo()
{
    int response;

    for (const auto& name : courseInfo)
    {
        cout << name;
    }

    cout << "\nIs the information above correct?\n"
            "[1] Yes\n"
            "[2] No\n"
            "[3] Exit\n"
            "Enter option: ";
    cin >> response;
    return response;
}


int Calculator::invalidInputs(int input)
{
    do
    {
        if (cin.fail() || input <= 0)
        {
            cout << "Invalid input! Enter again: ";
            cin.clear();
            excess();
            cin >> input;
        }
        else
        {
            cout << endl;
            break;
        }
    } while (true);
    return input;
}


void Calculator::getUserInputs()
{
    getTerms();
    for (int i = 0; i < terms; i++)
    {
        cout << "\nEnter total number of courses for term " << i + 1 << ": ";
        getCoursesPerTerm();

        for (int j = 0; j < courses; j++)
        {
            cout << "Enter the course name for course " << j + 1 << ": ";
            courseInfo.push_back("Course Name: " + getCourseName());
            cin.clear();

            cout << "Enter total number of units for course " << j + 1 << ": ";
            int courseUnits = getUnitsPerCourse();

            cout << "Enter letter grade for course " << j + 1 << ": ";
            string temp = getGradePerCourse();

            char charGradeInput = toupper(temp[0]); //convert letters to uppercase
            double grade = getGradeValue(charGradeInput);

            if (temp != "A+")
            {
                if (temp.find('+') != std::string::npos)
                {
                    //gradeInput.erase(gradeInput.begin() + 1);
                    grade = grade + 0.3;
                }
                else if (temp.find('-') != std::string::npos)
                {
                    //gradeInput.erase(gradeInput.begin() + 1);
                    grade = grade - 0.3;
                }
            }
            courseInfo[j] += "\t\tUnits: " + to_string(courseUnits) + "\tGrade: " + temp + "\n";
            calculateIndividualGrades(courseUnits, grade);
            cout << endl;
        }
        int choice = displayTermInfo();

        if (choice != 1)
        {
            exit(1);
            //resetInputs();
            //i = 0;
        }
        courseInfo.clear();
        cout << endl;
    }
    calculateGPA();
}


int Calculator::getTermsFromGUI(int termsInput)
{
    terms = termsInput;
    //cout << terms << endl;
    return 1;
}


int Calculator::getCoursesFromGUI(int coursesInput)
{
    courses = coursesInput;
    //cout << courses << endl;
    return 2;
}


int Calculator::getCourseNameFromGUI(string s)
{
    return 3;
}


string Calculator::changeDisplayText(string s)
{
    return s;
}


//working on grabbing input efficiently with GUI
void Calculator::getUserInputsGUI()
{
    string s;
    for (int i = 0; i < terms; i++)
    {
        s = "\nEnter total number of courses for term " + to_string(i + 1) + ": ";
        changeDisplayText(s);

        for (int j = 0; j < courses; j++)
        {
            s = "Enter the course name for course " + to_string(j + 1) + ": ";
            changeDisplayText(s);

            courseInfo.push_back("Course Name: " + getCourseName());
            cin.clear();

            cout << "Enter total number of units for course " << j + 1 << ": ";
            int courseUnits = getUnitsPerCourse();

            cout << "Enter letter grade for course " << j + 1 << ": ";
            string temp = getGradePerCourse();

            char charGradeInput = toupper(temp[0]); //convert letters to uppercase
            double grade = getGradeValue(charGradeInput);
        }
    }
}


ostream& operator<<(ostream& outs, const Calculator& c)
{
    outs << fixed << showpoint << setprecision(2);
    outs << "\nYour gpa is an estimated \"" << c.gpa << "\".";

    return outs;
}

