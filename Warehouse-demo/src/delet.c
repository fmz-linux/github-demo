#include "delet.h"
#include "ruku.h"


// 删除指定节点
bool deleteNode(Node *head, Node *delnode)
{
    // 不允许删除哨兵节点或空节点
    if (delnode == NULL || delnode == head)
        return false;

    // 从双向链表中摘除节点
    delnode->prev->next = delnode->next;
    delnode->next->prev = delnode->prev;

    free(delnode);
    return true;
}

bool deleteByValue(Node *head, int id)
{
    Node *cur = head->next;   // 从第一个数据节点开始
    while (cur != head) {     // 遍历所有数据节点
        Node *next = cur->next;  // 提前保存后继，防止删除后野指针

        if (cur->data.id == id) {
            if (deleteNode(head, cur)) {
                printf("删除成功\n");
                return true;
            } else {
                printf("删除失败\n");
                return false;
            }
        }
        cur = next;
    }
    printf("找不到该物品id\n");
    return false;
}

void delet()
{

    int id;
    int a=1;
    
    while (a==1)
    {   
       if(g_head->next == g_head || g_head == NULL)
        {
            printf("入库商品为空，无法删除\n");
            return;
        }
       printf("请输入要删除物品id：");
       scanf("%d",&id);
       deleteByValue(g_head,id);
       printf("是否要继续删除物品操作（1：是，0：否）：");
       scanf("%d",&a);

    }
    
    
}