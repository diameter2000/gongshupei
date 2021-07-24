/*第一种玩法*/
/*=====================================================================================*/
#pragma once
#ifndef BALL
#define BALL
#include "basic_message.h"
#include "test.h"
#include "basic_image.h"
#include "collision.h"
#include "TableBlackground.h"

void BallRun(int timerID);//实现球全部运动的时间回调函数
//void StartGame_1();	//开始玩法一//（处于测试阶段，还没有完全完成）
void MouseEventProcess(int x, int y, int button, int event);
int IfBallStop(int BallQuantity);
#endif