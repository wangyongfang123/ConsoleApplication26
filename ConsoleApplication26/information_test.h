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

	if ((cfPtr = fopen("credit.dat", "r+")) == NULL)//�ж��ļ��ǲ����Ѿ����ڣ���������w+��������r+
	{
		cfPtr = fopen("credit.dat", "w+");
	}
	int flag = 1;
	while (flag)
	{
		printf("\n");
		printf("\t\t\t����ϵͳ����Ա���û����ǹ���Ա(0\\1)��\n");
		printf("\t\t\t        ���������ֽ���ѡ��\n");
		printf("\t\t\t\t");
		scanf("%d", &choose);
		if (choose == 0 || choose == 1)
		{
			flag = 0;
			break;
		}
		printf("\t\t\t       �����������������\n");

	}
	while (choose != 2)
	{

		if (choose == Admin)
		{
			if (Login() == 1)//����Ա�˺������¼
			{
				if ((cfPtr = fopen("credit.dat", "r+")) != NULL)
				{
					int flag = 1;
					while (flag)
					{
						 
						char choice = AdminenterChoice();//����Ա����

					 	switch (choice)
						{
						case '1':
						{
							FLAG_NODE = 1;
							fputs("\t\t����** �ͻ����**����**��ַ**�ֻ�����**���:\n", stdout);
							memset(name, 0, 256);
							printf("\t\t\t\t");
							scanf("%d%s%s%ld%lf", &acctNum, &name, &address, &number, &balance);

							insertData(&header, name, address, acctNum, number, balance);
							system("pause");

						}
						break;
						case '2':
						{

							fputs("\t\t\t����Ҫɾ�����û�����:\n", stdout);
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
							fputs("\t\t����ҪѰ�ҵ��û�����:\n", stdout);
							memset(name, 0, 256);
							printf("\t\t\t\t\t");
							scanf("%s", &name);
							if (pNode = findData(&header, name))
							{
								printNodeInfo(pNode);

							}
							else
							{
								printf("\t\t%s �û�����Ϣû���ҵ�!\n", name);

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
							fputs("\t\t\t�û���Ϣ������Ϊ:\n", stdout);
							fputs("\t\t\t�û����*����*��ַ*�ֻ�����*���\n", stdout);
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
								printf("\t\t\t����ϵͳ����Ա���û����ǹ���Ա(0\\1)��\n");
								printf("\t\t\t        ���������ֽ���ѡ��\n");
								printf("\t\t\t\t");
								scanf("%d", &choose);
								if (choose == 0 || choose == 1)
								{
									flag = 0;
									break;
								}
								printf("\t\t\t       �����������������\n");

							}
						  }
						}
						if (choice < '0' || choice > '9')
						{
							printf("\t\t\t\t�������!\n");
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
					printf("\t\t\t����ϵͳ����Ա���û����ǹ���Ա(0\\1)��\n");
					printf("\t\t\t        ���������ֽ���ѡ��\n");
					printf("\t\t\t\t");
					scanf("%d", &choose);
					if (choose == 0 || choose == 1)
					{
						flag = 0;
						break;
					}
					printf("\t\t\t       �����������������\n");
					system("pause");
				}
			}
		}
		else
		{
			if (_Login(&header) == 1)//�û��˺������¼
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
							fputs("\t\t����ҪѰ�ҵ��û�����:\n", stdout);
							memset(name, 0, 256);
							printf("\t\t\t\t\t");
							scanf("%s", &name);
							if (pNode = findData(&header, name))
							{
								printNodeInfo(pNode);

							}
							else
							{
								printf("\t\t%s �û�����Ϣû���ҵ�!\n", name);
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
							fputs("\t\t\t�û���Ϣ������Ϊ:\n", stdout);
							fputs("\t\t\t�ͻ����*����*��ַ*�ֻ�����*���\n", stdout);
							processList(header);
							system("pause");
						}
						break;
						case '5':
						{
							Setting(&header, password);
							system("pause");
						}
						break;
						case '6':
							SysTail();
							flag = 0;
							int flag = 1;
							while (flag)
							{
								printf("\n");
								printf("\t\t\t����ϵͳ����Ա���û����ǹ���Ա(0\\1)��\n");
								printf("\t\t\t        ���������ֽ���ѡ��\n");
								printf("\t\t\t\t");
								scanf("%d", &choose);
								if (choose == 0 || choose == 1)
								{
									flag = 0;
									break;
								}
								printf("\t\t\t       �����������������\n");

							}
						}
						if (choice < '0' || choice > '9')
						{
							printf("\t\t\t\t�������!\n");
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
					printf("\t\t\t����ϵͳ����Ա���û����ǹ���Ա(0\\1)��\n");
					printf("\t\t\t        ���������ֽ���ѡ��\n");
					printf("\t\t\t\t");
					scanf("%d", &choose);
					if (choose == 0 || choose == 1)
					{
						flag = 0;
						break;
					}
					printf("\t\t\t       �����������������\n");
					system("pause");
				}
			}
		}

	}

	return 0;
}