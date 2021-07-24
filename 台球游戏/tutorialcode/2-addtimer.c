//===========================================================================
//
//  ��Ȩ�����ߣ� ���¹����㽭��ѧ�������ѧ�뼼��ѧԺ
//                       CAD&CG�����ص�ʵ����
//               xgliu@cad.zju.edu.cn
//  ����޸ģ�2020��3��25�� 
//  ���δ�����2020��3��21�գ�����<<�������ר��>>�γ̽�ѧ
//
//===========================================================================

/**************************************************************

1. ����������ʱ�����ֱ����ͼ�ε�λ��

***************************************************************/
#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <math.h>
#include"imgui.h"
#define TABLE_WIDTH 8 //WIDTHΪ���ӳ� 
#define TABLE_LENGTH 5  //LENGTHΪ���ӿ�  ����д���� 0.0 
#define GAP 0.8 //GAPΪ����κ��ھ��γ��Ĳ�ֵ 
#define fx 1 //���¶��� x���� 
#define fy 1 //���¶���y���� 
#define  MARK "0.0" //�����Ʒ֣�����Ʒֺ��� 

void DrawHole(double x, double y, double R, double start, double end, char* color) //���� 
{
	mySetPenColor(color);
	MovePen(x, y);
	StartFilledRegion(1);
	DrawArc(R, start, end);
	EndFilledRegion();
	mySetPenColor("Black");
}

void DrawTableFrame()
{
	mySetPenColor("BROWN");
	drawRectangle(fx, fy, TABLE_WIDTH, TABLE_LENGTH, 1);
	mySetPenColor("CHOCOLATE");
	drawRectangle(fx + GAP / 8, fy + GAP / 8, TABLE_WIDTH - GAP / 4, TABLE_LENGTH - GAP / 4, 1);
	mySetPenColor("TAN");
	drawRectangle(fx + GAP / 4, fy + GAP / 4, TABLE_WIDTH - GAP / 2, TABLE_LENGTH - GAP / 2, 1);
	mySetPenColor("SIENNA");
	drawRectangle(fx + 3 * GAP / 8, fy + 3 * GAP / 8, TABLE_WIDTH - 3 * GAP / 4, TABLE_LENGTH - 3 * GAP / 4, 1);
	mySetPenColor("FORESTGREEN");
	drawRectangle(fx + GAP / 2, fy + GAP / 2, TABLE_WIDTH - GAP, TABLE_LENGTH - GAP, 1); //ʵ�ֽ���ɫ�ı߿� 
}

//void SetCueStorage(void) //��������˴�
//{
////	MovePen(0.3, 0.5);
//	SetPenColor("Brown");
//	drawRectangle(0, 1, 0.3, 0.2, 1);
//	SetPenColor("White");
//	MovePen(0.15 + 0.05, 1.2);
//	StartFilledRegion(1);
//	DrawArc(0.05, 0, -180);
//	DrawLine(0.1, 0);
//	EndFilledRegion();
//	SetPenColor("Brown");
//	drawRectangle(0, 4.5, 0.3, 0.1, 1);
//	MovePen(0.15, 4.5);
//	SetPenColor("Black");
//	DrawLine(0, -0.4);
void Main()
{
	InitGraphics();
	DrawTableFrame(); //�����ӵĿ�� 
	DrawHole(fx + 0.45, fy + 0.3, 0.2, 0, 360, "BLACK");
	DrawHole(fx + 0.45, fy + TABLE_LENGTH - 0.3, 0.2, 0, 360, "BLACK");
	DrawHole(fx + TABLE_WIDTH / 2 + 0.2, fy + 0.2, 0.2, 0, 360, "BLACK");
	DrawHole(fx + TABLE_WIDTH / 2 + 0.2, fy + TABLE_LENGTH - 0.3, 0.2, 0, 360, "BLACK");
	DrawHole(fx + TABLE_WIDTH - 0.055, fy + 0.3, 0.2, 0, 360, "BLACK");
	DrawHole(fx + TABLE_WIDTH - 0.05, fy + TABLE_LENGTH - 0.3, 0.2, 0, 360, "BLACK");  //��̨������������
	button(1, 3, 0.3, 1.5, 0.5, "������Ϸ");
	button(1, 6, 0.3, 1.5, 0.5, "�浵");
	mySetPenColor("BROWN");
	drawBox(fx + TABLE_LENGTH / 2 + 1, fy + TABLE_WIDTH / 2 + 1.1, 1.5, 0.5, 0, "MARK", 1, "RED");
	//	SetCueStorage(); 



}
//#include "graphics.h"
//#include "extgraph.h"
//#include "imgui.h"
//#include "test.h"
//double box_x = 1.0;
//double box_y = 1.0;
//double label_x = 1.0;
//double label_y = 1.0;
//
//void display()
//{
//	double w = 1.0;
//	double h = GetFontHeight() * 2;
//	// �����Ļ
//	DisplayClear();
//	// draw a square
//	SetPenColor("Red");
//	drawLabel(label_x, label_y, "Lable is Here");
//	// ȡ�������ע�ͣ�draw ����Ķ���
//	//drawRectangle(x, y += h*1.2, w, h, 0);
//	//SetPenColor("Red"); drawBox(x, y += h*1.2, w, h, 0, "Box is here", 'c', "Green");
//	SetPenColor("Blue"); drawBox(box_x, box_y, w, h, 1, "Filled Box is here", 'c', "Green");
//}
//
//typedef enum {
//	LabelTimer,
//	BoxTimer,
//} MyTimer;
//
//void mytimer(int  timerID)
//{
//	switch (timerID)
//	{
//	case LabelTimer:
//		label_x += 0.05;
//		if (label_x > 5.0) 
//			label_x = 1.0;
//		display();
//		break;
//	case BoxTimer:
//		box_y += 0.5;
//		if (box_y > 5.0) box_y = 1.0;
//		display();
//		break;
//		break;
//	}
//}


//void Main()
//{
//	InitGraphics();
//	//InitConsole();
//	double initx, inity;//��һ����ĳ�ʼλ��
//	initx = GetWindowWidth() / 2;
//	inity = GetWindowHeight() / 2;
//	int d, e;
//	double x = initx - BallRadius * 1.72;
//	double y = inity;
//	int count ;
//	for (d = 1; d <= 5; d++)
//	{
//		x = x + BallRadius * 1.72;
//		y = inity + (d - 1) * BallRadius ;
//		for (e = 0; e < d; e++)
//		{
//			count = (d-1)*d /2+ e+1;
//			BallMessage[count].x = x;
//			BallMessage[count].y = y;
//			BallMessage[count].speed_x = 0;
//			BallMessage[count].speed_y = 0;
//			BallMessage[count].status = 1;
//			printf("%lf %lf %d %d %d\n", BallMessage[count].x, BallMessage[count].y,count,d,e);
//			y = y - 2*BallRadius;
//		}
//	}
	/*int i;
	for (i = 1; i <= 10; i++)
	{
		printf("%lf %lf\n", BallMessage[i].x, BallMessage[i].y);
	}*/
	//return 0;
	/*MovePen(BallMessage[1].x + BallRadius, BallMessage[1].y);
	DrawArc(BallRadius, 0, 360);
	MovePen(BallMessage[2].x + BallRadius, BallMessage[2].y);
	DrawArc(BallRadius, 0, 360);
	MovePen(BallMessage[3].x + BallRadius, BallMessage[3].y);
	DrawArc(BallRadius, 0, 360);
	MovePen(BallMessage[6].x + BallRadius, BallMessage[6].y);
	DrawArc(BallRadius, 0, 360);
	MovePen(BallMessage[10].x + BallRadius, BallMessage[10].y);
	DrawArc(BallRadius, 0, 360);*/
	//for (d = 1; d <= 15; d++)
	//{
	//	MovePen(BallMessage[d].x + BallRadius, BallMessage[d].y);
	//	DrawArc(BallRadius, 0, 360);
	//	
	//}
	/*registerTimerEvent(mytimer);
	startTimer(LabelTimer, 1);
	startTimer(BoxTimer, 2);*/

	//display();
//}