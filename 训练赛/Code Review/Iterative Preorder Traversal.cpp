//前序遍历
#include <iostream>
#include <stack>  // 引入栈头文件
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int v):val(v),left(nullptr),right(nullptr){}
};

void fun(Node* head)//并没有涉及到递归的过程，用一个栈就完成了全部任务
{
    if(head==nullptr)
    {
        cout<<'\n';
        return;
    }
    stack<Node*>sta;
    sta.push(head);
    while(!sta.empty())
    {
        Node* pre=sta.top();
        sta.pop();
        cout<<pre->val<<' ';
        if(pre->right!=nullptr)
        {
            sta.push(pre->right);
        }
        if(pre->left!=nullptr)
        {
            sta.push(pre->left);
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

    fun(root); // 调用前序遍历，预期输出：pre-order: 1 2 4 5 3 

    // 注意：实际需递归释放内存（此处简化，未写 delete 逻辑）
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

// 非递归前序遍历：根 → 左 → 右
void pre(Node* head) {
    cout << "pre-order: ";
    if (head == nullptr) { // 空树直接返回
        cout << endl;
        return;
    }

    stack<Node*> stk;  // 创建栈，存储节点指针
    stk.push(head);    // 根节点入栈

    while (!stk.empty()) { // 栈非空时循环
        Node* cur = stk.top(); // 取栈顶节点
        stk.pop();             // 弹出栈顶（处理当前节点）

        cout << cur->val << " "; // 打印当前节点值

        // 先压右孩子（栈是后进先出，右先压，左后压 → 左先弹出处理）
        if (cur->right != nullptr) {
            stk.push(cur->right);
        }
        if (cur->left != nullptr) {
            stk.push(cur->left);
        }
    }
    cout << endl;
}


*/