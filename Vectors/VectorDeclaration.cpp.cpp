#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //Initial size of the array is 0.

    vector<int> arr;
    int ans=(sizeof(arr)/sizeof(int)); //Compiler dependent stuff.
    cout<<ans<<endl;

    //Number of elements that are currently present in the vector.
    cout<<arr.size()<<endl;

    //Number of elements that can be stored in the vector(Like total size of the vector).
    cout<<arr.capacity()<<endl;

    //Inserting in the vector.
    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(14);

    //Printing the elements present in the vector.
    for(int i=0;i<size(arr);i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //Deleting an element from the vector.
    arr.pop_back();

    //Printing the elements present in the vector.
    for(int i=0;i<size(arr);i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //Another vector.
    vector <int> brr(10); //Explicitly size mentioned as 10.
    //In this case, both the size and capacity are set as 0;
    cout<<"Size of the vector: "<<brr.size()<<endl;
    cout<<"Capacity of the vector: "<<brr.capacity()<<endl;
    
    //Checking if the vector err is empty or not. 
    cout<<"Vector brr is empty or not?"<<endl<<brr.empty()<<endl;

    //Printing the elements present in the vector.
    for(int i=0;i<size(brr);i++)
    {
        cout<<brr[i]<<" ";
    }
    cout<<endl;

    //Initializing the vector as -1.
    vector <int> crr(10,-1);
    //Printing the elements present in the vector.
    for(int i=0;i<size(crr);i++)
    {
        cout<<crr[i]<<" ";
    }
    cout<<endl;

    //Another example: Dynamically input the size;
    int num;
    cout<<"Enter the size of the vector: "<<endl;
    cin>>num;

    //Vector of size "num" and initializing with 10;
    vector <int> drr(num,10);
    //Printing the elements present in the vector.
    for(int i=0;i<size(drr);i++)
    {
        cout<<drr[i]<<" ";
    }
    cout<<endl;

    //Another way of declaring a vector
    //Least used case.
    vector<int> err{10,20,30,40,50};
    cout<<"Printing err: "<<endl;
    //Printing the elements present in the vector.
    for(int i=0;i<size(err);i++)
    {
        cout<<err[i]<<" ";
    }
    cout<<endl;
    
    //Checking if the vector err is empty or not. 
    cout<<"Vector err is empty or not?"<<endl<<err.empty()<<endl;
    return 0;
}