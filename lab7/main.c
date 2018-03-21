#include <stdio.h>
#include <stdlib.h>

///lab qn1
int rNumDigits1(int num);
void rNumDigits2(int num, int *result);
int main(){
    int number, result=0;
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("rNumDigits1(): %d\n", rNumDigits1(number));
    rNumDigits2(number, &result);
    printf("rNumDigits2(): %d\n", result);
    return 0;
    }
int rNumDigits1(int num){
   if(num == 0)
    return 0;
   else
    return 1 + rNumDigits1(num/10);
}
void rNumDigits2(int num, int *result)
{
   if(num == 0)
    return; //terminate
   else
   {
       ++*result;
       rNumDigits2(num/10, result);
   }
}
//lab qn2
#include <stdio.h>
int rDigitPos1(int num, int digit);
void rDigitPos2(int num, int digit, int *pos);
int main(){

         int number, digit, result=0;
         printf("Enter the number: \n");
         scanf("%d", &number);
         printf("Enter the digit: \n");
         scanf("%d", &digit);
         printf("rDigitPos1(): %d\n", rDigitPos1(number, digit));
         rDigitPos2(number, digit, &result);
         printf("rDigitPos2(): %d\n", result);
         return 0;
}
int rDigitPos1(int num, int digit){
   int p;
   if (num % 10 == digit) //found digit in num
      return 1;
   else if (num < 10) //end of num
      return 0;
   else {
      p = rDigitPos1(num/10, digit);
      printf("p = %d",p);
      if (p > 0)
         return p + 1;
      else
         return 0;
   }
}
void rDigitPos2(int num, int digit, int *pos){
    int count = *pos;
   if (num % 10 == digit)
      *pos = 1;
   else if (num < 10)
      *pos = 0;
   else {
      rDigitPos2(num/10, digit, pos);
      if (*pos > 0)
         *pos += 1;
      else
         *pos = 0;
   }
}
//lab qn3
#include <stdio.h>
int rSquare1(int num);
void rSquare2(int num, int *result);
int main(){
    int number, result=0;
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("rSquare1(): %d\n", rSquare1(number));
    rSquare2(number, &result);
    printf("rSquare2(): %d\n", result);
    return 0;
}
int rSquare1(int num){
    if(num == 1){ //terminate at 1 since counting starts from 1
        return 1;
    }
    else{
        return (num+num-1)+rSquare1(num-1);
    }
}
void rSquare2(int num, int *result){
    if (num == 1){
        *result = *result + 1;
        return;
    }
    else{
        *result = num+num-1+*result;
        return rSquare2(num-1, result);
    }
}

//qn 4
#include <stdio.h>
#define SIZE 20
int rCountArray(int array[], int n, int a);
int main(){
    int array[SIZE];
    int index, count, target, size;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d numbers: \n", size);
    for (index = 0; index < size; index++)
        scanf("%d", &array[index]);
    printf("Enter the target number: \n");
    scanf("%d", &target);
    count = rCountArray(array, size, target);
    printf("rCountArray(): %d\n", count);
    return 0;
}
int rCountArray(int array[], int n, int a){ //n is size, a is target
    if(n == 0){ //terminating condition,
        return 0;
    }
    else{
        if(array[n-1] == a){ // found same as target
            return 1 + rCountArray(array,n-1,a) ;
        }
        else{
            return rCountArray(array,n-1,a);
        }
    }
}
////assignment///////////////////////////////////////////////////////////
#include <stdio.h>
void rGcd2(int num1, int num2, int *result);
int main(){
    int n1, n2, result;
    printf("Enter 2 numbers: \n");
    scanf("%d %d", &n1, &n2);
    rGcd2(n1, n2, &result);
    printf("rGcd2(): %d\n", result);
    return 0;
}
void rGcd2(int num1, int num2, int *result){
    if (num1 > num2){
        rGcd2(num1-num2, num2, result);
    }
    else if (num2 > num1){
        rGcd2(num1, num2-num1, result);
    }
    else{
        *result = num1;
    }
}

//qn2
#include <stdio.h>
int rDigitValue1(int num, int k);
int main(){
    int k, number;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("Enter k position: \n");
    scanf("%d", &k);
    printf("rDigitValue1(): %d\n", rDigitValue1(number, k));
    return 0;
}
int rDigitValue1(int num, int k){
    if(k == 1){
        return (num%10) ;
    }
    else{
        return rDigitValue1(num/10, k-1);
    }
}
//qn3
#include <stdio.h>
#define INIT_VALUE -1
void rAllEvenDigits2(int num, int *result);
int main(){
    int number, result=INIT_VALUE;
    printf("Enter a number: \n");
    scanf("%d", &number);
    rAllEvenDigits2(number, &result);
    if (result == 1)
        printf("rAllEvenDigits2(): yes\n");
    else if (result == 0)
        printf("rAllEvenDigits2(): no\n");
    else
        printf("rAllevenDigits2(): error\n");
    return 0;
}
void rAllEvenDigits2(int num, int *result){
    if(num / 10 != 0){
        if ( ((num%10) % 2) == 0 ){ // if is even continue iterating
            rAllEvenDigits2(num/10, result);
        }
        else{ //for odd numbers
            *result = 0;
        }
    }
    else if(num < 10){
        if ( (num%2) == 0){
            *result = 1;
        }
        else{ //for odd numbers
            *result = 0;
        }
    }
    else{
        *result = 1;
    }
}

#include <stdio.h>
int rLookupAr(int array[], int size, int target);
int main()
{
   int numArray[80];
   int target, i, size;
   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d numbers: \n", size);
   for (i=0; i < size; i++)
      scanf("%d", &numArray[i]);
   printf("Enter the target number: \n");
   scanf("%d", &target);
   printf("rLookupAr(): %d", rLookupAr(numArray, size, target));
   return 0;
}
int rLookupAr(int array[], int size, int target){
    if(array[size-1] == target){
        printf("array[size] = %d", array[size]);
        return size-1;
    }
    else if(size <= 0){
        return -1;
    }
    else{
        return rLookupAr(array,size-1,target);
    }
}












