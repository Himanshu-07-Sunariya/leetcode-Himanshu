class Solution {
public:

    vector <string> result;

    //recursive code
    void helper(string digits,int index,string ans,unordered_map<int,vector<char>> &mp){
        //+ve base case
        if(index==digits.length()){
            result.push_back(ans);
            return;
        }

        //recursive loop + self work
        int key=digits[index]-'0';

        for(char ch:mp[key]){
            helper(digits,index+1,ans+ch,mp);
        }
    }

    vector<string> letterCombinations(string digits) {
        string ans;
        int index=0;

        if(digits.length()==0){
            return result;
        }

        unordered_map<int, vector<char>> mp {
            {2,{'a','b','c'}},
            {3,{'d','e','f'}},
            {4,{'g','h','i'}},
            {5,{'j','k','l'}},
            {6,{'m','n','o'}},
            {7,{'p','q','r','s'}},
            {8,{'t','u','v'}},
            {9,{'w','x','y','z'}}
        };


        helper(digits,index,ans,mp);

        return result;
    }
};