#include <iostream>
#include<stdio.h>
using namespace std;
/*int main(){
    int a = 10;
    cout<<a;
    return 0 ;
}*/

int main(){
    int a = 10 ;
    int *p;
    p = &a;
    cout<<a<<endl;
    printf("Using pointer %d",*p);
    return 0;
}

/*int main(){
    int A[5]= {2,4,6,8,10};
    int *ptr;
    ptr = A;
    for(int i = 0;i<5;i++)
    cout<<A[i] <<endl;
    return 0;
}*/

// In heap memory allocation
/*int main(){
    int *p;
    p=(int*)malloc(5*sizeof(int));
    p[0]=10;p[1]=15;p[2]=14;p[3]=21;p[4]=31;
    for(int i=0;i<5;i++)
    cout<<p[i]<<endl;
    return 0;
}*/

//in c++ we use new keyword instead of malloc
/*int main(){
    int *p;
    p= new int[5];
    p[0]=10;p[1]=15;p[2]=14;p[3]=21;p[4]=31;
    for(int i=0;i<5;i++)
    cout<<p[i]<<endl;
    delete[]p;
    return 0;
}*/