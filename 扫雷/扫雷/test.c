#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include "game.h"
//简易的游戏菜单
void menu()
{
	puts("--------------------------\n");
	puts("------选择1开始游戏-------\n");
	puts("------选择0退出游戏-------\n");
	puts("--------------------------\n");
}
void game()
{
	//需要信息的存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11,防止溢出
	//2.排查好雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	IntBoard(mine, ROWS, COLS, '0');
	IntBoard(show, ROWS, COLS, '*');
	//打印雷的信息
	//puts("布置好雷的信息:");
	//DisplayBoard(mine, ROW, COL);
	puts("\n");
	puts("排查雷信息:");
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
	
}   
//进入游戏
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始扫雷游戏>\n");
			puts("\n");
			game();
			break;
		case 0:
			printf("退出游戏，重新选择!\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}
int main(void)
{
	test();
	return 0;
}