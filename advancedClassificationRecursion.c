#include <stdlib.h>
#include "NumClass.h"

// Power calculator.
int Powernth (int a, int n){
    if(n==0){
        return 1;
    }
    return a*Powernth(a,n-1);
}

// Return number length.
int numLengthR(int a){
    int snum = 0;
    while(a!=0){
        a/=10;
        snum++;
    }
    return snum;
}

//  Breaks a Number into intArray.
int *PrintArrR(int n){
    int i = 0;
    int mod = 0;   
    int len = numLengthR(n);
    int *array = malloc(sizeof(int) * len);
    //int numArray[len];
    while(n > 0){    
    mod=n%10;    
    array[i++] = mod;
    n=n/10;    
    }
    return array;
}

// Overloading of the next function isPalindromRec below.
int isPalindromRec(int numArray[], int start , int end){
    if(start >= end){
        return TRUE;
    }
    if(numArray[start]==numArray[end]){
        return isPalindromRec(numArray ,++start,--end);
    }
    else{
        return FALSE;
    }
    free(numArray);
    return FALSE;
    
}

// will return if a number is a palindrome.
int isPalindrom(int n){
    //  Breaks a Number into intArray.
    int *numArray = PrintArrR(n);
    int start = 0, end = (numLengthR(n)-1);

   return isPalindromRec(numArray,start,end);
}

// Overloading of the next function isArmstrongRec next.
int isArmstrongRec(int numArray[], int n, int sum, int start){
    if(start == numLengthR(n) && sum == n){
        return TRUE;
    }
    if(start == numLengthR(n) && sum !=n){
        return FALSE;
    }
    else {
        sum+= Powernth(numArray[start], numLengthR(n));
        return isArmstrongRec(numArray, n , sum , ++start);
    }
    free(numArray);
    return FALSE;
}

// will return if a number is Armstrong number.
int isArmstrong(int n){
    int *numArray = PrintArrR(n);
    int start = 0;
    return isArmstrongRec(numArray,n,0,start);
}
