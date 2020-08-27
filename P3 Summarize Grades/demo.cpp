/*
YC (Yucheng) Qiu
yqiu56@wisc.edu
*/
#include "SummarizeGrades.h"
int main(){
    using namespace std;
    // readGradeFile
    int numberofstudents, numberofassignments;
    map<int, Name> studentNames;
    map<int, vector<int> > studentscores;
    readGradeFile("unformatted_grades.txt", &numberofstudents, &numberofassignments, studentNames, studentscores);
    // Change format
    formatCaseOfNames(studentNames);
    // Compute total
    map<int, int> student_total_score;
    map<int, float> student_percent;
    computeTotalAndPercent(studentscores, student_total_score, student_percent);
    // output
    writeFormattedGrades("MyOutput.txt", studentNames, student_total_score, student_percent);
    
}