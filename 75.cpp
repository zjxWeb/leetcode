#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0 = 0,n1 = 0;
        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            nums[i] = 2;
            if(num < 2){
                nums[n1++] = 1;
            }
            if(num < 1) {
                nums[n0++] = 0;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

int part(vector<int>&list,int l ,int r){
    if(list.empty()) return 0;
    int base = list[l];
    while(l < r){
        while(l < r && list[r] >= base) r--;
        list[l] = list[r];
        while(l < r && list[l] <= base) l++;
        list[r] = list[l];
    }
    list[l] = base;
    return l;
}

void quickSort(vector<int>&list,int l ,int r){
    if(l >= r) return;
    int mid = part(list,l,r);
    quickSort(list,l,mid-1);
    quickSort(list,mid+1,r);
}

int main(){
    vector<int>list = {9,1,2};
    quickSort(list,0,list.size()-1);
    for(int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl;
    return 0;

}
*/