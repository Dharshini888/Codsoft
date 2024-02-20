#include<iostream>
using namespace std;
int cal(int c)
{
    while(c)
    {
        float a,b;
    char op;
    cout<<"\nEnter Two Values:"<<endl;
    cin>>a>>b;
    
    cout<<"Enter a Operator:";
    cin>>op;
    if(op=='+')
    {
        cout<<"The Addition :"<<a+b;
    }
    else if(op=='-')
    {
        cout<<"The Subtration :"<<a-b;
    }
    else if(op=='*')
    {
        cout<<"The Multiplication :"<<a*b;
    }
    else if(op=='/')
    {
        cout<<"The Division :"<<a/b;
    }
    else
    {
        cout<<"The Operation is Invalid";
    }
    c--;
    }
}
int main()
{
    cout<<" Simple Calculator "<<endl;
    int c;
    cout<<"Enter How many times the Program need to run :";
    cin>>c;
    cal(c);
}