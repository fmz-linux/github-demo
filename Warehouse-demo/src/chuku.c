#include"chuku.h"
#include"ruku.h"

//名称出库
void name_chuku(char *cname,int x)
{
        if (x <= 0)
    {
        printf("出库数量必须大于0！\n");
        return;
    }

    Node *res = g_head;
    do
    {
        res = res->next;
        //找到匹配名称
        if (strcmp(res->data.Name, cname) == 0)
        {
            if (res->data.Qty < x)
            {
                printf("出库失败，物品数量不足，该物品目前剩 %d 件\n", res->data.Qty);
                return;
            }
            res->data.Qty -= x;
            printf("出库成功，该物品目前剩 %d 件\n", res->data.Qty);
            return;
        }
    } while (res != g_head); //回到头节点代表遍历完毕

    //循环走完没return = 未找到
    printf("没有找到名称‘%s’的物品\n", cname);
}
    

           


//编号出库
void id_chuku(int cid,int x)
{
    if (x <= 0)
    {
        printf("出库数量必须大于0！\n");
        return;
    }

    Node *res = g_head;
    do
    {
        res = res->next;
        if (res->data.id == cid)
        {
            if (res->data.Qty < x)
            {
                printf("出库失败，物品数量不足，该物品目前剩 %d 件\n", res->data.Qty);
                return;
            }
            res->data.Qty -= x;
            printf("出库成功，该物品目前剩 %d 件\n", res->data.Qty);
            return;
        }
    } while (res != g_head);

    printf("没有找到编号‘%d’的物品\n", cid);
    
}




void chuku() //出库
{
    int a=1;
    int i=0;  //查找方式
    int x=0;  //qty
    char cname[64];
    int cid=0;
    if (g_head->next == g_head)
        {
            printf("暂无库存物品，无法出库！\n");
            return;
        }
    while (a)
    {
       
        printf("请输入查找出库物品的方式（输入‘1’为名称，输入‘2’为编号）：");
        do
        {
           scanf("%d",&i);
            if(i==1)
            {
                printf("请输入出库物品名称和出库数量(如： 苹果，10)：");
                scanf("%s,%d",cname,&x);
                name_chuku(cname,x);
                break;
            }
            else if  (i==2)
            {
                printf("请输入出库物品编号和出库数量(如： 1，10)：");
                scanf("%d,%d",&cid,&x);
                id_chuku(cid,x);
                break;
            }
            else
            {
                printf("入库方式输入错误, 请重新输入：");
            }

        }while (i!=1 && i!=2);
        
        printf("是否要继续出库，继续请输入‘1’，结束请输入‘0’：");
        scanf("%d",&a);

    }
    printf("物品出库操作结束。。。");
    
}