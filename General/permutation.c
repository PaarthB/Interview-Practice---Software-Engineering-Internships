// C program to print all permutations with duplicates allowed

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
 
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. 

  Complexity:

  Best Case: O(N^2), where N is the length of the string.
  Worst Case: O(N^2), where N is the length of the string.
  
*/
long int permute(char *a, int l, int r)
{
   int i;

   struct timeval tvBegin, tvEnd, tvDiff;
   //Start time.
   gettimeofday(&tvBegin, NULL);
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }


   //End time.
   gettimeofday(&tvEnd, NULL);

   //Computing the time since function started.
   long int diff = (tvEnd.tv_usec + (1000000*tvEnd.tv_sec)) - (tvBegin.tv_usec + (1000000*tvBegin.tv_sec));

   tvDiff.tv_sec = diff / 1000000;
   tvDiff.tv_usec = diff % 1000000;

   //Returning the number of microseconds elapsed since the permute() function started.
   return diff;
}
 
/* Driver program to test above functions 

This program creates different processes upon execution to 
compute permutations of different strings passed as user arguments.

COMPLEXITY:
  
  Best Case: O(1), if the arguments are invalid.
  Worst Case: O(N), where N is the number of argument supplied by the user and arguments are valid.

*/

int main(int argc, char* argv[])
{   
    //The process ID variable which is used to keep track of the PIDs of different processes created/forked.
    int pid;
    //The time variable which is used to record the time elapsed in execution of the permute() function through different processes.
    int time;
    //The count variable which is used to keep track of the Child Process Number (starting from 1) which were created.
    int count = 0;
    //The boolean variable which is used to ensure whether the user arguments are valid or not.
    bool valid=false;

    printf("\nThis program returns all permutations of strings you pass.\n");
    printf("\nValid input: 'n | [List]'\n");
    printf("\nWhere n is the number of strings you want to input, and List is the list of n strings separated by spaces.\n");

    //Checking validity of Program Input values.
    while(!valid){
       if(argc < 2){
          printf("Too few arguments. Add arguments of the form: 'n string_1 string_2 .... string_n");
       }
       else if(argc < (atoi(argv[1])+2)){
          printf("\nLess strings than %d. Please enter more strings.\n", atoi(argv[2]));
       }
       else if(argc > (atoi(argv[1])+2)){
          printf("\nMore strings than %d. Please remove some strings.\n", atoi(argv[2]));      
       }
       else if(argc == atoi(argv[1])+2){
          valid = true; 
       }
    }

    printf("Number of strings passed: %s\n", argv[1]);
    printf("%d\n", strlen(argv[2]));

    for(int i=2; i < argc; i++){

       //Creating a child process through fork().
       pid=fork();
       count += 1;
       if(pid == 0){
          printf("\nChild Process %d\n", count);
          printf("\nPermutations of string %s:\n", argv[i]);
          time = permute(argv[i], 0, strlen(argv[i])-1);
          printf("\nChild Process %d Time taken: %d seconds %d milliseconds\n", count, time/1000000, time%1000);
          exit(0);
       }

       else if (pid < 0){
          printf(" Failed to fork a process \n");
       }
    }
    return 0;
}
