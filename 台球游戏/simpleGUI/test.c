//��ģ�����ڲ���
//**********************
#include "test.h"
int IfStop;//�����ж��Ƿ���ͣ��0Ϊ��ͣ��1Ϊ����ͣ
int PlaySort;	//�淨���
int  BallQuantity_TEST;	//�������
void SetWhiteBallMessage(double x,double y,double speed_x,double speed_y)//�趨����ĺ����꣬�����꣬�����ٶȣ������ٶ�
{
	BallMessage[0].x = x;//;4;
	BallMessage[0].y = y;// 5;
	BallMessage[0].speed_x = speed_x;// 0.1;
	BallMessage[0].speed_y = speed_y;//0;
	BallMessage[0].status = 1;
}
void SetBallMessage1()
{
	IfStop = CONTINUE;//��ʼ״̬����ͣ
	SetWhiteBallMessage(6,5,0,0);
	
	double initx, inity;//��һ����ĳ�ʼλ��
	initx = 9;//GetWindowWidth() / 2;
	inity = 5;// GetWindowHeight() / 2;
	int d, e;
	double x = initx - BallRadius * 1.72;
	double y = inity;
	int count;
	for (d = 1; d <= 5; d++)
	{
		x = x + BallRadius * 1.72;
		y = inity + (d - 1) * BallRadius;
		for (e = 0; e < d; e++)
		{
			count = (d - 1) * d / 2 + e + 1;
			BallMessage[count].x = x;
			BallMessage[count].y = y;
			BallMessage[count].speed_x = 0;
			BallMessage[count].speed_y = 0;
			BallMessage[count].status = 1;
			//printf("%lf %lf %d %d %d\n", BallMessage[count].x, BallMessage[count].y, count, d, e);
			y = y - 2 * BallRadius;
		}
	}

	//SetWhiteBallMessage(4, 5,0.1, 0);//�趨�������Ϣ

	//BallMessage[1].x = 5;//�趨һ���ܻ������Ϣ
	//BallMessage[1].y = 5;
	//BallMessage[1].speed_x = 0.05;
	//BallMessage[1].speed_y = 0;
	//BallMessage[1].status = 1;
	//BallMessage[0].x = 6;
	//BallMessage[0].y = 5;
	//BallMessage[0].speed_x = -0.05;
	//BallMessage[0].speed_y = 0.02;
	//BallMessage[0].status = 1;
}//�趨�����Ϣ��������(Ŀǰֻ�������������Ϣ��

void SetBallMessage2()
{
	IfStop = CONTINUE;//��ʼ״̬����ͣ
	SetWhiteBallMessage(3, 5, 0, 0);

	double initx, inity;//��һ����ĳ�ʼλ��
	initx = 11;//GetWindowWidth() / 2;
	inity = 5;// GetWindowHeight() / 2;
	int d, e;
	double x = initx - BallRadius * 1.72;
	double y = inity;
	int count;
	for (d = 1; d <= 5; d++)
	{
		x = x + BallRadius * 1.72;
		y = inity + (d - 1) * BallRadius;
		for (e = 0; e < d; e++)
		{
			count = (d - 1) * d / 2 + e + 1;
			BallMessage[count].x = x;
			BallMessage[count].y = y;
			BallMessage[count].speed_x = 0;
			BallMessage[count].speed_y = 0;
			BallMessage[count].status = 1;
			//printf("%lf %lf %d %d %d\n", BallMessage[count].x, BallMessage[count].y, count, d, e);
			y = y - 2 * BallRadius;
		}
	}
	BallMessage[16].x = 4.5;
	BallMessage[16].y = 3.5;
	BallMessage[16].speed_x = 0;
	BallMessage[16].speed_y = 0;
	BallMessage[16].status = 1;
	BallMessage[17].x = 4.5;
	BallMessage[17].y = 6.5;
	BallMessage[17].speed_x = 0;
	BallMessage[17].speed_y = 0;
	BallMessage[17].status = 1;
	BallMessage[18].x = 4.5;
	BallMessage[18].y = 5;
	BallMessage[18].speed_x = 0;
	BallMessage[18].speed_y = 0;
	BallMessage[18].status = 1;
	BallMessage[19].x = 7.5;
	BallMessage[19].y = 5;
	BallMessage[19].speed_x = 0;
	BallMessage[19].speed_y = 0;
	BallMessage[19].status = 1;
	BallMessage[20].x = initx-0.9;
	BallMessage[20].y = 5;
	BallMessage[20].speed_x = 0;
	BallMessage[20].speed_y = 0;
	BallMessage[20].status = 1;
	BallMessage[21].x = initx +2.5;
	BallMessage[21].y = 5;
	BallMessage[21].speed_x = 0;
	BallMessage[21].speed_y = 0;
	BallMessage[21].status = 1;
}