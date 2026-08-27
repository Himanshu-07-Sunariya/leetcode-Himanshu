class Solution {
public:
    int lengthOfLastWord(string s) {

        int n=s.length();
        int temp=0;
        
        for(int i=n-1; i>=0; i--){
            if(s[i]!=' '){
                temp++;
            }
            else{
                if(temp!=0){
                    break;
                }
            }
        }

        return temp;
    }
};