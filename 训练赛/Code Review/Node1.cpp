#include <iostream>
// C++ 中无需包含 stdlib.h，iostream 已包含必要的内存管理声明

// 链表节点结构（C++ 风格）
struct Node {
    int val;         // 节点存储的值（统一命名为 val，更符合 C++ 习惯）
    Node* next;      // 指向下一个节点的指针（C++ 中可直接用 Node* 自引用）
    
    // 构造函数：简化节点创建，自动初始化 next 为 nullptr
    Node(int v) : val(v), next(nullptr) {}
};

// 创建新节点的函数（利用构造函数简化）
Node* createNode(int value) {
    // C++ 中用 new 替代 malloc，自动调用构造函数
    return new Node(value);
}

// 实现 removeValue 功能，移除链表中值为 num 的节点
// 参数使用指针，返回新的头节点指针
Node* removeValue(Node* head, int num) {
    // 处理头节点连续为 num 的情况
    // 循环移除所有值为 num 的头节点
    while (head != nullptr && head->val == num) {
        Node* temp = head;   // 暂存当前头节点
        head = head->next;   // 头指针后移
        delete temp;         // C++ 中用 delete 释放内存（替代 free）
    }
    
    // 如果链表已空，直接返回 nullptr
    if (head == nullptr) {
        return nullptr;
    }
    
    // 用于遍历的前驱节点和当前节点
    Node* pre = head;       // 前驱节点从 head 开始
    Node* cur = head->next; // 当前节点从 head 的下一个开始
    
    // 遍历剩余节点
    while (cur != nullptr) {
        if (cur->val == num) {
            // 若当前节点值为 num，移除当前节点
            pre->next = cur->next; // 前驱节点直接指向当前节点的下一个
            delete cur;            // 释放当前节点内存
        } else {
            // 若当前节点值不为 num，前驱节点后移
            pre = cur;
        }
        // 当前节点后移（无论是否删除，都从 pre 的下一个开始）
        cur = pre->next;
    }
    
    return head; // 返回处理后的头节点
}

// 打印链表的函数，用于测试
void printList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        // C++ 中用 cout 替代 printf，更类型安全
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl; // 换行
}

// 释放链表内存的函数
void freeList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        Node* temp = cur;   // 暂存当前节点
        cur = cur->next;    // 移动到下一个节点
        delete temp;        // 释放当前节点内存
    }
}

int main() {
    // 创建链表 1 -> 2 -> 3 -> 2 -> 4（利用 createNode 简化）
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(4);

    std::cout << "原链表：";
    printList(head);

    // 移除值为 2 的节点
    head = removeValue(head, 2);
    std::cout << "移除值为 2 后的链表：";
    printList(head);

    // 释放链表内存（防止内存泄漏）
    freeList(head);

    return 0;
}