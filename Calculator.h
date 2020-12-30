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
    vector<string> courseInfo;
    double gpa = 0;
    double totalUnits = 0;

public:
    Calculator();

    int getTerms();
    int getCoursesPerTerm();
    int getUnitsPerCourse();
    int displayTermInfo();
    static int invalidInputs(int input);

    double calculateIndividualGrades(int unitInput, double gradeValue);

    static string getGradePerCourse();
    static string getCourseName();
    static string invalidInputs(char a, char b, string correctInput);

    static gradeValues getGradeValue(char letterGrade);

    static void excess();
    void resetInputs();
    void calculateGPA();
    void getUserInputs();

    int getTermsFromGUI(int termsInput);
    int getCoursesFromGUI(int coursesInput);
    int getCourseNameFromGUI(string s);
    static string changeDisplayText(string s);
    void getUserInputsGUI();

    friend ostream& operator << (ostream& outs, const Calculator& c);
};


#endif //COLLEGE_GPA_CALCULATOR_CALCULATOR_H
