/*
 Question 4
Given a sorted array of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in
order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
*/
#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {

        int beg = 0;
        int end = nums.size()-1;
        int mid=0;
     if(nums[nums.size()-1]<target)
            return nums.size();
        if(nums[0]>target)
            return 0;
        while(beg<=end)
        {
             mid= (beg+end)/2;
            if(nums[mid]>target) {

                if(nums[mid-1]<target)
                    return mid;
             end = mid-1;}
            if(nums[mid]<target){

                if(nums[mid+1]>target)
                    return mid+1;
             beg=mid+1;}
            if(nums[mid]==target)
                return mid;
         }
        if(nums[nums.size()-1]<target)
            return nums.size();

        return 0;

}
// Time complexity O(log n)
int main(){
    vector<int>nums={1,3,5,6};//can change the input to check the correctness of algo
    int k=searchInsert(nums,5);
    cout<<"The index is "<<k<<endl;
    return 0;
}