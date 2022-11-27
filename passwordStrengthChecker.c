#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){
	char string[100];
	fgets(string, 100, stdin);
	
	for(int i=0; i<strlen(string); i++){
		if((char) string[i] == '\n'){
			string[i] = '\0';
			break;
		}
	}
	return 0;
}