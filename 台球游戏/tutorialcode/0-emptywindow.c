//===========================================================================
//
//  版权所有者： 刘新国，浙江大学计算机科学与技术学院
//                       CAD&CG国家重点实验室
//               xgliu@cad.zju.edu.cn
//  最近修改：2020年3月25日 
//  初次创建：2020年3月21日，用于<<程序设计专题>>课程教学
//
//===========================================================================
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
//#include "ball1.h"

#define TableLeftBoundary 0.1	//球桌的边界
#define TableRightBoundary 5
#define TableHighBoundary 0.1
#define TableLowBoundary 4


typedef enum {
	DrawBallTimer,
	CollisionTimer,

} MyTimer;


struct BALL_MESSAGE {
	double x;
	double y;
	double speed_x;
	double speed_y;
}BallMessage[10];//存储球信息的结构体数组


void SetBallMessage(int BallNumber)
{
	
		BallMessage[BallNumber].x = 2;
		BallMessage[BallNumber].y = 2;
		BallMessage[BallNumber].speed_x = 0.01;
		BallMessage[BallNumber].speed_y = 0.01;
	
}//设定某一编号球的信息


void DrawOneBall(int BallNumber)
{
	
	MovePen(BallMessage[BallNumber].x, BallMessage[BallNumber].y);
	DrawArc(0.2, 0, 360);
};//画某一编号的球


void DrawAllBall()
{
	DisplayClear();
	DrawOneBall(0);
}//画所有球

void Collision_WithTable()	//球与球桌边界碰撞
{
	int n = 0;//现在只写了一个球
	if (BallMessage[n].x <= TableLeftBoundary+0.1|| BallMessage[n].x >= TableRightBoundary-0.1)//触碰边界反弹
		BallMessage[n].speed_x = 0-BallMessage[n].speed_x;
	if (BallMessage[n].y <= TableLeftBoundary +0.1|| BallMessage[n].y >= TableRightBoundary-0.1)
		BallMessage[n].speed_y = 0 - BallMessage[n].speed_y;
}
void Collision_WithBall()
{

}

int BallRun(int timerID)	//球的运动
{
	int i = 0;//球的序号//现在只写了一个球
	switch (timerID)
	{
	case CollisionTimer:Collision_WithTable();

	case DrawBallTimer:BallMessage[i].x += BallMessage[i].speed_x; BallMessage[i].y += BallMessage[i].speed_y;
		DrawAllBall(); break;

	}
}
void Main()
{
	
	SetWindowTitle("台球");
	InitGraphics();
	MovePen(1, 1);
	DrawLine(0, 1);
	MovePen(1, 1);
	DrawArc(1, 0, 360);
}