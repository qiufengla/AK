#include <iostream>
#include <queue>  // 引入 STL 队列
using namespace std;

// 定义二叉树节点结构
struct Node {
    int val;        // 节点值
    Node* left;     // 左子树指针
    Node* right;    // 右子树指针
    // 构造函数：简化节点创建
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 层序遍历（广度优先遍历）
void level(Node* head) {
    if (head == nullptr) { // 空树直接返回
        cout << "空树" << endl;
        return;
    }

    queue<Node*> q;  // 创建队列，存储节点指针
    q.push(head);    // 根节点入队

    while (!q.empty()) { // 队列非空时循环
        Node* cur = q.front(); // 取出队首节点（不弹出）
        q.pop();               // 弹出队首节点（完成取出）

        cout << cur->val << " "; // 打印当前节点值

        // 左子节点非空则入队
        if (cur->left != nullptr) {
            q.push(cur->left);
        }
        // 右子节点非空则入队
        if (cur->right != nullptr) {
            q.push(cur->right);
        }
    }
    cout << endl;
}

// 测试用例1：原始测试树
Node* buildTree1() {
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
    return root;
}

// 测试用例2：空树
Node* buildTree2() {
    // 空树（无任何节点）
    return nullptr;
}

// 测试用例3：只有根节点的树
Node* buildTree3() {
    //   1
    // （仅包含根节点）
    return new Node(1);
}

// 测试用例4：左斜树（所有节点只有左子树）
Node* buildTree4() {
    //       1
    //      /
    //     2
    //    /
    //   3
    //  /
    // 4
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    return root;
}

// 测试用例5：右斜树（所有节点只有右子树）
Node* buildTree5() {
    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);
    return root;
}

// 测试用例6：完全二叉树
Node* buildTree6() {
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

// 测试用例7：非对称二叉树
Node* buildTree7() {
    //         1
    //        / \
    //       2   3
    //      /     \
    //     4       5
    //    /       /
    //   6       7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left->left = new Node(6);
    root->right->right->left = new Node(7);
    return root;
}

// 释放树的内存
void destroyTree(Node* root) {
    if (root == nullptr) return;
    destroyTree(root->left);  // 递归释放左子树
    destroyTree(root->right); // 递归释放右子树
    delete root;              // 释放当前节点
}

int main() {
    // 测试用例1：原始测试树
    Node* tree1 = buildTree1();
    cout << "测试用例1（原始测试树）层序遍历：";
    level(tree1);  // 预期输出：1 2 3 4 5
    destroyTree(tree1);

    // 测试用例2：空树
    Node* tree2 = buildTree2();
    cout << "测试用例2（空树）层序遍历：";
    level(tree2);  // 预期输出：空树

    // 测试用例3：只有根节点的树
    Node* tree3 = buildTree3();
    cout << "测试用例3（只有根节点）层序遍历：";
    level(tree3);  // 预期输出：1
    destroyTree(tree3);

    // 测试用例4：左斜树
    Node* tree4 = buildTree4();
    cout << "测试用例4（左斜树）层序遍历：";
    level(tree4);  // 预期输出：1 2 3 4
    destroyTree(tree4);

    // 测试用例5：右斜树
    Node* tree5 = buildTree5();
    cout << "测试用例5（右斜树）层序遍历：";
    level(tree5);  // 预期输出：1 2 3 4
    destroyTree(tree5);

    // 测试用例6：完全二叉树
    Node* tree6 = buildTree6();
    cout << "测试用例6（完全二叉树）层序遍历：";
    level(tree6);  // 预期输出：1 2 3 4 5 6 7
    destroyTree(tree6);

    // 测试用例7：非对称二叉树
    Node* tree7 = buildTree7();
    cout << "测试用例7（非对称二叉树）层序遍历：";
    level(tree7);  // 预期输出：1 2 3 4 5 6 7
    destroyTree(tree7);

    return 0;
}