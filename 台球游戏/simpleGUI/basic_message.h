


/*��ͷ�ļ��а������ֻ�����Ϣ���������õĿ⺯�����ǲ����õĺ궨�塢����ṹ�塢ȫ�ֱ���*/
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
#define TableLeftBoundary 1.5	//�����ı߽� ��
#define TableRightBoundary 14.5//			 ��
#define TableHighBoundary 8	//			 ��
#define TableLowBoundary 1.5	//			 ��
#define BallRadius 0.2	//��İ뾶
#define ImageRefreshInterval 2//ͼ��ˢ��ʱ����
#define STOP -1//�����ж��Ƿ���ͣ��0Ϊ��ͣ��1Ϊ����ͣ
#define CONTINUE 1//�����ж��Ƿ���ͣ��0Ϊ��ͣ��1Ϊ����ͣ
#define DistanceWithHole 0.2//��������жϾ���
typedef enum {
	DisplayTimer,//��ͼ���ʱ��
	StickTimer,	
} MyTimer;

struct BALL_MESSAGE {
	double x;	
	double y;
	double speed_x;
	double speed_y;
	int status;	//���״̬��1��ʾ�ڳ���0��ʾ�³�
}BallMessage[23];//�洢����Ϣ�Ľṹ������


#endif