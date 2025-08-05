#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v):val(v),left(nullptr),right(nullptr),parent(nullptr){}
};

Node* getmostleft(Node* x)          //找到右子树最左的节点
{
    if(x==nullptr)
    {
        return nullptr;
    }
    while(x->left!=nullptr)
    {
        x=x->left;
    }
    return x;
}

Node* fun(Node* node)
{
    if(node==nullptr) return nullptr;
    if(node->right!=nullptr)
    {
        return getmostleft(node->right);
    }
    else
    {
        Node* parent=node->parent;
        // 循环条件：父节点存在，且当前节点是父节点的右孩子
        while(parent!=nullptr&&parent->left!=node)
        {   
            node=parent;            //node=parent,提前移动到parent的位置上去
            parent=node->parent;    //接着在移动之后，再去找对应的parent；
        }
        return parent;
    }
}

// ===================== 测试工具：构建树并连接父子关系 =====================
// 辅助函数：构建简单二叉树（带父指针）
Node* buildTreeWithParent() {
    // 构建节点
    Node* root = new Node(6);
    Node* n3 = new Node(3);
    Node* n9 = new Node(9);
    Node* n1 = new Node(1);
    Node* n4 = new Node(4);
    Node* n8 = new Node(8);
    Node* n10 = new Node(10);

    // 连接父子关系
    root->left = n3; root->right = n9; root->parent = nullptr;
    n3->parent = root; n3->left = n1; n3->right = n4;
    n9->parent = root; n9->left = n8; n9->right = n10;
    n1->parent = n3;
    n4->parent = n3;
    n8->parent = n9;
    n10->parent = n9;

    return root;
}

// 辅助函数：打印节点值（空节点打印 nullptr）
void printNode(Node* node) {
    if (node == nullptr) {
        cout << "nullptr";
    } else {
        cout << node->val;
    }
}

// ===================== 测试用例 =====================
int main() {
    // 构建测试树（结构如下）
    //        6
    //       / \
    //      3   9
    //     / \ / \
    //    1  4 8 10
    Node* root = buildTreeWithParent();

    // 测试用例 1：节点 3 的后继（有右子树）
    Node* n3 = root->left;
    Node* succ3 = fun(n3);
    cout << "节点 3 的后继：";
    printNode(succ3); // 预期输出 4（右子树的最左节点）
    cout << endl;

    // 测试用例 2：节点 4 的后继（无右子树，向上找）
    Node* n4 = n3->right;
    Node* succ4 = fun(n4);
    cout << "节点 4 的后继：";
    printNode(succ4); // 预期输出 6（父节点链中第一个“左孩子是自己”的祖先）
    cout << endl;

    // 测试用例 3：节点 9 的后继（有右子树）
    Node* n9 = root->right;
    Node* succ9 = fun(n9);
    cout << "节点 9 的后继：";
    printNode(succ9); // 预期输出 10（右子树的最左节点）
    cout << endl;

    // 测试用例 4：节点 10 的后继（无右子树，向上找）
    Node* n10 = n9->right;
    Node* succ10 = fun(n10);
    cout << "节点 10 的后继：";
    printNode(succ10); // 预期输出 nullptr（已到树最右）
    cout << endl;

    return 0;
}


/*
// 定义二叉树节点结构（包含父指针）
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;  // 指向父节点的指针
    Node(int v) : val(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

// ===================== 辅助函数：找到最左子节点 =====================
Node* getLeftMost(Node* node) {
    if (node == nullptr) return nullptr;
    // 一直向左找，直到没有左子节点
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// ===================== 核心逻辑：找到后继节点 =====================
Node* getSuccessorNode(Node* node) {
    if (node == nullptr) return nullptr;

    // 情况 1：节点有右子树 → 后继是右子树的最左节点
    if (node->right != nullptr) {
        return getLeftMost(node->right);
    } 
    // 情况 2：节点无右子树 → 向上找第一个“当前节点是父节点左孩子”的祖先
    else {
        Node* parent = node->parent;
        // 循环条件：父节点存在，且当前节点是父节点的右孩子
        while (parent != nullptr && parent->left != node) {
            node = parent;       // 向上跳转到父节点
            parent = node->parent; // 更新父节点
        }
        // 退出循环时，parent 即为后继（或 nullptr）
        return parent;
    }
}

*/