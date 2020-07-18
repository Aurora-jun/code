#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<time.h>

#define MAXSTAR 1314
#define MAXMETEOR 520

//星星结构体
struct Star
{
	int x, y;
	int color;
	int step;
}star[MAXSTAR];
//流星雨结构体
struct Meteor
{
	int x, y;
	int style;
	int step;
}meteor[MAXMETEOR];

//流星贴图
IMAGE img1, img2;//定义图片


//文字输出函数
void printText()
{
	settextcolor(RGB(255, 0, 252));
	settextstyle(40, 0, L"华文行楷");
	outtextxy(350, 20, L"xxx 我喜欢你");
	//设置文字颜色
	settextcolor(RGB(0, 255, 255));
	//调整字体大小
	settextstyle(40, 0, L"华文行楷");
	//在指定位置输出字符串
	outtextxy(150, 100, L"终是庄周梦了蝶，你是恩赐也是劫。");
	outtextxy(150, 150, L"终是悟空成了佛，负了紫霞入了魔。");
	outtextxy(150, 200, L"愁聚眉峰尽日颦，千点啼痕，万点啼痕。");
	outtextxy(150, 250, L"晓看天色暮看云，行也思君，坐也思君。");
	outtextxy(150, 300, L"秋千水，竹马到，一眼见你，万物不及。");
	outtextxy(150, 350, L"春水初生，春林初盛，春风十里不如你。");
	outtextxy(150, 400, L"人间忽晚，万物河归，我希望你是为我而来。");
	_getch();//按键切换界面
}
//初始化星星
void initStar(int i)
{
	//随机产生坐标，颜色，速度
	star[i].x = rand() % 1200;
	star[i].y = rand() % 600;
	star[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);//五颜六色
	star[i].step = rand() % 10;
}
//画星星
void drawStar(int i)
{
	//画像素点
	putpixel(star[i].x, star[i].y, star[i].color);
	//移动星星
	star[i].x += star[i].step;
	//出窗口的星星在产生星星
	if (star[i].x >= 1200)
	{
		putpixel(star[i].x, star[i].y, star[i].color);
		initStar(i);
	}
}
//初始化流星
void initMeteor(int i)
{
	meteor[i].x = rand() % 2200 - 1000;
	meteor[i].y = rand() % 20 - 200;
	meteor[i].style = rand() % 2;
	meteor[i].step = rand() % 30 + 1;//流星速度不为0
}
//画流星
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
//流行移动
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
	//加载图片
	loadimage(&img1, L"1.jpg", 30, 20);
	loadimage(&img2, L"2.jpg", 50, 30);
	initgraph(1200, 600);//图形界面初始化
	//随机数
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
		cleardevice();//按键清空屏幕
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
	closegraph();//关闭图形界面
	return 0;
}