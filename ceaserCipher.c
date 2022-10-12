// C program to implement Caesar Cipher

#include <stdio.h>
#include <string.h>

// to encrypt original text to cipher
void encrypt(char str[], int shift)
{
	int i = 0;
	while (str[i] != '\0')
	{
		char c;
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			// c = str[i] - 'A';
			c += shift;
			while (c > 26){
				c = c % 26;
				}
			str[i] = c + 'A';
		}
		i++;
	}
	// printf("%s", str);
}

// to decrypt cipher into original text
void decrypt(char str[], int shift)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			char c = str[i] - 'A';
			c -= shift;
			c = c % 26;
			str[i] = c + 'A';
		}
		i++;
	}
	// printf("%s", str);
}

// Driver code
int main()
{
	char str[] = "ABCDX";
	// char* cipher = NULL;
	// char* original = NULL;
	printf("Original -> %s\n", str);

	encrypt(str, 10);
	// cipher = str;
	// printf("%s", cipher);
	printf("Encypted -> %s\n", str);

	decrypt(str, 10);
	// original = str;
	// printf("\n%s", original);
	printf("Decrypted -> %s\n", str);

	return 0;
}