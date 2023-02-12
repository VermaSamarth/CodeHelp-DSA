#include<iostream>
using namespace std;

//A function to linearly search the element in an array.
//Return time of the function is Boolean.
bool searchElement(int arr[],int size,int find)
{
    //Loop for comparing and checking the elements lineraly.
    for(int i=0;i<size;i++)
    {
        //If found returning the boolean value true.
        if(find==arr[i])
            return true;
    }
    //If not found then returning the boolean value false.
    return false;
}

//Main function.
int main()
{
    int arr[10]={2,5,4,7,8,1,9,10,11,6};
    int size=10;
    int find;
    //Entering the element to be found.
    cout<<"Enter the element to be searched: "<<endl;
    cin>>find;
    //Calling the searchElement function to check if the number is present or not.
    //If present then printing "Found" else printing "Not Found".
    if(searchElement(arr,size,find))
        cout<<"Found."<<endl;
    else
        cout<<"Not Found."<<endl;
    return 0;
}