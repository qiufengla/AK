#include <iostream> //二叉树的层序序列化
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

// ===================== 层序序列化（核心逻辑） =====================
queue<string> levelSerial(Node* head) {
    queue<string> ans; // 存储序列化结果的队列

    if (head == nullptr) {
        ans.push("null"); // 空树直接标记为 "null"
        return ans;
    }

    // 层序遍历的队列（存储节点指针）
    queue<Node*> q; 
    q.push(head);   // 根节点入队
    ans.push(to_string(head->val)); // 根节点值入结果队列

    while (!q.empty()) { // 队列非空时循环
        Node* cur = q.front(); // 取出队首节点
        q.pop();               // 弹出队首节点

        // 处理左子节点
        if (cur->left != nullptr) {
            ans.push(to_string(cur->left->val)); // 左子节点值入队
            q.push(cur->left);                   // 左子节点入层序队列
        } else {
            ans.push("null"); // 左子节点为空，标记为 "null"
        }

        // 处理右子节点
        if (cur->right != nullptr) {
            ans.push(to_string(cur->right->val)); // 右子节点值入队
            q.push(cur->right);                   // 右子节点入层序队列
        } else {
            ans.push("null"); // 右子节点为空，标记为 "null"
        }
    }

    return ans;
}

// ===================== 测试工具：打印队列内容 =====================
void printQueue(const queue<string>& q) {
    queue<string> temp = q; // 拷贝队列（避免修改原队列）
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

// ===================== 测试用例 =====================
int main() {
    // 构建测试二叉树：
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // 1. 测试层序序列化
    queue<string> serialQueue = levelSerial(root);
    cout << "层序序列化结果：";
    printQueue(serialQueue); 
    // 预期输出：1 2 3 4 5 null 6 null null null null 

    // 2. 测试空树序列化
    Node* nullRoot = nullptr;
    queue<string> nullQueue = levelSerial(nullRoot);
    cout << "空树序列化结果：";
    printQueue(nullQueue); 
    // 预期输出：null

    return 0;
}