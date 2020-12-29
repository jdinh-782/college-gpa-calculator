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
    return courses;
}


int Calculator::getUnitsPerCourse()
{
    cin >> units;
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


void Calculator::calculateGPA()
{
    for (auto grades : calculatedGrades)
    {
        gpa += grades;
    }
    gpa = gpa / totalUnits;
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
            calculateIndividualGrades(courseUnits, grade);
            cout << endl;
        }
    }
    calculateGPA();
}


ostream& operator<<(ostream& outs, const Calculator& c)
{
    outs << fixed << showpoint << setprecision(2);
    outs << "\nYour gpa is an estimated \"" << c.gpa << "\".";

    return outs;
}

