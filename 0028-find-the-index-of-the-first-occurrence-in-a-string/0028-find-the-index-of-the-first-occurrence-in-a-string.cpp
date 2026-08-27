class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx=-1;

        int n=haystack.length();

        for(int i=0; i<n; i++){

            if(haystack[i]==needle[0]){
                int tidx=i;
                int cnt=0;

                for(int j=0; j<needle.size() && tidx<n; j++){
                    if(haystack[tidx]==needle[j]){
                        cnt++;
                    }
                    tidx++;
                }

                if(cnt==needle.length()){
                    idx=i;
                    break;
                }
            }
        }

        return idx;
    }
};