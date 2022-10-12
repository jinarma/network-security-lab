// C program to implement Caesar Cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// to encrypt original text to cipher
void encrypt(char str[], int shift) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      char c = str[i] - 'A';
      c += shift;
      while (c > 25) {
        c = c % 26;
      }
      str[i] = c + 'A';
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      char c = str[i] - 'a';
      c += shift;
      while (c > 25) {
        c = c % 26;
      }
      str[i] = c + 'a';
    } else if (str[i] >= '0' && str[i] <= '9') {
      char c = str[i] - '0';
      c += shift;
      while (c > 9) {
        c = c % 10;
      }
      str[i] = c + '0';
    }
    i++;
  }
}

// to decrypt cipher into original text
void decrypt(char str[], int shift) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      char c = str[i] - 'A';
      int temp = shift;
      while (temp > 26) {
        temp %= 26;
      }
      c -= temp;
      if (c < 0) {
        c += 26;
      }
      while (abs(c) > 25) {
        c = c % 26;
      }
      str[i] = c + 'A';
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      char c = str[i] - 'a';
      int temp = shift;
      while (temp > 26) {
        temp %= 26;
      }
      c -= temp;
      if (c < 0) {
        c += 26;
      }
      while (abs(c) > 25) {
        c = c % 26;
      }
      str[i] = c + 'a';
    } else if (str[i] >= '0' && str[i] <= '9') {
      char c = str[i] - '0';
      c -= shift;
      while (c < 0) {
        c += 10;
      }
      str[i] = c + '0';
    }
    i++;
  }
}

// Driver code
int main() {
  char str[64];
  int key;
  printf("Enter a password: ");
  scanf("%s", str);
  printf("Enter key size: ");
  scanf("%d", &key);
  printf("Original -> %s\n", str);

  encrypt(str, key);
  printf("Encypted -> %s\n", str);

  decrypt(str, key);
  printf("Decrypted -> %s\n", str);

  return 0;
}