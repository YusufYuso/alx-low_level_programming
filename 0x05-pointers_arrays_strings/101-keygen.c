#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for the
 *        program 101-crackme.
 * getPassword - function to make a random password
 * 
 * Return: Always 0.
 */
void getPassword(int len) 
{
	char possibleChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
	char password[len+1];
	
	srand(time(0)); /* seed for random number generation */
	int i;

	for (i = 0; i < len; i++) 
	{
		int randomIndex = rand() % (sizeof(possibleChars) - 1);
		password[i] = possibleChars[randomIndex];
	}
	
	password[len] = '\0'; /* null terminate the string */
	printf("%s\n", password);
}

int main() 
{ /* desired length of password */
	getPassword(10);
	return 0;
}
