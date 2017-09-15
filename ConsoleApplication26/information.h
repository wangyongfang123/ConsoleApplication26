#pragma once

#ifndef _INFORMATION_h_
#define _INFORMATION_h_
#include <stdbool.h>

typedef struct _Node
{
	char account_number[256];
	char name[256];
	int acctNum;
	long int number;
	char address[100];
	double balance;
	char password[256];
	struct _Node* next;
}Node, *NodePtr;

bool isEmpty(NodePtr list);
int insertData(NodePtr *ppNode, const char* name, const char* address, int  acctNum, long int number, double balance);
int deleteData(NodePtr *ppNode, const char* data);
Node* UpData(NodePtr fptr);
NodePtr findData(NodePtr *list, const char* name);
void printNodeInfo(const NodePtr pNode);
void Modify(NodePtr fptr);
void textFile(NodePtr header);
void processList(NodePtr list);
char UserenterChoice(void);
char AdminenterChoice(void); 
int _Login(NodePtr *ppNode);
int  Setting(NodePtr *ppNode, const char*password);
void readFile(NodePtr* list);

#endif