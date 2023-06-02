/*
Question 1
Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to the target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include<bits/stdc++.h>
using namespace std;
int closetSum(vector<int> &nums,int target){
    int i=0;
    int diff = INT_MAX;
    int si,ei;
    int sum=0;
    int val=0;
    sort(nums.begin(),nums.end());
    for(i=0;i<nums.size()-1;i++){
        si=i+1;
        ei=nums.size()-1;
        while(si<ei){
            sum=nums[i]+nums[si]+nums[ei];
            if((abs(sum-target)<diff)){
                diff=abs(sum-target);
                val=sum;
            }
            if(sum==target){
                return target;
            }
            else if(sum<target){
                si++;
            }
            else{
                ei--;
            }
        }

    }
    return val;
}


int main(){
    vector<int> v={-1,2,1,-4};
    cout<<"The array is "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"The answer is "<<closetSum(v,1)<<endl;
    return 0;
}