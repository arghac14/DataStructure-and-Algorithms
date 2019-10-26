#include<bits/stdc++.h>
using namespace std;


int GCD(int a, int b)
{
	return (b==0) ? a: GCD(b, a%b);
}

int LCM(int a, int b) 
{
		return (a*b) / GCD(a, b);
}



int main()
{
    int a , b;
	cin>> a >> b;
	cout<<"GCD = "<<GCD(a , b)<<endl;
	cout<<"LCM = "<<LCM(a , b)<<endl;

    return 0;
}
