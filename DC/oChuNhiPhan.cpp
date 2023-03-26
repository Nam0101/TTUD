// cho bảng N*N, mỗi ô có giá trị là 0 hoặc 1
// cho tập D các từ, mỗi từ có độ dài <=50 
// đếm số từ xuất hiện trong D
//
// Input:
// 3
// 3
// 1 0 1
// 0 1 0
// 1 0 1
// 3
// 101
// 010
// 101
//
// Output:
// 3
//
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[100][100];
int res = 0;
const double eps = 1e-6;
void input(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
}
// using devide and conquer
int countSolution(int i, int j, int k){
    if(k == 0){
        return 1;
    }
    if(i == n || j == n){
        return 0;
    }
    int res = 0;
    res += countSolution(i + 1, j, k - 1) * a[i][j];
    res += countSolution(i, j + 1, k - 1) * a[i][j];
    return res;
}

