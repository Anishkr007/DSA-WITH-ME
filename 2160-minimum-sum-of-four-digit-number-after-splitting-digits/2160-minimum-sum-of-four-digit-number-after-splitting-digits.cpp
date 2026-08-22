class Solution {
public:
    int minimumSum(int num) {
        vector<int>d;

        while(num){
            int digit=num%10;
            d.push_back(digit);
            num=num/10;
        }

        sort(d.begin(),d.end());

        if(d[0]==0){
            return d[1]*10+d[2]+d[3];
        }
        return d[0]*10+d[2]+d[1]*10+d[3];
    }
};