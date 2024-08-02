#include<iostream>
using namespace std;

int main(){
    int nums[] = {2, 3, 1, 2, 0};
    int n = 5;
    int pos = 0;
    int cnt = 0;
    while(pos < n - 1){
        cout << pos <<"->";
        //现在可以到达的位置 [pos + 1, pos + nums[pos]]
        cnt++;
        int next_pos = pos + 1;
        if(pos + nums[pos] >= n - 1){
            pos = n - 1;
            continue;
        }
            
        for(int i = pos + 2; i <= pos + nums[pos]; i++){
            if(nums[i] + i > next_pos + nums[next_pos]){
                next_pos = i;
            }
        }
        pos = next_pos;
    }
    cout << n - 1 <<endl;
    cout <<cnt <<endl;

    return 0;
}