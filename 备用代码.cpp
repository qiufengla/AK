#include<bits/stdc++.h>
using namespace std;
const int MX=1e3;
int n,y;
string s;
int m[MX+10][MX+10];


int main() {
    cin>>n;
    cin>>s;
    int len=s.size();
    int x = n / 2, y = n / 2; // 中心点坐标
    int num = 0;
    int step = 1; // 当前层步长
    int dir = 0;  // 方向：0右，1下，2左，3上

    m[x][y] = num++;

    while (step < n*n) {
        for (int layer = 0; layer < 2; layer++) { // 每方向走两次
            for (int i = 0; i < step; i++) {
                // 根据方向移动坐标
                switch (dir) {
                    case 0: x--; break;
                    case 1: y++; break; // 右
                    case 2: x++; break; // 下
                    case 3: y--; break; // 左
                    // 上
                }
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if(num<=len-1) m[x][y] = num++;
                    else m[x][y] = len;
                }
            }
            dir = (dir + 1) % 4;
        }
        step++;
    }

    // 打印矩阵
    for (int i = 0;i< n; i++) {
        for (int j = 0; j < n; j++) {
        	if((s[m[i][j]]>='a'&&s[m[i][j]]<='z')||(s[m[i][j]]>='A'&&s[m[i][j]]<='Z'))
        	{
        		cout<<s[m[i][j]];
			}
        }
    }
    cout<<'\n'; 
    return 0;
}
