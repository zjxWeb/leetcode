/**
 * @file 215.cpp  数组中的第K个最大元素
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quick_sort(nums, 0, n-1);
        return nums[n-k];
    }
private:
/*
 * 快速排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     l -- 数组的左边界(例如，从起始位置开始排序，则l=0)
 *     r -- 数组的右边界(例如，排序截至到数组末尾，则r=a.length-1)
 */
    void quick_sort(vector<int>& nums, int l, int r)
    {
        if (l < r)
        {
            int i,j,x;

            i = l;
            j = r;
            x = nums[i];
            while (i < j)
            {
                while(i < j && nums[j] > x)
                    j--; // 从右向左找第一个小于x的数
                if(i < j)
                    nums[i++] = nums[j];
                while(i < j && nums[i] < x)
                    i++; // 从左向右找第一个大于x的数
                if(i < j)
                    nums[j--] = nums[i];
            }
            nums[i] = x;
            quick_sort(nums, l, i-1); /* 递归调用 */
            quick_sort(nums, i+1, r); /* 递归调用 */
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << s.findKthLargest(nums, k) << endl;
    return 0;
}