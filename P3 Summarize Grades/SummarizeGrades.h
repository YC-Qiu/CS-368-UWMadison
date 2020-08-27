/*
YC (Yucheng) Qiu
yqiu56@wisc.edu
*/
#ifndef SUMMARIZE_GRADES
#define SUMMARIZE_GRADES
#include<string>
#include<map>
#include<vector>
#include<cstdio>
#include<fstream>
using namespace std;

struct Name
{
    string firstName;
    string lastName;
};

void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments,
 map<int, Name> &studentNames, map<int, vector<int> > &studentScores);

void formatCaseOfNames(map<int, Name> &names);

void toNormalCase(string& str);

/**
*   This function takes the scores map and computes the total score (the sum of all points earned) as well as
* the final percentage as a float and stores these computed results in total and percent maps respectively
* where key is the student ID. Remember all assignments are worth 10 points each. Percentages should be
* computed as floats between 0 and 100.
*/
void computeTotalAndPercent(map<int, vector<int> >& scores, map<int, int>& total, map<int, float>
    & percent);

void writeFormattedGrades(const string outputFilepath, map<int, Name>& names, map<int, int>& total,
    map<int, float>& percent);

#endif
