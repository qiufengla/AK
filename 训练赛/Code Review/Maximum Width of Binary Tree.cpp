#include<bits/stdc++.h>
using namespace std;

// 定义二叉树节点结构
struct Node
{
    int val;         // 节点存储的值
    Node* left;      // 左子树指针
    Node* right;     // 右子树指针
    // 构造函数：初始化节点值和指针
    Node(int v):val(v),left(nullptr),right(nullptr){}
};

// 计算二叉树的最大宽度（某一层节点数量的最大值）
int level(Node* head)
{
    if(head==nullptr)  // 空树的最大宽度为0
    {
        return 0;
    }

    // 哈希表：记录每个节点对应的层级（键为节点指针，值为层级）
    unordered_map<Node*,int>map;
    // 队列：用于层序遍历，存储待处理的节点
    queue<Node*>q;

    q.push(head);  // 根节点入队
    Node* cur;     // 临时指针，用于指向当前处理的节点

    map[head]=1;   // 根节点的层级为1
    int wide=0;    // 记录当前层级的节点数量
    int current_level=1;  // 记录当前正在统计的层级
    int mx=0;      // 记录最大宽度

    // 层序遍历：队列非空时循环处理节点
    while(!q.empty())
    {
        cur=q.front();  // 取出队首节点
        q.pop();        // 弹出队首节点（已取出，后续处理）
        
        // 处理左子节点：若存在则记录其层级（当前节点层级+1）并加入队列
        if(cur->left!=nullptr)
        {
            map[cur->left]=map[cur]+1;
            q.push(cur->left);
        }
        // 处理右子节点：若存在则记录其层级（当前节点层级+1）并加入队列
        if(cur->right!=nullptr)
        {
            map[cur->right]=map[cur]+1;
            q.push(cur->right);
        }

        // 统计当前层级的节点数
        if(map[cur]==current_level)
        {
            wide++;  // 属于当前层级，节点数+1
        }
        else
        {
            // 进入新层级：更新最大宽度，重置当前层级节点数为1，切换到新层级
            mx=max(mx,wide);
            wide=1;
            current_level=map[cur];
        }
    }
    // 最后一层的宽度未在循环中比较，需单独处理
    mx=max(wide,mx);
    return mx;  // 返回最大宽度
}

// 测试用例1：完全二叉树（最大宽度在第2层，值为2）
//       1
//      / \
//     2   3
//    / \ / \
//   4  5 6  7
Node* buildTree1() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

// 测试用例2：空树（最大宽度为0）
Node* buildTree2() {
    return nullptr;
}

// 测试用例3：只有根节点（最大宽度为1）
//   1
Node* buildTree3() {
    return new Node(1);
}

// 测试用例4：左斜树（所有层宽度均为1）
//       1
//      /
//     2
//    /
//   3
//  /
// 4
Node* buildTree4() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    return root;
}

// 测试用例5：中间层宽度最大（第3层有4个节点）
//         1
//        / \
//       2   3
//      /|   |\
//     4 5   6 7
Node* buildTree5() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

// 测试用例6：非对称树（最大宽度在第3层，值为3）
//         1
//        / \
//       2   3
//      /     \
//     4       5
//    / \     /
//   6   7   8
Node* buildTree6() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->right->right->left = new Node(8);
    return root;
}

// 释放树内存：递归释放所有节点，避免内存泄漏
void destroyTree(Node* root) {
    if (root == nullptr) return;
    destroyTree(root->left);  // 先释放左子树
    destroyTree(root->right); // 再释放右子树
    delete root;              // 最后释放当前节点
}

int main()
{
    // 测试用例1：完全二叉树
    Node* tree1 = buildTree1();
    cout << "测试用例1（完全二叉树）最大宽度：" << level(tree1) << "（预期：2）" << endl;
    destroyTree(tree1);

    // 测试用例2：空树
    Node* tree2 = buildTree2();
    cout << "测试用例2（空树）最大宽度：" << level(tree2) << "（预期：0）" << endl;

    // 测试用例3：只有根节点
    Node* tree3 = buildTree3();
    cout << "测试用例3（只有根节点）最大宽度：" << level(tree3) << "（预期：1）" << endl;
    destroyTree(tree3);

    // 测试用例4：左斜树
    Node* tree4 = buildTree4();
    cout << "测试用例4（左斜树）最大宽度：" << level(tree4) << "（预期：1）" << endl;
    destroyTree(tree4);

    // 测试用例5：中间层宽度最大
    Node* tree5 = buildTree5();
    cout << "测试用例5（中间层最宽）最大宽度：" << level(tree5) << "（预期：4）" << endl;
    destroyTree(tree5);

    // 测试用例6：非对称树
    Node* tree6 = buildTree6();
    cout << "测试用例6（非对称树）最大宽度：" << level(tree6) << "（预期：3）" << endl;
    destroyTree(tree6);

    return 0;
}