#include "updata.h"
#include "ruku.h"


void updataXg (Node * res)
{
    int z = 1;
    int x;
    printf("ID：%d ，物品名称：%s ，类别：%s ，"
            "规格：%s ，数量：%d ，存放位置：%s\n",
            res->data.id, res->data.Name,
            res->data.Cat, res->data.Spec,
            res->data.Qty, res->data.Loc);
    while (z == 1)
    {
       
        printf("------------\n");       
        printf("1.名称更新\n");
        printf("2.类别更新\n");
        printf("3.规格更新\n");
        printf("4.数量更新\n");
        printf("5.存放位置更新\n");
        printf("请选择你要选择的更新内容：");
        scanf("%d", &x);

        char ch[64];
        int qt;
        switch (x)
        {
        case 1:
            printf("请输入物品的新名称：");
            scanf("%s",ch);
            strcpy(res->data.Name,ch);
            printf("更新成功\n");
            printf("更新后--ID：%d ，物品名称：%s ，类别：%s ，"
                "规格：%s ，数量：%d ，存放位置：%s\n",
                res->data.id, res->data.Name,
                res->data.Cat, res->data.Spec,
                res->data.Qty, res->data.Loc);
            break;
        case 2:
            printf("请输入物品的新类别：");
            scanf("%s",ch);
            strcpy(res->data.Cat,ch);
            printf("更新成功\n");
            printf("更新后--ID：%d ，物品名称：%s ，类别：%s ，"
                "规格：%s ，数量：%d ，存放位置：%s\n",
                res->data.id, res->data.Name,
                res->data.Cat, res->data.Spec,
                res->data.Qty, res->data.Loc);
            break;
        case 3:
            
            printf("请输入物品的新规格：");
            scanf("%s",ch);
            strcpy(res->data.Spec,ch);
            printf("更新成功\n");
            printf("更新后--ID：%d ，物品名称：%s ，类别：%s ，"
                "规格：%s ，数量：%d ，存放位置：%s\n",
                res->data.id, res->data.Name,
                res->data.Cat, res->data.Spec,
                res->data.Qty, res->data.Loc);
            break;
        case 4:
            printf("请输入物品的新数量：");
            scanf("%d",&qt);
            res->data.Qty = qt;
            printf("更新成功\n");
            printf("更新后--ID：%d ，物品名称：%s ，类别：%s ，"
                "规格：%s ，数量：%d ，存放位置：%s\n",
                res->data.id, res->data.Name,
                res->data.Cat, res->data.Spec,
                res->data.Qty, res->data.Loc);
            break;
        case 5:
            printf("请输入物品的新位置：");
            scanf("%s",ch);
            strcpy(res->data.Loc,ch);
            printf("更新成功\n");
            printf("更新后--ID：%d ，物品名称：%s ，类别：%s ，"
                "规格：%s ，数量：%d ，存放位置：%s\n",
                res->data.id, res->data.Name,
                res->data.Cat, res->data.Spec,
                res->data.Qty, res->data.Loc);
            break;
        
        default:
            printf("输入错误\n");
            break;
        }
        printf("是否要继续更新该物品（1.是，0.否）:");
        scanf("%d", &z);
    }
}
void updata()
{
    if(g_head->next == g_head)
    {
        printf("库内物品为空，无法更新\n");
        return  ;
    }
    printf("-----物品更新----\n");
    int a = 1;
    int id;
    Node *res = g_head;
    
    while (a == 1)
    {
        int b=1;
        printf("请输入物品编号:");
        scanf("%d", &id);
        do
            {
                res = res->next;
                // 找到匹配名称
                if (id == res->data.id)
                {
                    updataXg(res);
                    b=0;
                    break;
                }
                
            } while (res != g_head);
        if (b)
        {        
            printf("无法找到编号为‘%d’的物品\n",id);
        }
        printf("是否要继续选择物品更新（1.是，0.否）:");
        scanf("%d", &a);
    }
}