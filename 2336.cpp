/**
 * @file 2336.cpp 无限集中的最小数字
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * @cite https://leetcode.cn/problems/smallest-number-in-infinite-set/description/  
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <set>

using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        if(set.empty()){
            int ans = flage;
            flage++;
            return ans;
        }
        int ans = *set.begin();
        set.erase(set.begin());
        return ans;
    }
    
    void addBack(int num) {
        if(num < flage)set.insert(num);
    }
private:
    // 我们设置一个有序的序列，并且设置一个flage，num >= flage时候，则表示我们已经将这个数加入到集合中了
    // 因为flage是在删除的时候+1，所以它指向的是集合中最小的数，当我们插入的数num < flage 则表示集合中没有，可以add
    int flage = 1;
    set<int> set;
};

int main(){
    SmallestInfiniteSet* smallestInfiniteSet = new SmallestInfiniteSet();
    smallestInfiniteSet->addBack(2);    // 2 已经在集合中，所以不做任何变更。
    cout << smallestInfiniteSet->popSmallest() << endl; // 返回 1 ，因为 1 是最小的整数，并将其从集合中移除。
    cout << smallestInfiniteSet->popSmallest() << endl; // 返回 2 ，并将其从集合中移除。
    cout << smallestInfiniteSet->popSmallest() << endl; // 返回 3 ，并将其从集合中移除。
    smallestInfiniteSet->addBack(1);    // 将 1 添加到该集合中。
    cout << smallestInfiniteSet->popSmallest() << endl; // 返回 1 ，因为 1 在上一步中被添加到集合中，
                                                         // 且 1 是最小的整数，并将其从集合中移除。
    cout << smallestInfiniteSet->popSmallest() << endl; // 返回 4 ，并将其从集合中移除。
    cout << smallestInfiniteSet->popSmallest() << endl; // 返回 5 ，并将其从集合中移除。
    return 0;
}
