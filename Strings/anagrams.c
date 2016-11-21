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
	
	// Incrementing the place in arr which corresponds to ASCII code of char in string
	// for characters encountered in str1. Decrementing for characters encountered in str2.
	for (i = 0, int j=0; i < len1, j < len2; i++, j++){
	    arr[atoi(str1[i])] += 1;
	    arr[atoi(str2[j])] -= 1;
	}
	
	// If any of the places in ASCII conversion of chars in str1 or str2 are not 0, that means 
	// the frequency is not the same in the two strings which implies that the two strings are 
	// not anagrams. Hence returning 1 (failure/error).
	for (i = 0; i < len1; i++){
	    if (arr[atoi(str1[i])] != 0){
		free(arr);
	        return 1;
	    }
	}
	free(arr);
	// If we reach here means the two strings are anagrams. Hence we return 0 (success).
	return 0;
}

/**
void areAnagrams3(char *str1, char *str2){
	// Using the method of hash map.
	
}
**/

int main(int argc, char* argv[]){
	
	int choice, result;
	printf("\nThis program determines whether two strings are anagrams or not.\n");
    	printf("\nUsage: 'str1 str2 choice\n");
    	printf("\nWhere str1 and str2 are the two strings being tested for being anagrams and choice is the type of algorithm used (1 or 2).\n");
	bool valid=false;
	
	while (!valid){
	     if (argc == 3)
		valid = true;
		choice = argv[3];
	     else
		printf("Too few or too many strings. Enter only 2 strings followed by the choice of algorithm (1 or 2)");
	}
	
	switch(choice){
	    case '1':
		result = areAnagrams1(argv[1], argv[2]);
		break;
	    case '2':
		result = argeAnagrams2(argv[1], argv[2]);
		break;
	    default:
		printf("Incorrect choice of algorithm. Please enter 1 or 2");
		return 1;
	    	break;
	
	}
	switch (result){
	    case '0':
		printf("%s and %s are anagrams", argv[1], argv[2]);
		break;
	    case '1':
		printf("%s and %s are not anagrams", argv[1], argv[2]);
		break;
	
	}
	
	return 0;
}
