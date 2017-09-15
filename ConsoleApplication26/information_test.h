#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"information.h"
#include<string.h>

int FLAG_NODE = 0;

int Login()//����Ա�˺������¼
{
	char account_number[10];
	char password[10];
	char s_name[10] = "111";/*����Ա��ʼ����*/
	char s_password[10] = "666";
	for (int i = 1; i <= 3; i++)
	{
		printf("\t\t------------------�������˺�----------------\n");
		printf("\t\t\t\t");
		scanf("%s", account_number);
		if (strcmp(s_name, account_number) == 0)
		{
			printf("\t\t------------------����������----------------\n");
			printf("\t\t\t\t");
			scanf("%s", &password);
			if (strcmp(s_password, password) == 0)
			{
				printf("\t\t------------------��¼�ɹ�------------------\n");
				return 1;
			}
			else
			{
				printf("\t\t------------------��¼ʧ��------------------\n");
			}
		}
	}
	printf("\t\t-----------�Ѿ��������δ�����Ϣ�����Ժ�����-----------");
    void SysTitle();
	return -1;
}

int _Login(NodePtr *ppNode)//�û��˺������¼
{
	char account_number[10];
	char password[10];
	char s_name[10];
	char s_password[10];
	NodePtr fptr = *ppNode;
	for (int i = 1; i <= 3; i++)
	{
		printf("\t\t------------------�������˺�----------------\n");
		printf("\t\t\t\t\t");
		scanf("%s", &s_name);
		while (fptr)
		{
			if (strcmp(fptr->account_number, s_name) == 0)
			{
					printf("\t\t------------------����������----------------\n");
					printf("\t\t\t\t\t");
					scanf("%s", &s_password);
					if (strcmp(fptr->password, s_password) == 0)
					{
						printf("\t\t------------------��¼�ɹ�------------------\n");
						return 1;
					}
					else
					{
						printf("\t\t------------------��¼ʧ��------------------\n");
					}
					break;	
				}
				fptr = fptr->next;
			}
			if (fptr == NULL)
			{
				printf("\t\t\t\t���û�������\n");	
			}
		}
		printf("\t\t------�Ѿ��������δ�����Ϣ�����Ժ�����--------");
	    void SysTitle();
		return -1;
	}

void processList(NodePtr list)//��ʾ���������
{
	//�����������������
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

void SysTitle()//��ʼ����
{
	printf("\n \n"
	       "\t\t\t_____________________________\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*         ��ӭʹ��          *\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*      �û���Ϣ����ϵͳ     *\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*****************************\n");
}

char AdminenterChoice (void)//����Ա���˵�
{
	char  menuChoice[256];
	system("cls");
	printf("\t\t\t_____________________________\n"
	       "\t\t\t                             \n"
	       "\t\t\t*********����Ա���˵�********\n"
	       "\t\t\t_____________________________\n"
		   "\t\t\t*                           *\n"
	       "\t\t\t*      1.�������û���Ϣ     *\n"
	       "\t\t\t*      2.ɾ���û���Ϣ       *\n"
	       "\t\t\t*      3.�����û���Ϣ       *\n"
	       "\t\t\t*      4.�����û���Ϣ       *\n"
	       "\t\t\t*      5.�����û���Ϣ       *\n"
	       "\t\t\t*      6.�޸��û���Ϣ       *\n"
	       "\t\t\t*      7.��ʾ�û���Ϣ       *\n"
	       "\t\t\t*      8.ע���û���Ϣ       *\n"
	       "\t\t\t*      9.�˳�ϵͳ           *\n"
		   "\t\t\t*                           *\n"
	       "\t\t\t*****************************\n"
	       "\t\t\t                             \n"
	       "\t\t\t------��������Ҫѡ��Ĺ���---\n");
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

char UserenterChoice(void)//�û����˵�
{
	char menuChoice[256];
	system("cls");
	printf("\t\t\t_____________________________\n"
	       "\t\t\t                             \n"
	       "\t\t\t**********�û����˵�*********\n"
	       "\t\t\t_____________________________\n"
		   "\t\t\t*                           *\n"
	       "\t\t\t*      1.�����û���Ϣ       *\n"
	       "\t\t\t*      2.�޸��û���Ϣ       *\n"
	       "\t\t\t*      3.�����û���Ϣ       *\n"
	       "\t\t\t*      4.��ʾ�û���Ϣ       *\n"
	       "\t\t\t*      5.ע���û���Ϣ       *\n"
	       "\t\t\t*      6.�˳�ϵͳ           *\n"
		   "\t\t\t*                           *\n"
		   "\t\t\t*****************************\n"
		   "\t\t\t                             \n"
	       "\t\t\t----��������Ҫѡ��Ĺ���-----\n");
	printf("\t\t\t\t\t");
	scanf("%s", &menuChoice);
	if (menuChoice[0]> '0' && menuChoice[0] < '9'&&strlen(menuChoice) == 1)
	{
		return menuChoice[0];
	}
}

void SysTail()//��������
{
	//system("cls");
	printf("\n \n"
	       "\t\t\t_____________________________\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*          ллʹ��         *\n"
		   "\t\t\t*                           *\n"
	       "\t\t\t*      �û���Ϣ����ϵͳ     *\n"
	       "\t\t\t*                           *\n"
	       "\t\t\t*                           *\n"
           "\t\t\t*****************************\n");
}

