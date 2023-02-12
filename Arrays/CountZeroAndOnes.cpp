#include<iostream>
using namespace std;

//A function to linearly search the element in an array.
//Return time of the function is Boolean.
int searchElement(int arr[],int size,int find)
{
    int count=0;
    //Loop for comparing and checking the elements lineraly.
    for(int i=0;i<size;i++)
    {
        //Increasing the counter is number matched
        if(find==arr[i])
            count++;
    }
    //Returning the number of 0's or 1's.
    return count;
}

//Main function.
int main()
{
    int arr[10]={1,0,1,1,0,0,0,1,2,1};
    int size=10;
    //Calling the searchElement function to check the number of zeros and ones present.
    cout<<"Number of Zero's present: "<<searchElement(arr,size,0)<<endl;
    cout<<"Number of One's present: "<<searchElement(arr,size,1)<<endl;
    return 0;
}