class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector <int> freq(26,0);
        // sliding window wiht frequency

        int left=0;
        int right=0;

        int maxLen=0;
        // int count=0;

        while(right<s.length()){
            // main case
            freq[s[right]-'a']++;

            // shrinking part
            while(left<s.length() && freq[s[right]-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }

            
            maxLen=max(maxLen,right-left+1);
            right++;
        }

        return maxLen;
    }
};