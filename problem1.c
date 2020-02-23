/*
 *This program that finds locations of all the genes encoding Threonine
 *Author: Elisha Ishaal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkString(char *str){
	int check = 1;
    for(int i = 0; i < strlen(str); i++){
		if(str[i] != 65 && str[i] != 67 && str[i] != 71 && str[i] != 84){
			//CHECK TO SEE IF THE INPUT CHARS ARE EQUAL TO THE
			//ASCII REPRESENTATION OF ACGT
			check = -1;
			break;
		}
	}
	return check;
}

int main() {

	char dna[10000];

	char * threons[4] = {"ACT", "ACC", "ACA", "ACG"};

	printf("Enter the DNA sequecen: ");
	//read up to 9999 characters
	scanf("%9999s", dna);

	if(checkString(dna) == -1){
		//CHECK IF STRING IS VALID
		printf("%d", -1);
		return 0;
	}

	int count = 0;//count number of triples
	for(int i = 0; i < strlen(dna); i+=3){
		if(dna[i] == 65 && dna[i+1] == 67){
			//IF SUBSTRING BEGINS WITH AC, THEN IT CODES FOR THREON
			printf("%d\n", i);
			count++;
		}
	}

	//If string does not contain code for threon
	if(count == 0) printf("%d", -2);

	return 0;

}
