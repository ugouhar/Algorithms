#include<bits/stdc++.h>
using namespace std;
void computeLPS(char p[],int lps[])
{
    int j=0,i=1,n=strlen(p);
    lps[0]=0;
    while(i<n)
    {
        if(p[i]==p[j])
        {
            lps[i]=j+1;
            j++;
            i++;
        }
        else if(j!=0)
            j=lps[j-1];
        else
        {
            lps[i]=0;
            i++;
        }
    }
}

int KMPsearch(char str[],char pat[],int lps[])
{
    int i=0,j=0;
    int nstr=strlen(str);
    int npat=strlen(pat);
    while(i<nstr && j<npat)
    {
        if(str[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j!=0)
            j=lps[j-1];
        else i++;
        if(j==npat-1)
            return i-j; //i.e. i-length(pattern)
    }
    return -1;
}

int main()
{
    char str[100000], p[100000];
    cout<<"\nEnter string : "; cin>>str;
    cout<<"\nEnter pattern : ";cin>>p;

    int n=strlen(p);
    int lps[n];
    computeLPS(p,lps);
    int index=KMPsearch(str,p,lps);

    cout<<"\nPattern found at index : "<<index;

    return 0;
}
