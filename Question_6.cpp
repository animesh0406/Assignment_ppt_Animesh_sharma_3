/*
Question 6
Given a non-empty array of integers nums, every element appears twice except
for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only
constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1
*/
#include<bits/stdc++.h>
using namespace std;
int findUnique(vector<int>& nums){
    int sum=0;
    for(int i=0; i<nums.size();i++){
        sum^=nums[i];
    }
    return sum;
}
int main(){
    vector<int>v={2,2,3,3,4,4,5,5,1};
    cout<<"The given array is"<<endl;
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"The unique element is "<<findUnique(v)<<endl;
}