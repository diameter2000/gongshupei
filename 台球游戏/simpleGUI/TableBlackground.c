#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <math.h>
#include"imgui.h"
#include "record.h"
#include "test.h"
#include "TableBlackground.h"
#include "game1.h"
#include "ball.h"
#define TABLE_WIDTH 13 //WIDTH为桌子长 
#define TABLE_LENGTH 6.5 //LENGTH为桌子宽  长宽写反了 0.0 
#define GAP 0.8 //GAP为外矩形和内矩形长的差值 
#define fx 1.5 //左下顶点 x坐标 
#define fy 1.5 //左下顶点y坐标 
#define  MARK "0.0" //用来计分，还需计分函数 
extern int IfStop;
int score;
int score2;
extern int BallQuantity_TEST;
extern int PlaySort;
extern int order;
extern int firsthit1;
void IsInHole()//判断球是否进洞
{
	int i;
	for (i = 0; i < BallQuantity_TEST; i++)
	{
		
		if ((BallMessage[i].x - (fx + 0.45))*(BallMessage[i].x - (fx + 0.45)) + (-BallMessage[i].y + TableHighBoundary )* (-BallMessage[i].y + TableHighBoundary) <= (BallRadius + DistanceWithHole)* (BallRadius + DistanceWithHole))
		{
			BallMessage[i].status = 0;
			BallMessage[i].speed_x = 0;
			BallMessage[i].speed_y = 0;
		
		}//左上角
		if ((BallMessage[i].x - (fx + 0.45)) * (BallMessage[i].x - (fx + 0.45)) + (BallMessage[i].y - (fy + 0.3)) * (BallMessage[i].y - (fy + 0.3)) <= (BallRadius + DistanceWithHole) * (BallRadius + DistanceWithHole))
		{
			BallMessage[i].status = 0;
			BallMessage[i].speed_x = 0;
			BallMessage[i].speed_y = 0;
			
		}//左下角
		if (pow(-BallMessage[i].x + (fx + TABLE_WIDTH - 0.055),2) +pow(BallMessage[i].y - (fy + 0.3),2) <=pow( BallRadius + DistanceWithHole,2))
		{
			BallMessage[i].status = 0;
			BallMessage[i].speed_x = 0;
			BallMessage[i].speed_y = 0;
			
		}//右下角
		if (pow(-BallMessage[i].x + (fx + TABLE_WIDTH - 0.055),2) +pow(-BallMessage[i].y + fy + TABLE_LENGTH - 0.3 ,2)<=pow( BallRadius + DistanceWithHole,2))
		{
			BallMessage[i].status = 0;
			BallMessage[i].speed_x = 0;
			BallMessage[i].speed_y = 0;
			
		}//右上角
		if ((pow(-BallMessage[i].x + fx + TABLE_WIDTH / 2 ,2))  + pow(-BallMessage[i].y + fy + TABLE_LENGTH - 0.3,2) <= pow(BallRadius ,2))
		{
			BallMessage[i].status = 0;
			BallMessage[i].speed_x = 0;
			BallMessage[i].speed_y = 0;
			
		}//中上
		if ((pow(-BallMessage[i].x + fx + TABLE_WIDTH / 2 , 2)) + pow(BallMessage[i].y -(fy +0.3), 2) <= pow(BallRadius + DistanceWithHole/6, 2))
		{
			BallMessage[i].status = 0;
			BallMessage[i].speed_x = 0;
			BallMessage[i].speed_y = 0;
			
		}//中下
	}
}

void DrawHole(double x, double y, double R, double start, double end, char *color) //画洞 
{
	mySetPenColor(color);
	MovePen(x, y);
	StartFilledRegion(1);
	DrawArc(R, start, end);
	EndFilledRegion();
	mySetPenColor("Black");
}

void DrawTableFrame()
{
	mySetPenColor("BROWN");   
	drawRectangle(fx,fy,TABLE_WIDTH,TABLE_LENGTH,1);
	mySetPenColor("CHOCOLATE");
	drawRectangle(fx+GAP/8,fy+GAP/8,TABLE_WIDTH-GAP/4,TABLE_LENGTH-GAP/4,1);
	mySetPenColor("TAN");
	drawRectangle(fx+GAP/4,fy+GAP/4,TABLE_WIDTH-GAP/2,TABLE_LENGTH-GAP/2,1);
	mySetPenColor("SIENNA");
	drawRectangle(fx+3*GAP/8,fy+3*GAP/8,TABLE_WIDTH-3*GAP/4,TABLE_LENGTH-3*GAP/4,1);
	mySetPenColor("FORESTGREEN");
	drawRectangle(fx+GAP/2,fy+GAP/2,TABLE_WIDTH-GAP,TABLE_LENGTH-GAP,1); //实现渐变色的边框 
}

//void SetCueStorage(void) //画放置球杆处
//{
////	MovePen(0.3, 0.5);
//	SetPenColor("Brown");
//	drawRectangle(0, 1, 0.3, 0.2, 1);
//	SetPenColor("White");
//	MovePen(0.15 + 0.05, 1.2);
//	StartFilledRegion(1);
//	DrawArc(0.05, 0, -180);
//	DrawLine(0.1, 0);
//	EndFilledRegion();
//	SetPenColor("Brown");
//	drawRectangle(0, 4.5, 0.3, 0.1, 1);
//	MovePen(0.15, 4.5);
//	SetPenColor("Black");
//	DrawLine(0, -0.4);

void DrawButton()
{
	if (button(GenUIID(0), 3, 0.3, 1.5, 0.5, "读档"))
	{
		switch (PlaySort)
		{
		case 1:ReadRecord1(BallQuantity_TEST, "save1"); break;
		case 2:ReadRecord1(BallQuantity_TEST, "save2"); break;
		case 3:ReadRecord1(BallQuantity_TEST, "save3"); break;
		}
	}
	if (button(GenUIID(0), 0.5, 8.5, 0.5, 0.5, "||"))
	{
		IfStop = IfStop * -1;
	}
	if (button(GenUIID(0), 6, 0.3, 1.5, 0.5, "存档"))
	{
		switch (PlaySort)
		{
		case 1:SaveRecord1(BallQuantity_TEST, "save1"); break;
		case 2:SaveRecord1(BallQuantity_TEST, "save2"); break;
		case 3:SaveRecord1(BallQuantity_TEST, "save3"); break;
		}
	}
	if (button(GenUIID(0), 9, 0.3, 1.5, 0.5, "重新开始"))
	{
		switch (PlaySort)
		{
		case 1:SetBallMessage1(); break;
		case 2:SetBallMessage2(); break;
		}
	}
}

void DrawBackground(int playsort)
{
	

	char *mark1;
	char* mark2;//分数的字符串
	mark1 = (char*)malloc(sizeof(char) * 5);
	mark2 = (char*)malloc(sizeof(char) * 5);
	//mark = "MARK";
	DrawTableFrame(); //画桌子的框架 
	DrawHole(fx+0.45, fy+0.3,0.2,0,360,"BLACK");   //左下
	DrawHole(fx+0.45,fy+TABLE_LENGTH-0.3, BallRadius,0,360,"BLACK");//左上
	DrawHole(fx+TABLE_WIDTH/2+0.2,fy+0.2, BallRadius,0,360,"BLACK");//中下
	DrawHole(fx+TABLE_WIDTH/2+0.2,fy+TABLE_LENGTH-0.3, BallRadius,0,360,"BLACK");//中上
	DrawHole(fx+TABLE_WIDTH-0.055,fy+0.3, BallRadius,0,360,"BLACK");//右下
	DrawHole(fx+TABLE_WIDTH-0.05,fy+TABLE_LENGTH-0.3 , BallRadius,0,360,"BLACK");  //右上	//画台球桌的六个洞
	DrawButton();//画按钮
	//if (button(GenUIID(0), 3, 0.3, 1.5, 0.5, "读档1"))
	//{
	//	ReadRecord1(BallQuantity_TEST);
	//}
	//if (button(GenUIID(0), 0.5, 8.5, 0.5, 0.5, "||"))
	//{
	//	IfStop = IfStop * -1;
	//}
	//if (button(GenUIID(0), 6, 0.3, 1.5, 0.5, "存档1"))
	//{
	//	SaveRecord1(BallQuantity_TEST);
	//}
	//if (button(GenUIID(0), 9, 0.3, 1.5, 0.5, "重新开始"))
	//{
	//	SetBallMessage();
	//}
	mySetPenColor("BROWN");



	if (PlaySort == 1)
	{
		changeorder();
		score = CountScore1();//计算目前得分
		score2 = CountScore2();
		sprintf(mark1, "%d", score);//给分数字符串赋值
		sprintf(mark2, "%d", score2);
		drawBox(fx + TABLE_LENGTH / 2 + 1.2, fy + TABLE_WIDTH / 2 + 0.9, 1.5, 0.5, 0, mark1, 1, "RED");//分数显示
		drawBox(fx + TABLE_LENGTH / 2 + 3.2, fy + TABLE_WIDTH / 2 + 0.9, 1.5, 0.5, 0, mark2, 1, "RED");
		if (order == 1)
			drawBox(14.5, 0, 1.5, 0.5, 0, "先手击球", 1, "RED");
		else if (order == -1)
			drawBox(14.5, 0, 1.5, 0.5, 0, "后手击球", 1, "RED");
		win();

	}
	if (PlaySort == 2)
	{
		WhiteBallInHole2();
		checkwronghit2();
		score=CountScore_2();
		sprintf(mark1, "%d", score);
		drawBox(fx + TABLE_LENGTH / 2 + 2.2, fy + TABLE_WIDTH / 2 + 0.9, 1.5, 0.5, 0, mark1, 1, "RED");//分数显示
	}
	//SetCueStorage(); 
	
	 
	
}




