class Solution {
public:
    bool helper_Rec(int idx1,int idx2,string s,string p){
        // base case
        if(idx1==s.length() && idx2==p.length()) return true;
        // oye pattern khtm hogya string bchi wtf glt baat
        if(idx1!=s.length() && idx2==p.length()) return false;

        if(idx1==s.length() && idx2!=p.length()){
            for(int i=idx2; i<p.length(); i++){
                if(p[i]!='*') return false;
            }
            return true;
        }

        // selfwork + recursive call
        if(s[idx1]==p[idx2]){
            return helper_Rec(idx1+1,idx2+1,s,p);
        }
        else if(p[idx2]=='?'){
            return helper_Rec(idx1+1,idx2+1,s,p);
        }
        else if(p[idx2]=='*'){
            // star k teen choices h
            bool blank=helper_Rec(idx1,idx2+1,s,p);
            bool onechar=helper_Rec(idx1+1,idx2+1,s,p);
            bool multiplechar=helper_Rec(idx1+1,idx2,s,p);

            return blank || onechar || multiplechar;
        }
        return false;
    }

    bool isMatch(string s, string p) {
        // int idx1=0;
        // int idx2=0;

        // return helper_Rec(idx1,idx2,s,p);
        int n=s.length();
        int m=p.length();

        vector<vector<bool>> dp(s.length()+1, vector <bool> (p.length()+1,false));

        // base case fill
        dp[n][m]=1;

        for(int j=m-1; j>=0; j--){
            if(p[j]=='*'){
                dp[n][j]=true;
            }
            else{
                break;
            }
        }

        // reverse logic
        for(int idx1=n-1; idx1>=0; idx1--){
            for(int idx2=m-1; idx2>=0; idx2--){
                // selfwork + recursive call
                if(s[idx1]==p[idx2]){
                    dp[idx1][idx2]=dp[idx1+1][idx2+1];
                }
                else if(p[idx2]=='?'){
                    dp[idx1][idx2]=dp[idx1+1][idx2+1];
                }
                else if(p[idx2]=='*'){
                    // star k teen choices h
                    bool blank=dp[idx1][idx2+1];
                    bool onechar=dp[idx1+1][idx2+1];
                    bool multiplechar=dp[idx1+1][idx2];

                    dp[idx1][idx2]=blank || onechar || multiplechar;
                }
                else{
                    dp[idx1][idx2]=false;
                }
            }
        }

        return dp[0][0];
    }
};