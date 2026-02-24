#include <stdio.h>

struct Student {
    char name[50];
    float grade;
};

void bestStudent(struct Student students[], int n){
    if (n <= 0) return;
    struct Student* BestStudentPtr = &students[0];
    for (int i = 1; i < n; i++){
        if (students[i].grade >= BestStudentPtr->grade){
            BestStudentPtr = &students[i];
        }
    }

    printf("Name: %s, Grade: %.2f\n", BestStudentPtr->name, BestStudentPtr->grade);
}

int main(){
    struct Student Students[] = {{"alex", 67.0}, {"bob", 88.0}, {"amber", 99.9}};
    int n = sizeof(Students) / sizeof(Students[0]);

    bestStudent(Students, n);
}