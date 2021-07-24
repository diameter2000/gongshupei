
/*一种玩法所需调用的基本函数*/
/*=====================================================================================*/
#include "ball.h"
#include "math.h"
#include "cuenewest.h"
extern int IfStop;
extern int PlaySort;
extern int BallQuantity_TEST;
void slow(int i)	//球减速的函数
{
	double speed = sqrt(BallMessage[i].speed_x * BallMessage[i].speed_x + BallMessage[i].speed_y * BallMessage[i].speed_y);
	double cx = BallMessage[i].speed_x / speed;		//球速度的单位矢量
	double cy = BallMessage[i].speed_y / speed;
	if (fabs(BallMessage[i].speed_x) > SPEED_DECREASE)	//小于临界值直接归零，防止符号变化
	{
		
			BallMessage[i].speed_x = BallMessage[i].speed_x - SPEED_DECREASE*cx;
	
	}
	else
		BallMessage[i].speed_x = 0;
	if (fabs(BallMessage[i].speed_y) > SPEED_DECREASE)
	{
		
			BallMessage[i].speed_y = BallMessage[i].speed_y - SPEED_DECREASE*cy;	
		
	}
	else
		BallMessage[i].speed_y = 0;
}

int IfBallStop(int BallQuantity)//判断球是否都停下，是返回1，否返回0
{
	int i,stop;
	stop = 1;
	for (i = 0; i < BallQuantity; i++)
	{
		if (!BallMessage[i].speed_x && !BallMessage[i].speed_y)
		{
				stop = stop * 1;
		}
		else
			stop = stop * 0;
	}
	return stop;
}
void BallMove(int BallQuantity)	//根据球的速度，改变结构体中球的位置信息
{
	
	int i;

	for (i = 0; i < BallQuantity; i++)
	{
		BallMessage[i].x += BallMessage[i].speed_x; BallMessage[i].y += BallMessage[i].speed_y;//球延速度方向移动
		slow(i);
		
		//if (fabs(BallMessage[i].speed_x )<= 0.003)
		//	BallMessage[i].speed_x = 0;
		//else
		//{
		//	BallMessage[i].speed_x = BallMessage[i].speed_x * 0.995;
		//}
		//if (fabs(BallMessage[i].speed_y) <= 0.003)
		//	BallMessage[i].speed_y = 0;
		//else
		//{
		//	BallMessage[i].speed_y = BallMessage[i].speed_y * 0.995;
		//}
	}
}
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x, y, button, event); //GUI获取鼠标
	StickMouseEventProcess(x, y, button, event);//球都停止后画球杆
	DrawAllimage(BallQuantity_TEST, PlaySort); // 刷新显示,PlaySort为玩法编号
			
	
	
}
void BallRun(int timerID)	//球的运动
{
	//registerMouseEvent(MouseEventProcess);//调整时注释掉
	switch (timerID)
	{
	case DisplayTimer: 
		
			DrawAllimage(BallQuantity_TEST, PlaySort);  // 刷新显示,PlaySort为玩法编号

		if (IfStop != STOP)//不暂停时球才运动
			BallMove(BallQuantity_TEST);
		Collision_WithTable(BallQuantity_TEST); Collision_WithBall(BallQuantity_TEST);//碰撞
		 IsInHole();//判断进洞
		
	 break;

	}
}

//void ButtonEvent(int x, int y, int button, int event)
//{
//
//}


//void StartGame_1()
//{
//	cancelMouseEvent();
//	SetBallMessage();//测试用
//	//SetWindowSize(16, 9);
//	//InitGraphics();
//	registerTimerEvent(BallRun);
//	registerMouseEvent(MouseEventProcess);
//	startTimer(DisplayTimer, ImageRefreshInterval);
//	startTimer(StickTimer, 100);//和画球杆有关
//	//registerMouseEvent(MouseEventProcess);
//}