#include "main.h"
#include "mune.h"
#include "ruku.h"
#include "rukujilu.h"
#include "chuku.h"
#include "search.h"
#include "borrow.h"
#include "delet.h"
#include "updata.h"
int main()
{
    int n;
    rkJl_InitHead();
    Init_Head();
    Init_Borrow();
    while (1)
    {   
        printf_mune();
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                search();     //查询仓库
                break;
            case 2:
                chuku();      //物品出库
                break;
            case 3:
                ruku();       //入库
                break;
            case 4:
                rkJl_ShowALL();  //入库记录
                break;
            case 5:
                borrow();    //借用申请
                break;
            case 6:
                borrowList();    //查看借用申请表
                break;
            case 7:
                delet();
                break;
            case 8:
                updata();            //更新
                break;
            case 9:
                printf("待开发。。。。\n");
                break;
            case 0:
                printf("退出管理成功....\n");
                return 0;
            default:
                printf("输入错误请重新输入！\n");
                break;

        }
    }
    
}