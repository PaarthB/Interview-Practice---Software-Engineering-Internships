#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

void areAnagrams1(char *str1, char *str2){
	// Using the method of sorting
	
}

int areAnagrams2(char *str1, char *str2){
	// Using the method of comparing frequency
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	if(len1 != len2){
		return 1;
	char *arr;
	arr = (char *)malloc(sizeof(char)*256);  // allocate 256 chars
	for (int i=0; i<256; i++) // Setting all the ASCII char count values to 0.
	{
	  arr[i] = 0;
	}
	free(arr);
	
	return 0;
}

/**
void areAnagrams3(char *str1, char *str2){
	// Using the method of hash map.
	
}
**/

int main(int argc, char* argv[]){
	
	
	return 0;
}
