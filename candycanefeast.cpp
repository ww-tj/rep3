#include<iostream>
using namespace std;

int main(){
    int N, M;
    cin >>N >>M;
    int canes[M];
    long long cows[N];
    for(int i = 0; i < N; i++)
        cin >>cows[i];
    for(int i = 0; i < M; i++)
        cin >>canes[i];
    
    for(int i = 0; i < M; i++){
        int eats = 0;
        for(int j = 0; j < N; j++){

            if(cows[j] > eats && cows[j] < canes[i]){
                int tmp = eats;
                eats = cows[j];
                cows[j] += cows[j] - eats;
            }else if(cows[j] >= canes[i]){
                cows[j] += canes[i] - eats;
                break;
            }
            
        }
    }
    for(int i = 0; i < N; i++)
        cout <<cows[i] <<endl;


    return 0;
}