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

  double Number = 5.0, Precision = 0.000000000000001, Rest, Error = 5.0, Root = 0.0;  //Max Precision that I could run
  srand((unsigned int)time(NULL));     //setting the seed

  do {
    if(Error > 0){
      Root = ((double)rand()/(double)(RAND_MAX) * Error) + Root;     //Random Root
    } else if(Error < 0){
      Root = ((double)rand()/(double)(RAND_MAX) * (-Error)) + (Root + Error);
    }
    Rest = Number - (Root * Root);
    Error = Rest/Root;   //Calculating the Error
    printf("Number: %f\nRoot: %.20f\nRest: %.20f\nError: %.20f\n", Number, Root, Rest, Error);

  } while(Error >= Precision || Error <= -Precision);
  
  printf("PHI = %.15f\n", (1 + Root)/2);    //Calculating PHI (if Number = 5.0)

  return 0;
}
