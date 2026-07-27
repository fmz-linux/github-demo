#ifndef RUKU_H
#define RUKU_H

//用双循环链表来承接仓库管理的结构体
#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<stdbool.h>

//物品名称、类别、规格、数量和存放位置
typedef struct Item
{
    
    char Name[64];  
    char Cat[64];
    char Spec[64];
    char Loc[32];
    int  Qty;
    int  id;

}Item;


//链表
typedef struct Node
{
    Item data;
    struct Node * prev;
    struct Node * next;

}Node;

extern Node *g_head;//全局哨兵节点

void Init_Head();
Node* Creat_Node();
void inertTail();
void ruku();

#endif