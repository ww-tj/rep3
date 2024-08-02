#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    bool find = false;

    for(int m=2;m<=n-1;m+=1)
    {
        if(n%m==0){
            find = true;
        }
    }

    if(find == true){
        cout << "不是质数" <<endl;
    }else{
        cout <<"是质数" <<endl;
    }

    
}