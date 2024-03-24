// class Solution {
// public:
//     int maxWidthOfVerticalArea(vector<vector<int>>& points) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(0);
//         cout.tie(0);
        
//         sort(points.begin(),points.end());
//         int ans = 0;
//         for(int i = 1; i < points.size(); i++)
//         {
//             int prevX = points[i - 1][0];
//             int currX = points[i][0];
//             ans = max(ans, currX - prevX);
//         }
//         return ans;
//     }
// };