#include <stdio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include"information_test.h"
#include"information.h"
#include<conio.h>
#include"information_function.h"

int main()
{
	SysTitle();
	NodePtr header = 0;
	readFile(&header);
	Node* pCurNode = header;
	NodePtr pNode = 0;
	int acctNum = 1;
	char menuChoice[256];
	char name[256];
	char address[100] = { 0 };
	double balance = 1.0;
	long int number = 1;
	char password[256];
	Node information = { 0 };
	FILE *cfPtr;
	char choice;
	int Admin = 1;
	int choose = 0;

	if ((cfPtr = fopen("credit.dat", "r+")) == NULL)//判断文件是不是已经存在，不存在用w+，存在用r+
	{
		cfPtr = fopen("credit.dat", "w+");
	}
	int flag = 1;
	while (flag)
	{
		printf("\n");
		printf("\t\t\t操作系统的人员是用户还是管理员(0\\1)？\n");
		printf("\t\t\t        请输入数字进行选择\n");
		printf("\t\t\t\t");
		scanf("%d", &choose);
		if (choose == 0 || choose == 1)
		{
			flag = 0;
			break;
		}
		printf("\t\t\t       输入错误，请重新输入\n");
	}
	while (choose != 2)
	{
		if (choose == Admin)
		{
			if (Login() == 1)//管理员账号密码登录
			{
				if ((cfPtr = fopen("credit.dat", "r+")) != NULL)
				{
					int flag = 1;
					while (flag)
					{
						char choice = AdminenterChoice();//管理员界面
						switch (choice)
						{
						case '1':
						{
							FLAG_NODE = 1;
							fputs("\t\t输入** 客户编号**姓名**地址**手机号码**余额:\n", stdout);
							memset(name, 0, 256);
							printf("\t\t\t\t");
							scanf("%d%s%s%ld%lf", &acctNum, &name, &address, &number, &balance);
							insertData(&header, name, address, acctNum, number, balance);
							system("pause");
						}
						break;
						case '2':
						{
							fputs("\t\t\t输入要删除的用户姓名:\n", stdout);
							memset(name, 0, 256);
							printf("\t\t\t\t\t");
							scanf("%s", &name);
							deleteData(&header, name);
							system("pause");
						}
						break;
						case '3':
						{
							UpData(header);
							system("pause");
						}
						break;
						case '4':
						{
							fputs("\t\t输入要寻找的用户姓名:\n", stdout);
							memset(name, 0, 256);
							printf("\t\t\t\t\t");
							scanf("%s", &name);
							if (pNode = findData(&header, name))
							{
								printNodeInfo(pNode);
							}
							else
							{
								printf("\t\t%s 用户的信息没有找到!\n", name);
							}
							system("pause");
						}
						break;
						case '5':
						{
							textFile(header);
							system("pause");
						}
						break;
						case '6':
						{
							Modify(header);
							system("pause");
						}
						break;
						case '7':
						{
							fputs("\t\t\t用户信息的内容为:\n", stdout);
							fputs("\t\t\t用户编号*姓名*地址*手机号码*余额\n", stdout);
							processList(header);
							system("pause");
						}
						break;
						case '8':
						{
							Setting(&header, password);
							system("pause");
						}
						break;
						case '9':
						{
							SysTail();
							flag = 0;
							int Admin = 1;
							int flag = 1;
							while (flag)
							{
								printf("\n");
								printf("\t\t\t操作系统的人员是用户还是管理员(0\\1)？\n");
								printf("\t\t\t        请输入数字进行选择\n");
								printf("\t\t\t\t");
								scanf("%d", &choose);
								if (choose == 0 || choose == 1)
								{
									flag = 0;
									break;
								}
								printf("\t\t\t       输入错误，请重新输入\n");
							}
						}
						}
						if (choice < '0' || choice > '9')
						{
							printf("\t\t\t\t输入错误!\n");
							system("pause");
						}
					}
				}
			}
			else
			{
				SysTail();
				int flag = 1;
				while (flag)
				{
					printf("\n");
					printf("\t\t\t操作系统的人员是用户还是管理员(0\\1)？\n");
					printf("\t\t\t        请输入数字进行选择\n");
					printf("\t\t\t\t");
					scanf("%d", &choose);
					if (choose == 0 || choose == 1)
					{
						flag = 0;
						break;
					}
					printf("\t\t\t       输入错误，请重新输入\n");
					system("pause");
				}
			}
		}
		else
		{
			if (_Login(&header) == 1)//用户账号密码登录
			{
				if ((cfPtr = fopen("credit.dat", "r+")) != NULL)
				{
					Node client;
					fread(&client, sizeof(Node), 1, cfPtr);
					fseek(cfPtr, sizeof(Node), SEEK_CUR);
					int flag = 1;
					while (flag)
					{
						int choice = UserenterChoice();
						switch (choice)
						{
						case '1':
						{
							fputs("\t\t输入要寻找的用户姓名:\n", stdout);
							memset(name, 0, 256);
							printf("\t\t\t\t\t");
							scanf("%s", &name);
							if (pNode = findData(&header, name))
							{
								printNodeInfo(pNode);
							}
							else
							{
								printf("\t\t%s 用户的信息没有找到!\n", name);
							}
							system("pause");
						}
						break;

						case '2':
						{
							Modify(header);
							system("pause");
						}
						break;
						case '3':
						{
							textFile(header);
							system("pause");
						}
						break;
				
						case '4':
						{
							Setting(&header, password);
							system("pause");
						}
						break;
						case '5':
							SysTail();
							flag = 0;
							int flag = 1;
							while (flag)
							{
								printf("\n");
								printf("\t\t\t操作系统的人员是用户还是管理员(0\\1)？\n");
								printf("\t\t\t        请输入数字进行选择\n");
								printf("\t\t\t\t");
								scanf("%d", &choose);
								if (choose == 0 || choose == 1)
								{
									flag = 0;
									break;
								}
								printf("\t\t\t       输入错误，请重新输入\n");

							}
						}
						if (choice < '0' || choice > '9')
						{
							printf("\t\t\t\t输入错误!\n");
							system("pause");
						}
					}
				}
				fclose(cfPtr);
			}
			else
			{
				SysTail();
				int flag = 1;
				while (flag)
				{
					printf("\n");
					printf("\t\t\t操作系统的人员是用户还是管理员(0\\1)？\n");
					printf("\t\t\t        请输入数字进行选择\n");
					printf("\t\t\t\t");
					scanf("%d", &choose);
					if (choose == 0 || choose == 1)
					{
						flag = 0;
						break;
					}
					printf("\t\t\t       输入错误，请重新输入\n");
					system("pause");
				}
			}
		}
	}

	return 0;
}