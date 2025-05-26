class Solution {
public:
    void solve(vector<int>& arr, int target, vector<vector<int>>& ans,vector<int>& v,int index){
        //bs
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0){
            return;
        }

        for(int i=index;i<arr.size(); i++){
            v.push_back(arr[i]);
            solve(arr,target-arr[i],ans,v,i);
            //bt
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> v; //current vector 
        solve(candidates, target,ans,v,0);
        return ans ;

    }
};