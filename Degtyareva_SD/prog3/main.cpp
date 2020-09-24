
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
    std::cout << "Input N" << std::endl;
    if(!(std::cin >> n)){
        std::cerr << "Can't read N! " << std::endl;
        return 1;
    }
    /*std::cout << "Input M " << std::endl;
     if(!(std::cin>>m)){
     std::cout << "Can't read M! " << std::endl;
     }*/
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
    //int tmp;
    int pr=0;
    int i=0;
    int tmp=0;//возрастание иначе убывание
    for(i=0;i<n-1;i++)
    {
        if(A[i]<A[i+1] && tmp==0)
        {
            pr-=A[i];
            tmp=1;
            continue;
        }
        if(A[i]<A[i+1] && tmp==1)
            continue;
        if(A[i]>A[i+1] && tmp==1)
        {
            pr+=A[i];
            tmp=0;
            continue;
        }
        if(A[i]>A[i+1] && tmp==0)
            continue;
        if (A[i]==A[i+1])
            continue;
    }
    if (A[n-1]>A[n-2] && tmp==1)
        pr+=A[n-1];
    std::cout << "Result: "<< pr <<std::endl;
    return 0;
}
