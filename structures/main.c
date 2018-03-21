#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct{
    char name[20];
    int age;
}Person;
void readData( Person *p);
Person findMiddleAge(Person *p);
int main(){
    Person man[3], middle;
    readData(man);
    middle = findMiddleAge(man);
    printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
    return 0;
}
void readData(Person *p){
    int i = 0;
    for(i = 0; i < 3; i++){
        printf("Enter person %d:\n",i+1);
        scanf("%s %d", p[i].name, &p[i].age);
    }
}
Person findMiddleAge(Person *p){
    int i;
    int max;
    int min;
    max = p[0].age;
    min = p[0].age;

    for(i = 0; i < 3; i++){
        if( p[i].age > max){
            max = p[i].age;
        }
        if(p[i].age < min){
            min = p[i].age;
        }
    }
    for(i = 0; i<3; i++){
        if(p[i].age != max){
            if(p[i].age != min){
                return p[i];
            }
        }
    }
}
//qn2
#include <stdio.h>
#include <string.h>
typedef struct {
    char source;
    char code;
} Rule;
void encodeChar(Rule table[5], char *s, char *t);
int main(){
    char s[80],t[80];
    Rule table[5] = { 'a','d' , 'b','z' , 'z','a', 'd','b', '\0','\0' };
    printf("Source string: \n");
    gets(s);
    encodeChar(table,s,t);22
    printf("Encoded string: %s\n", t);
    return 0;
}
void encodeChar(Rule table[5], char *s, char *t){
    int i = 0, count = 0, j;
    while(*(s+i) != '\0'){
        i++;
        count++;
    }
    for(i = 0; i < count; i++){
        for(j = 0; j<5 ; j++){
            if(*(s+i) == table[j].source){
                *(t+i) = table[j].code;
                i++;
            }
        }
        t[i] = s[i];
    }
    t[i] = '\0';
}
//qn3
#include <stdio.h>
#include <string.h>
struct account {
    struct{
        char lastName[10];
        char firstName[10];
    }names;
    int accountNum;
    double balance;
};
void nextCustomer(struct account *acct);
void printCustomer(struct account acct);
int main(){
    struct account record;
    int flag = 0;
    do{
        nextCustomer(&record);
        if ((strcmp(record.names.firstName, "End") == 0) &&
            (strcmp(record.names.lastName, "Customer") == 0))
            flag = 1;
        if (flag != 1)
            printCustomer(record);
    }
    while (flag != 1);
}
void nextCustomer(struct account *acct){
    int i = 0;
    printf("Enter names (firstName lastName)\n");
    scanf("%s", acct->names.firstName);
    scanf("%s", acct->names.lastName);
    printf("Enter account number:\n");
    scanf("\n%d", &acct->accountNum);
    printf("Enter balance:\n");
    scanf("\n%lf", &acct->balance);
}
void printCustomer(struct account acct){
    printf("%s %s %d %lf\n", acct.names.firstName, acct.names.lastName, acct.accountNum, acct.balance);
}
//qn4
#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char name[20];
    char telno[20];
}PhoneBk;
int readin(PhoneBk *p);
void search(PhoneBk *p, int size, char *target);
int main(){
    PhoneBk s[MAX];
    char t[20];
    int size;
    size = readin(s);
    printf("Enter search name: \n");
    gets(t);
    search(s,size,t);
    return 0;
}
int readin(PhoneBk *p){
    int i=0;
    printf("Enter name:\n");
    gets(p[i].name);
    while( *(p+i)->name != '#'){
        printf("Enter tel:\n");
        gets(p[i].telno);
        i++;
        printf("Enter name:\n");
        gets(p[i].name);
    }
    return i;
}
void search(PhoneBk *p, int size, char *target){
    int i;
    for(i = 0; i < size; i++){
        if(strcmp(p[i].name, target) == 0){
            puts(p[i].name);
            puts(p[i].telno);
        }
        else if(i == (size-1) && strcmp(p[i].name, target) != 0){
            printf("Name not found!");
        }
    }
}
#include <stdio.h>
#include <string.h>
#define SIZE 50
typedef struct {
   int id;
   char name[50];
} Student;
void inputStud(Student *s, int size);
void printStud(Student *s, int size);
int removeStud(Student *s, int *size, char *target);
int main()
{
   Student s[SIZE];
   int size=0, choice;
   char target[80];
   int result;

   printf("Select one of the following options: \n");
   printf("1: inputStud()\n");
   printf("2: removeStud()\n");
   printf("3: printStud()\n");
   printf("4: exit()\n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("Enter size: \n");
            scanf("%d", &size);
            printf("Enter %d students: \n", size);
            inputStud(s, size);
            break;
         case 2:
            printf("Enter name to be removed: \n");
            scanf("\n");
            gets(target);
            printf("removeStud(): ");
            result = removeStud(s, &size, target);
            if (result == 0)
               printf("Successfully removed\n");
            else if (result == 1)
               printf("Array is empty\n");
            else if (result == 2)
               printf("The target does not exist\n");
            else
               printf("An error has occurred\n");
            break;
         case 3:
            printStud(s, size);
            break;
      }
   } while (choice < 4);
   return 0;
}
void inputStud(Student *s, int size)
{
    int i;
    for (i = 0; i < size; i++){
        printf("Student ID:\n");
        scanf("%d",&(s+i)->id);
        printf("Student Name:\n");
        scanf("\n");
        gets((s+i)->name);

    }
}
void printStud(Student *s, int size)
{
    int i;
    printf("The current student list:\n");
    if(size == 0){
        printf("Empty array\n");
   }
    else{
        for (i = 0; i<size; i++){
                printf("Student ID: %d Student Name: %s\n", (s+i)->id, (s+i)->name);
        }
    }
}
 int removeStud(Student *s, int *size, char *target){
    int i, j = 0;
    int remove = 2;
    if(*size == 0){ //in case nothing inside arrary
        return 1;
   }

   for(i = 0; i < *size; i++){
        if(strcmp(s[i].name, target) == 0){
            if(i+1 != *size){
                strcpy(s[i].name, s[i+1].name);
                s[i].id = s[i+1].id;
                j = i+1;
            }
           *size -= 1;
           remove = 0;
           break;
        }
    }
    while(j < *size){
            s[j].id = s[j+1].id;
            strcpy(s[j].name, s[j+1].name);
            j++;
        }
    return remove;
}
