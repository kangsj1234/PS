class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<bool>visit(len, false);
        
        int cur = 0;
        visit[0] = true;
        for(int i=0;i<len;i++){
            int jump = nums[i];
            if(!visit[i])continue;
            int to = min(i+jump, len-1);
            if(to==len-1)return true;
            for(int j=cur+1;j<=to;j++){
                visit[j] = true;  
                cur = j;
            }
        }
        if(visit[len-1])return true;
        return false;
    }
};
