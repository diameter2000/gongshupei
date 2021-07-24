/*¸ÃÄ£¿éÓÃÓÚ»­¸÷Àà¾²Ö¹Í¼Ïñ*/
#include "basic_message.h"
#include "TableBlackground.h"
#include "cuenewest.h"

	
	//MovePen(TableLeftBoundary, TableLowBoundary);
	//DrawLine(0, TableHighBoundary - TableLowBoundary);
	//DrawLine(TableRightBoundary - TableLeftBoundary, 0);
	//MovePen(TableLeftBoundary, TableLowBoundary);
	//DrawLine(TableRightBoundary - TableLeftBoundary, 0);
	//DrawLine(0, TableHighBoundary - TableLowBoundary);


void DrawOneBall1(int BallNumber)//Íæ·¨Ò»»­Çò
{
	if (BallMessage[BallNumber].status == 1)
	{
		MovePen(BallMessage[BallNumber].x + BallRadius, BallMessage[BallNumber].y);

		char *number ;
		switch (BallNumber)
		{
		case 0:SetPenColor ("White"); number = ""; break;
		case 1:SetPenColor("Yellow2"); number = "1"; break;
		case 2:SetPenColor("Blue3"); number = "2"; break;
		case 3:SetPenColor("Red"); number = "3"; break;
		case 4:SetPenColor("Purple"); number = "4"; break;
		case 5:SetPenColor("Orange"); number = "5"; break;
		case 6:SetPenColor("SeaGreen"); number = "6"; break;
		case 7:SetPenColor("Tomato"); number = "7"; break;
		case 8:SetPenColor("Black"); number = "8"; break;
		case 9:SetPenColor("Yellow2"); number = "9"; break;
		case 10:SetPenColor("Blue3"); number = "10"; break;
		case 11:SetPenColor("Red"); number = "11"; break;
		case 12:SetPenColor("Purple"); number = "12"; break;
		case 13:SetPenColor("Orange"); number = "13"; break;
		case 14:SetPenColor("SeaGreen"); number = "14"; break;
		case 15:SetPenColor("Tomato"); number = "15"; break;
		}
		
		StartFilledRegion(1);
		//DrawArc(BallRadius, 0, 180);
		DrawArc(BallRadius, 0, 360);
		EndFilledRegion();
		SetPenColor("Black");//Ãè±ß
		DrawArc(BallRadius, 0, 360);//Ãè±ß
		SetPenColor("White");
		MovePen(BallMessage[BallNumber].x + BallRadius / 2, BallMessage[BallNumber].y);
		StartFilledRegion(1);
		DrawArc(BallRadius/2, 0, 360);
		EndFilledRegion();
		SetPenColor("Black");
		if (BallNumber)//ÃèÄÚ±ß
		{
			MovePen(BallMessage[BallNumber].x + BallRadius / 2 + 0.01, BallMessage[BallNumber].y);
			DrawArc(BallRadius / 2 + 0.01, 0, 360);
		}
		MovePen(BallMessage[BallNumber].x -0.04, BallMessage[BallNumber].y-0.05);
		if(BallNumber>=10)
			MovePen(BallMessage[BallNumber].x - 0.1, BallMessage[BallNumber].y - 0.05);
		DrawTextString(number);

	}
}//»­Ä³Ò»±àºÅµÄÇò
void DrawOneBall2(int BallNumber)//Íæ·¨¶þ»­Çò
{
	if (BallMessage[BallNumber].status == 1)
	{
		MovePen(BallMessage[BallNumber].x + BallRadius, BallMessage[BallNumber].y);
		if(BallNumber==0)
			SetPenColor("White");
		if(BallNumber>=1&& BallNumber<=15)
		SetPenColor("Red");
		else
		{
			switch(BallNumber)
			{
				case 16:SetPenColor("Yellow2"); break;
				case 17:SetPenColor("Green"); break;
				case 18:SetPenColor("Brown"); break;
				case 19:SetPenColor("Blue3"); break;
				case 20:SetPenColor("Purple"); break;
				case 21:SetPenColor("Black"); break;
			}
		}
		StartFilledRegion(1);
		//DrawArc(BallRadius, 0, 180);
		DrawArc(BallRadius, 0, 360);
		EndFilledRegion();
		SetPenColor("Black");//Ãè±ß
		DrawArc(BallRadius, 0, 360);//Ãè±ß
		
		

	}
}
void DrawAllimage(int BallQuantity,int playsort)
{
	SetPenSize(1);
	DisplayClear();
	DrawBackground(playsort);
	
	int c;
	if(playsort==1)
	for (c = 0; c < BallQuantity; c++)
	{
		
		DrawOneBall1(c); 
			
	}
	if(playsort==2)
		for (c = 0; c < BallQuantity; c++)
		{

			DrawOneBall2(c);
		}
	
	if(IfBallStop(BallQuantity))sticktimer();//»­Çò¸Ë
}//»­ËùÓÐÍ¼Ïñ