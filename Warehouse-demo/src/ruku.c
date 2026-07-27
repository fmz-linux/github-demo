#include "ruku.h"
#include "rukujilu.h"

static int ids;
Node *g_head;

//初始头节点
void Init_Head()
{   
    g_head = (Node *)malloc(sizeof(Node));
    if (g_head == NULL)
    {
        perror("头节点内存分配失败...");
        exit(EXIT_FAILURE);
    }
    g_head->prev=g_head;
    g_head->next=g_head;
    ids=0;
}

//入库时创造节点
Node* Creat_Node()
{
    Node *newNode=malloc(sizeof(Node));
    if(!newNode)
    {
        perror("节点内存分配失败。。。。");
        exit(EXIT_FAILURE);
    }
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->data.id=++ids;
    printf("请输入入库物品名称：");
    scanf("%63s",newNode->data.Name);
    printf("请输入入库物品类别：");
    scanf("%63s",newNode->data.Cat);
    printf("请输入入库物品规格：");
    scanf("%63s",newNode->data.Spec);
    printf("请输入入库物品数量：");
    scanf("%d",&(newNode->data.Qty));
    printf("请输入入库物品位置：");
    scanf("%31s",newNode->data.Loc);
    return newNode;
}

//尾插法
void inertTail()
{
    Node* newNode = Creat_Node();
    if (g_head->next == g_head)
    {
        newNode->next = g_head;
        newNode->prev = g_head;
        g_head->next  = newNode;
        g_head->prev  = newNode;
    }
    else
    {
       Node* tail = g_head->prev;

       newNode->next = g_head;
       newNode->prev = tail;
       tail->next = newNode;
       g_head->prev = newNode;
    }
    rkJl_save(newNode);
    printf("id为‘%d’商品入库成功\n",newNode->data.id);
}

//入库操作
void ruku()
{
    int a=1;
    while (a==1)
    {
        inertTail();
        printf("该入库物品id：%d\n",ids);
        printf("如果需要继续入库请输入1，反之输入0：");
        scanf("%d",&a);
    }
    
}

