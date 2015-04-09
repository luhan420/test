#include <stdio.h>

/*
*输出以s为首地址的
*字符串的前n个字符
*/
void print_ch(char *s, int n)
{
int i;


for(i = 0; i < n; i++)
putchar(*(s + i));
putchar(' ');
}

/*
*逆序输出单词顺序
*/
void reverse_str(char *s)
{
int i, j;
char *p;
//找到下一个单词
for(p = s; *p != '\0' && *p != ' '; p++)
;

//结束条件
if(*p == '\0')
{
print_ch(s, p - s);
return;
}

//递归调用
reverse_str(p + 1);
print_ch(s, p - s);
}


int main()
{
char s[100];
gets(s);
reverse_str(s);
return 0;
}
