#ifndef RUKUJILU_H
#define RUKUJILU_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<stdbool.h>
#include "ruku.h"
//链表
typedef struct rkJilu
{
    Item data;
    struct rkJilu * prev;
    struct rkJilu * next;

}rkJilu;

extern rkJilu *jl_head;//全局记录入库哨兵节点
void rkJl_InitHead();         // 初始化台账空头
void rkJl_save(Node *newRuku);   // 保存一条入库记录
void rkJl_ShowALL();    
#endif