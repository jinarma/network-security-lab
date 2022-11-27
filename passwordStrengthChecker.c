/* 
Contributers:
	Shubhankar Sharma
	Ashwath Mahajan
	Ananya Sharma
	Fazilat Mob Beg
 */


// This program calculates the maximum number of calculations would be needed to
// crack a supplied password. These calculations can then be used to extrapolate
// the time required to actually crack said password, depending on the curent
// average computational power available.


#include <stdio.h>
#include <string.h>
#include <math.h>

// This function takes a string of characters (only the ones in the ASCII table)
// and proceeds to calculate how many computation cycles it would be required
// at maximum to find the correct string.
// This fucntion returns a double value.
int password_check_full(char string[]){

	// 4 arrays created for the corrosponding ASCII values of characters
	int special_chars[33] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126};
	int nums[10] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
	int uppercase[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
	int lowercase[26] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
	
	// ttypes is the total number of unique characters that are possible in the
	// string
	int ttypes = 0;

	// 4 flags set, so if a char from the string corrosponding to a specific array
	// group of ASCII values, it need not be checked again in that set. e.g. if 'a'
	// is encountered in string then in the next loop cycle the check for lowercase
	// array is omitted.
	int n_flag=1, s_flag=1, u_flag=1, l_flag=1;

	// checks are made to figure out if a char of a given ASCII set is present in
	// the string or not.
	for(int i=0; i<strlen(string); i++){
		if(s_flag){
			for(int j=0; j<sizeof(special_chars)/sizeof(int); j++){
				if((char) string[i] == special_chars[j]){
					ttypes += sizeof(special_chars)/sizeof(int);
					s_flag = 0;
					break;
				}
			}
		}
		if(n_flag){
			for(int j=0; j<sizeof(nums)/sizeof(int); j++){
				if((char) string[i] == nums[j]){
					ttypes += sizeof(nums)/sizeof(int);
					n_flag = 0;
					break;
				}
			}
		}
		if(u_flag){
			for(int j=0; j<sizeof(uppercase)/sizeof(int); j++){
				if((char) string[i] == uppercase[j]){
					ttypes += sizeof(uppercase)/sizeof(int);
					u_flag = 0;
					break;
				}
			}
		}
		if(l_flag){
			for(int j=0; j<sizeof(lowercase)/sizeof(int); j++){
				if((char) string[i] == lowercase[j]){
					ttypes += sizeof(lowercase)/sizeof(int);
					l_flag = 0;
					break;
				}
			}
		}
	}
	
	printf("\"%s\" will require a maximum of %.0f calculations", string, pow(ttypes, strlen(string)));
	return pow(ttypes, strlen(string));
}

int main(){

	// created and initialize an array of chars
	char string[100];
	fgets(string, 100, stdin);
	
	// converts the array to string by replacing the newline char at then end
	// with a null char
	for(int i=0; i<strlen(string); i++){
		if((char) string[i] == '\n'){
			string[i] = '\0';
			break;
		}
	}

	// call the function to calculate the strength of the string (password)
	password_check_full(string);

	return 0;
}