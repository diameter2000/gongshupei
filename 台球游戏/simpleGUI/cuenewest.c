#include "basic_message.h"
#include "ball.h"

#define CueLength 3//球杆长
#define PI 3.1415926 
#define MAXSPEED 0.3//赋予球的速度最大值
static double distance = 1; //球杆离母球距离
int flag = 0;//如果开始蓄力则flag=1，不然为0
int IsBatting = 1;//用以判断是否击球 
int isturn = 1;//用以判断球杆是否旋转 
int Batting = 0;//用以判断是否出杆 
int Storage = 0;//用以判断是否蓄力 

//extern int PlaySort;
static double strengh = 0;//力度
static double directionx,directiony,mx,my;//球杆的单位方向矢量,鼠标坐标
void DrawCue();
double distacewithball()
{
	double distaceweithball;
	distaceweithball = sqrt((mx - BallMessage[0].x) * (mx - BallMessage[0].x) + (my - BallMessage[0].y) * (my - BallMessage[0].y));
	return distaceweithball;
}
void direct()//球杆的单位方向矢量
{
	directionx = (mx - BallMessage[0].x) / distacewithball();
	directiony = (my - BallMessage[0].y) / distacewithball();
}

void setspeed()//赋予白球速度
{
	BallMessage[0].speed_x = -directionx * strengh;
	BallMessage[0].speed_y = -directiony *strengh;
}
void bat() //球杆回弹
{
	if (Batting)
	{
		
		//DisplayClear();
		distance = BallRadius;
		DrawCue();
		Batting = 0;
		setspeed();
		
		distance = 1;
		Storage = 0;
	}
	
		
	
}
void DrawCue()//画出球杆 
{
	if (isturn)
	{
		direct();
	}
	SetPenColor("Black");
	SetPenSize(4);
	MovePen(BallMessage[0].x + directionx * distance, BallMessage[0].y + directiony * distance);
	DrawLine(directionx * CueLength, directiony * CueLength);
}
void display1()
{
	//DisplayClear();
	DrawCue();
	bat();
}
void sticktimer()
{
	
		if (Storage)
		{
			if(strengh< MAXSPEED)
			strengh = strengh + 0.001;
			
			distance = distance + 0.01;
		}
		display1();
	
}
int inBox(double x, double y, double x1, double x2, double y1, double y2)
{
	return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}
int IsInButton(double mx, double my)
{
	if (inBox(mx, my, 3, 4.5, 0.3, 0.8) || inBox(mx, my, 0.5, 1, 8.5, 9) || inBox(mx, my, 6, 7.5, 0.3, 0.8) || inBox(mx, my, 9, 10.5, 0.3,0.8))
		return 0;
	else
		return 1;
}
void StickMouseEventProcess(int x, int y, int button, int event)
{
	 mx = ScaleXInches(x);
	 my = ScaleYInches(y);
	switch (event)
	{
	case BUTTON_UP:
		if (button == LEFT_BUTTON && flag == 1)		//左键松开球杆开始击球 
		{
			IsBatting = 0;
			Batting = 1;
			isturn = 1;
			Storage = 0;
			flag = 0;
		}
		
		break;
	case BUTTON_DOWN:
		if (button == LEFT_BUTTON && flag == 0)		//左键按下开始球杆蓄力 
		{
			if (IsInButton( mx,my))
			{
				isturn = 0;
				flag = 1;
				Storage = 1;
			}
			
		}
		if (button == RIGHT_BUTTON)	//右键松开取消球杆蓄力，可以重新调整击球方向 
		{
			isturn = 1;
			flag = 0;
			Storage = 0;
			distance = 1;
		}
	default:
		;
		break;
	}
}

//void Main()
//{
//
//	InitGraphics();
//	registerMouseEvent(StickMouseEventProcess);
//	registerTimerEvent(sticktimer);
//	startTimer(StickTimer, 2);
//}