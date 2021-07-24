//===========================================================================
//
//  ��Ȩ�����ߣ� ���¹����㽭��ѧ�������ѧ�뼼��ѧԺ
//                       CAD&CG�����ص�ʵ����
//               xgliu@cad.zju.edu.cn
//  ����޸ģ�2020��3��25�� 
//  ���δ�����2020��3��21�գ�����<<�������ר��>>�γ̽�ѧ
//
//===========================================================================
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
//#include "ball1.h"

#define TableLeftBoundary 0.1	//�����ı߽�
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
}BallMessage[10];//�洢����Ϣ�Ľṹ������


void SetBallMessage(int BallNumber)
{
	
		BallMessage[BallNumber].x = 2;
		BallMessage[BallNumber].y = 2;
		BallMessage[BallNumber].speed_x = 0.01;
		BallMessage[BallNumber].speed_y = 0.01;
	
}//�趨ĳһ��������Ϣ


void DrawOneBall(int BallNumber)
{
	
	MovePen(BallMessage[BallNumber].x, BallMessage[BallNumber].y);
	DrawArc(0.2, 0, 360);
};//��ĳһ��ŵ���


void DrawAllBall()
{
	DisplayClear();
	DrawOneBall(0);
}//��������

void Collision_WithTable()	//���������߽���ײ
{
	int n = 0;//����ֻд��һ����
	if (BallMessage[n].x <= TableLeftBoundary+0.1|| BallMessage[n].x >= TableRightBoundary-0.1)//�����߽練��
		BallMessage[n].speed_x = 0-BallMessage[n].speed_x;
	if (BallMessage[n].y <= TableLeftBoundary +0.1|| BallMessage[n].y >= TableRightBoundary-0.1)
		BallMessage[n].speed_y = 0 - BallMessage[n].speed_y;
}
void Collision_WithBall()
{

}

int BallRun(int timerID)	//����˶�
{
	int i = 0;//������//����ֻд��һ����
	switch (timerID)
	{
	case CollisionTimer:Collision_WithTable();

	case DrawBallTimer:BallMessage[i].x += BallMessage[i].speed_x; BallMessage[i].y += BallMessage[i].speed_y;
		DrawAllBall(); break;

	}
}
void Main()
{
	
	SetWindowTitle("̨��");
	InitGraphics();
	MovePen(1, 1);
	DrawLine(0, 1);
	MovePen(1, 1);
	DrawArc(1, 0, 360);
}