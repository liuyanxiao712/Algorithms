//
// Created by lyx on 6/22/2019.
//

//This program use divide and conquer method
//to solve the maximum subarray problem

#include <iostream>
#include <cmath>
#include <iostream>

int cross_sm(int arr[], int l, int m, int r){
    int sm = 0;
    int left_sm = -100;
    for(int i = m; i <l - 1; i--){
        sm = sm + arr[i];
        if(sm > left_sm){
            left_sm = sm;
        }
    }
    sm = 0;
    int right_sm = -100;
    for(int i = m + 1; i < r + 1; i++){
        sm = sm + arr[i];
        if(sm > right_sm){
            right_sm = sm;
        }
    }
    return left_sm+right_sm;
}

int compare(int a, int b, int c){
    int max;
    if(a > b){
        max = a;
    } else {
        max = b;
    }
    if(c > max){
        max = c;
    }
    return max;

}

int Max_SubArray_sm(int arr[], int l, int r){
    if(l == r){
        return arr[l];
    }
    int m = (l + r) / 2;
    int q = compare(Max_SubArray_sm(arr, l, r), Max_SubArray_sm(arr, m + 1, r), cross_sm(arr, l, m, r));
    return q;
}

int main(){
    int arr[8] = {2,3,-5,7,8,-2,7,-3};
    int length = sizeof(arr)/ sizeof(arr[0]);
    int max_sm = Max_SubArray_sm(arr, 0, length - 1);
    std::cout << "Maximum contiguous sum is " << max_sm << std::endl;
}