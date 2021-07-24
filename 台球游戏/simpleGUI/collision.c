/*��ģ������ʵ����ײ*/
/*=====================================================================================*/
#include "basic_message.h"
#include "math.h" 
void Collision_WithTable(int BallQuantity)	//���������߽���ײ
{
	int n;
	for (n = 0; n < BallQuantity; n++)
	{
		if (BallMessage[n].x <= TableLeftBoundary + BallRadius )//�����߽練��
		{
			BallMessage[n].speed_x = 0 - BallMessage[n].speed_x;
			BallMessage[n].x = TableLeftBoundary + BallRadius;
		}
		if (BallMessage[n].x >= TableRightBoundary - BallRadius)
		{
			BallMessage[n].speed_x = 0 - BallMessage[n].speed_x;
			BallMessage[n].x = TableRightBoundary - BallRadius;
		}


		if (BallMessage[n].y <= TableLowBoundary + BallRadius )
		{
			BallMessage[n].speed_y = 0 - BallMessage[n].speed_y;
			BallMessage[n].y = TableLowBoundary + BallRadius;
		}
		if (BallMessage[n].y >= TableHighBoundary - BallRadius)
		{
			BallMessage[n].speed_y = 0 - BallMessage[n].speed_y;
			BallMessage[n].y = TableHighBoundary - BallRadius;
		}
		//if (BallMessage[n].x <= TableLeftBoundary + BallRadius || BallMessage[n].x >= TableRightBoundary - BallRadius)//�����߽練��
		//
		//	BallMessage[n].speed_x = 0 - BallMessage[n].speed_x;

		//
		//if (BallMessage[n].y <= TableLowBoundary + BallRadius || BallMessage[n].y >= TableHighBoundary - BallRadius)
		//	BallMessage[n].speed_y = 0 - BallMessage[n].speed_y;
	}
}

double BallDistance(int BallNumber1, int BallNumber2)
{
	double dx, dy, distance;
	dx = BallMessage[BallNumber1].x - BallMessage[BallNumber2].x;
	dy = BallMessage[BallNumber1].y - BallMessage[BallNumber2].y;
	distance = sqrt(dx * dx + dy * dy);
	return distance;
}

int BallCollisionCheck(double normalspeed1, double normalspeed2)//��ֹ��Ϊ�������Ե��µġ����Ӿ������⡱������ģ����������������߷�����ٶȽ���������޷����룩
{
	double relative_normalspeed = normalspeed1 - normalspeed2;
	if (relative_normalspeed < 0)//������������߷���ӽ�������1��Զ�룬����0
		return 1;
	else
		return 0;
}
void Collision_BetweenTwoBall(int BallNumber1, int BallNumber2)
{
	if (BallMessage[BallNumber1].status && BallMessage[BallNumber2].status && BallDistance(BallNumber1, BallNumber2) <= 2 * BallRadius)	//ִ��������������ڳ��Ҿ���ﵽ�ٽ��
	{
		double	normalspeed1, normalspeed2;//�����߷����ٶȷ���
		double distance = BallDistance(BallNumber1, BallNumber2);
		double relative_xdirection = (BallMessage[BallNumber1].x - BallMessage[BallNumber2].x) / distance;//��Ծ���ĵ�λʸ��
		double relative_ydirection = (BallMessage[BallNumber1].y - BallMessage[BallNumber2].y) / distance;//��Ծ���ĵ�λʸ��
		//printf("%lf %lf\n", reality_xdirection, reality_ydirection);

		//printf("%lf %lf\n", reality_xdirection, reality_ydirection);
		normalspeed1 = BallMessage[BallNumber1].speed_x * relative_xdirection + BallMessage[BallNumber1].speed_y * relative_ydirection;
		normalspeed2 = BallMessage[BallNumber2].speed_x * relative_xdirection + BallMessage[BallNumber2].speed_y * relative_ydirection;
		//printf("normalspeed= %lf %lf\n",normalspeed1, normalspeed2);
		if (BallCollisionCheck(normalspeed1, normalspeed2) == 1)//���������߷�����Խӽ���ִ���ٶȸı�
		{
			BallMessage[BallNumber1].speed_x = BallMessage[BallNumber1].speed_x + relative_xdirection * (normalspeed2 - normalspeed1);
			BallMessage[BallNumber1].speed_y = BallMessage[BallNumber1].speed_y + relative_ydirection * (normalspeed2 - normalspeed1);
			BallMessage[BallNumber2].speed_x = BallMessage[BallNumber2].speed_x - relative_xdirection * (normalspeed2 - normalspeed1);
			BallMessage[BallNumber2].speed_y = BallMessage[BallNumber2].speed_y - relative_ydirection * (normalspeed2 - normalspeed1);
		}
	}
	//if (BallMessage[BallNumber1].status && BallMessage[BallNumber2].status && BallDistance(BallNumber1, BallNumber2) <= 2 * BallRadius)	//ִ��������������ڳ��Ҿ���ﵽ�ٽ��
	//{
	//	double temp;
	//	temp = BallMessage[BallNumber1].speed_x;
	//	BallMessage[BallNumber1].speed_x = BallMessage[BallNumber2].speed_x;
	//	BallMessage[BallNumber2].speed_x = temp;
	//	temp = BallMessage[BallNumber1].speed_y;
	//	BallMessage[BallNumber1].speed_y = BallMessage[BallNumber2].speed_y;
	//	BallMessage[BallNumber2].speed_y = temp;
	//}
}

void Collision_WithBall(int BallQuantity)//����Ϊ��ĸ���
{
	int a; int b;
	//Collision_BetweenTwoBall(0, 1);
	for (a = 0; a < BallQuantity; a++)		//��ѭ������������֮�����ײ
	{
		for (b = a+1; b < BallQuantity; b++)
		{
			Collision_BetweenTwoBall(a, b);
		}
	}
}