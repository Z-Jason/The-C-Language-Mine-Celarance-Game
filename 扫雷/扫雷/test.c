#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include "game.h"
//���׵���Ϸ�˵�
void menu()
{
	puts("--------------------------\n");
	puts("------ѡ��1��ʼ��Ϸ-------\n");
	puts("------ѡ��0�˳���Ϸ-------\n");
	puts("--------------------------\n");
}
void game()
{
	//��Ҫ��Ϣ�Ĵ洢
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11,��ֹ���
	//2.�Ų���׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	IntBoard(mine, ROWS, COLS, '0');
	IntBoard(show, ROWS, COLS, '*');
	//��ӡ�׵���Ϣ
	//puts("���ú��׵���Ϣ:");
	//DisplayBoard(mine, ROW, COL);
	puts("\n");
	puts("�Ų�����Ϣ:");
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);
	
}   
//������Ϸ
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼɨ����Ϸ>\n");
			puts("\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ������ѡ��!\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}
int main(void)
{
	test();
	return 0;
}