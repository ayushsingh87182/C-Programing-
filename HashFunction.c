#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct Employee {
    int id;
    char name[15];
};

typedef struct Employee EMP;

EMP employees[MAX];
int hashTable[MAX]; 

int createHash(int num) {
    return num % MAX; 
}

void getEmp(int key) {
    printf("\nEnter emp id: ");
    scanf("%d",&employees[key].id);
    printf("Enter emp name: ");
    scanf("%s", employees[key].name);
}

void display() {
    int i, ch;
    while (1) {
        printf("\n1. Display ALL\n2. Filtered Display");
        printf("\nEnter the choice: ");
        scanf("%d",&ch);

        if (ch == 1) {
            printf("\nThe hash table is:\n");
            printf("\nHTKey\tEmpID\tEmpName");
            for (i = 0; i < MAX; i++) {
                printf("\n%d\t%d\t%s", i, employees[i].id, employees[i].name);
            }
        } else if (ch == 2) {
            printf("\nThe hash table is:\n");
            printf("\nHTKey\tEmpID\tEmpName");
            for (i = 0; i < MAX; i++) {
                if (hashTable[i] != -1) {
                    printf("\n%d\t%d\t%s", i, employees[i].id, employees[i].name);
                }
            }
        } else {
            exit(0);
        }
    }
}

void linearProb(int key, int num) {
    int i, count = 0;
    if (hashTable[key] == -1) {
        hashTable[key] = num;
        getEmp(key);
    } else {
        printf("\nCollision Detected...!!!\n");
        
        for (i = 0; i < MAX; i++) {
            if (hashTable[i] != -1) {
                count++;
            }
        }
        
        if (count == MAX) {
            printf("\nHash table is full");
            display(); 
            return;
        }

        i = (key + 1) % MAX;
        while (i != key) {
            if (hashTable[i] == -1) {
                printf("\nCollision avoided successfully using LINEAR PROBING at index %d\n", i);
                hashTable[i] = num;
                getEmp(i);
                return;
            }
            i = (i + 1) % MAX;
        }
    }
}

void main() {
    int num, key, i;
    int ans = 1;

    printf("\nCollision handling by linear probing:");
    
    for (i = 0; i < MAX; i++) {
        hashTable[i] = -1;
    }

    do {
        printf("\nEnter the data (ID): ");
        scanf("%d",&num);
        
        key = createHash(num);
        linearProb(key, num);

        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d",&ans);
    } while (ans);

    display();
}