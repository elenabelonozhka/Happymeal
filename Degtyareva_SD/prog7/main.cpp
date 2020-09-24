#include <iostream>
#include <string>
bool ReadArray(int* arr, int n) {//считываем массив
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> arr[i]))
            return false;
    }
    return true;
}
void PrintArray(int* arr, int n){
    for(int i = 0; i < n; i++) {
        std::cout << arr[i]<<" ";
    }
    std::cout<<std::endl;
}
int main() {
    int n;
    std::cout << "Input N " << std::endl;
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
    std::cout << "Input mass" << std::endl;
    if(!A){
        std::cerr << "Can't allocate memory! " << std::endl;
        return 3;
    }
    if(!ReadArray(A,n)){
        std::cerr << "Can't read array! " << std::endl;
        return 4;
    }
    int k1=0;//левая граница единиц
    int k2=n-1;//левая граница двоек проверенных
    int k3=0;//правая граница единиц
    for(int i=k1;i<=k2;i++){
        if(A[i]==0)
        {
            int tmp=A[i];
            A[i]=A[k1];
            A[k1]=tmp;
            k1++;
            k3++;
            continue;
        }
        if(A[i]==1)
        {
            k3++;
            continue;
        }
        if(A[i]==2)
        {
            for(int j=k2;j>=k3;j--)
            {
                if(A[j]!=2)
                {
                    int tmp=A[i];
                    A[i]=A[j];
                    A[j]=tmp;
                    k2--;
                    break;
                }
            }
            i--;
        }
    }
   /* for(j=k2;j>=0;j--)
        if(A[j]==2)
        {
            break;
        }
        k2=j;
        if(k1<k2)
        {
            tmp=A[k1];
            A[k1]=A[k2];
            A[k2]=tmp;
        }
    }*/
    PrintArray(A,n);
    return 0;
}
