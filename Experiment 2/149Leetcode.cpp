class Solution {
public:
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            map<pair<int,int>, int> mp;
            int maxPointsOnLine = 0;
            
            for(int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                
                mp[{dx, dy}]++;
                maxPointsOnLine = max(maxPointsOnLine, mp[{dx, dy}]);
            }
            
            ans = max(ans, maxPointsOnLine + 1); // +1 for anchor point
        }
        
        return ans;
    }
};