https://leetcode.cn/problems/trapping-rain-water/
int trap(int* height, int heightSize){
    int st[20005],top = -1;

    int ans = 0;
    for(int i=0;i<heightSize;i++){

        while(top >= 1 && height[i] >= height[st[top]]){
            if(height[i] > height[st[top]]){
                int  w = height[st[top]];
                top --;
                int h = fmin(height[i], height[st[top]]) - w;
                ans += h * (i - st[top] - 1);
                //printf("%d %d %d\n",i,h,(i - st[top] - 1));
            }
            else if(height[i] == height[st[top]]){
                top --;
            }
           
        }
        if(top == 0 && height[i] >= height[st[top]]) top --;
        top ++;
        st[top] = i;
    }  
    return ans;
}