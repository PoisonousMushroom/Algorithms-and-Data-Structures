//Miron Oana P1.a)
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int x[n];
    int i;
    int mi=0;//min
    for(i=0;i<n;i++)
    {
        cin>>x[i];
        if(i==0||x[i]<mi)
        {
            mi=x[i];
        }
    }
    cout<<mi;
    return 0;
}
/*
In order to get the smallest element in a list you need to at most
check each element once (especially since the list is not ordered)
thus the worst time complexity should be θ(n) (Theta n) for n elements. There isn't a better
way to do that since even the best sorting would take Ω(n) (Omega n).
*/
