/* Documentation 
Name          : Anusree Mohan
Date          : 05-12-24
Title         : Caesar Cipher Challenge
Sample input  : Enter shift value: 3
				Enter the plaintext message: Hello World
Sample output : Encrypted message: Khoor Zruog
				Decrypted message: Hello World
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to encrypt text
void encrypt(char *plaintext, int shift, char *ciphertext) {
	int i = 0;
	while(plaintext[i] != '\0') {
		if( plaintext[i] != ' ' && plaintext[i] != '\t' && plaintext[i] != '\n' ) {
			ciphertext[i] = plaintext[i] + shift;
		} else {
			ciphertext[i] = plaintext[i];
		}
		i++;
	}
	ciphertext[i] = '\0';
}

// function to decrypt text
void decrypt(char *ciphertext, int shift, char *decryptedtext) {
	int i = 0;
	while( ciphertext[i] != '\0' ) {
		if(ciphertext[i] != ' ' && ciphertext[i] != '\t' && ciphertext[i] != '\n') {
				decryptedtext[i] = ciphertext[i] - shift;
		} else {
			decryptedtext[i] = ciphertext[i];
		}
		i++;
	}
	decryptedtext[i] = '\0';
}

int main()
{
	int shift;
	char str[50]; //  "Hello World";
	
	printf("Enter Shift value: ");
	scanf("%d", &shift);

	printf("Enter the plaintext message : ");
	scanf(" %[^\n]", str);

	// To perform Encryption
	int len = strlen(str);
	char *ciphertext = malloc((len + 1)*sizeof(char));
	if( ciphertext == NULL ) 
		return 0;

	encrypt(str, shift, ciphertext);
	printf("Encrypted message: %s\n", ciphertext);

	// To perform Decryption
	char *decryptedtext = malloc((len+1)*sizeof(char));
	if( decryptedtext == NULL ) 
		return 0;

	decrypt(ciphertext, shift, decryptedtext);
	printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}


