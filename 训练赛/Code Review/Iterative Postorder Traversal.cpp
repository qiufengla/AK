#include <iostream>//后序遍历
#include <stack>  // 引入 STL 栈
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int v):val(v),left(nullptr),right(nullptr){}
};

void fun(Node* head)
{
    if(head==nullptr)
    {
        cout<<'\n';
        return;
    }
    stack<Node*>stk;
    stk.push(head);
    Node* cur=nullptr;
    Node* last=nullptr;
    while(!stk.empty())
    {
        cur=stk.top();
        if(cur->left!=nullptr&&last!=cur->left&&last!=cur->right)
        {
            stk.push(cur->left);
        }
        else if(cur->right!=nullptr&&last!=cur->right)
        {
            stk.push(cur->right);
        }
        else
        {
            cout<< stk.top()->val <<' ';
            stk.pop();
            last=cur;
        }
    }
    cout<<'\n';
}

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

    fun(root); // 预期输出：pos-order: 4 5 2 3 1 

    return 0;
}

/*
// 定义二叉树节点结构
struct Node {
    int val;        // 节点值
    Node* left;     // 左子树指针
    Node* right;    // 右子树指针
    // 构造函数：简化节点创建
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 非递归后序遍历：左 → 右 → 根
void pos2(Node* h) {
    cout << "pos-order: ";
    if (h == nullptr) { // 空树直接返回
        cout << endl;
        return;
    }

    stack<Node*> stk;  // 存储节点的栈
    stk.push(h);       // 根节点入栈
    Node* c = nullptr; // 记录当前栈顶节点（待判断的节点）
    Node* last = nullptr; // 记录上一次处理的节点（核心：标记子树是否已遍历）

    while (!stk.empty()) {
        c = stk.top(); // 查看栈顶节点（不弹出）

        // 情况 1：左子树存在，且左、右子树均未处理过（last 不是左/右）
        if (c->left != nullptr && last != c->left && last != c->right) {
            stk.push(c->left); // 压入左子树，优先处理左
        } 
        // 情况 2：右子树存在，且右子树未处理过（last 不是右）
        else if (c->right != nullptr && last != c->right) {
            stk.push(c->right); // 压入右子树，处理右
        } 
        // 情况 3：左、右子树均已处理（或不存在），弹出当前节点并处理
        else {
            cout << stk.top()->val << " "; // 打印当前节点
            stk.pop();                     // 弹出节点
            last = c;                      // 更新 last 为当前处理的节点
        }
    }
    cout << endl;
}

*/
