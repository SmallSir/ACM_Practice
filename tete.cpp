/*词法分析源代码兴 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* token[8] 改为 token[9] */
/* 因为 "function" 是 8 个字符，字符串应多一个结束符 */
char prog[80], token[9];
char ch;
int syn, p, m, n, sum;

/* "end-func" 改为 "endfunc" */
char* rwtab[6] = { "function","if","then","while","do", "endfunc" };

void scaner();

int main()
{
	printf("\n please input string :\n");

	p = 0;
	do {
		scanf("%c", &ch);
		prog[p++] = ch;		/* 程序中所有的 ++p 均改为 p++，--p 改为 p-- */
	} while (ch != '#');

	p = 0;
	do
	{
		scaner();
		switch (syn)
		{
		case 11: printf("\n(%d, %d)", syn, sum); break;
		case -1: printf("\n error"); break;
		default: printf("\n(%d, %s)", syn, token);
		}
	} while (syn != 0);

	system("pause");
}

void scaner()
{
	// 初始化 token 数组
	for (n = 0; n < 9; n++)
	{
		token[n] = '\0';
	}

	/* 下面的代码修改，用来跳过空格和控制字符 */
	ch = prog[p++];
	while (ch == ' ' || ch == '\n' || ch == '\t') 
		ch = prog[p++];

	// 读到了字母
	if (ch >= 'a' && ch <= 'z')
	{
		m = 0;
		// 把所有字母读到 token 数组中
		while (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
		{
			token[m++] = ch;
			ch = prog[p++];
		}

		ch = prog[p--];
		syn = 10;

		// 判断是否匹配关键字
		for (n = 0; n < 6; n++)
		{
			if (strcmp(token, rwtab[n]) == 0)
			{
				syn = n + 1;
				break;
			}
		}
	}
	else if (ch >= '0' && ch <= '9')
	{
		sum = 0;
		while (ch >= '0' && ch <= '9')
		{
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		ch = prog[p--];
		syn = 11;
	}
	else
	{
		switch (ch)
		{
		case'<':
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=')
			{
				syn = 22;
				token[m + 1] = ch;
			}
			else {
				syn = 20;
				ch = prog[p--];
			}
			break;
		case'>':
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=')
			{
				syn = 24;
				token[m++] = ch;
			}
			else
			{
				syn = 23;
				ch = prog[p--];
			}
			break;
		case'=':
			m = 0; 
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=')
			{
				syn = 25;
				token[m++] = ch;
			}
			else
			{
				syn = 18;
				ch = prog[p--];
			}
			break;
		case '!':
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=')
			{
				syn = 22;
				token[m++] = ch;
			}
			else
			{
				syn = -1;
			}
			break;
		case '+': syn = 13; token[0] = ch; break;
		case '-': syn = 14; token[0] = ch; break;
		case '*': syn = 15; token[0] = ch; break;
		case '/': syn = 16; token[0] = ch; break;
		case ';': syn = 26; token[0] = ch; break;
		case '(': syn = 27; token[0] = ch; break;
		case ')': syn = 28; token[0] = ch; break;
		case '#': syn = 0; token[0] = ch; break;
		default:
			syn = -1;
		}
	}
}
