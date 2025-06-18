// lower bound logic -- return ind if present else return ind of first bigger ele
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    int n, target, temp1;
    cin>>n>>target;
    temp1=n;
    while(temp1--){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    int left=0, right=n-1;
    int ans=-1;

    while(left<right){
        int mid= (left+right)/2;
        if(arr[mid] >= target){
            ans= mid;
            right= mid-1;
        }
        else{
            left= mid+1;
        }
    }
    return ans;
}