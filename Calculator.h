//
// Created by jdinh on 12/28/2020.
//

#ifndef COLLEGE_GPA_CALCULATOR_CALCULATOR_H
#define COLLEGE_GPA_CALCULATOR_CALCULATOR_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


enum gradeValues
{
    A = 4,
    B = 3,
    C = 2,
    D = 1,
    F = 0
};

class Calculator
{
private:
    int terms, courses, units;
    vector<double> calculatedGrades;
    double gpa = 0;
    double totalUnits = 0;

public:
    Calculator();

    int getTerms();
    int getCoursesPerTerm();
    int getUnitsPerCourse();

    double calculateIndividualGrades(int unitInput, double gradeValue);

    string getGradePerCourse();
    string invalidInputs(char a, char b, string correctInput);

    gradeValues getGradeValue(char letterGrade);

    void calculateGPA();
    void getUserInputs();

    friend ostream& operator << (ostream& outs, const Calculator& c);
};


#endif //COLLEGE_GPA_CALCULATOR_CALCULATOR_H
