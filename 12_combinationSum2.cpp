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

            // Skip duplicates
            if (i > index && arr[i] == arr[i - 1]) continue; //gpt

            //"If the current number is the same as the previous one, and we're at the same level of recursion — skip it to avoid duplicate combinations."

            // if (arr[i] > target) break; // Optimization
            // "The current number is already bigger than the remaining target — no point in going further."



            v.push_back(arr[i]);
            solve(arr,target-arr[i],ans,v,i+1);
            //bt
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int> v; //current vector 
        solve(candidates, target,ans,v,0);
        
        return ans ;


    }
};