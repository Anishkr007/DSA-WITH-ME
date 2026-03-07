class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        int lp=0;
        int rp=n-1;
        int max_Area=0;
        while(lp<rp){
            int w=rp-lp;
            int h=min(height[lp],height[rp]);

            int area=w*h;

            max_Area=max(area,max_Area);

            if(height[lp]<height[rp]?lp++:rp--);


        }
        return max_Area;
    }
};