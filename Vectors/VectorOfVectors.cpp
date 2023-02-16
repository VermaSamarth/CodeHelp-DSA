#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //One way of initializing the Vector of Vectors.
    vector < vector <int> > arr;
    vector <int> a{1,2,3};
    vector <int> b{4,5,6};
    vector <int> c{7,8,9};

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    cout<<"Printing the matrix formed by vector of vectors."<<endl;
    for(int i=0; i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    //Another way of initializing the vector of vectors.
    int row=3;
    int col=5;
    vector < vector<int> > krr(row, vector<int>(col,0));
    cout<<"Printing the matrix formed by vector of vectors."<<endl;
    for(int i=0; i<krr.size();i++)
    {
        for(int j=0;j<krr[i].size();j++)
        {
            cout<<krr[i][j]<<" ";
        }
        cout<<endl;
    }

    int row1=5;
    int col1=5;
    vector < vector<int> > hrr(row1, vector<int>(col1,-8));
    cout<<"Printing the matrix formed by vector of vectors."<<endl;
    for(int i=0; i<hrr.size();i++)
    {
        for(int j=0;j<hrr[i].size();j++)
        {
            cout<<hrr[i][j]<<" ";
        }
        cout<<endl;
    }
}