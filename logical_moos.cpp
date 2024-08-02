#include<bits/stdc++.h>
using namespace std;


int main(){
    int N, Q;
    cin >>N >>Q;
    string s[N];
    int or_pos[N / 2], idx = 0;
    unordered_set<int> or_st;
    for(int i = 0; i < N; i++){
        cin >>s[i];
        if(s[i] == "or") {
            or_pos[idx++] = i;
            or_st.insert(i);
        }
    }
    int num_groups = idx + 1, num_or = idx;
    bool group_result[num_groups];
    int idx_group[N/2 + 1];

    int group_first_false[num_groups], group_last_false[num_groups];
    fill(group_first_false, group_first_false + num_groups, N);
    fill(group_last_false, group_last_false + num_groups, -1);

    int start = 0;
    for(int i = 0; i < num_groups; i++){
        int end = i < num_or? or_pos[i] - 1: N - 1;
        bool res = true;
        for(int j = start; j <= end; j += 2){
            if(s[j] == "false"){
                if(res) group_first_false[i] = j;
                res = false;
                group_last_false[i] = j;
            }
            idx_group[j / 2] = i;
        }
        group_result[i] = res;
        start = end + 2;
    }
    int first_true = N, last_true = -1;
    for(int i = 0; i < num_groups; i++)
        if(group_result[i] == true){
            first_true = i < num_groups - 1? or_pos[i] - 1: N - 1;
            break;
        }
    for(int i = num_groups - 1; i >= 0; i--)
        if(group_result[i] == true){
            last_true = i > 0? or_pos[i - 1] + 1: 0;
            break;
        }

    string ans;
    while(Q--){
        int l, r;
        cin >>l >>r;
        --l; 
        --r;
        string target;
        cin >>target;
        bool tag = target == "true"? true: false;

        if(l > first_true || r < last_true){
            ans += true == tag? 'Y': 'N';
        }else{
            bool tag_false = false;
            int l_group = idx_group[l/2], r_group = idx_group[r/2];
            if(group_first_false[l_group] < l || group_last_false[r_group] > r)
                tag_false = true;
            if(tag_false && tag) ans += 'N';
            else ans += 'Y';
            
        }
    }
    cout << ans <<endl;
}