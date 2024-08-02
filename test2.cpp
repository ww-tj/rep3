#include<bits/stdc++.h>
using namespace std;

//找到target返回idx,否则返回-1
int binarySearch(int nums[], int left, int right, int target){
    if(right < left){
        return - 1;
    }
    int mid = (left + right) / 2;
    if(nums[mid] == target){
        return mid;
    }else if(nums[mid] < target){
        return binarySearch(nums, mid + 1, right, target);
    }else{
        return binarySearch(nums, left, mid - 1, target);
    }
}

//用循环做
int binarySearch2(int nums[], int n, int target){
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = (left + right)/2;
        if(nums[mid] == target){
            left = mid + 1;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int nums[] = {1, 2, 2, 2, 4, 5};
    int n = 6;
    int target = 2;
    cout << binarySearch2(nums, n, target) <<endl;
    return 0;
}