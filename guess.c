//Miron Oana P1.b)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary(int top, int bot)
{
    if(top==bot)
        return top;

    int mid=(top+bot)/2;
    printf("Is the equal to %d? Yes or No?\n",mid);
    char c[4];
    scanf("%s",c);
    if(strcmp(c,"Yes")==0)
        return mid;

    printf("Is it greater than %d? Yes or No?\n",mid);
    scanf("%s",c);
    if(strcmp(c,"Yes")==0)
        return binary(top,mid+1);
    else
        return binary(mid-1,bot);
}
//considered that the user knows the number
int main()
{
    int n;
    scanf("%d",&n);
    printf("Is the number 0?Yes or No?\n");
    char c[3];
    scanf("%s",c);
    if(strcmp(c,"Yes")==0)
        printf("The number is 0");
    else
        printf("The number is %d",binary(n,1));
    return 0;
}

/*
The best algorithm that can be used for such a search is the binary
search which basically finds the index(in this context the actual value)
of the number, working with a complexity of θ(log(n)), which is the best
as it takes as much as log(n) steps to find the index of the value,
a sublogarithmic algorithm being nonexistent as of now.
*/
