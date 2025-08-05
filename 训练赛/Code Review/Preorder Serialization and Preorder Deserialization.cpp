#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 定义二叉树节点结构
struct Node {
    int val;        // 节点值
    Node* left;     // 左子树指针
    Node* right;    // 右子树指针
    Node(int v) : val(v), left(nullptr), right(nullptr) {} // 构造函数
};

// ===================== 前序序列化（递归实现） =====================
// 将二叉树前序序列存入队列（空节点用 "null" 标记）
void pres(Node* head, queue<string>& ans) {
    if (head == nullptr) {
        ans.push("null"); // 空节点标记为 "null"
        return;
    }
    // 非空节点：先存值，再递归处理左、右子树
    ans.push(to_string(head->val)); 
    pres(head->left, ans);  
    pres(head->right, ans); 
}

queue<string> preSerial(Node* head) {
    queue<string> ans;
    pres(head, ans);
    return ans;
}

// ===================== 前序反序列化（递归实现） =====================
// 从队列中读取前序序列，重建二叉树
Node* preb(queue<string>& prelist) {
    if (prelist.empty()) return nullptr; // 队列为空，返回空指针

    string val = prelist.front(); // 取出队首元素
    prelist.pop();                // 弹出队首元素

    if (val == "null") {          // 遇到空节点标记，返回空指针
        return nullptr;
    }

    // 非空节点：先创建根节点，再递归构建左、右子树
    Node* head = new Node(stoi(val)); 
    head->left = preb(prelist);   
    head->right = preb(prelist);  
    return head;
}

Node* buildByPreQueue(queue<string> prelist) {
    if (prelist.empty()) return nullptr; // 空队列直接返回
    return preb(prelist);
}

// ===================== 测试工具：打印队列内容 =====================
void printQueue(queue<string> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// ===================== 测试用例 =====================
int main() {
    // 构建测试二叉树：
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // 1. 测试前序序列化
    queue<string> serialQueue = preSerial(root);
    cout << "前序序列化结果：";
    printQueue(serialQueue); 
    // 预期输出：1 2 4 null null 5 null null 3 null null 

    // 2. 测试前序反序列化
    Node* rebuilt = buildByPreQueue(serialQueue);
    // 验证：rebuilt 应与原树结构一致（可通过再次序列化或遍历确认）
    queue<string> checkQueue = preSerial(rebuilt);
    cout << "反序列化后再次序列化结果：";
    printQueue(checkQueue); 
    // 预期输出与原序列化结果一致

    return 0;
}