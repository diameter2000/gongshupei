
/*һ���淨������õĻ�������*/
/*=====================================================================================*/
#include "ball.h"
#include "math.h"
#include "cuenewest.h"
extern int IfStop;
extern int PlaySort;
extern int BallQuantity_TEST;
void slow(int i)	//����ٵĺ���
{
	double speed = sqrt(BallMessage[i].speed_x * BallMessage[i].speed_x + BallMessage[i].speed_y * BallMessage[i].speed_y);
	double cx = BallMessage[i].speed_x / speed;		//���ٶȵĵ�λʸ��
	double cy = BallMessage[i].speed_y / speed;
	if (fabs(BallMessage[i].speed_x) > SPEED_DECREASE)	//С���ٽ�ֱֵ�ӹ��㣬��ֹ���ű仯
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

int IfBallStop(int BallQuantity)//�ж����Ƿ�ͣ�£��Ƿ���1���񷵻�0
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
void BallMove(int BallQuantity)	//��������ٶȣ��ı�ṹ�������λ����Ϣ
{
	
	int i;

	for (i = 0; i < BallQuantity; i++)
	{
		BallMessage[i].x += BallMessage[i].speed_x; BallMessage[i].y += BallMessage[i].speed_y;//�����ٶȷ����ƶ�
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
	uiGetMouse(x, y, button, event); //GUI��ȡ���
	StickMouseEventProcess(x, y, button, event);//��ֹͣ�����
	DrawAllimage(BallQuantity_TEST, PlaySort); // ˢ����ʾ,PlaySortΪ�淨���
			
	
	
}
void BallRun(int timerID)	//����˶�
{
	//registerMouseEvent(MouseEventProcess);//����ʱע�͵�
	switch (timerID)
	{
	case DisplayTimer: 
		
			DrawAllimage(BallQuantity_TEST, PlaySort);  // ˢ����ʾ,PlaySortΪ�淨���

		if (IfStop != STOP)//����ͣʱ����˶�
			BallMove(BallQuantity_TEST);
		Collision_WithTable(BallQuantity_TEST); Collision_WithBall(BallQuantity_TEST);//��ײ
		 IsInHole();//�жϽ���
		
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
//	SetBallMessage();//������
//	//SetWindowSize(16, 9);
//	//InitGraphics();
//	registerTimerEvent(BallRun);
//	registerMouseEvent(MouseEventProcess);
//	startTimer(DisplayTimer, ImageRefreshInterval);
//	startTimer(StickTimer, 100);//�ͻ�����й�
//	//registerMouseEvent(MouseEventProcess);
//}