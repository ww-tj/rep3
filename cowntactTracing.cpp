#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;

    int start,end;
    int min_days = INT_MAX;

    for(start = 0; start < N; start++){
        if(s[start] =='1'){
            for(end = start + 1; end < N; end++){
                if(s[end] == '0')
                    break;
            }
            //[start, end - 1]
            int days;
            int len = end - start;
            if(start == 0 || end == N){
                //区间接触到边界
                days = len - 1;
            }else{
                days = (len - 1) / 2;
            }
            min_days = min(min_days, days);
            start = end;
        }
    }
    
    return 0;
}