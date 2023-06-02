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
