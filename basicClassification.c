#include <stdlib.h>
#include "NumClass.h"
// Returns number length.
int numLength(int a){
    int snum = 0;
    while(a!=0){
        a/=10;
        snum++;
    }
    return snum;
}

//  Breaks a Number into intArray.
int *PrintArr(int n){
    int i = 0;
    int mod = 0;   
    int len = numLength(n);
    int *array = malloc(sizeof(int) * len);
    //int numArray[len];
    while(n > 0){    
    mod=n%10;    
    array[i++] = mod;
    n=n/10;    
    }
    return array;
}

// will return if a number is prime.
int isPrime(int n){
    if(n==1) return TRUE;
    int flag = 0;
    for (int i = 2; i<=n/2; i++)
    {
        if(n%i==0){
            flag = 1;
            break;
        }
    }
    if(flag){
        return FALSE;
    }
    else{
        return TRUE;
    }
}

// Factor calculator.
int Factorial (int n){
    if(n==1 || n==0){
        return 1;
    }
    return(n*Factorial(n-1));
}

// Strong number is a special number whose sum of the factorial of digits is equal to the original number.
int isStrong(int n){
    int origin = n;

    //Breaks a Number into intArray.
    int *numArray = PrintArr(n);
    
    //Factorial summing.
    int sum = 0;
    for (int i = 0; i < numLength(n); i++)
    {
        sum+=Factorial(numArray[i]);
    }
    if(sum==origin){
        return TRUE;
    }
    else{
        return FALSE;
    }
    free(numArray);
}



