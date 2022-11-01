#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char plain_text[50];
	printf("Enter text: ");
	fgets(plain_text, 50, stdin);
	char modified_string[50];
	int count = 0;
	
	for(int i=0; plain_text[i] != '\0'; i++){
		if(plain_text[i] != ' '){
			modified_string[count] = plain_text[i];
			count++;
		}
		else if(plain_text[i+1] == '\0'){
			modified_string[count] = '\0';
		}
	}
	printf("%s", modified_string);
	char result[50];
	count=0;
	for(int i=0; i<strlen(modified_string); i+=2){
		result[count] = tolower((char) modified_string[i]);
		count++;
	}
	
	for(int i=1; i<strlen(modified_string); i+=2){
		result[count] = tolower((char) modified_string[i]);
		count++;
	}

	result[count] = '\0';
	
	printf("%s", result);
	
	return 0;
}
