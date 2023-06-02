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