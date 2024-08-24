class Solution {
public:
    bool isThereSubset(vector<int>nums,int sum){
        int n=nums.size();
        bool t[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    t[i][j]=false;
                }
                if(j==0){
                    t[i][j]=true;
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }

        return t[n][sum];
    }

    int minimumDifference(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        //now that we know the sum, there should definetly be one subset contributing equal or greater than half the sum
        //so we run a loop checking if there is a subset 

        int num=sum/2;
        while(true){
            if(isThereSubset(nums,num)){
                return abs(num-abs(sum-num));
            }
            num++;
        }
        return -1;
    }
};