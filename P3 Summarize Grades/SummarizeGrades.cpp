/*
YC (Yucheng) Qiu
yqiu56@wisc.edu
*/
#include "SummarizeGrades.h"

void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments,
map<int, Name> &studentNames, map<int, vector<int> > &studentScores){
    FILE *fin = fopen(inputFilepath.data(),"rb");
    fscanf(fin,"number_of_students %d\n",numberOfStudents);
    fscanf(fin,"number_of_assignments %d\n", numberOfAssignments);
    fscanf(fin, "student_number first_name last_name");
    vector<int> AssignmentMaxGrade = vector<int>(*numberOfAssignments);
    for (int i = 0; i < *numberOfAssignments; i++) {
        fscanf(fin, "%d", &AssignmentMaxGrade[i]);
    }
    for(int i = 0; i < *numberOfStudents;i++ ){
        int studentID;
        char First_N[100];
        char Last_N[100];
        fscanf(fin,"%d %s %s",&studentID,First_N,Last_N);
        vector<int> grades = vector<int>(*numberOfAssignments);
        for(int j = 0; j < *numberOfAssignments; j++){
            fscanf(fin," %d",&grades[j]);
        }
        Name TempName = {First_N,Last_N};
        studentNames.insert(pair<int,Name>(studentID,TempName));
        studentScores.insert(pair<int,vector<int> >(studentID,grades));
    }
    fclose(fin);
}
void toNormalCase(string& str) {
    if (str[0] >= 'a' && str[0] <= 'z') str[0] -= 'a' - 'A';
    for (int i = 1; i < str.length();i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 'a' - 'A';
    }
}

void formatCaseOfNames(map<int, Name> &names){
    for(auto &x : names){
        toNormalCase(x.second.firstName);
        toNormalCase(x.second.lastName);
    }
}

void computeTotalAndPercent(map<int, vector<int> >& scores, map<int, int>& total, map<int, float>
    & percent) {
    
    for (map<int, vector<int>>::iterator iter = scores.begin(); iter != scores.end();iter++) {
        int studentID = iter->first;
        vector<int> grades = iter->second;
        int totalscore = 0;
        for (int i = 0; i < grades.size(); i++) {
            totalscore += grades[i];
        }
        total.insert(pair<int, int>(studentID, totalscore));
        float percentage = 10* (float)totalscore / grades.size();
        percent.insert(pair<int, float>(studentID, percentage));
    }

}

void writeFormattedGrades(const string outputFilepath, map<int, Name>& names,
    map<int, int>& total, map<int, float>& percent) {
    ofstream fout;
    fout.open(outputFilepath, ios::out);
    for (map<int, Name>::iterator iter = names.begin(); iter != names.end();iter++) {
        int studentID = iter->first, totalscore = total[studentID];
        float percentage = percent[studentID];
        Name studentName = iter->second;
        fout << studentName.lastName << ", " << studentName.firstName;
        int whitespaces = 16 - studentName.lastName.length() - studentName.firstName.length();
        for (int i = whitespaces; i >= 0; i--) {
            fout << " ";
        }
        char output[20];
        sprintf(output, "%3u  %5.1f\n", totalscore, percentage);
        fout << output;
    }
    fout.close();
}