//
// Created by GuoylyL on 2022/9/15.
//
#include <iostream>
#include <vector>
int process_max(int arr[], int L, int R) {
    if (L == R) {
        return arr[L];
    }
    int mid = (R + L) / 2;
    //int mid = L+((R-L)>>1);
    int leftMax = process_max(arr, L, mid);
    int rightMax = process_max(arr, mid + 1, R);
    return std::max(leftMax, rightMax);
}

int getMax(int arr[], int n) {
    return process_max(arr, 0, n - 1);
}

void merge(int *arr, int L, int mid, int R) {
    int *help = new int[R - L + 1];
    int i = 0;
    int p1 = L;
    int p2 = mid + 1;
    while (p1 <= mid && p2 <= R) {
        if (arr[p1] < arr[p2])
            help[i++] = arr[p1++];
        else
            help[i++] = arr[p2++];
    }
    while (p1 <= mid) {
        help[i++] = arr[p1++];
    }
    while (p2 <= R) {
        help[i++] = arr[p2++];
    }
    for (int i = L; i <= R; i++) {
        arr[i] = help[i - L];
    }
    delete[] help;
}

//递归方法
void process(int *arr, int L, int R) {
    if (L == R)
        return;
    int mid = L + ((R - L) >> 1);
    process(arr, L, mid);
    process(arr, mid + 1, R);
    merge(arr, L, mid, R);
}

//非递归方法
void N_process(int *arr) {
    int mergeSize = 1;
    int N = 7;
    if (arr == nullptr || N < 2) return;
    while (mergeSize < N) {
        int L = 0;
        while (L < N) {
            int M = L + mergeSize - 1;
            if (M >= N) break;
            int R = std::min(M + mergeSize, N - 1);
            merge(arr, L, M, R);
            L = R + 1;
        }
        if (mergeSize > N / 2) break;
        mergeSize <<= 1;
    }
}
//再一个数组中，一个数左边比它小的数的总和 叫做数的小和，所有数的小和累加起来叫数的组小和，求数组小和
int merge_t(int *arr,int L,int M,int R){
    int *help = new int[R - L + 1];
    int p1 = L;
    int p2 = M + 1;
    int i = 0;
    int res = 0;
    while(p1 <= M && p2 <= R){
        if(arr[p1] < arr[p2]){
            res += (R - p2 + 1) * arr[p1];
            help[i++] = arr[p1++];
        }
        else{
            res = 0;
            help[i++] = arr[p2++];
        }
    }
    while(p1 <= M){
        help[i++] = arr[p1++];
    }
    while(p2 <= R){
        help[i++] = arr[p2++];
    }
    for(int i = L; i <= R; i++){
        arr[i] = help[i - L];
    }
    delete[] help;
    return res;
}
int process_t(int *arr,int L,int R){
    if(L==R) return 0;
    int M = L + ((R - L) >> 1);
    return process_t(arr,L,M)+ process_t(arr,M+1,R)+ merge_t(arr,L,M,R);
}
void my_swap(int *arr,int i,int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
//partition 把小于等于num的数放在数组的左边，大于num的数放在数组的右边
int partition(int *arr,int L,int R){
    if(L > R) return -1;
    if(L == R) return L;
    int lessequal = L - 1;
    int index = L;
    while(index < R){
        if(arr[index] <= arr[R]){ //用最后一个数作为基准进行比较
            my_swap(arr,index,++lessequal);
        }
        index++;
    }
    my_swap(arr,++lessequal,R);
    return lessequal;
}


/* 给定一个数组arr和一个整数num，把小于num的数放在数组的左边，大于num的数放在数组的右边,等于num的放中间
 * 空间复杂度O(1)，时间复杂度O(N) */
int * netherlandsFlag(int *arr, int L, int R){
    if(L > R) return new int[]{-1,-1};
    if(L == R) return new int[]{L,R};
    int less = -1;
    int more = R;
    int index = L;
    while(index < more){
        if(arr[index] == arr[R]){
            index ++;
        }
        else if(arr[index] < arr[R]){
            my_swap(arr,index++,++less);
        }
        else{
            my_swap(arr,index,--more);
        }
    }
    my_swap(arr,more,R);
    return new int[]{less+1,more};
}
//快速排序1.0
//整个数组上，用最后一个值作划分值，做partition，大于等于x的放左边，小于x的放右边，x不动
//然后将x放到大于x的第一个，则得到了  <=x| x | >x 递归解决


//快速排序2.0
//



/*
int main() {
    int a[] = {3, 7, 8, 9, 1,10 ,0, 2,4};
    //process(a, 0, 7);
    //N_process(a);
    //std::cout << process_t(a,0,7)<<"\n";
//    for (auto i: a) {
//        std::cout << i << ",";
//    }
    int *s = netherlandsFlag(a,0,8);
    //int g = partition(a,0,8);
    for(auto i:a){
        std::cout << i<<",";
    }
    std::cout<<"lessEqual: "<<std::endl;
    std::cout<<*(s)<<std::endl;
    std::cout<<*(s+1)<<std::endl;


    return 0;
}

*/

