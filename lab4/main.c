#include <stdio.h>

void printReverse1(int ar[], int size);
void printReverse2(int ar[], int size);
void reverseAr1D(int ar[], int size);
int main(){
    int ar[10];
    int size, i;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i <= size-1; i++)
        scanf("%d", &ar[i]);

    printReverse1(ar, size);
    printReverse2(ar, size);
    reverseAr1D(ar, size);
    printf("reverseAr1D(): ");
        if (size > 0){
            for (i=0; i<size; i++)
              printf("%d ", ar[i]);
        }
return 0;
}

void printReverse1(int ar[], int size){
    int i;
    printf("printReverse1() : ");
    for(i = size-1 ; i > -1 ; i--){
        printf("%d ", ar[i]);
    }
}

void printReverse2(int ar[], int size){
    int i;
    printf("printReverse2() : ");
    for(i = size-1; i > -1; i--){
        printf("%d", *(ar+i));
    }
}
void reverseAr1D(int ar[], int size){
    int i ;
    int temp = 0;
    for (i = 0; i < size/2 ; i++){ // swapping values only half of it, center is the same of odd length.
       temp = ar[i];
       ar[i] = ar[size-i-1];
       ar[size-i-1] = temp;


        printf("temp = %d \n ar[i] = %d\n", temp, ar[i]);
        printf("i = %d \n ar[size-i-1]= %d\n",i,j);
    }

}

// question 2 findARID

#define INIT_VALUE -1000
int findAr1D(int size, int ar[], int target);
int main(){
    int ar[20];
    int size, i, target, result = INIT_VALUE;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<=size-1; i++)
        scanf("%d", &ar[i]);
    printf("Enter the target number: \n");
    scanf("%d", &target);
    result = findAr1D(size, ar, target);
    if (result == -1)
        printf("findAr1D(): Not found\n");
    else
        printf("findAr1D(): %d", result);
    return 0;
}

int findAr1D(int size, int ar[], int target){
     int i;
     for (i = 0; i < size; i++){
        if (ar[i] == target){
            return (i);
            break;
        }
        else if (i == (size-1) && ar[i] != target){
            return -1;
        }
     }
}

// question 3
#define SIZE 3
void swap2Rows(int ar[][SIZE], int r1, int r2);
void swap2Cols(int ar[][SIZE], int c1, int c2);
void display(int ar[][SIZE]);
int main(){
    int array[SIZE][SIZE];
    int row1, row2, col1, col2;
    int i,j;
    int choice;
    printf("\nSelect one of the following options: \n");
    printf("1: getInput()\n");
    printf("2: swap2Rows()\n");
    printf("3: swap2Cols()\n");
    printf("4: display()\n");
    printf("5: exit()\n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the matrix (3x3): \n");
                for (i=0; i<SIZE; i++) //row
                    for (j=0; j<SIZE; j++) //column
                        scanf("%d", &array[i][j]);
                break; //break the case
            case 2:
                printf("Enter two rows for swapping: \n");
                scanf("%d %d", &row1, &row2);
                swap2Rows(array, row1, row2);
                printf("The new array is: \n");
                display(array);
                break;
            case 3:
                printf("Enter two columns for swapping: \n");
                scanf("%d %d", &col1, &col2);
                swap2Cols(array, col1, col2);
                printf("The new array is: \n");
                display(array);
                break;
            case 4:
                display(array);
                break;
        } //close switch
    } //close do
    while (choice < 5);
        return 0;
} //close main

void display(int ar[][SIZE]){
    int l,m;
    for (l = 0; l < SIZE; l++) { //row
        for (m = 0; m < SIZE; m++) //column
            printf("%d ", ar[l][m]);
        printf("\n"); //break row
    }
}
void swap2Rows(int ar[][SIZE], int r1, int r2){
    int r, c, temp;
    for (r = 0; r < 3; r++){
        if(r == r1){
            for (c = 0; c < SIZE; c++){
                temp =  ar[r2][c];
                ar[r2][c] = ar[r1][c];
                ar[r1][c] = temp;
            }
        }
    }
}
void swap2Cols(int ar[][SIZE], int c1, int c2){
    int r, c, temp;
    for (c = 0; c < SIZE; c++){
        if(c == c1){
            for (r = 0; r < 3; r++){
                temp = ar[r][c2];
                ar[r][c2] = ar[r][c1];
                ar[r][c1] = temp;
            }
        }
    }
}

// question 4 minimize matrix

 #include <stdio.h>
   #define SIZE 10
   void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);
   void display(int ar[][SIZE], int rowSize, int colSize);
   int main()
   {
      int ar[SIZE][SIZE], rowSize, colSize;
      int i,j;
      printf("Enter row size of the 2D array: \n");
      scanf("%d", &rowSize);
      printf("Enter column size of the 2D array: \n");
      scanf("%d", &colSize);
      printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
      for (i=0; i<rowSize; i++)
         for (j=0; j<colSize; j++)
            scanf("%d", &ar[i][j]);
      reduceMatrix2D(ar, rowSize, colSize);
      printf("reduceMatrix2D(): \n");
      display(ar, rowSize, colSize);
      return 0;
   }
void display(int ar[][SIZE], int rowSize, int colSize){
int l,m;
      for (l = 0; l < rowSize; l++) {
         for (m = 0; m < colSize; m++)
            printf("%d ", ar[l][m]);
      printf("\n");
   }
}
void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize){
    int r, c;
    int i = -1;
    int sum = 0;
    for(c = 0; c < colSize; c++){
        for (r = rowSize-1; r > i ; r--){ //add from bottom up
            sum += ar[r][c];
            ar[r+1][c] = 0; //make everything iterated 0

        }
         ar[c][c] = sum; //ar[r][c] = sum
         i++;
         sum = 0; //reset for next colum
    }
}



