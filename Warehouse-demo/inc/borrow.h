#ifndef BORROW_H
#define BORROW_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<stdbool.h>
#include"ruku.h"
//物品名称或物品编号，借用数量，借用人以及预计借用时长和借用原因

typedef struct Borw
{
    
    char itemName[64];  
    int  id;
    int  Qty;
    char user[64];
    char time[64];
    char imp [128];
    char zt [64];

}Borw;

typedef struct Bnode
{
    Borw data;
    struct Bnode * prev;
    struct Bnode * next;

}Bnode;

extern Bnode *b_head;

void Init_Borrow();
Bnode* creat_Borrow();
void borrow();
void borrowList();
#endif