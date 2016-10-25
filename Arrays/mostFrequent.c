#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
//Gives the element in the list which is occurs the most times.
int getPopularElement(char *a[])
{
  int count = 1, tempCount;
  int popular = atoi(a[0]);
  int temp = 0;
  for (int i = 0; i < (sizeof(a) - 1); i++)
  {
    temp = atoi(a[i]);
    tempCount = 0;
    for (int j = 1; j < sizeof(a); j++)
    {
      if (temp == atoi(a[j]))
        tempCount++;
    }
    if (tempCount > count)
    {
      popular = temp;
      count = tempCount;
    }
  }
  return popular;
}


void main(char argc, char* argv[])
{
	int popular;
	char *arr[] = [1,2,5,5,5,5,7,7,8,8,8,8,8,8];
	popular = getPopularElement(argv);
	printf("\nMost frequent element: %d", popular);
	popular = getPopularElement(arr);
	printf("\nMost frequent element: %d", popular);
	
}
