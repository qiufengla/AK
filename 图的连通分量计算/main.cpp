/*
题目描述
有 n 座城市，依次坐落在一条直线上，相邻城市之间的距离为 1，且相邻城市之间原本有一条公路。现在，一场百年难遇的地震导致所有公路都被破坏了。
然而，每座城市都有一台空间传送机，可以从第 i 座城市传送到距离为 ai 的另一座城市，或者从距离为 ai 的城市传送到第 i 座城市（即从城市 i 可以传送到城市 i+ai 或 i−ai，或者反向传送，如果目标城市存在的话）。
现在，政府需要开展援助工作，希望能尽快实现从任意城市到任意城市的连通性。为此，政府决定修复部分公路。问至少修复多少长度的公路，才能满足上述要求？

输入
第一行一个整数 T(1≤T≤1000)，表示测试数据组数。
每组输入数据的第一行包含一个正整数 n(1≤n≤3×105)，表示城市数量。
第二行包含 n 个整数 a1,a2,…,an(1≤ai≤n)，表示每个城市的传送距离。
保证所有测试数据的 n 之和不超过 106。

输出
对于每组数据，输出一行一个整数表示需要最小需要修复公路的长度。
样例输入 Copy
2
4
1 2 1 3 
5
5 5 5 5 5
样例输出 Copy
0
4
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> graph(n + 1);
        for (int i = 1; i <= n; i++) {
            int to1 = i + a[i - 1];
            if (to1 <= n) {
                graph[i].push_back(to1);
                graph[to1].push_back(i);
            }
            int to2 = i - a[i - 1];
            if (to2 >= 1) {
                graph[i].push_back(to2);
                graph[to2].push_back(i);
            }
        }
        vector<bool> visited(n + 1, false);
        int components = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]==false) {
                components++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (int neighbor : graph[cur]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        cout << components - 1 << '\n';
    }
    return 0;
}

/*
为了解决这个问题，我们可以使用图的连通分量概念。每个城市通过传送机构成了一个无向图，我们需要计算这个图中的连通分量数量。然后，通过修复公路将这些连通分量连接起来，所需的最小公路长度即为连通分量数量减一。

方法思路
问题分析：城市按顺序排列在一条直线上，相邻城市距离为1。每个城市i有一个传送距离ai，可以从城市i传送到i+ai或i-ai（如果目标城市存在）。传送关系是双向的，形成无向图。

连通分量计算：使用BFS（广度优先搜索）遍历图中的所有节点，计算连通分量的数量。每个连通分量代表一组可以通过传送互相到达的城市。

修复公路：需要修复的公路数量等于连通分量数量减一，因为每条公路可以连接两个相邻的连通分量。


代码解释
输入处理：读取测试用例数量T，对于每组测试数据，读取城市数量n和传送距离数组a。

建图：构建一个邻接表表示的图。对于每个城市i，检查传送目标i+ai和i-ai是否存在。如果存在，则在图中添加双向边。

连通分量计算：使用BFS遍历图中的所有节点。初始化一个访问数组标记已访问的节点。遍历每个节点，如果未被访问，则进行BFS遍历并增加连通分量计数。

输出结果：计算需要修复的公路长度，即连通分量数量减一。每条公路长度为1，因此结果直接为components - 1。

这种方法通过BFS高效地计算连通分量，确保在最优时间内解决问题，适用于大规模输入数据。

*/
