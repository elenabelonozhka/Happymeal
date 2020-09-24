
#include <iostream>
#include <string>
bool ReadArray(int* arr, int n) {//считываем массив
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> arr[i]))
            return false;
    }
    return true;
}
int main() {
    int n;
    std::cout << "Input N " << std::endl;
    if(!(std::cin>>n)){
        std::cerr << "Can't read N! " << std::endl;
        return 1;
    }
    if(n<=0){
        std::cerr << "N <= 0! " << std::endl;
        return 2;
    }
    int* A = new int[n];
    if(!A){
        std::cerr << "Can't allocate memory! " << std::endl;
        return 3;
    }
    std::cout << "Input mass " << std::endl;
    if(!ReadArray(A,n)){
        std::cerr << "Can't read array! " << std::endl;
        return 4;
    }
    int  j=0;
    int tmp=A[0];
    for(int i=0;i<n;i++){
        if (A[i]==tmp){
            j++;
        }
        if (A[i]!=tmp){
            j--;
        }
        if (j==0){
            tmp=A[i];//кладем сюда элемент последовательности
            j++;
        }
    }
    std::cout << "Res "<< tmp << std::endl;
    delete[] A;
    return 0;
}
