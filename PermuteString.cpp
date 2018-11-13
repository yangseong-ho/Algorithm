#include<iostream>

void permuteString(char *str, int begin, int end);
void swap(char *a, char *b);
int main(void)
{
	char str[] = "abcd";
	permuteString(str, 0, strlen(str));

		return 0;
}
void permuteString(char *str, int begin, int end)
{
	int i;
	int range = end - begin;
	if (range == 1)
		printf("%s\n", str);
	else
	{
		for (i = 0; i < range; i++)
		{
			swap(&str[begin], &str[begin + i]);
			permuteString(str, begin + 1, end);
			swap(&str[begin], &str[begin + i]); /* recover */
		}
	}
}
void swap(char *a, char *b) 
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
