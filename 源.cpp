#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<time.h>

#define MAXSTAR 1314
#define MAXMETEOR 520

//���ǽṹ��
struct Star
{
	int x, y;
	int color;
	int step;
}star[MAXSTAR];
//������ṹ��
struct Meteor
{
	int x, y;
	int style;
	int step;
}meteor[MAXMETEOR];

//������ͼ
IMAGE img1, img2;//����ͼƬ


//�����������
void printText()
{
	settextcolor(RGB(255, 0, 252));
	settextstyle(40, 0, L"�����п�");
	outtextxy(350, 20, L"xxx ��ϲ����");
	//����������ɫ
	settextcolor(RGB(0, 255, 255));
	//���������С
	settextstyle(40, 0, L"�����п�");
	//��ָ��λ������ַ���
	outtextxy(150, 100, L"����ׯ�����˵������Ƕ���Ҳ�ǽ١�");
	outtextxy(150, 150, L"������ճ��˷𣬸�����ϼ����ħ��");
	outtextxy(150, 200, L"���ü�御��򭣬ǧ����ۣ������ۡ�");
	outtextxy(150, 250, L"������ɫĺ���ƣ���Ҳ˼������Ҳ˼����");
	outtextxy(150, 300, L"��ǧˮ��������һ�ۼ��㣬���ﲻ����");
	outtextxy(150, 350, L"��ˮ���������ֳ�ʢ������ʮ�ﲻ���㡣");
	outtextxy(150, 400, L"�˼��������ӹ飬��ϣ������Ϊ�Ҷ�����");
	_getch();//�����л�����
}
//��ʼ������
void initStar(int i)
{
	//����������꣬��ɫ���ٶ�
	star[i].x = rand() % 1200;
	star[i].y = rand() % 600;
	star[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);//������ɫ
	star[i].step = rand() % 10;
}
//������
void drawStar(int i)
{
	//�����ص�
	putpixel(star[i].x, star[i].y, star[i].color);
	//�ƶ�����
	star[i].x += star[i].step;
	//�����ڵ������ڲ�������
	if (star[i].x >= 1200)
	{
		putpixel(star[i].x, star[i].y, star[i].color);
		initStar(i);
	}
}
//��ʼ������
void initMeteor(int i)
{
	meteor[i].x = rand() % 2200 - 1000;
	meteor[i].y = rand() % 20 - 200;
	meteor[i].style = rand() % 2;
	meteor[i].step = rand() % 30 + 1;//�����ٶȲ�Ϊ0
}
//������
void drawMeteor(int i)
{
	for (i = 0; i < MAXMETEOR; i++)
	{
		switch (meteor[i].style)
		{
		case 0:
			putimage(meteor[i].x, meteor[i].y, &img1,SRCPAINT);
			break;
		case 1:
			putimage(meteor[i].x, meteor[i].y, &img2,SRCPAINT);
			break;
		}
	}
}
//�����ƶ�
void moveMeteor(int i)
{
	for (i = 0; i < MAXMETEOR; i++)
	{
		meteor[i].x += meteor[i].step;
		meteor[i].y += meteor[i].step;
	}
}
int main()
{
	//����ͼƬ
	loadimage(&img1, L"1.jpg", 30, 20);
	loadimage(&img2, L"2.jpg", 50, 30);
	initgraph(1200, 600);//ͼ�ν����ʼ��
	//�����
	srand((unsigned int)time(NULL));
	printText();
	int i;
	for (i = 0; i < MAXSTAR; i++)
	{
		initStar(i);
	}
	for (i = 0; i < MAXMETEOR; i++)
	{
		initMeteor(i);
	}
	while (1)
	{
		BeginBatchDraw();
		cleardevice();//���������Ļ
		for (i = 0; i < MAXSTAR; i++)
		{
			drawStar(i);
		}
		drawMeteor(i);
		moveMeteor(i);
		Sleep(100);
		EndBatchDraw();
	}
	while (1);
	closegraph();//�ر�ͼ�ν���
	return 0;
}