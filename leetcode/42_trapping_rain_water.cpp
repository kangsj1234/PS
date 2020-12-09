// time complexity : O(N)
// space complexity : O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;
        int len = height.size();
        if(len==0)return answer;
        
        vector<int>rightMax(len,0);
        int maxVal = height[len-1];
        for(int i=len-2;i>0;i--){
            rightMax[i] = maxVal;
            if(height[i]>maxVal)
                maxVal = height[i];
        }
        
        maxVal = height[0];
        for(int i=1;i<len-1;i++){
            int left = maxVal;
            int right = rightMax[i];
            
            if(maxVal<height[i])
                maxVal = height[i];
            
            if(height[i]>=left || height[i]>=right)continue;
            answer += min(left, right) - height[i];
        }
            
        return answer;
    }
};
