#include <stdio.h>
#include <string.h>

char decode_letter(char c, int offset)
{
	if ((('`' < c) && (c < '{')) && (c = c - (char)offset, c < 'a')) {
		c = c + '\x1a';
	}
	return c;
}


int main () {
	char s[100] = "ciwfu_xywcjbyl_gy";
	char copy[100];
	strcpy(copy, s);

	for (int offset = 0; offset < 32; offset++){
		for (int i = 0; i < strlen(s); i++)
			s[i] = decode_letter(s[i], offset);

		if (strstr(s, "iocla_")) {
			printf("%s\n", s);
			break;
		}
		
		strcpy(s, copy);
	}
}