#include <stdio.h>
#include <stdlib.h>
///string
.//lab question 1 sweepspace

char *sweepSpace1(char *str);
char *sweepSpace2(char *str);
int main(){
    char str[80];
    printf("Enter the string: \n");
    gets(str);
    printf("sweepSpace1(): %s\n", sweepSpace1(str));
    printf("sweepSpace2(): %s\n", sweepSpace2(str));
    return 0;

}

char *sweepSpace1(char *str){
    int i, j, len;

    i=0; len=0;
    while (str[i]!='\0'){
        len++; //find length of string
        i++;
    }
    j = 0;
    for (i=0; i < len; i++){
        if (str[i] != ' '){ //not the spot of whitespace
            str[j] = str[i]; //put the element that is not a white space to array starting from 0;
            j++; //new length of array
        }
    }
    str[j] = '\0'; // add a null character at the end
    return str;
}

char *sweepSpace2(char *str){ //str is a pointer variable
    //go through the string if string = ' '
    int i ,j ,len;
    i = 0;
    j = 0;
    len = 0;
    while (*(str+i) != '\0'){
        len++;
        i++;
    }
    j=0;
    for (i=0; i< len; i++){
        if (*(str+i) != ' '){
            *(str+j) = *(str+i);
            j++;
        }
    }
    *(str+j) = '\0';
    return str;
}

/// lab question 2

 #include <stdio.h>
char *stringncpy(char *s1, char *s2, int n);
int main(){
    char sourceStr[40], targetStr[40], *target;
    int length;
    printf("Enter the string: \n");
    gets(sourceStr);
    printf("Enter the number of characters: \n");
    scanf("%d", &length);
    target = stringncpy(targetStr, sourceStr, length);
    printf("stringncpy(): %s\n", target);
    return 0;
}
char *stringncpy(char *s1, char *s2, int n){
    // n is length
    //s1 is target(d)
    //s2 is source (s)

    int i,j;
    j = 0;

    for(i = 0; i< n; i++){
        *(s1+j) = *(s2+i);
        j++;
    }
    *(s1+k) = '\0';
    for (h = k; h < n; h++)
        *(s1+h) = '\0';
    return s1;
}

//qn3
#include <string.h>
#define SIZE 10
#define INIT_VALUE 999
void printNames(char nameptr[][80], int size);
void readNames(char nameptr[][80], int *size);
int findTarget(char *target, char nameptr[][80], int size);
int main(){
    char nameptr[SIZE][80], t[40];
    int size, result = INIT_VALUE;
    int choice;
    printf("\nSelect one of the following options: \n");
    printf("1: readNames()\n");
    printf("2: findTarget()\n");
    printf("3: printNames()\n");
    printf("4: exit()\n");
    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readNames(nameptr, &size);
                break;
            case 2: //find target
               printf("Enter target name: \n");
               scanf("\n");
               gets(t);
               result = findTarget(t, nameptr, size);
               printf("findTarget(): %d\n",  result);
               break;
            case 3:
               printNames(nameptr, size);
               break;
        }
    }
    while (choice < 4);
        return 0;
}
void printNames(char nameptr[][80], int size){

    int i = 0;
    for (i = 0; i < size; i++){
        printf("%s ", nameptr[i]);
    }
    printf("\n");
    return;
}
void readNames(char nameptr[][80], int *size){
    int i;
    printf("Enter Size: \n");
    scanf("%d", size);
    printf("Enter %d names: \n", *size);
    for (i = 0; i < *size ; i++){
        scanf("\n%s", nameptr[i]);
    }
}
int findTarget(char *target, char nameptr[][80], int size){
    int  i;
    for (i = 0; i < size; i++){
        if((strcmp(nameptr[i], target)) == 0){
            return i;
        }
        return -1;
        }
    }
}
// lab question 4

#define INIT_VALUE -1
int palindrome(char *str);
int main(){
    char str[80];
    int result = INIT_VALUE;
    printf("Enter a string: \n");
    gets(str);
    result = palindrome(str);
    if (result == 1)
        printf("palindrome(): A palindrome\n");
    else if (result == 0)
        printf("palindrome(): Not a palindrome\n");
    else
        printf("An error\n");
    return 0;
}
int palindrome(char *str){ // if abbcbba is same if read from left or right it is palindrome
    int i, len, count;
    i = 0; len = 0; count = 0;
    while (*(str+i) != '\0'){ //find the length of the string input
        len++;
        i++;
    }

    for(i = 0; i < len/2; i++){
       if (*(str+i) == *(str+(len-1)-i)){ // check the 1st element with the last element
        return 1; //track number of same elements
       }
       else{
        return 0;
       }
    }
    return -1;
}



/////assignment 5/

//q1 insert char

#include <stdio.h>
void insertChar(char *str1, char *str2, char ch);
int main(){
    char a[80],b[80];
    char ch;
    printf("Enter a string: \n");
    gets(a);
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a,b,ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}
void insertChar(char *str1, char *str2, char ch){
    int i, len, j;
    len = 0;
    i = 0;
    while(*(str1+i) != '\0'){
        len++;
        i++;
    }
    j=0;
    for (i = 0; i < len+1; i++){
        if (i%3 == 0 && i>0){
            str2[j] = ch;
            ++j;
        }
        str2[j] = str1[i];
        j++;
    }

    *(str2+j) = '\0';
}

//q2 count max length
int longWordLength(char *s);
int main(){
    char str[80];
    printf("Enter a string: \n");
    gets(str);
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s){
    int i = 0;
    int len = 0;
    int wordCnt = 0;
    int longWord = 0;
    while( *(s+i) != '\0'){
        len++;
        i++;
    }
    for(i = 0; i < len; i++){

        if ((*(s+i) >= 'A' && *(s+i) <= 'Z') || (*(s+i)>= 'a' && *(s+i) <= 'z')){
            wordCnt++;
        }
        else{
            wordCnt = 0;
        }
        if (wordCnt >= longWord){
            longWord = wordCnt;
        }
    }
    return longWord;
}

///q3 swap max and min

#include <stdio.h>
void maxCharToFront(char *str);
int main()
{
    char str[80];
    printf("Enter a string: \n");
    gets(str);
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}
void maxCharToFront(char *str){
    int i = 0;
    int len = 0;
    int pos = 0;
    char temp;

    while(*(str+i) != '\0'){
        len++;
        i++;
    }
    for (i = 0; i < len; i++){ //find max char
       if(temp < str[i]){
        pos = i; //store index number
        temp = str[i]; //store value
       }
    }
    ////found max char
    for (i = pos; i > 0; i--){
        *(str+i) = *(str+i-1);
    }
    str[0] = temp;
}

/////question 4

#include <stdio.h>
#define INIT_VALUE 999
int stringcmp(char *s1, char *s2);
int main(){
    char source[80], target[80];
    int result = INIT_VALUE;
    printf("Enter a source string: \n");
    gets(source);
    printf("Enter a target string: \n");
    gets(target);
    result = stringcmp(source, target);
    if (result == 1)
        printf("stringcmp(): greater than");
    else if (result == 0)
        printf("stringcmp(): equal");
    else if (result == -1)
        printf("stringcmp(): less than");
    else
        printf("stringcmp(): error");
    return 0;
}
int stringcmp(char *s1, char *s2){
    int i = 0;

    while(s1[i] != '\0' ){

        if (s1[i] > s2[i])
            return 1;
        else if(s1[i] < s2[i])
            return -1;
        else
            i++;


    }
    return 0;

}












