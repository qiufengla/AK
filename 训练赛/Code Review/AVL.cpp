#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义 AVL 树节点结构
typedef struct AVLNode {
    // 键
    int key;
    // 值（这里简单用字符串示例，可根据需求修改）
    char *value;
    // 高度，用于平衡因子计算
    int height;
    // 左子节点
    struct AVLNode *left;
    // 右子节点
    struct AVLNode *right;
} AVLNode;

// 创建一个新的 AVL 树节点
AVLNode* createAVLNode(int key, const char *value) {
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->key = key;
    newNode->value = (char *)malloc(strlen(value) + 1);
    strcpy(newNode->value, value);
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 获取节点的高度
int getHeight(AVLNode *node) {
    return node ? node->height : 0;
}

// 更新节点的高度
void updateHeight(AVLNode *node) {
    if (node) {
        node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    }
}

// 获取平衡因子（左子树高度 - 右子树高度）
int getBalanceFactor(AVLNode *node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// 左旋操作
AVLNode* leftRotate(AVLNode *y) {
    AVLNode *x = y->right;
    AVLNode *T2 = x->left;

    x->left = y;
    y->right = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// 右旋操作
AVLNode* rightRotate(AVLNode *x) {
    AVLNode *y = x->left;
    AVLNode *T2 = y->right;

    y->right = x;
    x->left = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// 插入节点（递归方式，保持 AVL 树平衡）
AVLNode* insertAVLNode(AVLNode *root, int key, const char *value) {
    // 普通二叉搜索树的插入
    if (!root) {
        return createAVLNode(key, value);
    }
    if (key < root->key) {
        root->left = insertAVLNode(root->left, key, value);
    } else if (key > root->key) {
        root->right = insertAVLNode(root->right, key, value);
    } else {
        // 键已存在，更新值（类似 TreeMap 的 put 覆盖已有键对应的值）
        free(root->value);
        root->value = (char *)malloc(strlen(value) + 1);
        strcpy(root->value, value);
        return root;
    }

    // 更新当前节点高度
    updateHeight(root);

    // 获取平衡因子，判断是否需要平衡
    int balance = getBalanceFactor(root);

    // 左左情况（右旋）
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }
    // 右右情况（左旋）
    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }
    // 左右情况（先左旋左子树，再右旋当前节点）
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // 右左情况（先右旋右子树，再左旋当前节点）
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// 查找节点
AVLNode* searchAVLNode(AVLNode *root, int key) {
    while (root) {
        if (key < root->key) {
            root = root->left;
        } else if (key > root->key) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

// 找到以 root 为根的树中最小键的节点（用于删除操作）
AVLNode* findMinNode(AVLNode *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

// 删除节点（递归方式，保持 AVL 树平衡）
AVLNode* deleteAVLNode(AVLNode *root, int key) {
    if (!root) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteAVLNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteAVLNode(root->right, key);
    } else {
        // 找到要删除的节点，分三种情况
        // 情况 1：没有子节点或只有一个子节点
        if (!root->left || !root->right) {
            AVLNode *temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp->value);
            free(temp);
        } else {
            // 情况 2：有两个子节点，找到右子树中最小键的节点替代
            AVLNode *temp = findMinNode(root->right);
            root->key = temp->key;
            free(root->value);
            root->value = (char *)malloc(strlen(temp->value) + 1);
            strcpy(root->value, temp->value);
            root->right = deleteAVLNode(root->right, temp->key);
        }
    }

    if (!root) {
        return root;
    }

    // 更新高度
    updateHeight(root);

    // 获取平衡因子，判断是否需要平衡
    int balance = getBalanceFactor(root);

    // 左左情况（右旋）
    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }
    // 右右情况（左旋）
    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }
    // 左右情况（先左旋左子树，再右旋当前节点）
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // 右左情况（先右旋右子树，再左旋当前节点）
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// 中序遍历（用于按键的升序输出，体现有序性）
void inorderTraversal(AVLNode *root) {
    if (root) {
        inorderTraversal(root->left);
        printf("Key: %d, Value: %s\n", root->key, root->value);
        inorderTraversal(root->right);
    }
}

// 释放 AVL 树内存
void freeAVLTree(AVLNode *root) {
    if (root) {
        freeAVLTree(root->left);
        freeAVLTree(root->right);
        free(root->value);
        free(root);
    }
}
int main() {
    AVLNode *treeMap = NULL;

    // 插入元素，类似 TreeMap 的 put 操作
    treeMap = insertAVLNode(treeMap, 3, "我是3");
    treeMap = insertAVLNode(treeMap, 4, "我是4");
    treeMap = insertAVLNode(treeMap, 8, "我是8");
    treeMap = insertAVLNode(treeMap, 5, "我是5");
    treeMap = insertAVLNode(treeMap, 7, "我是7");
    treeMap = insertAVLNode(treeMap, 1, "我是1");
    treeMap = insertAVLNode(treeMap, 2, "我是2");

    // 查找元素，类似 TreeMap 的 containsKey 和 get 操作
    AVLNode *foundNode = searchAVLNode(treeMap, 1);
    printf("containsKey(1): %s\n", foundNode ? "true" : "false");
    foundNode = searchAVLNode(treeMap, 10);
    printf("containsKey(10): %s\n", foundNode ? "true" : "false");

    foundNode = searchAVLNode(treeMap, 4);
    printf("get(4): %s\n", foundNode ? foundNode->value : "null");
    foundNode = searchAVLNode(treeMap, 10);
    printf("get(10): %s\n", foundNode ? foundNode->value : "null");

    // 更新元素，类似 TreeMap 的 put 覆盖操作
    treeMap = insertAVLNode(treeMap, 4, "他是4");
    foundNode = searchAVLNode(treeMap, 4);
    printf("get(4) after update: %s\n", foundNode ? foundNode->value : "null");

    // 删除元素，类似 TreeMap 的 remove 操作
    treeMap = deleteAVLNode(treeMap, 4);
    foundNode = searchAVLNode(treeMap, 4);
    printf("get(4) after delete: %s\n", foundNode ? foundNode->value : "null");

    // 中序遍历，按键升序输出，体现有序性
    printf("Inorder Traversal (sorted by key):\n");
    inorderTraversal(treeMap);

    // 释放内存
    freeAVLTree(treeMap);

    return 0;
}