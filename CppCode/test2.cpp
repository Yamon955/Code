/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cnt,tmp[2005];
void dfs(int* candidates,int pos,int num,int sum,int candidatesSize, int target,int** ans,int **returnColumnSizes)
{
    if(sum > target) return;
    if(sum == target){
        for(int i=0;i<num;i++) ans[cnt][i] = tmp[i];
        returnColumnSizes[cnt] = num; 
        cnt++;
        return;
    }
    for(int i=pos;i<candidatesSize;i++){
        tmp[num] = candidates[i];
        dfs(candidates,i,num+1,sum+candidates[i],candidatesSize,target,ans,returnColumnSizes);
    }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **ans = (int **) malloc(sizeof(int *) * 2005);
    for(int i=0;i<2005;i++) ans[i] = (int *) malloc (sizeof(int) * 2005);

    returnColumnSizes = (int *)malloc(sizeof(int)*2005);
    cnt = 0;
    dfs(candidates,0,0,0,candidatesSize,target,ans,returnColumnSizes);

    *returnSize = cnt;
    return ans;


}
int main()
{
    
}