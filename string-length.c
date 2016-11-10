/**
检测字符串长度
*/
#include <stdio.h>
/*#include <curses.h>*/
int main() {
	char str[100], i = 0, length;
	
	printf("\n Enter the string : ");
	gets (str);
	while (str[i] != '\0')
		i++;
	length = i;
	printf("\n The length of the string is : %d", length);
	
	return 0;
}
