//calculating roots by guessing
//calculating PHI = (1 + root(5))/2

//root(n) = a => n/a = b (with a = b);
//I want to guess what a is and then multiply a time a and see if it equals n
//Naturally it will never be exaclty the same, but I'm going to adjust the
//result every time based on the rest of "Number - a*a";

//For Reference
//PHI = 1,6180339...
//root(5) = 2.2360679...

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

  float Number = 5.0, Precision = 0.000001, Rest, Error = 5.0, a = 0.0;
  srand((unsigned int)time(NULL));     //setting the seed

  do {
    a = ((float)rand()/(float)(RAND_MAX) * Error) + a;     //Random a
    Rest = Number - (a * a);
    Error = Rest/a;   //Calculating the Error
    printf("N: %f\nA: %f\nR: %f\nE: %f\n", Number, a, Rest, Error);

  } while(Error >= Precision || Error <= -Precision);

  printf("N: %f\nA: %f\nR: %f\nE: %f\n", Number, a, Rest, Error);
  printf("PHI = %f\n", (1 + a)/2);    //Calculating PHI

  return 0;
}
