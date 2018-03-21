#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

//computer grade
int main(){

    int ID;
    float grade = 0;

    printf("What is the ID?\n");
    scanf("%d", &ID);

    while (ID != -1){
        printf("What is the grade\n");
        scanf("\n%f", &grade);

        while (grade<=100){

            if (grade >= 75){
                printf("Grade A");
            }
            else if ( (grade >= 65) && (grade < 75)){
                printf("Grade B");
            }
            else if ((grade >= 55) && (grade < 45)  ){
                printf("Grade C");
            }
            else if ((grade >= 45) && (grade < 55)){
                printf("Grade D");
            }
            else{
                printf("Fail");
            }
        }

    return 0;
    }
}



// using switch statement. Question why wont it loop infinitely till -1?
int main(){

    int grades;
    int student_id;

    printf("what is the studen_id?\n");
    scanf("%d", &student_id);

    while (student_id != -1){

        printf("what is the score?\n");
        scanf("\n%d", &grades);

        switch(grades/5){
            case 20:
            case 19:
            case 18:
            case 17:
            case 16:
            case 15:
                printf("Grade A");
                break;
            case 14:
            case 13:
                printf("Grade B");
                break;
            case 12:
            case 11:
                printf("Grade C");
                break;
            case 10:
            case 9:
                printf("Grade D");
                break;
            default:
                printf("fail");
        }
        return 0;

    }

}

//multi line
int main()
{
   int total, count, lines, input;
   double average;
   int i;

   printf("Enter number of lines: \n");
   scanf("%d", &lines);
   for (i = 0; i < lines; i++) {
      total=0; count=0;
      printf("Enter line %d (end with -1): \n", i+1);
      scanf("%d", &input);
      while (input != -1)
      {
         total += input;
         count++;
         scanf("%d", &input);
      }
      average = (double)total/(double)count;
      printf("Average = %.2f\n", average);
   }
   return 0;
}


/*

}
//patterns

int main(){

    int height;
    int x; //row
    int y;  //column
    int num;

    printf("what is the height?\n");
    scanf("%d", &height);

    if(height < 10 && height > 0){
        for( x = 0; x< height+1; x++){ //print row
            for(y= 0; y<x; y++){ //print column
                if(x%3 == 0){
                    num = 3;  //print 3 instead of 0, mod 3 is 0, 1, 2
                }
                else{
                    num = (x%3);
                }
                printf("%d",num);
            }
            printf("\n");
        }
    }
        else{
            printf("invalid\n");
        }

    return 0;
}


//series for e^x
int main(){
    int n = 1;
    int denominator = 1;
    float numerator = 1.0;
    float result = 1.0; //first value of the formula
    float x = 1.0;

    printf("Enter x: \n");
    scanf("%f", &x);

    for(n=1; n <= 10; n++){
        denominator = denominator*n;
        numerator = numerator*x;
        result =  result + (numerator/denominator);

    }
    printf("d: %d\n", denominator);
    printf("n: %f\n", numerator);
    printf("result: %f\n", result);

return 0;
}

// income tax annd pay
int main(){
    int hours;
    float tax, grossPay, netPay;

    printf("Enter hours of work: \n");
    scanf("%d", &hours);

    if(hours < 40){
        grossPay = hours*6.00;
        tax = 0.1*grossPay;
        netPay = grossPay - tax;
     }
    else{
        grossPay = ((hours-40)*9.0)+240;
        if(grossPay < 1000){
            tax = 0.1*grossPay;
            netPay = grossPay - tax;
        }
        else if (grossPay > 1000 && grossPay <= 1500){
            tax = (0.2*(grossPay-1000))+100;
            netPay = grossPay - tax;
        }
        else{
            tax = (0.3*(grossPay-1500))+200;
            netPay = grossPay - tax;
        }
    }
    printf("Gross pay = %.2f\n", grossPay);
    printf("Tax = %.2f\n", tax);
    printf("Net pay = %.2f\n", netPay);
    return 0;
}

//salary grade
int main(){
    int salary, merit;
    printf("Enter the salary: \n");
    scanf("%d", &salary);
    printf("Enter the merit: \n");
    scanf("%d", &merit);

    if (salary >= 700 && salary <= 899){
        if (salary <= 799 && merit < 20){
            printf("grade B");
        }
        else{
            printf("grade A");
        }
    }
    else if (salary < 700 && salary >= 600){
        if(merit<10){
            printf("grade c");
        }
        else{
            printf("grade b");
        }
    }
    else{
        printf("grade c");
    }

    return 0;
}
*/




// compute car price

#include <stdio.h>
int main(){
    int list, coe = 0, cat;
    double discounted, luxury = 0, gst, total;

    printf("Please enter the list price: \n");
    scanf("%d", &list);
    printf("Please enter the category: \n");
    scanf("%d", &cat);

    if (cat == 1){
        coe = 70000;
    }
    else if (cat == 2){
        coe = 80000;
    }
    else if (cat == 3){
        coe = 23000;
    }
    else if (cat == 4){
        coe = 600;
    }
    else{
        printf("wrong category");
    }
    discounted = 0.9*list;
    gst = 0.03*discounted;
    if (list > 100000){
        luxury = 0.1*discounted;
        total = gst + luxury + discounted + coe;
    }
    else{
        total = discounted + gst + coe;
    }

    printf("Total price is $%.2lf\n", total);
return 0;

}



//counting digits and chars


#include <stdio.h>
int main2(){
    int ccount = 0, dcount = 0;
    int i;
    char ch;
    printf("Enter your characters (# to end): \n");
    scanf("%c", &ch);

    while(ch != '#'){
        scanf("%c", &ch);
        for(i = 0; i < ch; i++){
            if ( ch < '57' && ch > '48'){
                dcount++;
            }
            else{
                ccount++;
            }
        }
    }


    printf("The number of digits: %d\n", dcount);
    printf("The number of letters: %d\n", ccount);
    return 0;
}
