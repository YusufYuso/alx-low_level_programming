#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
	int count;
	unsigned long first = 0, second = 1, sum;

	for (count = 1; count <= 50; count++)
	{
		sum = first + second;
		printf("%lu", sum);
		first = second;
		second = sum;
		if (count == 50)
			printf("\n");
		else
			printf(", ");
	}
	return (0);
}
