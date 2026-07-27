#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef data dataType;
// 结构体
typedef struct data
{
    char name[10]
;    int age;

}data;


typedef struct node // 这里的Node是结构体标签
{
    int data;
    struct Node *prev;
    struct Node *next;

} node; // 这里的node是结构体类型别名

// chaung
node *CreatrNode(dataType data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        perror("malloc fail");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void initList(node **head)
{
    *head = NULL;
}

bool isEmpty(node *head)
{
    return head == NULL;
}

// 链表长度
int getLength(node *head)
{
    if (isEmpty(head))
        return 0;
    int count = 0;
    node *res = head;
    do
    {
        count++;
        res = res->next;
    } while (res != head);
    return count;
}

// 头插法
void inertHead(node **head, dataType data)
{
    node *newnode = CreatrNode(data);
    if (isEmpty(*head))
    {
        newnode->prev = newnode->next = newnode;
        *head = newnode;
    }
    else
    {
        node *tail = (*head)->prev;

        (*head)->prev = newnode;
        tail->next = newnode;
        newnode->next = (*head);
        newnode->prev = tail;

        *head = newnode;
    }
}

// 尾插法
void inertTail(node **head, dataType data)
{
    node *newnode = CreatrNode(data);
    if (isEmpty(*head))
    {
        (*head) = newnode;
        newnode->prev = newnode;
        newnode->next = newnode;
    }
    else
    {
        node *tail = (*head)->prev;

        newnode->next = (*head);
        newnode->prev = tail;
        tail->next = newnode;
        (*head)->prev = newnode;
    }
}

// 按位置插入
bool insertAt(node **head, int pos, dataType data)
{
    int len = getLength(*head);
    if (pos < 0 || pos > len)
    {
        printf("over area:[0,%d]\n", len - 1);
        return false;
    }
    if (pos == 0)
    {
        inertHead(head, data);
        return true;
    }
    if (pos == len)
    {
        inertTail(head, data);
        return true;
    }
    node *newhead = CreatrNode(data);
    node *cur = *head;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->next; // 指到要插入的位置
    }
    newhead->prev = cur->prev;
    newhead->next = cur;
    cur->prev->next = newhead;
    cur->prev = newhead;
    return true;
}

// 删除指定节点
bool deleteNode(node **head, node *delnode)
{
    if (isEmpty(*head) || delnode == NULL)
        return false;

    if (getLength(*head) == 1)
    {
        if ((*head) == delnode)
        {
            free(delnode);
            *head = NULL;
            return true;
        }
        return false;
    }

    node *prevnode = delnode->prev;
    node *nextnode = delnode->next;

    prevnode->next = nextnode;
    nextnode->prev = prevnode;

    if (*head == delnode)
    {
        *head = nextnode;
    }
    free(delnode);
    return true;
}

// 按值删除,删除第一匹配到的数据
bool deleteByValue(node **head, dataType value)
{
    if (isEmpty(*head))
    {
        printf("List is empty\n");
        return false;
    }

    node *cur = *head;
    do
    {   
        if (cur->data == value)
        {   
            bool result = deleteNode(head, cur);
            if (result)
            {
                return true;
            }
            else
            {
                printf("deleter node is false\n");
                return true;
            }
            
        }
        cur = cur->next;
    } while (cur != (*head));
    printf("no fine this node\n");
    return false;
}
// 按位置删除
bool deleteByAt(node **head, int pos)
{
    if (isEmpty(*head))
    {
        printf("List is empty\n");
        return false;
    }

    int len = getLength(*head);
    if (pos < 0 || pos >=len)
    {
        printf("over area:[0,%d]\n", len - 1);
        return false;
    }

    node *cur = *head;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }

    bool result = deleteNode(head, cur);
    if (result)
    {
        return true;
    }
    else
    {
        printf("deleter node is false\n");
        return false;
    }

    return false;
}
// 按指查找
node *findByValur(node *head, dataType value)
{
    if (isEmpty(head))
        return NULL;
    node *cur = head;
    do
    {
        if (cur->data == value)
        {
            return cur;
        }
        cur = cur->next;
    } while (cur != head);

    return NULL;
}
// 按位查找
node *findByIndex(node *head, int pos)
{
    if (isEmpty(head))
        return NULL;

    int len = getLength(head);
    if (pos < 0 || pos > len)
    {
        printf("over area:[0,%d]\n", len - 1);
        return NULL;
    }

    node *cur = head;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }

    return cur;
}

// 按值修改
bool updateByValue(node *head, dataType old, dataType new)
{
    if (isEmpty(head))
    {
        printf("List is empty\n");
        return NULL;
    }
    node *cur = head;
    do
    {
        if (cur->data == old)
        {
            cur->data = new;
            return true;
        }
        cur = cur->next;
    } while (cur != head);
    return false;
}

// 按位修改
bool updateByIndex(node *head, int pos, dataType new)
{
    if (isEmpty(head))
    {
        printf("List is empty\n");
        return false;
    }

    int len = getLength(head);
    if (pos < 0 || pos >= len)
    {
        printf("over area:[0,%d]\n", len - 1);
        return false;
    }

    node *cur = head;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }
    cur->data = new;

    return true;
}

// 输出
void printfnodedata(node *head)
{
    printf("%d ", head->data);
}

// 头遍历
bool displayForward(node *head)
{
    if (isEmpty(head))
    {
        printf("List is empty\n");
        return false;
    }
    printf("display to forward:");
    node *cur = head;
    do
    {
        printfnodedata(cur);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
    return true;
}

// 尾遍历
bool displayaBackward(node *head)
{
    if (isEmpty(head))
    {
        printf("List is empty\n");
        return false;
    }
    printf("display to backward:");
    node *cur = head->prev;
    node *tail = cur;
    do
    {
        printfnodedata(cur);
        cur = cur->prev;
    } while (cur != tail);
    printf("\n");
    return true;
}

// 销毁链表
bool destroyList(node **head)
{
    if (isEmpty(*head))
    {
        printf("List is empty\n");
        return false;
    }
    node *cur = *head;
    node *nextcur = NULL;
    do
    {
        nextcur = cur->next;
        free(cur);
        cur = nextcur;

    } while (cur != *head);
    *head = NULL;
    return true;
}

int main() {
    node *list = NULL;
    initList(&list);

    // 头插
    inertHead(&list, 10);
    inertHead(&list, 20);
    inertHead(&list, 30);
    printf("After head insert 30,20,10:\n");
    displayForward(list);

    // 尾插
    inertTail(&list, 40);
    inertTail(&list, 50);
    printf("After tail insert 40,50:\n");
    displayForward(list);

    // 按位置插入
    insertAt(&list, 2, 25); // 插入到索引2
    printf("After insert 25 at position 2:\n");
    displayForward(list);

    // 长度
    printf("Length: %d\n", getLength(list));

    // 反向遍历
    displayaBackward(list);

    // 按值查找
    node *found = findByValur(list, 25);
    if (found) printf("Found value 25 at node with data %d\n", found->data);
    else printf("Value 25 not found\n");

    // 按位查找
    found = findByIndex(list, 3);
    if (found) printf("Element at index 3: %d\n", found->data);
    else printf("Index 3 out of range\n");

    // 按值删除
    deleteByValue(&list, 20);
    printf("After deleting value 20:\n");
    displayForward(list);

    // 按位置删除
    deleteByAt(&list, 1);
    printf("After deleting position 1:\n");
    displayForward(list);

    // 销毁
    destroyList(&list);
    if (isEmpty(list)) printf("List destroyed successfully.\n");

    return 0;
}