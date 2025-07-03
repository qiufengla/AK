/*
给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。

请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。

任何误差小于 10-5 的答案都将被视为正确答案。

 

示例 1：

输入：nums = [1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
示例 2：

输入：nums = [5], k = 1
输出：5.00000
 

提示：

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double  sum=0,av=0,mx=INT_MIN;
        int l=nums.size();
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        // if (l == 0 || k <= 0 || k > l) {
        //     return 0.0;
        // }
        mx=max(mx,sum*1.0/k);
        for(int i=1;i<=l-k;i++)
        {
            sum=sum-nums[i-1];
            sum+=nums[i+k-1];

            av=sum*1.0/k;
            mx=max(mx,av);
        }
        return mx;
    }
};
