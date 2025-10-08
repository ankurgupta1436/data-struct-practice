//Accessing of elenments using dot operetor and pointer operator in stack
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;

};
int main(){
    /*struct Rectangle r = {10,5};
    //Dot operator
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    //Pointer operator
    Rectangle *p=&r;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
    return 0;

    //in heap memory allocation
    Rectangle *p;
    p=(struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 15;
    p->breadth = 7;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
    return 0;*/

    //in c++ we use new keyword instead of malloc
    struct Rectangle*p;
    p = new Rectangle;
    p->length =15;
    p->breadth = 7;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
    return 0 ;
  
    
}