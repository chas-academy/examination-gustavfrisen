#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char name[10];
    int testScores[13];
    float avg;
} student;

int main() {
    student students[5];
    float avgTotal = 0.0;
    int maxAvg = 0;

    for (int i = 0; i < 5; i++) {
        students[i].avg = 0.0;
        scanf("%s", students[i].name);
        
        for (int j = 0; j < 13; j++) {
            scanf("%i", &students[i].testScores[j]);
            students[i].avg += students[i].testScores[j];
        }
        students[i].avg = students[i].avg / 13;

        if (i == 0 || students[i].avg > students[maxAvg].avg) {
            maxAvg = i;
        }
    }

    for (int i = 0; i < 5; i++) {
        avgTotal += students[i].avg;
    }

    avgTotal = avgTotal / 5;

    students[maxAvg].name[0] = toupper(students[maxAvg].name[0]);
    printf("%s\n", students[maxAvg].name);

    for (int i = 0; i < 5; i++) {
        if (students[i].avg < avgTotal) {
            students[i].name[0] = toupper(students[i].name[0]);
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}