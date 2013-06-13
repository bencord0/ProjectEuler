/*
* Copyright 2013 Ben Cordero
*
* This file is part of my ProjectEuler implementations.
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
Each character on a computer is assigned a unique code and the
preferred standard is ASCII (American Standard Code for Information
Interchange). For example, uppercase A = 65, asterisk (*) = 42, and
lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes
to ASCII, then XOR each byte with a given value, taken from a secret
key. The advantage with the XOR function is that using the same
encryption key on the cipher text, restores the plain text; for
example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the
plain text message, and the key is made up of random bytes. The
user would keep the encrypted message and the encryption key in
different locations, and without both "halves", it is impossible
to decrypt the message.

Unfortunately, this method is impractical for most users, so the
modified method is to use a password as a key. If the password is
shorter than the message, which is likely, the key is repeated
cyclically throughout the message. The balance for this method is
using a sufficiently long password key for security, but short enough
to be memorable.

Your task has been made easy, as the encryption key consists of three
lower case characters. Using cipher1.txt (right click and
'Save Link/Target As...'), a file containing the encrypted ASCII codes,
and the knowledge that the plain text must contain common English words,
decrypt the message and find the sum of the ASCII values in the original text.
*/

/* This problem will be tacled in two phases. One routine to attempt a decryption,
then another routine to search for common English words (or word). A controller
function, will assign each key in turn for the decrypter, then pass on the job of
testing which passes suspects to the user.
*/

#include <stdio.h>
#include <string.h>

void decrypter(char *key, FILE *ciphertext);
void reader(char *key); /* Each decryption is uniqe to the key */
int next_key(char *key);

int Problem059(void) {
	return 1; /* XXX */
}

int _Problem059(void) {
	char key[4];
	FILE *ciphertext;

	strcpy(key, "aaa");
	ciphertext = fopen("files/cipher1.txt", "r");
	if(ciphertext == (FILE*) NULL) {
		perror("059: Cannot open files/cipher1.txt for reading\n");
		return 2;
	}

	do {
		rewind(ciphertext);
		decrypter(key, ciphertext);

		next_key(key);
	} while (strcmp(key, "aaa"));

	fclose(ciphertext);

	return 1;
}

void decrypter(char *key, FILE *ciphertext) {
	FILE *plaintext;
	char *plaintext_name = "files/059---.txt";
	int a,b,c; /* temp variables */
	int check = 0;

	strncat(plaintext_name+9, key, 3);

	plaintext = fopen(plaintext_name, "w");
	if(plaintext == (FILE*) NULL) {
		perror("059 decrypter: Unable to write to output");
		return;
	}

	/* input and output files are ready, now to xor them */
	do{
		check = fscanf(ciphertext, "%d,%d,%d", &a, &b, &c);
	} while (check == 3);

	fclose(plaintext);
	return;
}

int next_key(char *key) {
	if(key[2] != 'z') {
		key[2] = key[2] + 1;
	}

	if(key[2] == 'z' && key[1] != 'z') {
		key[2] = 'a';
		key[1] = key[1] + 1;
	}

	if(key[2] == 'z' && key[1] == 'z' && key[0] != 'z') {
		key[2] = key[1] = 'a';
		key[0] = key[0] + 1;
	}

	if(key[2] == 'z' && key[1] == 'z' && key[0] == 'z') {
		key[2] = key[1] = key[0] = 'a';
	}

	return 0;
}
