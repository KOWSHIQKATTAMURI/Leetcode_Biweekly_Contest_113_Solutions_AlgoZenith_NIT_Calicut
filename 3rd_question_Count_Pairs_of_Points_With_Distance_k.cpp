class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k){
        int n = c.size(), ans = 0;
        //map is used to store the number of values of (x_new, y_new) that satsify the required condition with every (x, y) in the 2D vector c.
        map<pair<int, int>, int> mp;
        for(int i = 0; i < n; i++){
            //according to the question, the condition is c[i][0]^x_new +c[i][1]^y_new = k                   
            //let c[i][0]^x_new = temp, then c[i][1]^y_new = k - temp
            //the most important property of XOR is that if a^b = c, then a^c = b.
            /*so we can have the following results:
                       c[i][0]^temp = x_new
                       c[i][1]^(k - temp) = y_new;
            */
            //considering the fact that temp has the range of [0, k], we can traverse through all possible values of temp to get all (x_new, y_new)
            for(int temp = 0; temp <= k; temp++){
                int x_new = temp^c[i][0];    
                int y_new = (k - temp)^c[i][1];
                pair<int, int> p = {x_new, y_new};
                //mp[p] = 0 if the coordinate (x_new, y_new) has not been visited so far
                ans += mp[p];
            }
            pair<int, int> p = {c[i][0], c[i][1]};
            mp[p]++;
        }
        return ans;
    }
};
