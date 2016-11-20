#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

void areAnagrams1(char *str1, char *str2){
	// Using the method of sorting
	
}

void areAnagrams2(char *str1, char *str2){
	// Using the method of comparing frequency
	char *arr;
	arr = (char *)malloc(sizeof(char)*256);  // allocate 256 chars
	for (int i=0; i<256; i++) // Setting all the ASCII char count values to 0.
	{
	  arr[i] = 0;
	}
	free(arr);

}

/**
void areAnagrams3(char *str1, char *str2){
	// Using the method of hash map.
	
}
**/

int main(int argc, char* argv[]){
	
	
	return 0;
}
