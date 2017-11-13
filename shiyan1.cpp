/*�ʷ�����Դ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

char prog[80], token[9];
char ch;
int syn, p, m, n, sum;
char* rwtab[6] = { "function","if","then","while","do", "endfunc" };

void scaner();

int main()
{
	p = 0;
	printf("\n please input string :\n");
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	do {
		scanf("%c", &ch);
		prog[++p] = ch;
	} while (ch != '#');

	p = 0;
	do
	{
		scaner();
		switch (syn)
		{
		case 11: printf("\n(%d, %d)", syn, sum); break;
		case -1: printf("\n error"); break;
		default: printf("\n(%d, %s)", syn, token);//�ؼ��ֱ���
		}
	} while (syn != 0);
	printf("\n");
}

void scaner()
{
	// ��ʼ�� token ����
	memset(token,0,sizeof(token));
	// �����ո��ַ�
	ch = prog[++p];
	while (ch == ' ' || ch == '\n' || ch == '\t') 
		ch = prog[++p];

	// ��������ĸ
	if (ch >= 'a' && ch <= 'z')
	{
		m = 0;
		// ��������ĸ���� token ������
		while((ch >= 'a' && ch <= 'z') ||( ch >= '0' && ch <= '9')||(ch>='A'&&ch<='Z'))
		{
			token[m++] = ch;
			ch = prog[++p];
		}
		
		ch = prog[--p];
		syn = 10;//�������10���Ǳ�������������

		// �ж��Ƿ�ƥ��ؼ���
		for (n = 0; n < 6; n++)
		{
			if (strcmp(token, rwtab[n]) == 0)
			{
				syn = n + 1;//�ҵ���Ӧ�ؼ���
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
			ch = prog[++p];
		}
		ch = prog[--p];
		syn = 11;
	}
	else
	{
		switch (ch)
		{
		case'<':
			m = 0;
			token[m++] = ch;
			ch = prog[++p];
			if (ch == '=')
			{
				syn = 21;
				token[m + 1] = ch;
			}
			else {
				syn = 20;
				ch = prog[--p];
			}
			break;
		case'>':
			m = 0;
			token[m++] = ch;
			ch = prog[++p];
			if (ch == '=')
			{
				syn = 24;
				token[m++] = ch;
			}
			else
			{
				syn = 23;
				ch = prog[--p];
			}
			break;
		case'=':
			m = 0; 
			token[m++] = ch;
			ch = prog[++p];
			if (ch == '=')
			{
				syn = 25;
				token[m++] = ch;
			}
			else
			{
				syn = 18;
				ch = prog[--p];
			}
			break;
		case '!':
			m = 0;
			token[m++] = ch;
			ch = prog[++p];
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
		case '+': 
			syn = 13; 
			token[0] = ch; 
			break;
		case '-': 
			syn = 14; 
			token[0] = ch;
			break;
		case '*': 
			syn = 15; 
			token[0] = ch; 
			break;
		case '/': 
			syn = 16; 
			token[0] = ch;
			break;
		case ';': 
			syn = 26; 
			token[0] = ch; 
			break;
		case '(': 
			syn = 27; 
			token[0] = ch; 
			break;
		case ')': 
			syn = 28; 
			token[0] = ch; 
			break;
		case '#': 
			syn = 0; 
			token[0] = ch;
			break;
		default:
			syn = -1;
		}
	}
}
