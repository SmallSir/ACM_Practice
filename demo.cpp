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
#include<GLUT/freeglut>
#include <ctime>
using namespace std;
typedef long long LL;

void RenderScenceCB()
{
	//�����ɫ����
	glClear(GL_COLOR_BUFFER_BIT);
	//����ǰ�󻺴�
	glutSwapBuffers();
}
int main()
{
	//��ʼ��GLUT
	glutInit(&argc,argv);
	//��ʾģʽ:˫���壬RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//��������
	glutInitWindowSize(480,320); //���ڳߴ�
	glutInitWindowPosition(100,100);//����λ��
	glutCreateWindow("Tutorial 01");//���ڱ���
	//��ʼ��Ⱦ
	glutDisplayFunc(RenderScenceCB);
	//������պ����ɫֵ
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	//֪ͨ��ʼGLUT���ڲ�ѭ��
	glutMainLoop();
 return 0;
}
