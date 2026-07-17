class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int,int>ans;
        ans={0,0};
        for(auto ch : moves){
            if(ch=='R'){
                ans.first+=1;
            }
             if(ch=='L'){
                ans.first-=1;
            }
             if(ch=='U'){
                ans.second-=1;
            }

            if(ch=='D'){
                ans.second+=1;
            }

        }

        if(ans.first==0){
            if(ans.second==0){
                return true;
            }
        }

        return false;
    }
};