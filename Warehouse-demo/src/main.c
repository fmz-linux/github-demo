#include "main.h"
#include "mune.h"
#include "ruku.h"
int main()
{
    int n;
    Init_Head();
    while (1)
    {   
        printf_mune();
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("查询仓库");
                break;
            case 2:
                printf("物品出库");
                break;
            case 3:
                ruku();       //入库
                break;
            case 4:
                printf("入库");
                break;
            case 5:
                printf("入库");
                break;
            case 6:
                printf("入库");
                break;
            case 7:
                printf("入库");
                break;
            case 8:
                printf("入库");
                break;
            case 9:
                printf("入库");
                break;
            case 0:
                printf("退出管理成功....");
                return 0;
            default:
                printf("输入错误请重新输入！");
                break;

        }
    }
    
}