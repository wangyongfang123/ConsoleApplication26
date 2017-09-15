#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"information.h"
#include<string.h>

int FLAG_NODE = 0;

int Login()//管理员账号密码登录
{
	char account_number[10];
	char password[10];
	char s_name[10] = "111";/*管理员初始密码*/
	char s_password[10] = "666";
	for (int i = 1; i <= 3; i++)
	{
		printf("\t\t------------------请输入账号----------------\n");
		printf("\t\t\t\t");
		scanf("%s", account_number);
		if (strcmp(s_name, account_number) == 0)
		{
			printf("\t\t------------------请输入密码----------------\n");
			printf("\t\t\t\t");
			scanf("%s", &password);
			if (strcmp(s_password, password) == 0)
			{
				printf("\t\t------------------登录成功------------------\n");
				return 1;
			}
			else
			{
				printf("\t\t------------------登录失败------------------\n");
			}
		}
	}
	printf("\t\t-----------已经输入三次错误信息，请稍后再试-----------");
    void SysTitle();
	return -1;
}

int _Login(NodePtr *ppNode)//用户账号密码登录
{
	char account_number[10];
	char password[10];
	char s_name[10];
	char s_password[10];
	NodePtr fptr = *ppNode;
	for (int i = 1; i <= 3; i++)
	{
		printf("\t\t------------------请输入账号----------------\n");
		printf("\t\t\t\t\t");
		scanf("%s", &s_name);
		while (fptr)
		{
			if (strcmp(fptr->account_number, s_name) == 0)
			{
					printf("\t\t------------------请输入密码----------------\n");
					printf("\t\t\t\t\t");
					scanf("%s", &s_password);
					if (strcmp(fptr->password, s_password) == 0)
					{
						printf("\t\t------------------登录成功------------------\n");
						return 1;
					}
					else
					{
						printf("\t\t------------------登录失败------------------\n");
					}
					break;	
				}
				fptr = fptr->next;
			}
			if (fptr == NULL)
			{
				printf("\t\t\t\t该用户不存在\n");	
			}
		}
		printf("\t\t------已经输入三次错误信息，请稍后再试--------");
	    void SysTitle();
		return -1;
	}

void processList(NodePtr list)//显示存入的内容
{
	//遍历单链表，输出数据
	Node* pNode = list;
	while (pNode != 0)
	{
		if(pNode->acctNum!=0)
		{
		printf("\t\t\t%d\t%s\t%s\t%ld\t%lf\n", pNode->acctNum, pNode->name, pNode->address, pNode->number, pNode->balance);
		}
		pNode = pNode->next;
	}
	fputs("\n", stdout);
}

void SysTitle()//开始界面
{
	printf("\n \n"
	       "\t\t\t_____________________________\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*         欢迎使用          *\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*      用户信息管理系统     *\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*****************************\n");
}

char AdminenterChoice (void)//管理员主菜单
{
	char  menuChoice[256];
	system("cls");
	printf("\t\t\t_____________________________\n"
	       "\t\t\t                             \n"
	       "\t\t\t*********管理员主菜单********\n"
	       "\t\t\t_____________________________\n"
		   "\t\t\t*                           *\n"
	       "\t\t\t*      1.创建新用户信息     *\n"
	       "\t\t\t*      2.删除用户信息       *\n"
	       "\t\t\t*      3.更新用户信息       *\n"
	       "\t\t\t*      4.查找用户信息       *\n"
	       "\t\t\t*      5.保存用户信息       *\n"
	       "\t\t\t*      6.修改用户信息       *\n"
	       "\t\t\t*      7.显示用户信息       *\n"
	       "\t\t\t*      8.注册用户信息       *\n"
	       "\t\t\t*      9.退出系统           *\n"
		   "\t\t\t*                           *\n"
	       "\t\t\t*****************************\n"
	       "\t\t\t                             \n"
	       "\t\t\t------请输入你要选择的功能---\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t");
	scanf("%s", &menuChoice);
	/*for (; menuChoice == '\n';)
	{
		menuChoice = getchar();
	}*/
	if (menuChoice[0]> '0' && menuChoice[0] < '9'&&strlen(menuChoice)==1)
	{
		return menuChoice[0];
	}
	
}

char UserenterChoice(void)//用户主菜单
{
	char menuChoice[256];
	system("cls");
	printf("\t\t\t_____________________________\n"
	       "\t\t\t                             \n"
	       "\t\t\t**********用户主菜单*********\n"
	       "\t\t\t_____________________________\n"
		   "\t\t\t*                           *\n"
	       "\t\t\t*      1.查找用户信息       *\n"
	       "\t\t\t*      2.修改用户信息       *\n"
	       "\t\t\t*      3.保存用户信息       *\n"
	       "\t\t\t*      4.显示用户信息       *\n"
	       "\t\t\t*      5.注册用户信息       *\n"
	       "\t\t\t*      6.退出系统           *\n"
		   "\t\t\t*                           *\n"
		   "\t\t\t*****************************\n"
		   "\t\t\t                             \n"
	       "\t\t\t----请输入你要选择的功能-----\n");
	printf("\t\t\t\t\t");
	scanf("%s", &menuChoice);
	if (menuChoice[0]> '0' && menuChoice[0] < '9'&&strlen(menuChoice) == 1)
	{
		return menuChoice[0];
	}
}

void SysTail()//结束界面
{
	//system("cls");
	printf("\n \n"
	       "\t\t\t_____________________________\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*          谢谢使用         *\n"
		   "\t\t\t*                           *\n"
	       "\t\t\t*      用户信息管理系统     *\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*                           *\n"
           "\t\t\t*****************************\n");
}

