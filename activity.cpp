#include<iostream>
using namespace std;

struct Activity{
    int start, finish;
};
bool cmp(Activity a, Activity b){
    return a.finish < b.finish;
}

int main(){
    int s[10] = {3, 1, 5, 2, 5, 3, 8, 6, 8, 12};
    int f[10] = {6, 4, 7, 5, 9, 8, 11, 10, 12, 14};
    // (1, 4) -> (5, 7) -> (8, 11) -> (12, 14)
    Activity arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = {s[i], f[i]};
    } 
    sort(arr, arr + 10, cmp);
    int final = arr[0].finish;
    int record = 1; // 选取了arr[0]这个活动

    for(int i = 1; i < 10; i++){
        // 当前活动arr[i]可以选取
        if(arr[i].start >= final){
            final = arr[i].finish;
            cout << arr[i].start <<" " <<arr[i].finish <<endl;
            record++;
        }
    }
    cout <<record <<endl;
    return 0;
}