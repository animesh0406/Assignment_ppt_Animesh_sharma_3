/*
Question 7
You are given an inclusive range [lower, upper] and a sorted unique integer array
nums, where all elements are within the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in
nums.

Return the shortest sorted list of ranges that exactly covers all the missing
numbers. That is, no element of nums is included in any of the ranges, and each
missing number is covered by one of the ranges.

Example 1:
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]

Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> missingRange(vector<int>& nums,int lower, int upper){
    vector<vector<int>> v;
    int k=0;
     if(lower<nums[0]){
            vector<int>ans={lower,nums[0]-1};
            v.push_back(ans);
        }
    for(int i = 1; i < nums.size()-1;i++){
       
        if(nums[i]+1!=nums[i+1]){
                vector<int>ans={nums[i]+1,nums[i+1]-1};
                v.push_back(ans);
        }
       }
        if(nums[nums.size()-1]<upper){
            vector<int>ans={nums[nums.size()-1]+1,upper};
            v.push_back(ans);
        }
    return v;
}
int main(){
    vector<int>v={0,1,3,50,75};
    cout<<"Given Array is"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<vector<int>> ans=missingRange(v,0,99);
    cout<<"The Ranges are: "<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
}