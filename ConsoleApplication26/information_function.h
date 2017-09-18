#pragma once
#include <stdio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include"information_test.h"
#include"information.h"
#include<conio.h>

bool isEmpty(NodePtr list)
{
	return list == 0;
}
int  Setting(NodePtr *ppNode, const char*password)//ע���˻�������
{
	NodePtr pCurNode = *ppNode;
	NodePtr pNode = *ppNode;
	int choose = 0;
	int Admin = 1;
	char name[10];
	printf("\t\t\t���ע���µ��˺ź����룬������1\n");
	printf("\t\t\t\t");
	scanf("%d", &choose);
	if (choose == 1)
	{
		while (pNode != NULL)
		{
			if (pNode->account_number == name)
			{
				printf("\t\t����û�����Ϣ�Ѿ�����!\n");
				return -1;
			}
			pNode = pNode->next;
		}
		if (pCurNode == 0) //��Ϊ�յ����������ڵ�λ��Ϊ�գ�
		{
			*ppNode = (NodePtr)malloc(sizeof(Node));
			memset(*ppNode, 0, sizeof(Node));
			pCurNode = *ppNode;
		}
		else
		{
			Node* pNewNode = (Node*)malloc(sizeof(Node));
			memset(pNewNode, 0, sizeof(Node));
			pNewNode->next = pCurNode->next;
			pCurNode->next = pNewNode;
			pCurNode = pNewNode;
		}
		if (choose == 1)
		{
			printf("\t\t-----------ע������ǰ���˺ź�����-----------\n");
			printf("\t\t------------------ע���˺�Ϊ----------------\n");
			printf("\t\t\t\t");
			scanf("%s", name);
			printf("\t\t------------------ע������Ϊ----------------\n");
			printf("\t\t\t\t");
			scanf("%s", password);
			printf("\t\t------------------ע�����------------------\n");
			strcpy(pCurNode->account_number, name);
			strcpy(pCurNode->password, password);
		}
	}
	else
	{
		return -1;
	}
}
int insertData(NodePtr *ppNode, const char* name, const char* address, int  acctNum, long int number, double balance)
{
	NodePtr pCurNode = *ppNode;
	NodePtr pNode = *ppNode;
	while (pNode != NULL && FLAG_NODE == 1)
	{
		if (pNode->acctNum == acctNum)
		{
			printf("\t\t����û�����Ϣ�Ѿ�����!\n");
			return -1;
		}
		pNode = pNode->next;
	}
	if (pCurNode == 0) //��Ϊ�յ����������ڵ�λ��Ϊ�գ�
	{
		*ppNode = (NodePtr)malloc(sizeof(Node));
		memset(*ppNode, 0, sizeof(Node));
		pCurNode = *ppNode;
	}
	else
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		while (pCurNode->next != 0)
		{
			pCurNode = pCurNode->next;
		}
		pCurNode->next = pNewNode;
		pNewNode->next = 0;
		pCurNode = pNewNode;
	}
	pCurNode->acctNum = acctNum;
	strcpy(pCurNode->name, name);
	pCurNode->number = number;
	strcpy(pCurNode->address, address);
	pCurNode->balance = balance;
	return 0;
}
int deleteData(NodePtr *ppNode, const char* data)//ɾ���û���Ϣ
{
	if (ppNode == 0 || *ppNode == 0)
	{
		printf("\t\t\tû��Ҫɾ�����˻���Ϣ !\n");
		return -1;
	}
	NodePtr pNode = *ppNode;
	NodePtr preNode = 0;
	while (pNode != 0)
	{
		if (strcmp(pNode->name, data) == 0)
		{
			if (preNode == 0)
			{
				*ppNode = (*ppNode)->next;
			}
			else
			{
				preNode->next = pNode->next;
			}
			free(pNode);
			printf("\t\t\tɾ���ɹ�\n");
			return 0;
		}
		preNode = pNode;
		pNode = pNode->next;
	}
	printf("\t\t\tû��Ҫɾ�����˻���Ϣ !\n");
	return 0;
}
Node* UpData(NodePtr fptr)//�����û���Ϣ
{
	int acctNum;
	char name;
	double transaction;
	NodePtr fpptr = fptr;
	printf("\t\t������Ҫ���µ��û����� ( 1 - 100 ): ");
	scanf("%d", &acctNum);
	while (fpptr != NULL)
	{
		if (fpptr->acctNum == acctNum)
		{
			fputs("\t\tinput** �ͻ����**����**��ַ**�ֻ�����**���:\n", stdout);
			printf("\t\t%-6d%-10s%-10s%-8ld%10.2f\n\n", fpptr->acctNum, fpptr->name, fpptr->address, fpptr->number, fpptr->balance);
			printf("\t\t�������� ( + ) ���� ȡ��( - ): ");
			scanf("%lf", &transaction);
			fpptr->balance += transaction;
			fputs("\t\t�û�����**����**��ַ**�ֻ�����**���:\n", stdout);
			printf("\t\t%-6d%-10s%-10s%-8ld%10.2f\n", fpptr->acctNum, fpptr->name, fpptr->address, fpptr->number, fpptr->balance);
			return fpptr;
		}
		fpptr = fpptr->next;
	}
	if (fpptr == NULL || fpptr->acctNum != acctNum)
	{
		printf("\t\t�û�����Ϊ #%d ����Ϣû���ҵ�.\n", acctNum);
		return 0;
	}
}
NodePtr findData(NodePtr *list, const char* name)//�����û���Ϣ
{
	if (list == 0 || *list == 0)
	{
		return 0;
	}
	NodePtr plist = *list;
	while (list != 0 && plist->name != 0 && plist != 0)
	{
		if (strcmp(plist->name, name) == 0)
		{
			return plist;
		}
		plist = plist->next;
	}
	return 0;
}
void printNodeInfo(const NodePtr pNode)//��ʾ�û���Ϣ
{
	if (pNode)
	{
		printf("\t\tѰ�ҵ�����Ϣ��:\n");
		fputs("\t\t������** �ͻ����**����**��ַ**�ֻ�����**���:\n", stdout);
		printf("\t\t%d\t%s\t%s\t%ld\t%lf\n", pNode->acctNum, pNode->name, pNode->address, pNode->number, pNode->balance);
	}
}
void Modify(NodePtr fptr)//�޸��û���Ϣ
{
	char name[10] = { '0' };
	long int number = 1;
	char address[20] = { '0' };
	NodePtr fpptr = fptr;
	printf("\t\t\t����Ҫ�޸��˵����֣�\n");
	printf("\t\t\t\t");
	scanf("%s", &name);
	int ret = (int)findData(&fpptr, name);//�ҵ�Ҫ�޸���Ϣ����ϵ��  
	if (ret != 0)
	{
		printf("\t\t\t�������޸ĺ�ĵ�ַ��\n");
		printf("\t\t\t\t");
		scanf("%s", &fpptr->address);
		printf("\t\t\t�������޸ĺ���ֻ��ţ�\n");
		printf("\t\t\t\t");
		scanf("%ld", &fpptr->number);
		printf("\t\t\t�޸���Ϣ�ɹ���\n");
	}
	else
		printf("\t\t\t�޸���Ϣʧ�ܣ�\n");
}
void textFile(NodePtr header)//�����ı�������
{
	FILE *writePtr;
	int num = 100;
	NodePtr temp = header;
	if ((writePtr = fopen("accounts.dat", "w+")) == NULL)
		printf("File could not be opened.\n");
	else
	{
		int count = 0;
		while (temp != NULL)
		{
			fseek(writePtr, count*sizeof(Node), SEEK_SET);
			fwrite(temp, sizeof(Node), 1, writePtr);
			temp = temp->next;
			count++;
		}
		fclose(writePtr);
	}
}
void  readFile(NodePtr* list)
{
	FILE *readPtr = fopen("accounts.dat", "r+");
	Node *curnode = (NodePtr)malloc(sizeof(Node));
	memset(curnode, 0, sizeof(Node));
	fseek(readPtr, 0, SEEK_SET);
	int i = 0;
	while (feof(readPtr) == 0)
	{
		fseek(readPtr, i*sizeof(Node), SEEK_SET);
		int ret = fread(curnode, sizeof(Node), 1, readPtr);
		if (curnode->acctNum == 0)
			continue;
		if (ret != 1)
			break;
		insertData(list, curnode->name, curnode->address, curnode->acctNum, curnode->number, curnode->balance);
		i++;
	}
	fclose(readPtr);
}


