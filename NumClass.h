#ifndef FUNC_H
#define FUNC_H

//Two constants definition exported by library.
#define FALSE 0
#define TRUE 1

// Strong number is a special number whose sum of the factorial of digits is equal to the original number.
int isStrong(int n);
// will return if a number is prime.
int isPrime(int n);
// will return if a number is a palindrom.
int isPalindrom(int n);
// will return if a number is Armstrong number.
int isArmstrong(int n);

#endif