#include <iostream>
using namespace std;

// 定义二叉树节点结构（带构造函数，简化节点创建）
struct Node {
    int val;        // 节点值
    Node *left;     // 左子树指针
    Node *right;    // 右子树指针
    // 构造函数：初始化节点值和指针
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// ===================== 遍历函数 =====================
// 1. 前序遍历：根 → 左 → 右
void pre(Node *head) {
    if (head == nullptr) {
        return; // 递归终止条件：空节点直接返回
    }
    cout << head->val << " "; // 先访问当前节点
    pre(head->left);          // 递归遍历左子树
    pre(head->right);         // 递归遍历右子树
}

// 2. 中序遍历：左 → 根 → 右
void in(Node *head) {
    if (head == nullptr) {
        return;
    }
    in(head->left);           // 先递归遍历左子树
    cout << head->val << " "; // 访问当前节点
    in(head->right);          // 递归遍历右子树
}

// 3. 后序遍历：左 → 右 → 根
void pos(Node *head) {
    if (head == nullptr) {
        return;
    }
    pos(head->left);          // 先递归遍历左子树
    pos(head->right);         // 递归遍历右子树
    cout << head->val << " "; // 访问当前节点
}

int main() {
    // 构建测试二叉树（结构同 C 语言示例）：
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // 测试遍历
    cout << "前序遍历："; pre(root); cout << endl; // 预期：1 2 4 5 3
    cout << "中序遍历："; in(root);  cout << endl; // 预期：4 2 5 1 3
    cout << "后序遍历："; pos(root); cout << endl; // 预期：4 5 2 3 1

    // 注意：实际使用需递归释放内存（此处简化，未写 delete 逻辑）
    return 0;
}