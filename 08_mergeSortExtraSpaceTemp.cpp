class Solution {
public:
void merge(vector<int>& nums, vector<int>& temp,int start,int mid, int end){
    int i=start, j=mid+1 , k=start;
    while(i<=mid && j<=end){
        if(nums[i]<= nums[j]){
            temp[k]=nums[i];
            k++; i++;
        }
        else{
            temp[k]=nums[j];
            k++;j++;
        }
    }
    //simple mergesort waps likh rahe hai 
    while(i<=mid) temp[k++]=nums[i++];
    while(j<=end) temp[k++]=nums[j++];
    while(start<=end){ //jo bhi temp array mein sort kiya usko main arr mein copy 
        nums[start]=temp[start];
        start++;
    }

}
void mergesort(vector<int>& nums, vector<int>& v,int start, int end){
    //bc
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    mergesort(nums,v,start,mid);
    mergesort(nums,v,mid+1,end);
    merge(nums,v,start,mid,end);
}
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size(),0);
        mergesort(nums,temp,0,nums.size()-1);
        return nums;
    }
};