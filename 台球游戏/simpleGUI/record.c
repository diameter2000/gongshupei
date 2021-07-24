
#pragma warning(disable:4996)


#include "basic_message.h"
#include "test.h"

//int main()
//{
//	FILE *fp=fopen("C:\\Users\\gongs\\Desktop\\testfile.txt", "w");
//	fclose(fp);
//	return 0;
//}

void SaveRecord1(int BallQuantity,char filename[])//´æµµ£¬´æ´¢BallQuantity¸öÇòµÄÊý¾Ý£¨°üÀ¨°×Çò£©
{
	int i;//
	FILE* fp;
	fp = fopen(filename, "w+");
	for (i = 0; i < BallQuantity; i++)//
	{
		fwrite(&(BallMessage[i]), sizeof(struct BALL_MESSAGE), 1, fp);
	}
	//fseek(fp, 0, SEEK_SET);
	fclose(fp);
}
void ReadRecord1(int BallQuantity, char filename[])//¶Áµµ
{
	int i;//
	FILE* fp;
	fp = fopen(filename, "r");
	for (i = 0; i < BallQuantity; i++)//
	{
		fread(&(BallMessage[i]), sizeof(struct BALL_MESSAGE), 1, fp);
	}
	fclose(fp);
}
//int main()
//{
//
//	SetBallMessage();
//	SaveRecord1();
//	ReadRecord1();
//	printf("%lf %lf %lf %lf %d", BallMessage[2].x, BallMessage[2].y, BallMessage[2].speed_x, BallMessage[2].speed_y, BallMessage[2].status);
//	
//}

