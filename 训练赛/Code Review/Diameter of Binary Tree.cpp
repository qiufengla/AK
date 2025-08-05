#include <iostream>//计算二叉树中 “最长路径（直径）” 【树形DP】
#include <algorithm> // 用于 max
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(nullptr),right(nullptr){}
};

struct  info
{
    int maxwide;
    int height;
    info(int m,int h):maxwide(m),height(h){}
    /* data */
};

info process(Node* x)
{
    if(x==nullptr)
    {
        return info(0,0);
    }
    info leftinfo=process(x->left);
    info rightinfo=process(x->right);

    int height=max(leftinfo.height,rightinfo.height)+1;
    int maxwide=max(max(leftinfo.maxwide,rightinfo.maxwide),leftinfo.height+rightinfo.height+1);
    
    return info(maxwide,height);
}

int getMaxDistance(Node* root) {
    return process(root).maxwide;
}


// ===================== 测试用例 =====================
int main() {
    // 测试用例 1：单节点树
    Node* root1 = new Node(1);
    cout << "测试用例 1（单节点树）：最长路径 = " << getMaxDistance(root1) << endl;
    // 预期输出：1（路径长度为 1，仅包含根节点）

    // 测试用例 2：链式树（高度为 3）
    //    1
    //     \
    //      2
    //       \
    //        3
    Node* root2 = new Node(1);
    root2->right = new Node(2);
    root2->right->right = new Node(3);
    cout << "测试用例 2（链式树）：最长路径 = " << getMaxDistance(root2) << endl;
    // 预期输出：3（路径：1-2-3，长度 3）

    // 测试用例 3：平衡树（最长路径经过根节点）
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(3);
    root3->left->left = new Node(4);
    root3->left->right = new Node(5);
    cout << "测试用例 3（平衡树）：最长路径 = " << getMaxDistance(root3) << endl;
    // 预期输出：4（路径：4-2-5 或 4-2-1-3，长度 4）

    return 0;
}

/*
// 定义二叉树节点结构
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 定义返回信息结构体（最大路径长度 + 子树高度）
struct Info {
    int maxDistance; // 子树中的最长路径（直径）
    int height;      // 子树的高度
    Info(int d, int h) : maxDistance(d), height(h) {}
};

// 递归处理函数：返回子树的最长路径和高度
Info process(Node* x) {
    if (x == nullptr) { // 空树：路径 0，高度 0
        return Info(0, 0);
    }

    // 1. 递归处理左子树和右子树
    Info leftInfo = process(x->left);
    Info rightInfo = process(x->right);

    // 2. 计算当前子树的高度（左右子树最大高度 + 1）
    int height = max(leftInfo.height, rightInfo.height) + 1;

    // 3. 计算当前子树的最长路径（直径）
    // 可能的最长路径：左子树的最长路径、右子树的最长路径、经过当前节点的路径（左高 + 右高 + 1）
    int maxDistance = max({
        leftInfo.maxDistance,          // 左子树的最长路径
        rightInfo.maxDistance,         // 右子树的最长路径
        leftInfo.height + rightInfo.height + 1 // 经过当前节点的路径
    });

    // 返回当前子树的信息
    return Info(maxDistance, height);
}

// 辅助函数：计算二叉树的最长路径（对外接口）
int getMaxDistance(Node* root) {
    return process(root).maxDistance;
}

*/


