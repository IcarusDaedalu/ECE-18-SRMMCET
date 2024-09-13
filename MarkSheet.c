#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct marksheet {
    char name[50];
    int rollno;
    int arr[5];
    int total;
    float percentage;
    char grade;
};

void saving(struct marksheet m[], int count) {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(m, sizeof(struct marksheet), count, file);
    fclose(file);
}

void searching(int rollno) {
    FILE *file = fopen("students.dat", "rb");
    struct marksheet m;
    int i = 0;
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    while (fread(&m, sizeof(struct marksheet), 1, file)) {
        if (m.rollno == rollno) {
            printf("Name: %s\n", m.name);
            printf("Roll No: %d\n", m.rollno);
            printf("Marks: ");
            
            for (i = 0; i < 5; i++) {
                printf("%d ", m.arr[i]);
            }
            
            printf("\nTotal: %d\n", m.total);
            printf("Percentage: %.2f\n", m.percentage);
            fclose(file);
            return;
        }
    }
    
    printf("Roll number %d not found.\n", rollno);
    fclose(file);
}

void main() {
    struct marksheet m[3];
    int marks;
    int i = 0, j = 0, k = 0;
    int func, rollno;

    printf("If Student to Be Enrolled: Press 1\n");
    printf("If Student Detail Required: Press 2\n");
    printf("...................\n");
    scanf("%d", &func);

    if (func == 1) {
        for (i = 0; i < 3; i++) {
            printf("Student Name: ");
            scanf("%s", m[i].name);
            printf("Student RollNo: ");
            scanf("%d", &m[i].rollno);
            m[i].total = 0;
            for (j = 0; j < 5; j++) {
                printf("Mark of Subject %d:\n", j + 1);
                scanf("%d", &m[i].arr[j]);
                m[i].total += m[i].arr[j];
            }
            m[i].percentage = (float) m[i].total / 5;
            printf("Student Name: %s\n", m[i].name);
            printf("Student RollNo: %d\n", m[i].rollno);
            printf("Marks Obtained In Each Subject:\n");
            for (k = 0; k < 5; k++) {
                printf("%d\n", m[i].arr[k]);
            }
            printf("Total Marks Obtained: %d\n", m[i].total);
            printf("Percentage Obtained: %f\n", m[i].percentage);
        }
        saving(m, 3);
    } else if (func == 2) {
        printf("Enter Roll No To Be Searched: ");
        scanf("%d", &rollno);
        searching(rollno);
    } else {
        printf("Invalid Input");
    }
}

