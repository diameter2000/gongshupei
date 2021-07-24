//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <stddef.h>
//#include "graphics.h"
//#include "genlib.h"
//#include "conio.h"
//
//#include <windows.h>
//#include <olectl.h>
//#include <stdio.h>
//#include <mmsystem.h>
//#include <wingdi.h>
//#include <ole2.h>
//#include <ocidl.h>
//#include <winuser.h>
//#define CUELENGTH 3
//
//extern double winwidth, winheight; 
//extern double fh;
//
//void FillTable(double x, double y, double width, double height)
//{
//	mySetPenColor("Dark Green");
//	double i = 0;
//
//	while (i < width)
//	{
//		MovePen(x + i, y);
//		DrawLine(0, height);
//		i += 0.01;
//	}
//
//	mySetPenColor("Black");
//}
//
//void DrawHole(double x, double y, double R, double start, double end, char *color)
//{
//	mySetPenColor(color);
//	MovePen(x, y);
//	StartFilledRegion(1);
//	DrawArc(R, start, end);
//	EndFilledRegion();
//	mySetPenColor("Black");
//}
//
//void DrawCorner()
//{
//	DrawHole(1, 0.5, 0.3, 0, 360, "Yellow");
//	DrawHole(winwidth-0.5, 0.5, 0.3, 0, 360, "Yellow");
//	DrawHole(1, winheight-1.8, 0.3, 0, 360, "Yellow");
//	DrawHole(winwidth-0.5, winheight-1.8, 0.3, 0, 360, "Yellow");	
//}
//
//void FillFrame(double x, double y, double Width, double Xlength, double Ylength)	//从里到外以此为Chestnut、Tan、Brown 
//{
//	mySetPenColor("Chestnut");
//		drawRectangle(x, y+0.2, Xlength, Width/3, 1);
//		drawRectangle(x, y+Ylength+0.3, Xlength, Width/3, 1);
//		drawRectangle(x+Xlength, y+0.3, Width/3, Ylength, 1);
//		drawRectangle(x-0.1, y+0.3, Width/3, Ylength, 1);
//	mySetPenColor("Tan");
//		drawRectangle(x, y+0.1, Xlength, Width/3, 1);
//		drawRectangle(x, y+Ylength+0.4, Xlength, Width/3, 1);
//		drawRectangle(x+Xlength+0.1, y+0.3, Width/3, Ylength, 1);
//		drawRectangle(x-0.2, y+0.3, Width/3, Ylength, 1);
//	mySetPenColor("Brown");	
//		drawRectangle(x, y, Xlength, Width/3, 1);
//		drawRectangle(x, y+Ylength+0.5, Xlength, Width/3, 1);
//		drawRectangle(x+Xlength+0.2, y+0.3, Width/3, Ylength, 1);
//		drawRectangle(x-0.3, y+0.3, Width/3, Ylength, 1);	
//	mySetPenColor("Black");
//}
//
//void SetScoreTable()
//{
//	char c='A';
//	double width, height;
//	width=GetWindowWidth();
//	height=GetWindowHeight(); 
//	mySetPenColor("Red");
//	drawBox(width/4, height-1, 1, 0.6, 0, "P1:等待后续", c, "Blue");
//	drawBox(width*3/4, height-1, -1, 0.6, 0, "P2:等待后续", c, "Red");
//	mySetPenColor("Black");
// } 
//
//void DrawFrame()
//{
//	mySetPenColor("Black");
//	double Width, Height;
//	Width=GetWindowWidth();
//	Height=GetWindowHeight(); 
//	SetPenSize(2);	//加粗加粗 
//		DrawHole(1, 0.5, 0.22, 0, 360, "Black");
//		DrawHole(Width-0.6, 0.5, 0.22, 0, 360, "Black");
//		DrawHole((Width-0.6+1)/2, 0.5, 0.22, 0, 360, "Black");
//		DrawHole(Width-0.6, Height-1.8, 0.22, 0, 360, "Black");
//		DrawHole((Width-0.6+1)/2, Height-1.8, 0.22, 0, 360, "Black"); 
//		DrawHole(1, Height-1.8, 0.22, 0, 360, "Black"); 
//	MovePen(0.7, 0.2);	//画边框 
//		DrawLine(Width-1.5, 0);
//		DrawLine(0, Height-1.7);
//		DrawLine(1.5-Width, 0);
//		DrawLine(0, 1.7-Height);
//	MovePen(0.4, 0.5);
//		DrawLine(Width-0.9, 0);
//		DrawLine(0, Height-2.3);
//		DrawLine(0.9-Width, 0);
//		DrawLine(0, 2.3-Height);
//	SetPenSize(1); 
//}
//
//void FillRTTriangle(double x, double y, double a, int shape, char *color)	//等腰直角三角形填充
//{
//	mySetPenColor(color);
//	double i=0;
//	switch(shape)
//	{
//		case 1:	//顶点在左下
//			while(i<=a)
//			{
//				MovePen(x, y+i);
//				DrawLine(a-i, 0);
//				i+=0.01;
//			};break;
//		case 2:	//顶点在右下
//			while(i<=a)
//			{
//				MovePen(x, y+i);
//				DrawLine(i-a, 0);
//				i+=0.01;
//			};break;
//		case 3:	//顶点在右上
//			while(i<=a)
//			{
//				MovePen(x, y-i);
//				DrawLine(i-a, 0);
//				i+=0.01;
//			};break;
//		case 4:	//顶点在左下
//			while(i<=a)
//			{
//				MovePen(x, y-i);
//				DrawLine(a-i, 0);
//				i+=0.01;
//			};break;
//			
//		default :break;
//	}
//	mySetPenColor("Black");
//}
//
//void DrawInterFrame()
//{
//	double Width, Height;
//	Width=GetWindowWidth();
//	Height=GetWindowHeight(); 
//	mySetPenColor("Green");
//	FillRTTriangle(0.7, Height-2.2, 0.1, 1, "Green");
//		FillRTTriangle(0.7, 0.9, 0.1, 4, "Green");
//		mySetPenColor("Green");
//		drawRectangle(0.7, 0.9, 0.1, 3.9, 1);
//	FillRTTriangle(1.2, Height-1.8, 0.1, 3, "Green");
//		FillRTTriangle((Width-0.6+1)/2-0.6, Height-1.8, 0.1, 4, "Green");
//		mySetPenColor("Green");
//		drawRectangle(1.2, 0.5, 3.3, 0.1, 1);
//	FillRTTriangle(1.2, 0.5, 0.1, 2, "Green");
//		FillRTTriangle((Width-0.6+1)/2-0.7, 0.5, 0.1, 1, "Green");
//		mySetPenColor("Green");
//		drawRectangle(1.2, Height-1.9, 3.4, 0.1, 1);
//	FillRTTriangle((Width-0.6+1)/2+0.2, Height-1.8, 0.1, 3, "Green");
//		FillRTTriangle((Width-0.6+1)/2+0.2, 0.5, 0.1, 2, "Green");
//		mySetPenColor("Green");
//		drawRectangle((Width-0.6+1)/2+0.2, Height-1.9, 3.3, 0.1, 1);
//	FillRTTriangle(Width-1.3, 0.5, 0.1, 1, "Green");
//		FillRTTriangle(Width-1.3, Height-1.8, 0.1, 4, "Green");
//		mySetPenColor("Green");
//		drawRectangle((Width-0.6+1)/2+0.2, 0.5, 3.3, 0.1, 1);
//	FillRTTriangle(Width-0.8, 0.9, 0.1, 3, "Green");
//		FillRTTriangle(Width-0.8, Height-2.2, 0.1, 2, "Green");
//		mySetPenColor("Green");
//		drawRectangle(Width-0.8, 0.9, -0.1, 3.9, 1);
//}
//
//void SetGameTable()	//R=0.2 
//{
//	//double width, height;
//	//width=GetWindowWidth();
//	//height=GetWindowHeight(); 
//	DrawCorner();
//	FillTable(0.7, 0.5, winwidth - 1.5, winheight - 2.3);	//桌面 
//	FillFrame(0.7, 0.2, 0.3, winwidth - 1.5, winheight - 2.3);	//边框 
//	//printf("%.2f, %.2f", width, height);
//	//int size;
//	//size=GetPenSize();
//	//printf("%d\n", size)； 
//	DrawInterFrame();
//	DrawFrame();
//}
//
//void SetCueStorage(void) //画放置球杆处
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
//}
//
//void SetIcon(void) //话菜单图标
//{
//	SetPenColor("Dark Gray");
//	drawRectangle(0, winheight - 0.4, 0.4, 0.4, 1);
//	MovePen(0.08, winheight - 0.1);
//	SetPenSize(2);
//	SetPenColor("White");
//	DrawLine(0.2, 0);
//	MovePen(0.08, winheight - 0.2);
//	DrawLine(0.2, 0);
//	MovePen(0.08, winheight - 0.3);
//	DrawLine(0.2, 0);
//	SetPenSize(1);
//}
//
//void star(void)
//{
//	MovePen(1, winheight-0.5);
//	drawstars("Yellow", 30, 0.5);
//}
//
//void SetGameInterface()
//{
//	SetPenColor("Background");
//	drawRectangle(0, 0, winwidth, winheight ,1);
//	SetGameTable();
////	SetScoreTable();
//	SetCueStorage();
//	SetIcon();
//	//star();
//}

