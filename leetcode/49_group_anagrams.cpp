class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz = strs.size();
        unordered_map<string, vector<string>>anagram;
        
        for(int i=0;i<sz;i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            anagram[str].push_back(strs[i]);
        }
        
        vector<vector<string>>answer;
        for(pair<string, vector<string>>pi : anagram){
            answer.push_back(pi.second);
        }
        return answer;         
    }
};
