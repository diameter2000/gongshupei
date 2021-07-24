


/*该头文件中包含各种基本信息，包括引用的库函数、非测试用的宏定义、各类结构体、全局变量*/
/*=====================================================================================*/
#pragma once
#ifndef BASIC_MESSAGE
#define BASIC_MESSAGE
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
//#include "background.c"
#define TableLeftBoundary 1.5	//球桌的边界 左
#define TableRightBoundary 14.5//			 右
#define TableHighBoundary 8	//			 上
#define TableLowBoundary 1.5	//			 下
#define BallRadius 0.2	//球的半径
#define ImageRefreshInterval 2//图像刷新时间间隔
#define STOP -1//用于判断是否暂停，0为暂停，1为不暂停
#define CONTINUE 1//用于判断是否暂停，0为暂停，1为不暂停
#define DistanceWithHole 0.2//球进洞的判断距离
typedef enum {
	DisplayTimer,//画图像的时刻
	StickTimer,	
} MyTimer;

struct BALL_MESSAGE {
	double x;	
	double y;
	double speed_x;
	double speed_y;
	int status;	//球的状态，1表示在场，0表示下场
}BallMessage[23];//存储球信息的结构体数组


#endif