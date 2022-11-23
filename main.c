#include <stdio.h>
#include "NumClass.h"

 
int main(){

    // Console gets two numbers.
    int n = 0;
    int n1 = 0;
    scanf("%d",&n);
    scanf("%d",&n1);

    // Prints Armstrong numbers.
    printf("The Armstrong numbers are:");
    for (int i = n; i <=n1; i++)
    {
        if(isArmstrong(i)){
            printf(" %d",i);
        }
    }
    putchar('\n');

    // Prints Palindromes numbers.
    printf("The Palindromes are:");
    for (int i = n; i <=n1; i++)
    {
        
        if(isPalindrom(i)){
            printf(" %d",i);
        }
    }
    putchar('\n');

    // Prints Prime numbers.
    printf("The Prime numbers are:");
    for (int i = n; i <=n1; i++)
    {   
        if(isPrime(i)){
            printf(" %d",i);
        }
    }
    putchar('\n');

    // Prints Strong numbers.
    printf("The Strong numbers are:");
    for (int i = n; i <=n1; i++)
    {
        if(isStrong(i)){
            printf(" %d",i);
        }
    }
    putchar('\n');
}
