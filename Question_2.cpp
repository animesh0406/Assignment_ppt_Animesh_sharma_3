/*
    Question 2
Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:
           ● 0 <= a, b, c, d < n
           ● a, b, c, and d are distinct.
           ● nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> quadrupletsum(vector<int> &nums, int target){
    sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target) {
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        for(auto quadruplets : s)
            output.push_back(quadruplets);
        return output;
}
int main(){
    cout<<"Given array is :"<<endl;

    vector<int>v1={1,0,-1,0,-2,2};
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    vector<vector<int>>v=quadrupletsum(v1,0);
    cout<<"The answer is"<<endl;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<" "<<v[i][j];
        }
        cout<<endl;
    }
}