#include<vector>

class Solution {
public:
void mergeInplace(vector<int>& nums,int start,int mid, int end){
    int total_len=end-start+1;
    int gap=total_len/2 + total_len%2;//ceil
    while(gap>0){
        int i=start , j=start+gap;
        while(j<=end){
            if(nums[i]>nums[j]){
                swap(nums[i],nums[j]);
            }
            i++,j++;
        }
        gap=gap<= 1 ? 0 : (gap/2) +(gap%2) ; //agar gap<=1 ho gay toh gap =0 ho jayega : else gap ko update kr do  
    }

}
void mergesort(vector<int>& nums,int start, int end){
    //bc
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    mergesort(nums,start,mid);
    mergesort(nums,mid+1,end);
    mergeInplace(nums,start,mid,end);
}
    vector<int> sortArray(vector<int>& nums) {
        
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};