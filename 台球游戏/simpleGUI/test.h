//本模块用于测试
//**********************
#pragma once
#pragma once
#ifndef TEST
#define TEST
#include "basic_message.h"
//#define BallQuantity_TEST 16	//球的数量
#define SPEED_DECREASE 0.0002
void SetBallMessage1();//测试用，设定球的初始信息
void SetWhiteBallMessage(double x, double y, double speed_x, double speed_y);//设定白球的横坐标，纵坐标，横向速度，纵向速度
#endif