//��ģ�����ڻ���Ϸ�ĳ�ʼ����
//**********************
#pragma warning(disable:4996)

#include "basic_message.h"
#include "game1.h"

void DrawInterfaceButton()	//����ʼ����İ�ť(δ��)
{
	if (button(GenUIID(0), GetWindowWidth() / 2-1, GetWindowHeight() * 2 / 3, 1.5, 0.5, "�淨1"))
	{
		game1interface();
		
	}
	if (button(GenUIID(0), GetWindowWidth() / 2 - 1, GetWindowHeight()/2, 1.5, 0.5, "�淨2"))
	{
		game2interface();

	}

}
void InterfaceMouseEvent(int x, int y, int button, int event)
{
	uiGetMouse(x, y, button, event);
	DrawInterfaceButton();
}
void DrawInterface()//����ʼ�Ľ������棨ѡ�淨��
{
	SetWindowSize(16, 9);
	InitGraphics();
	registerMouseEvent(InterfaceMouseEvent);
}

