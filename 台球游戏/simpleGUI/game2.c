#include "ball.h"
#include "cuenewest.h"
#include "basic_message.h"
#include "StartInterface.h"
extern int BallQuantity_TEST;
extern int PlaySort;
int discount = 0;
void game2interface();
void StartGame_2();
int judge()//�жϺ����Ƿ��Ѿ��������Ƿ���1�����Ƿ���0
{
	int j;
	int judge=1;
	for (j = 1; j <= 15; j++)
	{
		judge = judge*(!BallMessage[j].status);
	}
	return judge;
}
int CountScore_2()
{
	int i;
	int score = 0;
	score = score-discount ;
	discount = 0;
	for (i = 1; i <= 21; i++)
	{
		if (i >= 1 && i <= 15)
			score = score + (!BallMessage[i].status);
		else if(judge())
			switch (i)
			{
			case 16:score=score + 2* (!BallMessage[i].status);
			case 17:score= score + 3 * (!BallMessage[i].status);
			case 18:score = score + 4 * (!BallMessage[i].status);
			case 19:score = score + 5 * (!BallMessage[i].status);
			case 20:score = score + 6 * (!BallMessage[i].status);
			case 21:score = score + 7 * (!BallMessage[i].status);
			}
		
				
	}
	return score;
}
int WhiteBallInHole2()//�����������Ȩת�ã�����ع�Ĭ��λ��
{
	if (BallMessage[0].status == 0)
	{
		SetWhiteBallMessage(3, 5, 0, 0);
		return 1;
	}
	else
		return 0;
}
void checkwronghit2()//�������ǰ�����򣬸�λ���۷�
{
	int i;
	//if(!judge())
	for (i = 16; i <= 21; i++)
	{
		if (BallMessage[i].status == 0)
		{
			
			switch (i)
			{
			case 16:
				discount++;
				BallMessage[16].x = 4.5;
				BallMessage[16].y = 3.5;
				BallMessage[16].speed_x = 0;
				BallMessage[16].speed_y = 0;
				BallMessage[16].status = 1; break;
			case 17:
				discount++;
				BallMessage[17].x = 4.5;
				BallMessage[17].y = 6.5;
				BallMessage[17].speed_x = 0;
				BallMessage[17].speed_y = 0;
				BallMessage[17].status = 1; break;
			case 18:
				discount++;
				BallMessage[18].x = 4.5;
				BallMessage[18].y = 5;
				BallMessage[18].speed_x = 0;
				BallMessage[18].speed_y = 0;
				BallMessage[18].status = 1; break;
			case 19:
				discount++;
				BallMessage[19].x = 7.5;
				BallMessage[19].y = 5;
				BallMessage[19].speed_x = 0;
				BallMessage[19].speed_y = 0;
				BallMessage[19].status = 1; break;
			case 20:
				discount++;
				BallMessage[20].x = 11 - 0.9;
				BallMessage[20].y = 5;
				BallMessage[20].speed_x = 0;
				BallMessage[20].speed_y = 0;
				BallMessage[20].status = 1;
			case 21:
				discount++;
				BallMessage[21].x = 11 + 2.5;
				BallMessage[21].y = 5;
				BallMessage[21].speed_x = 0;
				BallMessage[21].speed_y = 0;
				BallMessage[21].status = 1; break;
			}
		}
	}
}
void game2interfacebutton()
{
	if (button(GenUIID(0), GetWindowWidth() / 2 - 1, GetWindowHeight() * 2 /3-1, 1.5, 0.5, "��ʼ��Ϸ"))
	{

		StartGame_2();

	}
	if (button(GenUIID(0), GetWindowWidth() / 2 - 1, GetWindowHeight() / 3, 1.5, 0.5, "˵��"))
	{
		DisplayClear();
		drawBox(3 , 8, 10, 0.5, 0, "���������ܻ�����", 1, "RED");
		drawBox(3, 7, 10, 0.5, 0, "��1�֣���2�֣���3�֣���4�֣���5�֣���6�֣���7��", 1, "RED");
		drawBox(3, 6, 10, 0.5, 0, "û�����������򣬲���λ����һ��", 1, "RED");

		
	}
	if (button(GenUIID(0), GetWindowWidth()-2 , GetWindowHeight()-1, 1.5, 0.5, "�ص��ڶ���"))
	{
		game2interface();
	}
	if (button(GenUIID(0), GetWindowWidth() - 2, GetWindowHeight() - 2, 1.5, 0.5, "�ص���һ��"))
	{
		cancelMouseEvent();
		DrawInterface();
	}
}
void Game2InterfaceMouseEvent(int x, int y, int button, int event)
{
	uiGetMouse(x, y, button, event);
	game2interfacebutton();
}
void game2interface()
{
	
	cancelMouseEvent();
	DisplayClear();
	registerMouseEvent(Game2InterfaceMouseEvent);
}
void StartGame_2()
{

	BallQuantity_TEST = 22;//��ĸ���Ϊ16
	PlaySort = 2;//��Ϊ��һ���淨
	cancelMouseEvent();
	SetBallMessage2();//������
	//SetWindowSize(16, 9);
	//InitGraphics();
	registerTimerEvent(BallRun);
	registerMouseEvent(MouseEventProcess);
	startTimer(DisplayTimer, ImageRefreshInterval);

	//registerMouseEvent(MouseEventProcess);
}