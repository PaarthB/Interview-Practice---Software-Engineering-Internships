#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

// Quicksort implementation in C.
void QuickSort(char *str1, int from, int to){
	int index;
	
	if (from < to){
	    index = partition(str1, from, to);
	    QuickSort(str1, from, index-1);
	    QuickSort(str1, index+1, to);
	}
}
	
// Partition function for implementing QuickSort.
int partition(char *str1, int p, int r){
	int *x = str1+p;
	int i = p-1;
	
	for (int j = p; j < r; j++){
	    if (&(str1+j) <= &x){
	    	i += 1;
		swap(str+i, j);
	    }
	}
	swap(str+(i+1), str+r);
	return (i+1);
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
