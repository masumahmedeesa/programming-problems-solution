#include<iostream>
#include<algorithm>
#define sz 100

using namespace std;

typedef struct
{
    int weight,price;
}object;

int main()
{
    int n,i,w,mat[sz][sz];
    int capacity;
    cin>>n;
    object obj[n];
    for(i = 1; i<=n; ++i)
    {
        cin>>obj[i].weight>>obj[i].price;
    }
    cin>>capacity;
    for(i = 0; i<=n; ++i)
    {
        mat[i][0] = 0;
    }
    for(w = 0; w<=capacity; ++w)
    {
        mat[0][w] = 0;
    }
    for(i = 1; i<=n; ++i)
    {
        for(w = 1; w<=capacity; ++w)
        {
            if(obj[i].weight>w)
            {
                mat[i][w] = mat[i-1][w];
            }
            else
            {
                mat[i][w] = max(mat[i-1][w],(mat[i-1][w-(obj[i].weight)]+(obj[i].price)));
            }
        }
    }
    cout<<"Maximum Profit = "<<mat[n][capacity]<<endl;
    i = n;
    w = capacity;
    while(i>0||w>0)
    {
        if(mat[i][w] != mat[i-1][w])
        {
            cout<<i<<", ";
            w = w-obj[i].weight;
        }
        i--;
    }
    return 0;
}

