class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        string ans = "";
            int anss = INT_MAX;
        for (int i = 0; i < n; i++) {
            string temp = "";
            int cnt = 0;
            int len = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    cnt++;
                }
                len++;
                temp += s[j];
                if (cnt == k) {
                    if (anss > len) {
                        anss = len;
                        ans = temp;
                    } else if (anss == len && (ans == "" || temp < ans)) {
                        anss = len;
                        ans = temp;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};