// solution1 : recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        
        if(plen == 0)return slen==0;
        
        bool first_letter = slen>0 && (p[0]==s[0] || p[0]=='.');
        
        if(plen >= 2 && p[1] == '*'){
            return isMatch(s, p.substr(2)) || (first_letter && isMatch(s.substr(1), p));
        }
        else{
            return first_letter && (isMatch(s.substr(1), p.substr(1)));
        }
    }
};

// solution2 : dp
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        
        bool dp[slen+1][plen+1];
        for(int i=0;i<=slen;i++){
            for(int j=0;j<=plen;j++){
                dp[i][j] = false;
            }
        }
        
        dp[slen][plen] = true;
        
        for(int i=slen; i>=0; i--){
            for(int j=plen-1; j>=0; j--){
                bool first_letter = i<slen && (p[j]==s[i] || p[j]=='.');
                if(j+1<plen && p[j+1]=='*')
                    dp[i][j] = dp[i][j+2] || (first_letter && dp[i+1][j]);
                else
                    dp[i][j] = first_letter && dp[i+1][j+1];
            }
        }
        
        return dp[0][0];
    }
};
