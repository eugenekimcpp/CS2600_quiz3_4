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

const int SIZE = 3;

// Function prototypes
int test(int arr[3][3]);

int main()
{

    int result; 

    // Create two 2-d array to be tested, one lo shu, one no lo shu
    int loShu[3][3] = {
        {4,9,2},
        {3,5,7},
        {8,1,6}
    };

    int noLoShu[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    // send lo shu to test function, and print result 
    result = test(loShu);
    if(result == 1)
    {
        printf("First array is Lo Shu Magic Square\n");
    }
    else{
        printf("First array is NOT Lo Shu Magic Square\n");
    }

    // send no lo shu to test function, and print result
    result = test(noLoShu);
    if(result == 1)
    {
        printf("Second array is Lo Shu Magic Square\n");
    }
    else
    {
        printf("Second array is NOT Lo Shu Magic Square\n");
    }


    
    return EXIT_SUCCESS;
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