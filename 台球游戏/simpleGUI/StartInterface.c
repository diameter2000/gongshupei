//本模块用于画游戏的初始界面
//**********************
#pragma warning(disable:4996)

#include "basic_message.h"
#include "game1.h"

void DrawInterfaceButton()	//画初始界面的按钮(未完)
{
	if (button(GenUIID(0), GetWindowWidth() / 2-1, GetWindowHeight() * 2 / 3, 1.5, 0.5, "玩法1"))
	{
		game1interface();
		
	}
	if (button(GenUIID(0), GetWindowWidth() / 2 - 1, GetWindowHeight()/2, 1.5, 0.5, "玩法2"))
	{
		game2interface();

	}

}
void InterfaceMouseEvent(int x, int y, int button, int event)
{
	uiGetMouse(x, y, button, event);
	DrawInterfaceButton();
}
void DrawInterface()//画开始的交互界面（选玩法）
{
	SetWindowSize(16, 9);
	InitGraphics();
	registerMouseEvent(InterfaceMouseEvent);
}

