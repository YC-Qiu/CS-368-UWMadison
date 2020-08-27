# Description of My Program
## Yucheng (YC) Qiu
### CS @ UW-Madison


The program includes functions that are related to File I/O operations.
It reads a file with student information and their homework scores, manipulate
that data to compute the total score and percentage for each student, and writes
a summary file with the computed scores for each student.

**void readGradeFIle(const string inputFilepath, int *numberOfStudents,int*numberOfAssignments,map<int, Name> &studentNames, map<int, vector<int> > &studentScores)**

This function takes the path of the input file and references to some data structures that will hold 
the student names and scores for other functions to process. It also contains pointers to variables that 
will keep track of the number of students and assignments. Sample unformatted gradebook file is provided 
for reference.

**void formatCaseOfNames(map<int, Name> &names)**
Some of the student names in the gradebook file are lower case, some are uppercase, and some are capitalized. This is unacceptable. This function takes the student names map and changes the first and last name strings in the struct (values in map) so that the first letter of each string is a capital letter and all other letters are lower case.

**void computeTotalAndPercent(map<int, vector<int> > &scores, map<int, int> &total, map<int, float> &percent)**
This function takes the scores map and computes the total score (the sum of all points earned) as well as the final percentage as a float and stores these computed results in total and percent maps respectively where key is the student ID. Remember all assignments are worth 10 points each. Percentages should be computed as floats between 0 and 100.

**void writeFormattedGrades(const string outputFilepath, map<int, Name> &names, map<int, int> &total, map<int, float> &percent)**
Each line should begin with the student's last name followed by a comma, a space and then their first name. After that write their total score and percentage to the file. Scores should be aligned so that the ones digit of every total falls in the 22nd column. You may assume that the name length (last name + first name) is always <= 15 characters and the total score will take max 3 characters. Percentages should be values between 0 and 100 written to one decimal place of precision. This means that even if the percentage is 100, it will be reported as 100.0. The decimal point goes in the 28th column.

**Compile instruction**
g++ -o demo -c demo.cpp SummarizeGrades.h SummarizeGrades.cpp



