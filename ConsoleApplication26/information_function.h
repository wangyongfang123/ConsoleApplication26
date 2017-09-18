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
int  Setting(NodePtr *ppNode, const char*password)//注册账户和密码
{
	NodePtr pCurNode = *ppNode;
	NodePtr pNode = *ppNode;
	int choose = 0;
	int Admin = 1;
	char name[10];
	printf("\t\t\t如果注册新的账号和密码，请输入1\n");
	printf("\t\t\t\t");
	scanf("%d", &choose);
	if (choose == 1)
	{
		while (pNode != NULL)
		{
			if (pNode->account_number == name)
			{
				printf("\t\t这个用户的信息已经存在!\n");
				return -1;
			}
			pNode = pNode->next;
		}
		if (pCurNode == 0) //表为空的情况（插入节点位置为空）
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
			printf("\t\t-----------注册您当前用账号和密码-----------\n");
			printf("\t\t------------------注册账号为----------------\n");
			printf("\t\t\t\t");
			scanf("%s", name);
			printf("\t\t------------------注册密码为----------------\n");
			printf("\t\t\t\t");
			scanf("%s", password);
			printf("\t\t------------------注册完毕------------------\n");
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
			printf("\t\t这个用户的信息已经存在!\n");
			return -1;
		}
		pNode = pNode->next;
	}
	if (pCurNode == 0) //表为空的情况（插入节点位置为空）
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
int deleteData(NodePtr *ppNode, const char* data)//删除用户信息
{
	if (ppNode == 0 || *ppNode == 0)
	{
		printf("\t\t\t没有要删除的账户信息 !\n");
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
			printf("\t\t\t删除成功\n");
			return 0;
		}
		preNode = pNode;
		pNode = pNode->next;
	}
	printf("\t\t\t没有要删除的账户信息 !\n");
	return 0;
}
Node* UpData(NodePtr fptr)//更新用户信息
{
	int acctNum;
	char name;
	double transaction;
	NodePtr fpptr = fptr;
	printf("\t\t输入需要更新的用户编码 ( 1 - 100 ): ");
	scanf("%d", &acctNum);
	while (fpptr != NULL)
	{
		if (fpptr->acctNum == acctNum)
		{
			fputs("\t\tinput** 客户编号**姓名**地址**手机号码**余额:\n", stdout);
			printf("\t\t%-6d%-10s%-10s%-8ld%10.2f\n\n", fpptr->acctNum, fpptr->name, fpptr->address, fpptr->number, fpptr->balance);
			printf("\t\t请输入存款 ( + ) 或者 取款( - ): ");
			scanf("%lf", &transaction);
			fpptr->balance += transaction;
			fputs("\t\t用户编码**姓名**地址**手机号码**余额:\n", stdout);
			printf("\t\t%-6d%-10s%-10s%-8ld%10.2f\n", fpptr->acctNum, fpptr->name, fpptr->address, fpptr->number, fpptr->balance);
			return fpptr;
		}
		fpptr = fpptr->next;
	}
	if (fpptr == NULL || fpptr->acctNum != acctNum)
	{
		printf("\t\t用户编码为 #%d 的信息没有找到.\n", acctNum);
		return 0;
	}
}
NodePtr findData(NodePtr *list, const char* name)//查找用户信息
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
void printNodeInfo(const NodePtr pNode)//显示用户信息
{
	if (pNode)
	{
		printf("\t\t寻找到的信息是:\n");
		fputs("\t\t请输入** 客户编号**姓名**地址**手机号码**余额:\n", stdout);
		printf("\t\t%d\t%s\t%s\t%ld\t%lf\n", pNode->acctNum, pNode->name, pNode->address, pNode->number, pNode->balance);
	}
}
void Modify(NodePtr fptr)//修改用户信息
{
	char name[10] = { '0' };
	long int number = 1;
	char address[20] = { '0' };
	NodePtr fpptr = fptr;
	printf("\t\t\t输入要修改人的名字：\n");
	printf("\t\t\t\t");
	scanf("%s", &name);
	int ret = (int)findData(&fpptr, name);//找到要修改信息的联系人  
	if (ret != 0)
	{
		printf("\t\t\t请输入修改后的地址：\n");
		printf("\t\t\t\t");
		scanf("%s", &fpptr->address);
		printf("\t\t\t请输入修改后的手机号：\n");
		printf("\t\t\t\t");
		scanf("%ld", &fpptr->number);
		printf("\t\t\t修改信息成功！\n");
	}
	else
		printf("\t\t\t修改信息失败！\n");
}
void textFile(NodePtr header)//保存文本的作用
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


