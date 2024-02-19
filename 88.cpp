#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = nums1.size(),n2 = nums2.size();
        int i  = 0,j = 0;
        if(n1 > m) i = m;
        else i = n1;
        if(n2 > n) j = n;
        else j = n2;
        for(int k = i,h = 0; k <= n1 && h < j; k++,h++){
            nums1[k] = nums2[h];
        }
        sort(nums1.begin(),nums1.end());
    }
};

int main(){
    vector<int> nums1 = {1,2,3,0,0,0},nums2 = {2,5,6};
    Solution s;
    s.merge(nums1,3,nums2,3);
    for(auto i : nums1) cout << i << " ";
}

