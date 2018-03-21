#include <stdio.h>
#include <math.h>

e//lab q1
struct circle {
    double radius;
    double x;
    double y;
};
int intersect(struct circle, struct circle);
int contain(struct circle *, struct circle *);
int main(){
    struct circle c1, c2; //initialize structure
    int choice, result = INIT_VALUE;
      printf("\nSelect one of the following options: \n");
         printf("1: intersect()\n");
         printf("2: contain()\n");
         printf("3: exit()\n");
         do {
            result=-1;
            printf("Enter your choice: \n");
            scanf("%d", &choice);
            switch (choice) {
               case 1:
                  printf("Enter circle 1 (radius x y): \n");
                  scanf("%lf %lf %lf", &c1.radius, &c1.x, &c1.y);
                  printf("Enter circle 2 (radius x y): \n");
                  scanf("%lf %lf %lf", &c2.radius, &c2.x, &c2.y);
                  result = intersect(c1, c2);
                  if (result == 1)
                     printf("intersect(): intersect\n");
                  else if (result == 0)
                     printf("intersect(): not intersect\n");
                  else
                     printf("intersect(): error\n");
                  break;
               case 2:
                  printf("Enter circle 1 (radius x y): \n");
                  scanf("%lf %lf %lf", &c1.radius, &c1.x, &c1.y);
                  printf("Enter circle 2 (radius x y): \n");
                  scanf("%lf %lf %lf", &c2.radius, &c2.x, &c2.y);
                  result = contain(&c1, &c2);
                  if (result == 1)
                     printf("contain(): contain\n");
                  else if (result == 0)
                     printf("contain(): not contain\n");
                  else
                     printf("contain(): error\n");
                  break;
            }
         } while (choice < 3);
         return 0;
      }
int intersect(struct circle c1, struct circle c2){
    double xsquare, ysquare, distance, radiisum;

    xsquare = pow(c1.x - c2.x ,2);
    ysquare = pow(c1.y - c2.y ,2);
    distance = sqrt(xsquare+ysquare);
    radiisum = c1.radius + c2.radius;

    if (distance <=  radiisum){
        return 1;
    }
    else{
        return 0;
    }




}
int contain(struct circle *c1, struct circle *c2)
{
    //Circlec1containscirclec2whentheradius of c1 is larger than
    //or equal to the sum of the radius of c2 and the distance between the centres of c1 and c2
    double xsquare, ysquare, distance, sumofYandDist;

    xsquare = pow(c1->x - c2->x, 2);
    ysquare = pow(c1->y - c2->y, 2);

    distance = sqrt(xsquare + ysquare);
    sumofYandDist = distance + c2->y;

    if(c1->radius >= sumofYandDist){
        return 1;
    }
    else{
        return 0;
    }

}
///////lab question 2 calculator
typedef struct {
    float operand1, operand2;
    char op;
}bexpression;
float compute1(bexpression expr);
float compute2(bexpression *expr);
int main(){
    bexpression e;
    int choice;
    printf("\nSelect one of the following options: \n");
    printf("1: compute1()\n");
    printf("2: compute2()\n");
    printf("3: exit()\n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter expression (op1 op2 op): \n");
                scanf("%f %f %c", &e.operand1, &e.operand2, &e.op);
                printf("compute1(): %.2f\n", compute1(e));
                break;
            case 2:
                printf("Enter expression (op1 op2 op): \n");
                scanf("%f %f %c", &e.operand1, &e.operand2, &e.op);
                printf("compute2(): %.2f\n", compute2(&e));
                break;
        }
    }
    while (choice < 3);
    return 0;
}
float compute1(bexpression expr){
    float results;
    char op = expr.op;

   if(op == '+'){
        results = expr.operand1 + expr.operand2;
   }
   else if(op == '-'){
        results = expr.operand1 - expr.operand2;
   }
   else if (op == '/'){
        results = expr.operand1 / expr.operand2;
   }
   else if (op == '*'){
        results = expr.operand1*expr.operand2;
   }
   else{
        results = 0;
   }

   return results;
}
float compute2(bexpression *expr){
    float results;
    char op = expr->op;

    if (op == '+'){
        results = expr->operand1 + expr->operand2;
    }
    else if(op == '-'){
        results = expr->operand1 - expr->operand2;
    }
    else if(op == '*'){
        results = expr->operand1*expr->operand2;
    }
    else if(op == '/'){
        results = expr->operand1/expr->operand2;
    }
    else{
        results = 0;
    }

    return results;
}
//////////////////////////lab question 3
#include <stdio.h>
#include <string.h>
struct student{
    char name[20];
    double testScore;
    double examScore;
    double total;
};
double average();
int main(){
    printf("average(): %.2f\n", average());
    return 0;

}
double average(){
    int i = 0;
    double totalAll = 0;
    struct student studentIndex[50];
    printf("Enter student name: \n");
    gets(studentIndex[i].name);

    while (strcmp(studentIndex[i].name,"END")) {
        printf("Enter test score: \n");
        scanf("%lf", &studentIndex[i].testScore);
        printf("Enter exam score: \n");
        scanf("%lf", &studentIndex[i].examScore);
        studentIndex[i].total = (studentIndex[i].testScore + studentIndex[i].examScore) / 2 ;
        printf("Student %s total = %.2lf\n", studentIndex[i].name, studentIndex[i].total);
        totalAll += studentIndex[i].total;
        i++;
        printf("Enter student name: \n");
        scanf("\n");
        gets(studentIndex[i].name);
    }
    if (i != 0){
        return (totalAll/i);
    }
    else{
        return 0.0;
    }
}
//////////lab qn4

#include <stdio.h>
#define INIT_VALUE 1000
typedef struct {
    int id; // staff identifier
    int totalLeave; // the total number of days of leave allowed
    int leaveTaken; // the number of days of leave taken so far
} leaveRecord;
int mayTakeLeave(leaveRecord list[], int id, int leave, int n);
void getInput(leaveRecord list[], int *n);
void printList(leaveRecord list[], int n);
int main(){
    leaveRecord listRec[10];
    int len;
    int id, leave, canTake=INIT_VALUE;
    int choice;
    printf("\nSelect one of the following options: \n");
    printf("1: getInput()\n");
    printf("2: printList()\n");
    printf("3: mayTakeLeave()\n");
    printf("4: exit()\n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            getInput(listRec, &len);
            break;
        case 2:
            printList(listRec, len);
            break;
        case 3:
            printf("Please input id, leave to be taken: \n");
            scanf("%d %d", &id, &leave);
            canTake = mayTakeLeave(listRec, id, leave, len);
            if (canTake == 1)
                printf("The staff %d can take leave\n", id);
            else if (canTake == 0)
                printf("The staff %d cannot take leave\n", id);
            else if (canTake == -1)
                printf("The staff %d is not in the list\n", id);
            else
               printf("Error!");
            break;
        }
   }
   while (choice < 4);
   return 0;
}
void printList(leaveRecord list[], int n){
    int p;
    printf("The staff list: \n");
    for (p = 0; p < n; p++)
        printf ("id = %d, totalleave = %d, leave taken = %d\n",
        list[p].id, list[p].totalLeave, list[p].leaveTaken);
}
void getInput(leaveRecord list[], int *n){
    int i;
    printf("Enter the number of staff records\n");
    scanf("%d", n);

    for(i = 0; i < *n; i++){
        printf("Enter id, totalleave, leavetaken\n");
        scanf("%d %d %d", &list[i].id, &list[i].totalLeave, &list[i].leaveTaken);
    }

}
int mayTakeLeave(leaveRecord list[], int id, int leave, int n){
    int i ;

    for(i = 0; i < n; i++){
        if(list[i].id == id && leave <= list[i].totalLeave){
            return 1;
        }
        else if (list[i].id == id && leave > (list[i].totalLeave-list[i].leaveTaken)){
            return 0;
        }
    }
    return -1;
}

///////assignment////
//qn1


typedef struct {
    double real;
    double imag;
} Complex;

Complex add(Complex c1, Complex c2);
Complex mul(Complex c1, Complex c2);
Complex sub(Complex *c1, Complex *c2);
Complex div(Complex *c1, Complex *c2);

int main(){
    int choice;

    Complex input1, input2, result;
    printf("Complex number operations: \n");
    printf("1 - addition \n");
    printf("2 - subtraction \n");
    printf("3 - multiplication \n");
    printf("4 - division \n");
    printf("5 - quit \n");
    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        if (choice == 5)
            return 0;
        printf("Enter Complex Number 1: \n");
        scanf("%lf %lf", &input1.real, &input1.imag);
        printf("Enter Complex Number 2: \n");
        scanf("%lf %lf", &input2.real, &input2.imag);
        switch (choice) {
            case 1: result = add(input1, input2);
                break;
            case 2: result = sub(&input1, &input2);
                break;
            case 3: result = mul(input1, input2);
                break;
            case 4: result = div(&input1, &input2);
                break;
         }
         printf("complex(): real %.2f imag %.2f\n",
                result.real, result.imag);
      }
      while (choice<5);
        return 0;
}
Complex add(Complex c1, Complex c2){
    Complex result;

    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;

    return result;

}
Complex sub(Complex *c1, Complex *c2){
    Complex result;

    result.real = c1->real - c2->real;
    result.imag = c1->imag - c2->imag;

    return result;
}
Complex mul(Complex c1, Complex c2){
    Complex result;

    result.real = (c1.real*c2.real) - (c1.imag*c2.imag);
    result.imag = (c1.real*c2.imag) + (c2.real*c1.imag);

    return result;
}
Complex div(Complex *c1, Complex *c2){
    int denominator;
    Complex result;
    denominator = (c2->real*c2->real) + (c2->imag*c2->imag);

    result.real = ((c1->real*c2->real) + (c1->imag*c2->imag))/denominator;
    result.imag = ((c1->imag*c2->real) - (c1->real*c2->imag))/denominator;

    return result;

}

////assignment qn2

typedef struct {
    double x;
    double y;
} Point;
typedef struct {
    Point topLeft;
    Point botRight;
} Rectangle;
Rectangle getRect(); //function prototype!

void printRect(Rectangle r);
double findArea(Rectangle r);
int main(){
    Rectangle r;
    int choice;
    printf("Select one of the following options:\n");
    printf("1: getRect()\n");
    printf("2: findArea()\n");
    printf("3: printRect()\n");
    printf("4: exit()\n");
    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("getRect(): \n");
                r = getRect();
                break;
            case 2:
                printf("findArea(): %.2f\n", findArea(r));
                break;
            case 3:
                printf("printRect(): \n");
                printRect(r);
                break;
            default:
                break;
      }
   }
    while (choice < 4);
        return 0;
}
Rectangle getRect(){
    Rectangle r;
    printf("Enter top left point\n");
    scanf("%lf %lf", &r.topLeft.x, &r.topLeft.y);
    printf("Enter bottom right point\n");
    scanf("%lf %lf", &r.botRight.x, &r.botRight.y);

    return r;
}
void printRect(Rectangle r){
    printf("Top left point: %.2lf %.2lf\n", r.topLeft.x, r.topLeft.y);
    printf("Bottom right point: %.2lf %.2lf\n", r.botRight.x, r.botRight.y);
}
double findArea(Rectangle r){
    double Area;

    Area = fabs((r.topLeft.x - r.botRight.x)*(r.topLeft.y - r.botRight.y));

    return Area;
}
*/

///qn 3 assignment//////
#include <string.h>
#define SIZE 50
typedef struct {
    int id;
    char name[50];
} Student;
void inputStud(Student *s, int size);
void printStud(Student *s, int size);
int removeStud(Student *s, int *size, char *target);
int main(){
    Student s[SIZE];
    int size=0, choice;
    char target[80];
    int result;
    printf("Select one of the following options: \n");
    printf("1: inputStud()\n");
    printf("2: removeStud()\n");
    printf("3: printStud()\n");
    printf("4: exit()\n");
    do{
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
void inputStud(Student *s, int size){
    int i;
    for (i = 0; i < size; i++){
        printf("Student ID:\n");
        scanf("%d",&(s+i)->id);
        printf("Student Name:\n");
        scanf("\n");
        gets((s+i)->name);

    }
}
void printStud(Student *s, int size){
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
        j++;
        if(strcmp((s+i)->name, target) == 0){
            j++; //skip the current one
            (s+i)->id = (s+j)->id;
            strcpy((s+i)->name,(s+j)->name);
            *size = *size-1;
            remove = 0;
        }
    }
    return remove;
}
//////////assignment qn4

#include <string.h>
#define MAX 100
typedef struct {
    char name[80];
    char telno[40];
    int id;
    double salary;
} Employee;
int readin(Employee *p);
void printEmp(Employee *p, int size) ;
int search(Employee *p, int size, char *target);
int addEmployee(Employee *p, int size, char *target);
int main(){
    Employee emp[MAX];
    char name[10];
    int k, size=0, found=0, ans, choice, result;
    printf("Select one of the following options: \n");
    printf("1: readin()\n");
    printf("2: search()\n");
    printf("3: addEmployee()\n");
    printf("4: print()\n");
    printf("5: exit()\n");
    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                size = readin(emp);
                break;
            case 2:
                printf("Enter search name: \n");
                scanf("\n");
                gets(name);
                result = search(emp,size,name);
                if (result != 1)
                  printf ("Name not found!\n");
                break;
            case 3:
                printf("Enter new name: \n");
                scanf("\n");
                gets(name);
                result = search(emp,size,name);
                if (result != 1)
                    size = addEmployee(emp, size, name);
                else
                    printf("The new name has already existed in the database");
                break;
            case 4:
                printEmp(emp, size);
                break;
            default:
                break;
        }
    }
    while (choice < 5);
    return 0;
}
int readin(Employee *p){
    int i = 0;
    printf("Enter name:\n");
    scanf("\n");
    gets((p+i)->name);
    while(strcmp((p+i)->name, "#") != 0){
        printf("Enter tel:\n");
        gets((p+i)->telno);
        printf("Enter id:\n");
        scanf("\n");
        scanf("%d", &(p+i)->id);
        printf("Enter salary:\n");
        scanf("\n");
        scanf("%lf", &(p+i)->salary);
        i++;
        printf("Enter name:\n");
        scanf("\n");
        gets((p+i)->name);
    }
    return i;
}
void printEmp(Employee *p, int size){
    int i = 0;
    printf("The current employee list:\n");
    for(i=0; i < size; i++){
        printf("%s %s %d %.2lf\n", (p+i)->name, (p+i)->telno, (p+i)->id, (p+i)->salary);
    }
}
int search(Employee *p, int size, char *target){
    int i = 0;
    for(i = 0; i<size; i++){
        if(strcmp(target, (p+i)->name ) == 0){
            printf("Employee found at index location: %d\n", i);
            printf("%s %s %d %.2lf\n", (p+i)->name, (p+i)->telno, (p+i)->id, (p+i)->salary);
            return 1;
        }
    }
    return 0;
}
int addEmployee(Employee *p, int size, char *target){
    if (size < 100 && size >=0){
        int i = size;
        strcpy((p+i)->name, target);
        printf("Enter tel:\n");
        gets((p+i)->telno);
        printf("Enter id:\n");
        scanf("\n");
        scanf("%d", &(p+i)->id);
        printf("Enter salary:\n");
        scanf("\n");
        scanf("%lf", &(p+i)->salary);
        printf("Added at position: %d\n", i);
        size++;
        return size;
    }
    else{
        return 0;
    }

}
*/

