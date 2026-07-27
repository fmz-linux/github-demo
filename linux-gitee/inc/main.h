int delete(node* head,) {
    if (head == NULL) {
        return ;
    }
   
    while (cur != head) {
        Node* next_node = cur->next;  // 先保存下一个节点的地址
        free(cur);                    // 释放当前有效节点
        cur = next_node;              // 移到下一个节点继续
    }
    free(head);
    return 1;
    
}

