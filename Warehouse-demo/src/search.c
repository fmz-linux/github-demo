#include "search.h"
#include "ruku.h"

void search_fs(int x, int y)
{
    Node *res = g_head;
    if (g_head->next == g_head)
    {
        printf("暂无库存物品，无法查询！\n");
        return;
    }

    char cx[64];
    int vxs;
    int mun = 0;
    if (y == 1)
    {
        switch (x)
        {
        case 1:
            printf("请输入物品编号:");
            scanf("%d", &vxs);
            do
            {
                res = res->next;
                // 找到匹配名称
                if (vxs == res->data.id)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 2:
            printf("请输入名称:");
            scanf("%s", cx);
            do
            {
                res = res->next;
                // 找到匹配名称
                if (strcmp(cx, res->data.Name) == 0)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 3:
            printf("请输入物品类别:");
            scanf("%s", cx);
            do
            {
                res = res->next;
                // 找到匹配名称
                if (strcmp(cx, res->data.Cat) == 0)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 4:
            printf("请输入物品规格:");
            scanf("%s", cx);
            do
            {
                res = res->next;
                // 找到匹配名称
                if (strcmp(cx, res->data.Spec) == 0)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 5:
            printf("请输入物品数量:");
            scanf("%d", &vxs);
            do
            {
                res = res->next;
                // 找到匹配名称
                if (vxs == res->data.Qty)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;

        case 6:
            printf("请输入物品存放位置:");
            scanf("%s", cx);
            do
            {
                res = res->next;
                // 找到匹配名称
                if (strcmp(cx, res->data.Loc) == 0)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 7:
            do
            {
                res = res->next;
                printf("ID：%d ，物品名称：%s ，类别：%s ，"
                       "规格：%s ，数量：%d ，存放位置：%s\n",
                       res->data.id, res->data.Name,
                       res->data.Cat, res->data.Spec,
                       res->data.Qty, res->data.Loc);
                mun++;
            } while (res->next != g_head);
            break;
        default:
            printf("查询方式输入错误");
            break;
        }
    }

    else if (y == 2)
    {
        switch (x)
        {
        case 1:
            printf("请输入物品编号:");
            scanf("%d", &vxs);
            do
            {
                res = res->prev;
                // 找到匹配名称
                if (vxs == res->data.id)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 2:
            printf("请输入名称:");
            scanf("%s", cx);
            do
            {
                res = res->prev;
                // 找到匹配名称
                if (strcmp(cx, res->data.Name) == 0)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 3:
            printf("请输入物品类别:");
            scanf("%s", cx);
            do
            {
                res = res->prev;
                // 找到匹配名称
                if (strcmp(cx, res->data.Cat) == 0)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 4:
            printf("请输入物品规格:");
            scanf("%s", cx);
            do
            {
                res = res->prev;
                // 找到匹配名称
                if (strcmp(cx, res->data.Spec) == 0)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 5:
            printf("请输入物品数量:");
            scanf("%d", &vxs);
            do
            {
                res = res->prev;
                // 找到匹配名称
                if (vxs == res->data.Qty)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;

        case 6:
            printf("请输入物品存放位置:");
            scanf("%s", cx);
            do
            {
                res = res->prev;
                // 找到匹配名称
                if (strcmp(cx, res->data.Loc) == 0)
                {
                    printf("ID：%d ，物品名称：%s ，类别：%s ，"
                           "规格：%s ，数量：%d ，存放位置：%s\n",
                           res->data.id, res->data.Name,
                           res->data.Cat, res->data.Spec,
                           res->data.Qty, res->data.Loc);
                }
                mun++;
            } while (res != g_head);
            break;
        case 7:
            do
            {
                res = res->prev;
                printf("ID：%d ，物品名称：%s ，类别：%s ，"
                       "规格：%s ，数量：%d ，存放位置：%s\n",
                       res->data.id, res->data.Name,
                       res->data.Cat, res->data.Spec,
                       res->data.Qty, res->data.Loc);
                mun++;
            } while (res->prev != g_head);
            break;
        default:
            printf("查询方式输入错误");
            break;
        }
    }
    else
    {
        printf("查询顺序输入错误\n");
        return;
    }
    if(mun==0)
    {
        printf("--没有查询到物品--\n");
    }
}

void search()
{
    printf("--------查询物品--------\n");
    int x; // 查询方式
    int y; // 1，正序 2，逆序
    int z = 1;
    while (z == 1)
    {
        printf("1.编号查询\n");
        printf("2.名称查询\n");
        printf("3.类别查询\n");
        printf("4.规格查询\n");
        printf("5.数量查询\n");
        printf("6.存放位置查询\n");
        printf("7.全部物品查询\n");
        printf("请选择你要选择的查询方式：");
        scanf("%d", &x);
        printf("请选择你要查询的顺序（1.正序，2.逆序）:");
        scanf("%d", &y);
        search_fs(x,y);
        printf("是否要继续查询（1.是，0.否）:");
        scanf("%d", &z);
    }
}
