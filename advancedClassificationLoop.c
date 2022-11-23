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
int numlength(int a){
    int snum = 0;
    while(a!=0){
        a/=10;
        snum++;
    }
    return snum;
}

//  Breaks a Number into intArray.
int *Printarr(int n){
    int i = 0;
    int mod = 0;   
    int len = numlength(n);
    int *array = malloc(sizeof(int) * len);
    //int numArray[len];
    while(n > 0){    
    mod=n%10;    
    array[i++] = mod;
    n=n/10;    
    }
    return array;
}

// will return if a number is a palindrom.
int isPalindrom(int n){
    //Breaks a Number into intArray.
    int *numArray = Printarr(n);
    // Comparing the first++ and last-- elements. 
    int flag = 0;
    for (int i = 0; i < numlength(n)/2; i++)
    {
        if(numArray[i] != numArray[numlength(n)-1-i]){ 
            flag =TRUE;
        }
    }
    if(flag){
        return FALSE;
    }
    else{
        return TRUE;
    }
    free(numArray);
}

// will return if a number is Armstrong number.
int isArmstrong(int n){
    int origin = n;
    //Breaks a Number into intArray.
    int *numArray = Printarr(n);
    // Summing the digits power the length of the number.
    int sum = 0;
    for (int i = 0; i < numlength(n); i++)
    {
        sum+=Powernth(numArray[i],numlength(n));
    }
    if(origin == sum){
        return TRUE;
    }
    else{
        return FALSE;
    }
    free(numArray);
}