#include "ball.h"
#include "cuenewest.h"
extern int PlaySort;
extern int  BallQuantity_TEST;

int order = 1;//��Ȩ������1�������֣�-1��������
int FirstInHole[15]={ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
void game1interface();
void Game1InterfaceMouseEvent(int x, int y, int button, int event);
void StartGame_1();
int CountScore1()//�������ַ���
{
	int i;
	int score = 0;
	for (i = 1; i <= 7; i++)
	{
		
		score = score + (!BallMessage[i].status);
	}
	return score;
}
int CountScore2()//������ַ���
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
	int in = 1;//���غϻ����Ƿ���Լ�����0Ϊ����1Ϊ����
	int wrong = 1;//���غϻ����Ƿ���Է�����0Ϊ����1Ϊ����
	switch (order)
	{
	case 1:
		//for (i = 1; i <= 7; i++)
		//{
		//	if (!BallMessage[i].status && FirstInHole[i - 1])//���ַ�û�����Լ�������Ȩת��
		//	{
		//		in = in * 0;
		//		FirstInHole[i - 1] = 0;//ֻ�ж�һ��
		//		
		//	}
		//}
		for (i = 9; i <= 15; i++)
		{
			if (BallMessage[i].status==0 && FirstInHole[i - 1])//���ַ������ַ�������룬��Ȩת��
			{
				
				wrong = wrong * 0;
				FirstInHole[i - 1] = 0;//ֻ�ж�һ��
			}
		}
	case -1:
		for (i = 1; i <= 7; i++)
		{
			if (BallMessage[i].status==0 && FirstInHole[i - 1])//���ַ������ַ�������룬��Ȩת��
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
		//		FirstInHole[i - 1] = 0;//ֻ�ж�һ��
		//	}
		//}
	}
	if (in==1||wrong==0)
		order = -order;

}
int WhiteBallInHole()//�����������Ȩת�ã�����ع�Ĭ��λ��
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

void changeorder()//�жϽ�����Ȩ�ĺ���
{
	static int judge1 = 1;//�ж��Ƿ�����ͣ���һ���ж�
	static firsthit1 = 1;//�ж��Ƿ�Ϊ�ʼ
	
		
		if (IfBallStop(16) && judge1)
		{
			if (!firsthit1)
			{
				if (!WhiteBallInHole())//ִ�а����жϾͲ�ִ��������ķ����ж�
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

void win()//�ж���ʤ����
{
	int i;
	int judge = 1;
	if (order == 1)
	{
		for (i = 1; i <= 7; i++)
		{
			
				judge = judge * (!BallMessage[i].status);//Ϊ1ʱ�򶼽�
			
		}
		if (!judge)
		{
			if (!BallMessage[8].status)
			{
			drawBox(14.5, 0, 1.5, 0.5, 0, "����Ӯ", 1, "RED");
				
			}
		}
		else
			drawBox(14.5, 0, 1.5, 0.5, 0, "����Ӯ", 1, "RED");
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
				
				drawBox(14.5, 0, 1.5, 0.5, 0, "����Ӯ", 1, "RED");
				
			}
		}
		else
			drawBox(14.5, 0, 1.5, 0.5, 0, "����Ӯ", 1, "RED");
	}
}
void game1interfacebutton()
{
	
	DisplayClear();
	if (button(GenUIID(0), GetWindowWidth() / 2 - 1, GetWindowHeight() * 2 / 3 - 1, 1.5, 0.5, "��ʼ��Ϸ"))
	{

		StartGame_1();

	}
	if (button(GenUIID(0), GetWindowWidth() / 2 - 1, GetWindowHeight() / 3, 1.5, 0.5, "˵��"))
	{
		DisplayClear();
		drawBox(3, 8, 10, 0.5, 0, "˫����Ϸ�����ֻ�1~7���򣬺��ֻ�9~15����", 1, "RED");
		drawBox(3, 7, 10, 0.5, 0, "�ѶԷ�����������������Ȩת��", 1, "RED");
		drawBox(3, 6, 10, 0.5, 0, "û�����Լ������8���򣬶��ֻ�ʤ���Ȼ����Լ������߻�ʤ", 1, "RED");


	}
	if (button(GenUIID(0), GetWindowWidth() - 2, GetWindowHeight() - 1, 1.5, 0.5, "�ص��ڶ���"))
	{
		game1interface();
	}
	if (button(GenUIID(0), GetWindowWidth() - 2, GetWindowHeight() - 2, 1.5, 0.5, "�ص���һ��"))
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
	BallQuantity_TEST=16;//��ĸ���Ϊ16
	PlaySort = 1;//��Ϊ��һ���淨
	cancelMouseEvent();
	SetBallMessage1();//������
	//SetWindowSize(16, 9);
	//InitGraphics();
	registerTimerEvent(BallRun);
	registerMouseEvent(MouseEventProcess);
	startTimer(DisplayTimer, ImageRefreshInterval);

	//registerMouseEvent(MouseEventProcess);
}

