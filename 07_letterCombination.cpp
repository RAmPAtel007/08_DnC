class Solution {
public:
    void solve( vector<string>& mapping,string output,string digits, vector<string>& ans, int index){
        //base case  //agar index string k bhahr nikl jaye 
        if(index>=digits.length()){
            ans.push_back(output);
            return ;
        }
        //1 case mera 
        int digit = digits[index]-'0'; //string to integer coversion 
        string value = mapping[digit]; // jo bhi value assigned hai us number pr 
        for(int i=0 ; i<value.length(); i++){
            char ch =value[i]; //charcter mel gaya ab esko include krna hai 
            output.push_back(ch);
            //re 
            solve(mapping,output,digits,ans ,index+1);
            //backtrack 
            output.pop_back();

        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        //empty case 
        if(digits.length()==0)
           return ans ;
        int index=0;
        string output="";
        vector<string> mapping(10);
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        solve(mapping,output,digits, ans,index);
        return ans;
        
    }
};