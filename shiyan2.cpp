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
char prog[500], token[200];
char ch;
int syn, p, m = 0, n, sum, kk = 0;
int flag;
int y;
int num = 0;
FILE* fp1, *fp2;
char * rwtab[6] = { "function", "if", "then", "while", "do", "endfunc" };

void yucu();
void statement();
void expression();
void term();
void factor();

void check()
{
	if ((ch <= '9' && ch >= '1') || ch == '+' || ch == '-')
	{
		token[m++] = ch;
		ch = prog[p++];
	}
	else
	{
		syn = -1;
		while ((ch <= '9 '&& ch >= '0') || (ch <= 'z' && ch >= 'a') || ch == '.')
		{
			ch = prog[p++];
		}
		ch = prog[p--];
		return;
	}
	while ((ch <= '9' && ch >= '0') || ch == '.')
	{
		if (ch == '.')
		{
			syn = -1;
			ch = prog[p++];
			while ((ch <= '9 '&& ch >= '0') || (ch <= 'z' && ch >= 'a') || ch == '.')
			{
				ch = prog[p++];
			}
			ch = prog[p--];
			return;
		}
		else
		{
			token[m++] = ch;
			ch = prog[p++];
		}
	}
	if (ch <= 'z' && ch >= 'a' || token[m - 1] == '-' || token[m - 1] == '+')
	{
		syn = -1;
		ch = prog[p++];
		while ((ch <= '9 '&& ch >= '0') || (ch <= 'z' && ch >= 'a') || ch == '.')
		{
			ch = prog[p++];
		}
		ch = prog[p--];
		return;
	}
	ch = prog[p--];
}
void DFA()
{

	if (ch == '+' || ch == '-')
	{
		token[m++] = ch;
		ch = prog[p++];
	}
	if (ch == '0')
	{
		if (prog[p + 1] == '.')
		{
			token[m++] = ch;
			ch = prog[p++];
			token[m++] = ch;
			ch = prog[p++];
		}
		else
		{
			syn = -1;
			ch = prog[p++];
			while ((ch <= '9 '&& ch >= '0') || (ch <= 'z' && ch >= 'a') || ch == '.')
			{
				ch = prog[p++];
			}
			ch = prog[p--];
			return;
		}
	}
	while ((ch <= '9' && ch >= '0') || ch == '.')
	{
		if (ch == '.')
		{
			if (flag)
			{
				syn = -1;
				ch = prog[p++];
				while ((ch <= '9 '&& ch >= '0') || (ch <= 'z' && ch >= 'a') || ch == '.')
				{
					ch = prog[p++];
				}
				ch = prog[p--];
				return;
			}
			else
				flag = 1;
		}
		//cout<<endl<<"----"<<ch<<endl;
		token[m++] = ch;
		ch = prog[p++];
		//cout<<endl<<"----"<<token<<endl;
	}
	if (ch == 'e')
	{
		if (token[m - 1] == '.')
		{
			syn = -1;
			while ((ch <= '9 '&& ch >= '0') || (ch <= 'z' && ch >= 'a') || ch == '.')
			{
				ch = prog[p++];
			}
			ch = prog[p--];
			return;
		}
		token[m++] = ch;
		ch = prog[p++];
		check();
	}
	else
	{
		if (token[m - 1] == '.' || ch <= 'z' && ch >= 'a')
		{
			syn = -1;
			while ((ch <= '9 '&& ch >= '0') || (ch <= 'z' && ch >= 'a') || ch == '.')
			{
				ch = prog[p++];
			}
			ch = prog[p--];
			return;
		}
		else
		{
			ch = prog[p--];
			return;
		}
	}
}
void scaner()
{
	// ��ʼ�� token ����
	int flow;
	memset(token, 0, sizeof(token));
	// �����ո��ַ�
	ch = prog[p++];
	while (ch == ' ' || ch == '\n' || ch == '\t')
	{
		ch = prog[p++];
	}
	flow = 0;
	// ��������ĸ
	//cout<<endl<<ch<<endl;
	if (ch >= 'a' && ch <= 'z')
	{
		m = 0;
		// ��������ĸ���� token ������
		while ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A'&&ch <= 'Z'))
		{
			token[m++] = ch;
			ch = prog[p++];
		}

		ch = prog[p--];
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
		m = 0;
		flag = 0;
		syn = 11;
		DFA();
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
				syn = 21;
				token[m++] = ch;
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
		case '+':
			flow = syn;
			syn = 13;
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			flag = 0;
			if (ch <= '9' && ch >= '0' && flow != 11 && flow != 10 && flow != 28)
			{
				syn = 11;
				DFA();
			}
			else
				ch = prog[p--];
			break;
		case '-':
			flow = syn;
			syn = 14;
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			flag = 0;
			if (ch <= '9' && ch >= '0' && flow != 11 && flow != 10 && flow != 28)
			{
				syn = 11;
				DFA();
			}
			else
				ch = prog[p--];
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
void weibu()
{
	if (syn == 6)
	{
		scaner();
		if (syn == 0 && kk == 0)    // �������ʶ����
		{
			if (y == 2)
				printf("����ɹ�\n");
			else
			{
				fprintf(fp2, "����ɹ�\n");
			}
		}
		else {
			if (y == 2)
				printf("����ʧ��\n");
			else
			{
				fprintf(fp2, "����ʧ��\n");
			}
		}
	}
	else
	{
		//if (kk != 1)
		//{
		if (y == 2)
			printf("�� %d ��,�д���, ȱ�� 'endfunc'\n", num);
		else
		{
			fprintf(fp2, "�� %d ��,�д���, ȱ�� 'endfunc'\n", num);
		}
		kk = 1;
		//}
	}
}
void lrparser()
{
	if (syn == 1)//�ж��Ƿ���function��Ϊ���γ���Ŀ�ʼ
	{
		scaner();
		yucu();
		weibu();
	}
	else
	{
		if (y == 2)
			printf("�� %d ��,�д���,ȱ��'function'\n", num);
		else
		{
			fprintf(fp2, "�� %d ��,�д���,ȱ��'function'\n", num);
		}
		kk = 1;
		num--;
		yucu();
		weibu();
	}
}

void yucu() // ��䴮����
{
	flag = 0;
	num++;
	statement();// ��������������
	while (syn == 26)    // һ�����ʶ�����������ʶ��
	{
		flag = 0;
		num++;
		scaner();
		if (syn == 6 || syn == 0)
			break;
		statement();
	}
}

void statement()
{
	if (syn == 10)//����Ǳ�������
	{
		//flag = 0;
		scaner();
		if (syn == 18)//�����=
		{
			scaner();
			expression();
			//�ж��Ƿ��зֺ�
			if (syn != 26)
			{
				if (!flag)
				{
					if (syn == -1)
					{
						scaner();
						if (y == 2)
							printf("�� %d ��,�������\n", num);
						else
						{
							fprintf(fp2, "�� %d ��,�������\n", num);
						}
					}
					else if (syn == 28)
					{
						scaner();
						if (y == 2)
							printf("�� %d ��,ȱ��'('\n", num);
						else
						{
							fprintf(fp2, "�� %d ��,ȱ��'('\n", num);
						}
					}
					else if (syn == 18)
					{
						scaner();
						if (y == 2)
							printf("�� %d ��,���ֶ���'='\n", num);
						else
						{
							fprintf(fp2, "�� %d ��,���ֶ���'='\n", num);
						}
					}
					else if (syn == 22)
					{
						scaner();
						if (y == 2)
							printf("�� %d ��,����'!'����\n", num);
						else
						{
							fprintf(fp2, "�� %d ��,����'!'����\n", num);
						}
					}
					else if (syn == 20)
					{
						scaner();
						if (y == 2)
							printf("�� %d ��,����'<'����\n", num);
						else
						{
							fprintf(fp2, "�� %d ��,����'<'����\n", num);
						}
					}
					else if (syn == 23)
					{
						scaner();
						if (y == 2)
							printf("�� %d ��,����'<'����\n", num);
						else
						{
							fprintf(fp2, "�� %d ��,����'<'����\n", num);
						}
					}
					else
					{
						if (y == 2)
							printf("�� %d ��,�д���,ȱ��';'���߲�����\n", num);
						else
						{
							fprintf(fp2, "�� %d ��,�д���,ȱ��';' ���߲�����\n", num);
						}
					}
					kk = 1;
				}

			}
		}
		else
		{
			if (flag == 0)
			{
				flag = 1;
				if (y == 2)
					printf("�� %d ��,ȱ�ٵȺ�\n", num);
				else
				{
					fprintf(fp2, "�� %d ��,ȱ�ٵȺ�\n", num);
				}
			}
			kk = 1;
		}
	}
	else//����Ķ��������Ա������ִ�ͷ
	{
		if (flag == 0)
		{
			if (y == 2)
				printf("�� %d ��,�д���,ȱ�ٱ���\n", num);
			else
			{
				fprintf(fp2, "�� %d ��,�д���,ȱ�ٱ���\n", num);
			}
			flag = 1;
		}
		kk = 1;
	}
	//scaner();
	while (syn != 26 && syn != 0 && syn != 6)
	{
		scaner();
	}
}

void expression()   // ���ʽ��������
{
	term();
	while (syn == 13 || syn == 14)//�ж���+����-
	{
		scaner();
		term();
	}
}

void term() // ���������
{
	factor();
	while (syn == 15 || syn == 16)//*����/
	{
		scaner();
		factor();
	}
}

void factor()   // ���ӷ�������
{
	if (syn == 10 || syn == 11)//=�ұ�������ַ�����������
	{
		scaner();
	}
	else// ���Ƿ��Ǳ��ʽ
	{
		//flag = 0;
		if (syn == 27)//�����(
		{
			scaner();
			expression();
			if (syn == 28)//�����)
			{
				scaner();
			}
			else if (syn == 27)
			{
				if (flag == 0)
				{
					if (y == 2)
						printf("�� %d ��,�д���,���ֶ���'('\n", num);
					else
					{
						fprintf(fp2, "�� %d ��,�д���,���ֶ���'��'\n", num);
					}
					flag = 1;
				}
				kk = 1;
			}
			/*else if (syn == 10 || syn == 11)
			{
			if (flag == 0)
			{
			if (y == 2)
			printf("�� %d ��,ȱ�ٲ���������ȱ��';'\n", num);
			else
			{
			fprintf(fp2, "�� %d ��,ȱ�ٲ���������ȱ��';' \n", num);
			}
			flag = 1;
			}
			kk = 1;
			}*/
			else
			{
				//flag = 1;
				if (flag == 0)
				{
					if (y == 2)
						printf("�� %d ��,�д���,ȱ��')'\n", num);
					else
					{
						fprintf(fp2, "�� %d ��,�д���,ȱ��')'\n", num);
					}
					flag = 1;
				}
				kk = 1;
			}
		}
		else
		{
			if (flag == 0 && syn == -1)
			{
				flag = 1;
				if (y == 2)
					printf("�� %d ��,ʵ������\n", num);
				else
				{
					fprintf(fp2, "�� %d ��,ʵ������\n", num);
				}
			}
			if (flag == 0)
			{
				flag = 1;
				if (y == 2)
					printf("�� %d ��,ȱ�ٲ�����\n", num);
				else
				{
					fprintf(fp2, "�� %d ��,ȱ�ٲ�����\n", num);
				}
			}
		}
	}
}

int main()
{
	p = 0;
	printf("\nplease input the string:\n");
	printf("ѡ���ļ�����1,�ֶ�����2\n");
	int x;
	cin >> x;
	cout << "ѡ���ļ�����1������̨����2" << endl;
	cin >> y;
	if (y == 1)
		fp2 = fopen("out.txt", "w");
	if (x == 1)
	{
		fp1 = fopen("in.txt", "r");
		do {
			fscanf(fp1, "%c", &ch);
			prog[p++] = ch;
		} while (ch != '#');
	}
	else
	{
		do
		{
			ch = getchar();
			prog[p++] = ch;
		} while (ch != '#');
	}
	p = 0;
	//ch = prog[p++];
	scaner();
	num++;

	lrparser();
	system("pause");
}
