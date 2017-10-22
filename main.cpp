#include <iostream>
#include <cstdlib>
#include <string.h>
#include <ctime>

using namespace std;

void pas(int n,char x[],char y[],int k)
{
    if(n>k)
    {
        for(int i=0;i<95;i++)
        {
            y[k]=' '+i;
            pas(n,x,y,k+1);
            if(strcmp(x,y)==0)
                break;
        }
    }
}

int main()
{
    int n;
    cout<<"The number of characters contained by the password is ";
    cin>>n;
    char c[n+1],r[n+1];
    srand (time(NULL));
    for(int i=0;i<n;i++)
    {
        c[i]=' '+(rand()%95);
    }
    c[n]='\0';
    r[n]='\0';
    cout<<"The password is ";
    pas(n,c,r,0);
    for(int i=0;i<n;i++)
        cout<<r[i];
    cout<<endl;
    cout<<"The set up password was ";
    for(int i=0;i<n;i++)
        cout<<c[i];
    return 0;
}

/*
the worst time complexity to find out a password when the only knowledge is
the number of characters is achieved when every possibility is checked.
Thus, assuming the user is allowed to use every character available on the keyboard
0-9 (10 characters)
~`!@#$%^&*()_-=+[]\;'.,/{}|:"?>< (32 characters)
A-Z (26 characters)
a-z (26 characters)
" "->space (1 character)
there exist 95 possibilities.
By using brute force, through θ(95^n) you can get the password in exponential time.
*/
