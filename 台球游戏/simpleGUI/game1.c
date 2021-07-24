#include "ball.h"
#include "cuenewest.h"
extern int PlaySort;
extern int  BallQuantity_TEST;

int order = 1;//球权归属，1归属先手，-1归属后手
int FirstInHole[15]={ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
void game1interface();
void Game1InterfaceMouseEvent(int x, int y, int button, int event);
void StartGame_1();
int CountScore1()//计算先手分数
{
	int i;
	int score = 0;
	for (i = 1; i <= 7; i++)
	{
		
		score = score + (!BallMessage[i].status);
	}
	return score;
}
int CountScore2()//计算后手分数
{
	int i;
	int score = 0;
	for (i =9 ; i <= 15; i++)
	{
		
		score = score + (!BallMessage[i].status);
	}
	return score;
}
void checkwronghit()
{
	int i;
	int in = 1;//本回合击球方是否进自己的球，0为进，1为不进
	int wrong = 1;//本回合击球方是否进对方的球，0为进，1为不进
	switch (order)
	{
	case 1:
		//for (i = 1; i <= 7; i++)
		//{
		//	if (!BallMessage[i].status && FirstInHole[i - 1])//先手方没击入自己的球，球权转让
		//	{
		//		in = in * 0;
		//		FirstInHole[i - 1] = 0;//只判断一次
		//		
		//	}
		//}
		for (i = 9; i <= 15; i++)
		{
			if (BallMessage[i].status==0 && FirstInHole[i - 1])//先手方将后手方的球击入，球权转让
			{
				
				wrong = wrong * 0;
				FirstInHole[i - 1] = 0;//只判断一次
			}
		}
	case -1:
		for (i = 1; i <= 7; i++)
		{
			if (BallMessage[i].status==0 && FirstInHole[i - 1])//后手方将先手方的球击入，球权转让
			{
				
				wrong = wrong * 0;
				FirstInHole[i - 1] = 0;
			}
		}
		//for (i = 9; i <= 15; i++)
		//{
		//	if (!BallMessage[i].status && FirstInHole[i - 1])
		//	{

		//		in = in * 0;
		//		FirstInHole[i - 1] = 0;//只判断一次
		//	}
		//}
	}
	if (in==1||wrong==0)
		order = -order;

}
int WhiteBallInHole()//白球进洞，球权转让，白球回归默认位置
{
	if (BallMessage[0].status == 0)
	{
		SetWhiteBallMessage(6, 5, 0, 0);
		order = -order;
		return 1;
	}
	else
		return 0;
}

void changeorder()//判断交换球权的函数
{
	static int judge1 = 1;//判断是否是球停后第一次判断
	static firsthit1 = 1;//判断是否为最开始
	
		
		if (IfBallStop(16) && judge1)
		{
			if (!firsthit1)
			{
				if (!WhiteBallInHole())//执行白球判断就不执行其他球的犯规判断
				checkwronghit();
				judge1 = 0;
			}
		}
		else if (!IfBallStop(16))
		{
			judge1 = 1;
			firsthit1 = 0;
		}
	
}

void win()//判定获胜条件
{
	int i;
	int judge = 1;
	if (order == 1)
	{
		for (i = 1; i <= 7; i++)
		{
			
				judge = judge * (!BallMessage[i].status);//为1时球都进
			
		}
		if (!judge)
		{
			if (!BallMessage[8].status)
			{
			drawBox(14.5, 0, 1.5, 0.5, 0, "后手赢", 1, "RED");
				
			}
		}
		else
			drawBox(14.5, 0, 1.5, 0.5, 0, "先手赢", 1, "RED");
	}
	if (order == -1)
	{
		for (i = 9; i <= 15; i++)
		{
			
			
				judge = judge * (!BallMessage[i].status);
			
		}
		if (!judge)
		{
			if (!BallMessage[8].status)
			{
				
				drawBox(14.5, 0, 1.5, 0.5, 0, "先手赢", 1, "RED");
				
			}
		}
		else
			drawBox(14.5, 0, 1.5, 0.5, 0, "后手赢", 1, "RED");
	}
}
void game1interfacebutton()
{
	
	DisplayClear();
	if (button(GenUIID(0), GetWindowWidth() / 2 - 1, GetWindowHeight() * 2 / 3 - 1, 1.5, 0.5, "开始游戏"))
	{

		StartGame_1();

	}
	if (button(GenUIID(0), GetWindowWidth() / 2 - 1, GetWindowHeight() / 3, 1.5, 0.5, "说明"))
	{
		DisplayClear();
		drawBox(3, 8, 10, 0.5, 0, "双人游戏，先手击1~7号球，后手击9~15号球", 1, "RED");
		drawBox(3, 7, 10, 0.5, 0, "把对方的球击入或击入白球，球权转让", 1, "RED");
		drawBox(3, 6, 10, 0.5, 0, "没击完自己的球击8号球，对手获胜，先击完自己的球者获胜", 1, "RED");


	}
	if (button(GenUIID(0), GetWindowWidth() - 2, GetWindowHeight() - 1, 1.5, 0.5, "回到第二层"))
	{
		game1interface();
	}
	if (button(GenUIID(0), GetWindowWidth() - 2, GetWindowHeight() - 2, 1.5, 0.5, "回到第一层"))
	{
		cancelMouseEvent();
		DrawInterface();
	}
}
void Game1InterfaceMouseEvent(int x, int y, int button, int event)
{
	uiGetMouse(x, y, button, event);
	game1interfacebutton();
}
void game1interface()
{
	
	cancelMouseEvent();
	DisplayClear();
	registerMouseEvent(Game1InterfaceMouseEvent);
}
void StartGame_1()
{
	BallQuantity_TEST=16;//球的个数为16
	PlaySort = 1;//调为第一种玩法
	cancelMouseEvent();
	SetBallMessage1();//测试用
	//SetWindowSize(16, 9);
	//InitGraphics();
	registerTimerEvent(BallRun);
	registerMouseEvent(MouseEventProcess);
	startTimer(DisplayTimer, ImageRefreshInterval);

	//registerMouseEvent(MouseEventProcess);
}

