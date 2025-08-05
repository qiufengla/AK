#include<bits/stdc++.h>//前序，中序，后序输出
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int v):val(v),left(nullptr),right(nullptr){}
};

void pre(Node* head)
{
    if(head==nullptr)
    {
        return;
    }
    cout<<head->val<<' ';
    pre(head->left);
    pre(head->right);
}

void in(Node* head)
{
    if(head==nullptr)
    {
        return;
    }
    in(head->left);
    cout<<head->val<<' ';
    in(head->right);
}

void post(Node* head)
{
    if(head==nullptr)
    {
        return;
    }
    post(head->left);
    post(head->right);
    cout<<head->val<<' ';
}

// 辅助函数：打印遍历结果，方便测试
// 这里用 std::function 要确保包含 <functional> 头文件，且在命名空间 std 下
void printTraversalResult(const string& traversalName, function<void(Node*)> traversalFunc, Node* root) {
    cout << traversalName << " traversal result: ";
    traversalFunc(root);
    cout << endl;
}
// 测试用例7构建函数（保持原结构）
Node* buildTestTree7() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->left = new Node(9);
    return root;
}
int main() {
    // 构建一棵简单的二叉树
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // 测试先序遍历
    printTraversalResult("Pre-order", pre, root);
    // 测试中序遍历
    printTraversalResult("In-order", in, root);
    // 测试后序遍历
    printTraversalResult("Post-order", post, root);

    Node* tree7 = buildTestTree7();
    cout << "测试用例7：\n";
    post(tree7); 
    // 预期输出：7 8 4 2 5 9 6 3 1

    // 手动释放内存，避免内存泄漏（简单示例，实际可考虑更完善的内存管理）
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}