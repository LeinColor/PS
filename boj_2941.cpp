#include <stdio.h>

int main()
{
	int c = 0;
	char s[110];

	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'c' && s[i + 1] == '=') i++;
		else if (s[i] == 'c' && s[i + 1] == '-') i++;
		else if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') i += 2;
		else if (s[i] == 'd' && s[i + 1] == '-') i++;
		else if (s[i] == 'l' && s[i + 1] == 'j') i++;
		else if (s[i] == 'n' && s[i + 1] == 'j') i++;
		else if (s[i] == 's' && s[i + 1] == '=') i++;
		else if (s[i] == 'z' && s[i + 1] == '=') i++;
		c++;
	}

	printf("%d", c);
	return 0;
}