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


/*
Question 3
A permutation of an array of integers is an arrangement of its members into a
sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater
permutation of its integer. More formally, if all the permutations of the array are
sorted in one container according to their lexicographical order, then the next
permutation of that array is the permutation that follows it in the sorted container.

If such an arrangement is not possible, the array must be rearranged as the
lowest possible order (i.e., sorted in ascending order).

● For example, the next permutation of arr = [1,2,3] is [1,3,2].
● Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
● While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
*/
#include<bits/stdc++.h>
using namespace std;
 void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            for (int i = n-1; i > idx; i--) {
                if (nums[i] > nums[idx]) {
                    swap(nums[i], nums[idx]);
                    break;
                }
            }
        }
        reverse(nums.begin()+idx+1, nums.end());
    }
int main(){
    vector<int> nums={1,2,3};
    cout<<"Before"<<endl;
    for(int i=0; i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    nextPermutation(nums);
    cout<<endl<<"The answer is "<<endl;
    for(int i=0; i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}


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


/*
Question 5
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most significant
to least significant in left-to-right order. The large integer does not contain any
leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]

Explanation:The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

*/
#include<bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int>& v) {
        int n = v.size();

        for(int i=n-1; i>=0; i--){
            if(v[i]<9){
                ++v[i];
                return v;
            }else{
                v[i] = 0;
            }
        }

        v.push_back(0);      // to handle '999' => 999 + 1 = 1000
        v[0] = 1;
        return v;
}
// Since iterating array only once therefore complexity(time)=O(n)
int main(){
     vector<int>ans={1,9,9,9,9};
    cout<<"Current number is"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;

    ans=plusOne(ans);
    cout<<"Number after plus one is"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    return 0;


}



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


/*
Question 8
Given an array of meeting time intervals where intervals[i] = [starti, endi],
determine if a person could attend all meetings.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
*/
#include<bits/stdc++.h>
using namespace std;
bool toAttend(vector<vector<int>>&v){
    sort(v.begin(), v.end());
    for(int i = 1; i < v.size();i++){
        if(v[i][0]<v[i-1][1]){
            return false;
        }
    }
    return true;
}
//Time complexity O(nlogn)
int main(){
    vector<vector<int>> intervals={{0,30},{15,20},{5,10}};
    if(toAttend(intervals)){
        cout<<"Can attend the meeting"<<endl;
    }
    else cout<<"Cannot attend"<<endl;
    return 0;
}

