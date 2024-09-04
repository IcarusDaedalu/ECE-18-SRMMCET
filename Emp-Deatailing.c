#include <stdio.h>
#include <string.h>

enum designation {
    Software_Dev,
    Circuit_Embedding,
    Accounts,
    Marketing,
    Clerical
};

struct emp {
    int ID;
    char name[50];
    enum designation desig;
    float Base;
    float Renumeration;
    float Salary;
};

void main() {
    struct emp epd[10];
    int i = 0;
    char temp[50];

    for (i = 0; i < 10; i++) {
        printf("Enter ID:");
        scanf("%d", &epd[i].ID);
        printf("Enter Name:");
        scanf("%s", epd[i].name);
        printf("Enter Designation:");
        scanf("%s", temp);
        if (strcmp(temp, "Software_Dev") == 0)
            epd[i].desig = Software_Dev;
        else if (strcmp(temp, "Circuit_Embedding") == 0)
            epd[i].desig = Circuit_Embedding;
        else if (strcmp(temp, "Accounts") == 0)
            epd[i].desig = Accounts;
        else if (strcmp(temp, "Marketing") == 0)
            epd[i].desig = Marketing;
        else if (strcmp(temp, "Clerical") == 0)
            epd[i].desig = Clerical;
        else {
            printf("Invalid Designation\n");
            i--;  
            continue;
        }

        printf("Enter Base Package:");
        scanf("%f", &epd[i].Base);
        switch (epd[i].desig) {
            case Accounts:
                epd[i].Renumeration = epd[i].Base * 0.2;  
                break;
            case Software_Dev:
                epd[i].Renumeration = epd[i].Base * 0.15; 
                break;
            case Circuit_Embedding:
                epd[i].Renumeration = epd[i].Base * 0.18; 
                break;
            case Marketing:
                epd[i].Renumeration = epd[i].Base * 0.12; 
                break;
            case Clerical:
                epd[i].Renumeration = epd[i].Base * 0.10; 
                break;
        }

        epd[i].Salary = epd[i].Base + epd[i].Renumeration;
        printf("Total Salary for %s: %.2f\n", epd[i].name, epd[i].Salary);
    }
}

