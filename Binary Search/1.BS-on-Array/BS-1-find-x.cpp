#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 ;
        int h = nums.size()-1;
        int mid;

        while(l<=h){
            mid = (l+h)/2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                l++;
            }
            else{
                h--;
            }
        }
        return -1;
    }
};