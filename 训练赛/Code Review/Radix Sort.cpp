#include<bits/stdc++.h>
using namespace std;

// 定义二叉树节点结构（注：当前代码未使用，可根据需求扩展）
struct Node {
    int val;         // 节点存储的值
    Node* left;      // 左子树指针
    Node* right;     // 右子树指针
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 获取数字 num 的第 d 位（从右往左，第 1 位是个位，第 2 位是十位...）
int getnum(int num, int d) {
    for (int i = 1; i < d; i++) {
        num = num / 10; // 右移：去掉低位，直到保留第 d 位
    }
    return num % 10;     // 返回第 d 位的数字
}

// 基数排序核心逻辑：按 digit 位进行排序（仅处理非负整数）
void radixSort(vector<int>& num, int l, int r, int digit) {
    const int radix = 10;       // 基数：0~9（十进制）
    vector<int> help(r - l + 1); // 辅助数组，存储排序结果
    int k;

    // 逐位处理：从第 1 位（个位）到第 digit 位（最高位）
    for (int d = 1; d <= digit; d++) {
        vector<int> count(radix, 0); // 计数数组：统计当前位各数字的出现次数

        // 1. 统计当前位数字的出现次数
        for (int i = r; i >= l; i--) {
            k = getnum(num[i], d);  // 获取第 d 位的数字
            count[k]++;             // 对应数字的计数 +1
        }

        // 2. 前缀和转换：count[i] 表示 <= i 的数字总个数（用于确定元素位置）
        for (int i = 1; i < radix; i++) {
            count[i] += count[i - 1]; // 累加得到前缀和
        }

        // 3. 稳定排序：从后往前遍历，保证相同数字的相对位置不变
        for (int i = r; i >= l; i--) {
            k = getnum(num[i], d);
            // 根据 count 定位元素在辅助数组中的位置
            help[count[k] - 1] = num[i];
            count[k]--; // 相同数字下次放前一个位置（保证稳定性）
        }

        // 4. 回写结果：将辅助数组的内容写回原数组
        for (int i = l; i <= r; i++) {
            num[i] = help[i - l]; // 映射辅助数组索引（help 从 0 开始）
        }
    }
}

// 获取数组中最大值的位数（确定基数排序的总位数）
int mxwide(const vector<int>& num) {
    if (num.empty()) return 0;
    int mx = num[0];
    for (int n : num) {
        mx = max(mx, n); // 找最大值（仅处理非负整数）
    }

    int cnt = 0;
    while (mx > 0) { // 计算最大值的位数
        mx = mx / 10;
        cnt++;
    }
    return cnt;
}

// 对外接口：基数排序入口（仅处理非负整数）
void radixSort(vector<int>& num) {
    int n = num.size();
    if (n < 2) return; // 空数组或长度 <2，无需排序

    int digit = mxwide(num); // 获取最大值的位数
    radixSort(num, 0, n - 1, digit); // 对整个数组进行基数排序
}

// 打印数组内容（辅助函数）
void printArray(const vector<int>& num, const string& desc) {
    cout << desc << "：";
    for (int n : num) {
        cout << n << " ";
    }
    cout << endl;
}

int main() 
{
    // 测试用例 1：基本正整数场景
    vector<int> arr1 = {123, 45, 678, 90, 12, 345};
    printArray(arr1, "测试用例 1（基本正整数）排序前");
    radixSort(arr1);
    printArray(arr1, "测试用例 1（基本正整数）排序后");
    // 预期结果：12 45 90 123 345 678

    // 测试用例 2：包含 0 和重复值
    vector<int> arr2 = {0, 123, 0, 45, 45, 99};
    printArray(arr2, "测试用例 2（包含 0 和重复值）排序前");
    radixSort(arr2);
    printArray(arr2, "测试用例 2（包含 0 和重复值）排序后");
    // 预期结果：0 0 45 45 99 123

    // 测试用例 3：大数值测试（验证高位处理）
    vector<int> arr3 = {123456, 98765, 1000000, 999999, 123};
    printArray(arr3, "测试用例 3（大数值测试）排序前");
    radixSort(arr3);
    printArray(arr3, "测试用例 3（大数值测试）排序后");
    // 预期结果：123 98765 123456 999999 1000000

    // 测试用例 4：全重复值测试
    vector<int> arr4 = {555, 555, 555, 555};
    printArray(arr4, "测试用例 4（全重复值）排序前");
    radixSort(arr4);
    printArray(arr4, "测试用例 4（全重复值）排序后");
    // 预期结果：555 555 555 555

    // 测试用例 5：单元素数组（边界测试）
    vector<int> arr5 = {999};
    printArray(arr5, "测试用例 5（单元素数组）排序前");
    radixSort(arr5);
    printArray(arr5, "测试用例 5（单元素数组）排序后");
    // 预期结果：999

    // 测试用例 6：空数组（边界测试）
    vector<int> arr6;
    printArray(arr6, "测试用例 6（空数组）排序前");
    radixSort(arr6);
    printArray(arr6, "测试用例 6（空数组）排序后");
    // 预期结果：空数组

    // 测试用例 7：递增序列（验证稳定性）
    vector<int> arr7 = {1, 2, 3, 4, 5, 6};
    printArray(arr7, "测试用例 7（递增序列）排序前");
    radixSort(arr7);
    printArray(arr7, "测试用例 7（递增序列）排序后");
    // 预期结果：1 2 3 4 5 6

    // 测试用例 8：递减序列（验证排序逻辑）
    vector<int> arr8 = {6, 5, 4, 3, 2, 1};
    printArray(arr8, "测试用例 8（递减序列）排序前");
    radixSort(arr8);
    printArray(arr8, "测试用例 8（递减序列）排序后");
    // 预期结果：1 2 3 4 5 6

    return 0;
}