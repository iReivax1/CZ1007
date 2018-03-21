#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numDigits1(int num);
int digitPos1(int num, int digit);
int square1(int num);
void numDigits2(int num, int *result);
void digitPos2(int num, int digit, int *result);
void square2(int num, int *result);
int main(){
    int choice;
    int number, digit, result=0;
    do {
        printf("\nPerform the following functions ITERATIVELY:\n");
        printf("1:  numDigits1()\n");
        printf("2:  numDigits2()\n");
        printf("3:  digitPos1()\n");
        printf("4:  digitPos2()\n");
        printf("5:  square1()\n");
        printf("6:  square2()\n");
        printf("7:  quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
         case 1:
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("numDigits1(): %d\n", numDigits1(number));
            break;
         case 2:
            printf("Enter the number: \n");
            scanf("%d", &number);
            numDigits2(number, &result);
            printf("numDigits2(): %d\n", result);
            break;
         case 1:
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("numDigits1(): %d\n", numDigits1(number));
            break;
         case 2:
            printf("Enter the number: \n");
            scanf("%d", &number);
            numDigits2(number, &result);
            printf("numDigits2(): %d\n", result);
            break;
         case 3:
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("Enter the digit: \n");
            scanf("%d", &digit);
            printf("digitPos1(): %d\n", digitPos1(number, digit));
            break;
          case 4:
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("Enter the digit: \n");
            scanf("%d", &digit);
            digitPos2(number, digit, &result);
            printf("digitPos2(): %d\n", result);
            break;
          case 5:
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("square1(): %d\n", square1(number));
            break;
          case 6:
            printf("Enter the number: \n");
            scanf("%d", &number);
            square2(number, &result);
            printf("square2(): %d\n", result);
            break;
          default: printf("Program terminating .....\n");
            break;
      }
   }
   while (choice < 7);
   return 0;
}
//add function code here
int numDigits1(int num){

    int n = num;
    int count = 0;

    while (n != 0){
        n /= 10;
        count++;
    }
    return count;
}
void numDigits2(int num, int *result){
    int n = num;
    int count = 0;

    while(n != 0){
        n = n/10;
        count++;
    }

    *result = count;

}
int digitPos1(int num, int digit){

    int result;
    int count = 1;

    result = num % 10;
    num = num/10;

    while (result != digit){
        result = num % 10;
        num = num/10;
        count++;
        if(num == 0 && result != digit){
            count = 0;
            break;
        }
    }
    return count;
}
void digitPos2(int num, int digit, int *result){

    int resultant;
    int count = 1;

    resultant = num % 10;
    num = num/10;

    while (resultant != digit){
        result = num % 10;
        num = num/10;
        count++;
        if(num == 0 && resultant != digit){
            count = 0;
            break;
        }
    }
    *result = count;
}

int square1(int num){
    int i;
    int number = 0;
    for(i=0; i<num; i++){
        number = number + (i*2+1);
    }
    return number;
}

void square2(int num, int *result){
    int i;
    int number = 0;
    for(i=0; i<num; i++){
        number = number + (i*2+1);
    }
    *result = number;

}

//question 1

int numDigits1(int num);
void numDigits2(int num, int *results);
int main(){

    int number;
    int result = 0;

    printf("Enter the number:\n");
    scanf("%d", &number);
    printf("numDigits1: %d\n", numDigits1(number));

    numDigits2(number, &result);
    printf("numDigits2(): %d\n", result);

    return 0;
}

int numDigits1(int num){

    int n = num;
    int count = 0;

    while (n != 0){
        n /= 10;
        count++;
    }
    return count;
}
void numDigits2(int num, int *result){
    int n = num;
    int count = 0;

    while(n != 0){
        n = n/10;
        count++;
    }

    *result = count;

}
*/
//question 2


int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);

int main(){
    int number, digit, result = 0;

    printf("Enter the number:\n");
    scanf("%d", &number);
    printf("Enter the digit: \n");
    scanf("%d", &digit);
    printf("digitPos1: %d\n", digitPos1(number, digit));
    digitPos2(number, digit, &result);
    printf("digitPos2: %d\n", result);

    return 0;
}
int digitPos1(int num, int digit){

    int result;
    int count = 1;
    result = num % 10; //find the number iterating
    num = num/10; //interate through the string of numbers

    while (result != digit){
        result = num % 10;
        num = num/10;
        count++;
        if(num == 0 && result != digit){ //if after interating everything and cannot find, return 0
            count = 0;
            break;
        }

    }
    return count;
}
void digitPos2(int num, int digit, int *result){

    int resultant;
    int count = 1;

    resultant = num % 10;
    num = num/10;

    while (resultant != digit){
        result = num % 10;
        num = num/10;
        count++;
        if(num == 0 && resultant != digit){
            count = 0;
            break;
        }
    }
    *result = count;
}

/*
//question 3
int square1(int num);
void square2(int num, int *result);
int main(){
    int number, result = 0;

    printf("Enter the number\n");
    scanf("%d", &number);
    printf("square1: %d\n", square1(number));
    square2(number, &result);
    printf("square2: %d\n", result);

    return 0;
}

int square1(int num){
    int i;
    int number = 0;
    for(i=0; i<num; i++){
        number = number + (i*2+1);
    }
    return number;
}

void square2(int num, int *result){
    int i;
    int number = 0;
    for(i=0; i<num; i++){
        number = number + (i*2+1);
    }
    *result = number;

}


//question 4
void inputXY(double *x1, double *y1, double *x2, double *y2);
double calDistance1(double x1, double y1, double x2, double y2);
void calDistance2(double x1, double y1, double x2, double y2, double *dist);
void outputResult(double dist);

int main(){
    double x1, y1, x2, y2;
    double distance = 0.0;

    inputXY(&x1, &y1, &x2, &y2);
    distance = calDistance1(x1, y1, x2, y2);
    printf("calDistance1():\n");
    outputResult(distance);
    calDistance2(x1, y1, x2, y2, &distance);
    printf("calDistance2():\n");
    outputResult(distance);

    return 0;

}

void inputXY(double *x1, double *y1, double *x2, double *y2){

    printf("Input x1,y1, y1,y2 : \n");
    scanf("%lf %lf %lf %lf", x1, y1, x2, y2);
}
void outputResult(double dist){
    printf("%.2lf \n", dist);
}

double calDistance1(double x1, double y1, double x2, double y2){
    double dist = 0.0;
    double x;
    double y;

    x = pow((x2 - x1), 2);
    y = pow((y2 - y1), 2);
    dist = sqrt(x+y);

    return dist;
}


void calDistance2(double x1, double y1, double x2, double y2, double *dist){
    double result = 0.0;
    double x;
    double y;

    x = pow((x2 - x1), 2);
    y = pow((y2 - y1), 2);
    result = sqrt(x+y);

    *dist = result;
}

*/






