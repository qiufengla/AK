#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <iomanip> // 用于格式化输出
using namespace std;

// 定义二叉树节点结构
struct Node {
    int val;        // 节点值
    Node* left;     // 左子树指针
    Node* right;    // 右子树指针
    Node(int v) : val(v), left(nullptr), right(nullptr) {} // 构造函数
};

// 根据字符串生成节点（辅助函数）
Node* generateNode(const string& val) {
    if (val == "null") { // 空节点标记
        return nullptr;
    }
    return new Node(stoi(val)); // 非空节点，转换为 int 并创建节点
}

// 根据层序序列化队列重建二叉树
Node* buildByLevelQueue(queue<string> levelList) {
    if (levelList.empty()) { // 队列为空，返回空树
        return nullptr;
    }

    // 1. 构建根节点
    string rootVal = levelList.front();
    levelList.pop();
    Node* head = generateNode(rootVal);

    if (head == nullptr) { // 根节点为空（空树）
        return nullptr;
    }

    // 2. 层序遍历的节点队列（存储待处理的节点）
    queue<Node*> q;
    q.push(head);

    Node* node = nullptr; // 当前处理的节点

    while (!levelList.empty() && !q.empty()) { // 队列非空且还有数据需要处理
        node = q.front(); // 取出队首节点
        q.pop();

        // 处理左子节点
        if (!levelList.empty()) { // 确保队列还有数据
            string leftVal = levelList.front();
            levelList.pop();
            node->left = generateNode(leftVal);
            if (node->left != nullptr) { // 左子节点非空，入队等待处理
                q.push(node->left);
            }
        }

        // 处理右子节点
        if (!levelList.empty()) { // 确保队列还有数据
            string rightVal = levelList.front();
            levelList.pop();
            node->right = generateNode(rightVal);
            if (node->right != nullptr) { // 右子节点非空，入队等待处理
                q.push(node->right);
            }
        }
    }

    return head;
}

// 辅助函数：计算树的高度（用于可视化打印）
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

// 辅助函数：填充节点值到二维数组（用于可视化打印）
void fillValues(Node* node, vector<vector<string>>& res, int row, int col, int height) {
    if (node == nullptr) return;
    res[row][col] = to_string(node->val);
    // 计算下一层的列偏移量
    int offset = 1 << (height - row - 2); // 2^(height - row - 2)
    // 填充左子树
    fillValues(node->left, res, row + 1, col - offset, height);
    // 填充右子树
    fillValues(node->right, res, row + 1, col + offset, height);
}

// 可视化打印树结构（简易格式）
void printTreeStructure(Node* head) {
    if (head == nullptr) {
        cout << "树结构：空树" << endl;
        return;
    }

    int height = getHeight(head);
    int width = (1 << height) - 1; // 总宽度：2^height - 1
    vector<vector<string>> res(height, vector<string>(width, " "));

    // 填充节点值
    fillValues(head, res, 0, width / 2, height);

    // 打印树结构
    cout << "树结构（可视化）：" << endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << setw(2) << res[i][j]; // 每个位置占2个字符宽度
        }
        cout << endl;
    }
}

// 层序遍历打印（验证重建结果）
void levelPrint(Node* head) {
    if (head == nullptr) {
        cout << "层序打印：null" << endl;
        return;
    }

    queue<Node*> q;
    q.push(head);
    cout << "层序打印：";

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (cur == nullptr) {
            cout << "null ";
        } else {
            cout << cur->val << " ";
            // 空节点也入队，保证层序格式完整
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    cout << endl;
}

// 释放树内存
void destroyTree(Node* root) {
    if (root == nullptr) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

// 测试用例生成工具：将字符串数组转换为队列
queue<string> createQueue(const vector<string>& vals) {
    queue<string> q;
    for (const string& val : vals) {
        q.push(val);
    }
    return q;
}

// ===================== 测试用例 =====================
int main() {
    // 测试用例 1：完全二叉树
    // 层序序列：1 2 3 4 5 6 7
    // 树结构：
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    cout << "=== 测试用例 1：完全二叉树 ===" << endl;
    vector<string> vals1 = {"1", "2", "3", "4", "5", "6", "7"};
    queue<string> q1 = createQueue(vals1);
    Node* root1 = buildByLevelQueue(q1);
    levelPrint(root1); // 预期：1 2 3 4 5 6 7 null null null null null null null null 
    printTreeStructure(root1);
    destroyTree(root1);
    cout << endl;

    // 测试用例 2：左斜树
    // 层序序列：1 2 null 3 null null 4
    // 树结构：
    //       1
    //      /
    //     2
    //    /
    //   3
    //  /
    // 4
    cout << "=== 测试用例 2：左斜树 ===" << endl;
    vector<string> vals2 = {"1", "2", "null", "3", "null", "null", "4"};
    queue<string> q2 = createQueue(vals2);
    Node* root2 = buildByLevelQueue(q2);
    levelPrint(root2); // 预期：1 2 null 3 null null 4 null null ...
    printTreeStructure(root2);
    destroyTree(root2);
    cout << endl;

    // 测试用例 3：右斜树
    // 层序序列：1 null 2 null 3 null 4
    // 树结构：
    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    cout << "=== 测试用例 3：右斜树 ===" << endl;
    vector<string> vals3 = {"1", "null", "2", "null", "3", "null", "4"};
    queue<string> q3 = createQueue(vals3);
    Node* root3 = buildByLevelQueue(q3);
    levelPrint(root3); // 预期：1 null 2 null 3 null 4 null ...
    printTreeStructure(root3);
    destroyTree(root3);
    cout << endl;

    // 测试用例 4：非对称树
    // 层序序列：1 2 3 4 null null 5 null 6
    // 树结构：
    //       1
    //      / \
    //     2   3
    //    /     \
    //   4       5
    //    \
    //     6
    cout << "=== 测试用例 4：非对称树 ===" << endl;
    vector<string> vals4 = {"1", "2", "3", "4", "null", "null", "5", "null", "6"};
    queue<string> q4 = createQueue(vals4);
    Node* root4 = buildByLevelQueue(q4);
    levelPrint(root4); // 预期：1 2 3 4 null null 5 null 6 null null null ...
    printTreeStructure(root4);
    destroyTree(root4);
    cout << endl;

    // 测试用例 5：空树
    // 层序序列：null
    cout << "=== 测试用例 5：空树 ===" << endl;
    vector<string> vals5 = {"null"};
    queue<string> q5 = createQueue(vals5);
    Node* root5 = buildByLevelQueue(q5);
    levelPrint(root5); // 预期：null
    printTreeStructure(root5);
    destroyTree(root5);

    return 0;
}