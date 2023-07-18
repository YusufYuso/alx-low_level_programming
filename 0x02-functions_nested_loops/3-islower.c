#include "main.h"

/**
* _islower - checks for lowercase character.
* @c: the checked character
*
* Return: 1 for success 0 otherwise
*/

int _islower(int c)
{
	if (c >= 61 && c <= 122)
		return (1);
	else
		return (0);
}
