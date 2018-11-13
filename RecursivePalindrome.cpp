#include<iostream>
#include<cstring>

int R_Palindrom(char str[], int first, int last);

int main() {

	int testcase;

	scanf("%d", &testcase);

	while (testcase--) {
		char str[1000];

		scanf("%s", str);

		printf("%d\n", R_Palindrom(str, 0, strlen(str) - 1));
	}


	return 0;
}

int R_Palindrom(char str[], int first, int last) {

	if (last <= first)
		return 1;
	else if (str[first] != str[last])
		return 0;
	else
		return R_Palindrom(str, first+1, last - 1);

}
