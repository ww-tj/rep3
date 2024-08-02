#include<bits/stdc++.h>
using namespace std;

int N, Q;
string expression[200000];

bool parse(string s){
    if(s == "true"){
        return true;
    }
    return false;
}

char func(int l, int r, string target){
    bool res[N / 2 + 1];
    int idx = 0;
    int start = 0, finish = 0;
    bool res2 = false;
    while(finish < N){
        bool tag = expression[finish] == "true";
        // 起点start, 终点finish
        while(finish < N - 1 && expression[finish + 1] == "and"){
            finish += 2;
            if(expression[finish] == "false")
                tag = false;
        }
        //check [start, finish]这一段的结果在tag里面， 然后放到res；
        if(tag == true){
            res2 = true;
            break;
        }
        res[idx++] == tag;
    }


}

char isValid(int l, int r, string target){
    string stack[N/2 + 1];
    int top = -1;
    int i = 0;

    while(i < N){
        if(i == l) stack[++top] = target;
        else stack[++top] = expression[i];

        if(top > 0 && expression[i - 1] == "and"){
            if(parse(stack[top]) && parse(stack[top - 1]))
                stack[top - 1] = "true";
            else
                stack[top - 1] = "false";
            top--;
        }
        if(i == l) i = r;
        i += 2;
    }
    bool result = false;
    for(int i = 0; i <= top; i++){
        if(stack[i] == "true"){
            result = true;
            break;
        }
    }
    return result == parse(target)? 'Y': 'N';
}

int main(){
    cin >>N >>Q;
    for(int i = 0; i < N; i++)
        cin >>expression[i];
    
    string ans;
    while(Q--){
        int l, r;
        cin >>l >>r;
        l--;
        r--;
        string target;
        cin >>target;

        ans += isValid(l, r, target);


    }
    cout <<ans <<endl;
    return 0;
}