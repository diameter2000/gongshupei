/*��һ���淨*/
/*=====================================================================================*/
#pragma once
#ifndef BALL
#define BALL
#include "basic_message.h"
#include "test.h"
#include "basic_image.h"
#include "collision.h"
#include "TableBlackground.h"

void BallRun(int timerID);//ʵ����ȫ���˶���ʱ��ص�����
//void StartGame_1();	//��ʼ�淨һ//�����ڲ��Խ׶Σ���û����ȫ��ɣ�
void MouseEventProcess(int x, int y, int button, int event);
int IfBallStop(int BallQuantity);
#endif