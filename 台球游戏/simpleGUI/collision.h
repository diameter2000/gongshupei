/*本模块用于实现碰撞*/
/*=====================================================================================*/
#pragma once
#ifndef COLLISION
#define COLLISION

void Collision_WithTable(int BallQuantity);	//球与球桌边界碰撞,参数为球的个数
void Collision_WithBall(int BallQuantity); //球与球碰撞
#endif