#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> preSum;
int getSum(int row, int col){
  if(row < 0 || col < 0)
    return 0;
  return preSum[row][col];
}

int sumRegion(int row1, int col1, int row2, int col2) {
  int get1 = getSum(row2,col2), get2 = getSum(row1-1,col2), get3 = getSum(row2,col1-1), get4 = getSum(row1-1,col1-1);  
  int x =  getSum(row2,col2) - getSum(row1-1,col2) - getSum(row2,col1-1) + getSum(row1-1,col1-1);
  cout<<"Sum region"<<endl;
  cout<<"getSum(row2,col2) - getSum(row1-1,col2) - getSum(row2,col1-1) + getSum(row1-1,col1-1)"<<endl;
  cout<<get1<<"-"<<get2<<"-"<<get3<<"+"<<get4<<"="<<x<<endl;
  return x;
}

int largestSubgrid(vector<vector<int>>& grid, int k){
  int n = grid.size();
  preSum.resize(n,vector<int>(n,0));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        int get1 = getSum(i-1,j);
        int get2 = getSum(i,j-1);
        int get3 = getSum(i-1,j-1) ;
        int get4 = grid[i][j];
      
      int x = getSum(i-1,j) + getSum(i,j-1) - getSum(i-1,j-1) + grid[i][j];

      cout<<x<<",";
      preSum[i][j] = x;
    }
    cout<<endl;
  }
  int low = 0, high = n, ans = 0;
  while(low <= high){
    int mid = low + (high - low)/2;
    cout<<"low:"<<low<<";high:"<<high<<";mid:"<<mid<<";ans:"<<ans<<endl;
    if(mid == 0)
    return 0;
    bool stop = false;
    for(int i=mid-1; i<n && !stop; i++){
      for(int j=mid-1; j<n && !stop; j++){
        int subSum = sumRegion(i-mid+1,j-mid+1,i,j);
        if(subSum > k){
          stop = true;
        }
      }
    }
    if(stop){
      high = mid - 1;
    }
    else{
      ans = mid;
      low = mid + 1;
    }
  }
  return ans;
}
int main() {
  vector<vector<int>> mat = {{2,2,2},
                             {3,3,3},
                             {4,4,4}
                             };
  cout<<largestSubgrid(mat,15)<<endl;
}