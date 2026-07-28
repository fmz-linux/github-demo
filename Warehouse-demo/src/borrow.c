#include "borrow.h"
#include"ruku.h"
Bnode *b_head;


void Init_Borrow()
{
    b_head = malloc(sizeof(Bnode));
    if (b_head == NULL)
    {
        perror("头节点内存分配失败...");
        exit(EXIT_FAILURE);
    }
    b_head->prev=b_head;
    b_head->next=b_head;
}


Bnode* creat_Borrow()
{
    Bnode *newNode = malloc(sizeof(Bnode));
    if (!newNode) {
        perror("节点内存分配失败");
        exit(EXIT_FAILURE);
    }
    newNode->next = NULL;
    newNode->prev = NULL;

    int retry = 1;
    while (retry == 1) {
        printf("请输入借用物品的编号：");
        scanf("%d", &newNode->data.id);
        printf("请输入借用物品的数量：");
        scanf("%d", &newNode->data.Qty);

        // 数量必须大于0，否则直接重新输入
        if (newNode->data.Qty <= 0) {
            printf("申请数量必须大于0！请重新输入。\n");
            continue;   // 回到 while 开头，重新输入
        }

        Node *res = g_head;
        int found = 0;        // 是否找到编号
        int shortage = 0;     // 是否数量不足

        do {
            res = res->next;
            if (res->data.id == newNode->data.id) {
                found = 1;
                if (res->data.Qty < newNode->data.Qty) {
                    printf("申请失败，物品数量不足，该物品目前剩 %d 件\n", res->data.Qty);
                    shortage = 1;
                    break;   // 跳出内层循环，回到外层重新输入
                } else {
                    // 数量充足，填写申请信息
                    strcpy(newNode->data.itemName, res->data.Name);
                    strcpy(newNode->data.zt, "申请待通过");
                    printf("请输入借用人的名字：");
                    scanf("%63s", newNode->data.user);   // 修正：无 &，限制长度
                    printf("请输入预计借用物品的时长：");
                    scanf("%63s", newNode->data.time);
                    printf("请输入借用物品的原因：");
                    scanf("%127s", newNode->data.imp);

                    // 插入链表尾部（空链表也适用）
                    newNode->next = b_head;
                    newNode->prev = b_head->prev;
                    b_head->prev->next = newNode;
                    b_head->prev = newNode;

                    printf("物品借用申请表提交成功\n");
                    return newNode;
                }
            }
        } while (res != g_head);

        // 内层循环结束后的处理
        if (found && shortage) {
            // 数量不足，自动重新循环（用户可直接重新输入编号和数量）
            printf("请重新输入编号和数量。\n");
            // retry 保持 1，循环继续
        } else if (!found) {
            // 未找到编号，询问是否退出
            printf("没有找到编号‘%d’的物品\n", newNode->data.id);
            printf("是否要继续填写申请？（1.是 0.否）：");
            scanf("%d", &retry);
        }
    }

    free(newNode);
    return NULL;
}

void borrow()
{
    int a=1;
    if (g_head->next == g_head)
    {
        printf("暂无库存物品，无法申请！\n");
        return;
    }
    while (a==1)
    {   
        Bnode* newNode = creat_Borrow();
        if (newNode !=NULL)
        {
            printf("--申请表：物品ID：%d ，物品名称：%s ，借用数量：%d ，申请借用人：%s ，预计借用时长： %s，借用原因：%s-----\n"
                ,newNode->data.id,newNode->data.itemName,newNode->data.Qty
                ,newNode->data.user,newNode->data.time,newNode->data.imp);
        }
        
        printf("如果需要继续申请借用请输入1，反之输入0：");
        scanf("%d",&a);
    }
}

void borrowList()
{
    Bnode *res = b_head;
    int mun =0;
     if (b_head->next == b_head)
        {
            printf("暂无申请表！\n");
            return;
        }
        do
        {
            res = res->next;
            mun++;
            printf("--%2d.申请表：物品ID：%d ，物品名称：%s ，借用数量：%d" 
                "，申请借用人：%s ，预计借用时长： %s，借用原因：%s ，借用状态：%s----\n"
                ,mun,res->data.id,res->data.itemName,res->data.Qty
                ,res->data.user,res->data.time,res->data.imp,res->data.zt);
      
        } while (res->next != b_head);
}