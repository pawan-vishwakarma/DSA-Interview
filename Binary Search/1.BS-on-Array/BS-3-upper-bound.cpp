#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]= {1,9,5,6,2,3};
    int n=6;
    int left=0, right= n-1;
    int target= 6, ans=-1;
    while(left < right){
        int mid= (left+right)/2;
        
        if(arr[mid] > target){
            ans= mid;
            right= mid-1;
        }
        else{
            left= mid+1;
        }
    }
    return ans;
}