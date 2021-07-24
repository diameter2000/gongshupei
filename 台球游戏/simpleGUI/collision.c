/*本模块用于实现碰撞*/
/*=====================================================================================*/
#include "basic_message.h"
#include "math.h" 
void Collision_WithTable(int BallQuantity)	//球与球桌边界碰撞
{
	int n;
	for (n = 0; n < BallQuantity; n++)
	{
		if (BallMessage[n].x <= TableLeftBoundary + BallRadius )//触碰边界反弹
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
		//if (BallMessage[n].x <= TableLeftBoundary + BallRadius || BallMessage[n].x >= TableRightBoundary - BallRadius)//触碰边界反弹
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

int BallCollisionCheck(double normalspeed1, double normalspeed2)//防止因为不连续性导致的“量子纠缠问题”（两球穿模后会连续进行延连线方向的速度交换，造成无法分离）
{
	double relative_normalspeed = normalspeed1 - normalspeed2;
	if (relative_normalspeed < 0)//如果两球延连线方向接近，返回1；远离，返回0
		return 1;
	else
		return 0;
}
void Collision_BetweenTwoBall(int BallNumber1, int BallNumber2)
{
	if (BallMessage[BallNumber1].status && BallMessage[BallNumber2].status && BallDistance(BallNumber1, BallNumber2) <= 2 * BallRadius)	//执行条件：两球均在场且距离达到临界点
	{
		double	normalspeed1, normalspeed2;//延连线方向速度分量
		double distance = BallDistance(BallNumber1, BallNumber2);
		double relative_xdirection = (BallMessage[BallNumber1].x - BallMessage[BallNumber2].x) / distance;//相对距离的单位矢量
		double relative_ydirection = (BallMessage[BallNumber1].y - BallMessage[BallNumber2].y) / distance;//相对距离的单位矢量
		//printf("%lf %lf\n", reality_xdirection, reality_ydirection);

		//printf("%lf %lf\n", reality_xdirection, reality_ydirection);
		normalspeed1 = BallMessage[BallNumber1].speed_x * relative_xdirection + BallMessage[BallNumber1].speed_y * relative_ydirection;
		normalspeed2 = BallMessage[BallNumber2].speed_x * relative_xdirection + BallMessage[BallNumber2].speed_y * relative_ydirection;
		//printf("normalspeed= %lf %lf\n",normalspeed1, normalspeed2);
		if (BallCollisionCheck(normalspeed1, normalspeed2) == 1)//两球延连线方向相对接近，执行速度改变
		{
			BallMessage[BallNumber1].speed_x = BallMessage[BallNumber1].speed_x + relative_xdirection * (normalspeed2 - normalspeed1);
			BallMessage[BallNumber1].speed_y = BallMessage[BallNumber1].speed_y + relative_ydirection * (normalspeed2 - normalspeed1);
			BallMessage[BallNumber2].speed_x = BallMessage[BallNumber2].speed_x - relative_xdirection * (normalspeed2 - normalspeed1);
			BallMessage[BallNumber2].speed_y = BallMessage[BallNumber2].speed_y - relative_ydirection * (normalspeed2 - normalspeed1);
		}
	}
	//if (BallMessage[BallNumber1].status && BallMessage[BallNumber2].status && BallDistance(BallNumber1, BallNumber2) <= 2 * BallRadius)	//执行条件：两球均在场且距离达到临界点
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

void Collision_WithBall(int BallQuantity)//参数为球的个数
{
	int a; int b;
	//Collision_BetweenTwoBall(0, 1);
	for (a = 0; a < BallQuantity; a++)		//单循环进行球两两之间的碰撞
	{
		for (b = a+1; b < BallQuantity; b++)
		{
			Collision_BetweenTwoBall(a, b);
		}
	}
}