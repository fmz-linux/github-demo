#include "rukujilu.h"
#include "ruku.h"

rkJilu *jl_head;

void rkJl_InitHead()
{   
    jl_head = (rkJilu *)malloc(sizeof(rkJilu));
    if (jl_head == NULL)
    {
        perror("入库记录头节点内存分配失败...");
        exit(EXIT_FAILURE);
    }
    jl_head->prev=jl_head;
    jl_head->next=jl_head;
}

void rkJl_save(Node *newRuku)
{
    rkJilu *newJl = (rkJilu *)malloc(sizeof(rkJilu));
    if (newJl == NULL)
    {
        perror("入库记录节点内存分配失败...");
        exit(EXIT_FAILURE);
    }
    newJl->data = newRuku->data;
      if (jl_head->next == jl_head)
    {
        newJl->next = jl_head;
        newJl->prev = jl_head;
        jl_head->next  = newJl;
        jl_head->prev  = newJl;
    }
    else
    {
       rkJilu* tail = jl_head->prev;

       newJl->next = jl_head;
       newJl->prev = tail;
       tail->next = newJl;
       jl_head->prev = newJl;
    }
    printf("成功记录id为‘%d’商品入库\n",newJl->data.id);
}

void rkJl_ShowALL()
{
    if(jl_head->next == jl_head)
    {
        printf("还没有物品入库。。。。\n");
        return;
    }
    printf("-----入库记录------\n");
    rkJilu* res =jl_head;
    do
    {
        res =res->next;
        printf("ID：%d ，物品名称：%s ，类别：%s ，"
                "规格：%s ，数量：%d ，存放位置：%s\n",
                res->data.id,res->data.Name,
                res->data.Cat,res->data.Spec,
                res->data.Qty,res->data.Loc);
    }while (res->next != jl_head);
    
}