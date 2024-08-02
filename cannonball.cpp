#include<iostream>
using namespace std;

int main(){
    int N, S;
    cin >>N >>S;
    int q[N], v[N];
    for(int i = 0; i < N; i++)
        cin >>q[i] >>v[i];
    int pos = S - 1;
    int power = 1;


    int dirc = 1; //   right->   pos = pos + power
                    //   left->    pos = pos - power
                    // pos = pos + dirc * power

    int record = 0;
    bool broken[N];
    for(int i = 0; i < N; i++)
        broken[i] = false;

    int cnt = 0;
    while(pos >= 0 && pos < N && cnt < 999999){
        cnt++;
        //jump pad
        if(q[pos] == 0){
            //pos, power, dirc需要变化
            dirc = !dirc;
            power += v[pos];
            pos += dirc * power;
        }
        //target
        else{
            // judge(broken[i] == false,  power >= v[i])
            if(power >= v[pos] && !broken[pos]){
                broken[pos] = true;
                record++;
            }
            //改变pos
            pos += dirc * power;

        }
    }

    cout << record <<endl;
    return 0;
}