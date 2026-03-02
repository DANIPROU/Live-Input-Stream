#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int is_capital_letter(char c)
{
	return 'A' <= c && c <= 'Z';
}

int is_lower_case(char c)
{
	return 'a' <= c && c <= 'z';
}

int is_number(char c)
{
	return '0' <= c && c <= '9';
}

int main(void) //(int argc, char* argv[])
{
	/*
	   if (argc != 2)
	   {
	   printf("Wtf is wrong with you!\n");
	   return 1;
	   }
	   size_t sum = 0;
	   for (size_t i = 0 ; argv[1][i] ; i++)
	   sum += argv[1][i] - 'a';
	   printf("%s  --  %lu\n", argv[1], sum);
	   return 0;
	   */

	char* buffer;
	size_t n = 0;
	ssize_t end = 0;
	while (1)
	{
		end = getdelim(&buffer, &n, '\n', stdin); 
		buffer[end - 1] = '\0';
		if (!strcmp(buffer, "done"))
		{
			free(buffer);
			return 0;
		}
		size_t sum = 0;
		for (size_t i = 0 ; buffer[i] ; i++)
		{
			if (is_number(buffer[i]))
				sum += buffer[i] - '0';
			else if (is_capital_letter(buffer[i]))
				sum += buffer[i] - 'A';
			else if (is_lower_case(buffer[i]))
				sum += buffer[i] - 'a';
		}
		printf("%s  --  %lu\n\n", buffer, sum);
	}
	return 0;
}
