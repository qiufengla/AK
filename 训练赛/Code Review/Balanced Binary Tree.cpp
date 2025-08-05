#include <iostream>
#include <algorithm> // 用于 max 和 abs
using namespace std;

// 定义二叉树节点结构
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 定义返回信息结构体（是否平衡 + 子树高度）
struct info
{
    bool blance;
    int hight;
    info(bool b,int h):blance(b),hight(h){}
};

// 递归处理函数：返回子树的平衡状态和高度
info possess2(Node* x)
{
    if(x==nullptr)
    {
        return info(true,0);
    }
    info leftinfo=possess2(x->left);
    info rightinfo=possess2(x->right);
    
    //程序在执行递归操作，直到他完成他的任务，才会接着往下执行
    //一直分到了最小，然后又从最小回来执行接下来的操作

    int hight=max(leftinfo.hight,rightinfo.hight)+1;
    bool blance=true;
    if(leftinfo.blance==false||rightinfo.blance==false||abs(leftinfo.hight-rightinfo.hight)>1)
    {
        blance=false;
    }

    return info(blance,hight);
}

// 辅助函数：判断二叉树是否平衡（对外接口）
bool isBalancedTree(Node* root) {
    return possess2(root).blance;
}

// ===================== 测试用例 =====================
int main() {
    // 测试用例 1：平衡树
    //    1
    //   / \
    //  2   3
    // / \
    //4  5
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    cout << "测试用例 1（平衡树）：" << (isBalancedTree(root1) ? "平衡" : "不平衡") << endl;
    // 预期输出：平衡

    // 测试用例 2：不平衡树（右子树高度差 > 1）
    //    1
    //     \
    //      2
    //       \
    //        3
    Node* root2 = new Node(1);
    root2->right = new Node(2);
    root2->right->right = new Node(3);
    cout << "测试用例 2（不平衡树）：" << (isBalancedTree(root2) ? "平衡" : "不平衡") << endl;
    // 预期输出：不平衡

    // 测试用例 3：空树
    Node* root3 = nullptr;
    cout << "测试用例 3（空树）：" << (isBalancedTree(root3) ? "平衡" : "不平衡") << endl;
    // 预期输出：平衡

    // 测试用例 4：只有根节点的树
    Node* root4 = new Node(1);
    cout << "测试用例 4（只有根节点）：" << (isBalancedTree(root4) ? "平衡" : "不平衡") << endl;
    // 预期输出：平衡

    // 测试用例 5：左子树高度差 > 1
    //       1
    //      /
    //     2
    //    /
    //   3
    Node* root5 = new Node(1);
    root5->left = new Node(2);
    root5->left->left = new Node(3);
    cout << "测试用例 5（左子树高度差>1）：" << (isBalancedTree(root5) ? "平衡" : "不平衡") << endl;
    // 预期输出：不平衡

    // 测试用例 6：左右子树高度差为1（平衡）
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    Node* root6 = new Node(1);
    root6->left = new Node(2);
    root6->right = new Node(3);
    root6->left->left = new Node(4);
    cout << "测试用例 6（左右子树高度差为1）：" << (isBalancedTree(root6) ? "平衡" : "不平衡") << endl;
    // 预期输出：平衡

    // 测试用例 7：复杂平衡树
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    //  /         \
    // 7           8
    Node* root7 = new Node(1);
    root7->left = new Node(2);
    root7->right = new Node(3);
    root7->left->left = new Node(4);
    root7->left->right = new Node(5);
    root7->right->right = new Node(6);
    root7->left->left->left = new Node(7);
    root7->right->right->right = new Node(8);
    cout << "测试用例 7（复杂平衡树）：" << (isBalancedTree(root7) ? "平衡" : "不平衡") << endl;
    // 预期输出：不平衡

    // 测试用例 8：复杂不平衡树
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    //  /         \
    // 7           8
    //              \
    //               9
    Node* root8 = new Node(1);
    root8->left = new Node(2);
    root8->right = new Node(3);
    root8->left->left = new Node(4);
    root8->left->right = new Node(5);
    root8->right->right = new Node(6);
    root8->left->left->left = new Node(7);
    root8->right->right->right = new Node(8);
    root8->right->right->right->right = new Node(9);
    cout << "测试用例 8（复杂不平衡树）：" << (isBalancedTree(root8) ? "平衡" : "不平衡") << endl;
    // 预期输出：不平衡

    return 0;
}    


/*源代码
struct Info {
    bool isBalanced; // 是否平衡
    int height;      // 子树高度
    Info(bool b, int h) : isBalanced(b), height(h) {}
};
// 递归处理函数：返回子树的平衡状态和高度
Info process2(Node* x) {
    if (x == nullptr) { // 空树：平衡，高度 0
        return Info(true, 0);
    }

    // 1. 递归处理左子树和右子树
    Info leftInfo = process2(x->left);
    Info rightInfo = process2(x->right);

    // 2. 计算当前子树的高度（左右子树最大高度 + 1）
    int height = max(leftInfo.height, rightInfo.height) + 1;

    // 3. 判断当前子树是否平衡
    bool isBalanced = true;
    // 条件：左子树不平衡 或 右子树不平衡 或 高度差 > 1
    if (!leftInfo.isBalanced || !rightInfo.isBalanced || abs(leftInfo.height - rightInfo.height) > 1) {
        isBalanced = false;
    }

    // 返回当前子树的信息
    return Info(isBalanced, height);
}
*/