#include <iostream>
#include <string>
bool ReadArray(int* arr, int n) {
     for (int i = 0; i < n; i++) {
        if (!(std::cin >> arr[i]))
            return false;
        }
     return true;
     }
int main() {
    int n;
    int m;
    std::cout << "Input N and M " << std::endl;
    if(!(std::cin >> n >> m)){
        std::cerr << "Can't read N and M! " << std::endl;
        return 1;
    }
    if(n<=0 || m<=0 ){
        std::cerr << "N or M <= 0! " << std::endl;
        return 2;
    }
    if(n>m)
        std::cout << "Repeat input " << std::endl;
    int* A = new int[n];
    int* B = new int[m];
    if((!A) || (!B)){
        std::cerr << "Can't allocate memory! " << std::endl;
        return 3;
    }
    std::cout << "Input mass A" << std::endl;
    if(!ReadArray(A,n)){
        std::cerr << "Can't read array! " << std::endl;
        return 4;
    }
    std::cout << "Input mass B" << std::endl;
    if(!ReadArray(B,m)){
        std::cerr << "Can't read array! " << std::endl;
        return 5;
    }
    int i=n-1;
    int j=m-1;
    int k=0;
    while(i>=0 && j>=0){
            if(A[i]==B[j])
            {
                i--;
                j--;
                k++;
            }
            if(A[i]!=B[j])
            {
                j--;
            }
    }
   /* for(int i=0;i<n;i++){
        if (A[i]==B[j]){
                tmp1++;
                j++;
                continue;
            }
        }
    int k=0;
    for(int i=0;i<m;i++){
        if (B[i]==A[k]){
            tmp2++;
            k++;
            continue;
        }
    }*/
    
    if(k==n)
    std::cout << "Yes "<<std::endl;
    else
    std::cout << "No "<<std::endl;
    delete []A;
    delete []B;
    return 0;
}
