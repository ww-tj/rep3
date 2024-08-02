#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int nums[5] = {2, 3, 1, 1, 0};
    int pos = 0;
    int step = 1;
    while(pos + nums[pos] < n - 1){
        // pos + 1 ~ pos + nums[pos]
        int idx = pos + 1;
        for(int i = pos + 2; i <= pos + nums[pos]; i++){
            // 找出两步跳的最远的, 即 max( i+nums[i] )
            if(i + nums[i] > idx + nums[idx]){
                idx = i;
            }
        }
        pos = idx;
        step++;
    }
    cout << step <<endl;
    return 0;
}