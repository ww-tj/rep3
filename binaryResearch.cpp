#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, float target){
    int left = 0;
    int right = n-1;
    while (left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    // right, left 分别在target的两侧
    // cout << "right:" <<right <<endl;
    // cout << "left:" <<left <<endl;
    return -1;
}


int binarySearch_recursion(int arr[], int left, int right, int target){
    if(right < left){
        return -1;
    }
    int mid = (left + right) / 2;
    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] < target){
        return binarySearch_recursion(arr, mid + 1, right, target);
    }else{
        return binarySearch_recursion(arr, left, mid - 1, target);
    }
}

// 找到第一个target的index
int binarySearch_firstEle(int arr[], int n, int target){
    int left = 0;
    int right = n-1;
    while (left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == target){
            right = mid - 1;
        }else if(arr[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    if(target == arr[left])
        return left;
    else 
        return -1;
}

// 找到第一个大于或等于target的index
int binarySearch_firstEle2(int arr[], int n, int target){
    int left = 0;
    int right = n-1;
    while (left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == target){
            right = mid - 1;
        }else if(arr[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

//旋转 升序数组 中的最小值
int min_element(int a[], int n){
    int left = 0, right = n - 1;
    while(left <= right){
        if(a[left] < a[right]){
            return a[left];
        }
        int mid = left + (right - left) / 2;
        if(a[mid] < a[right]){
            right = mid;
        }else if(a[mid] > a[left]){
            left = mid + 1;
        }else{
            //mid == left
            return min(a[left], a[right]);
        }
    }
}

//旋转 非降序数组 中的最小值
int min_element2(int a[], int n){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(a[left] <= a[mid] && a[mid] <= a[right]){
            return a[left];
        }else if(a[left] <= a[mid]){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
}


int main(){
    int a[] = {6, 7, 1, 2, 2, 2, 2, 2, 3};
    int n = 7;
    cout <<min_element(a, n) <<endl;
    cout <<min_element2(a, n) <<endl;
    return 0;
}
