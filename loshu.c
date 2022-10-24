/*
    Program: loshu.c

    This program simulate a magic square using a 2-d array. 
    Write a function that accepts a 2-d array as argument and determine
    whether the array is lo shu square 

    1) Simple: define two of 2-d array, one lo shu, one fore not.
       then, send it to test funciton. array define in main

    2) challenging: create and populate 2-d with random # 1-9.
       No repeat number. then cehck if it is lo shu. 
       put random number square until is lo shu
       print 2 thing
       * total number of square generated and tested before success, the count
       * print the lo shu 

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

const int SIZE = 3;

// Function prototypes
int test(int arr[3][3]);
void printArray(int arr[3][3]);

int main()
{
    int result = 0;
    int mark[] = {0,0,0,0,0,0,0,0,0}; // it will turn 1 when rand is made 
    int loshu[3][3];
    int checkCounter =1;
    // seed random number 
    time_t t;
    srand((unsigned) time(&t));


    while(result == 0)
    {
        //clear the Square first and mark
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                loshu[i][j] = 0;
            }
        }
        for(int i = 0; i < 9; i++){
            mark[i] = 0;
        }
        // fill the loshu
        for(int i = 0; i < SIZE; i++){
            for(int j =0; j < SIZE; j++){
                // check loshu[i][j] is filled already
                int isRepeat = 0;
                while(isRepeat == 0){
                    int n = (rand() % 9) + 1; // 1 - 9 is generated
                    if(mark[n-1] == 0){
                        loshu[i][j] = n;
                        mark[n-1] = 1;
                        isRepeat = 1;
                    }
                }
            }
        }
        // Now 2-d array is generated
        //check the result,
        result = test(loshu);
        if(result == 1) 
        {
            break;
        }
        checkCounter++;
    }
        printf("Total %d squares were generated.\n", checkCounter);
        printArray(loshu);  
    
    return 0;
}


int test(int arr[3][3])
{
    
    // total 8 sum needed

    // find the magic number
    int target = (arr[0][0] + arr[0][1] + arr[0][2]);

    // row check
    if((arr[1][0] + arr[1][1] + arr[1][2]) != target)
    {
        return 0;
    }
    else if((arr[2][0] + arr[2][1] + arr[2][2]) != target)
    {
        return 0;
    }
    else if((arr[0][0] + arr[1][0] + arr[2][0]) != target)
    {
        // col check 
        return 0;
    }
    else if((arr[0][1] + arr[1][1] + arr[2][1]) != target)
    {
        // col check 
        return 0;
    }
    else if((arr[0][2] + arr[1][2] + arr[2][2]) != target)
    {
        // col check 
        return 0;
    }
    else if((arr[0][0] + arr[1][1] + arr[2][2]) != target)
    {
        // diag
        return 0;
    }
    else if((arr[0][2] + arr[1][1] + arr[2][0]) != target)
    {
        // diag
        return 0;
    }
    else{
        return 1;
    }
}

void printArray(int arr[3][3])
{
    printf("[%d %d %d]\n[%d %d %d]\n[%d %d %d]\n", 
            arr[0][0], arr[0][1], arr[0][2],
            arr[1][0], arr[1][1], arr[1][2],
            arr[2][0], arr[2][1], arr[2][2]
    );
}