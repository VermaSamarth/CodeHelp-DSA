#include<iostream>
using namespace std;
int main(){
    int arr[5]={10,12,14,16,18};
    cout<<arr[0]<<endl;
    cout<<&arr[0]<<endl;
    cout<<&arr<<endl;
    cout<<arr<<endl;
    //The above three statement return the same value. It is because the '&arr' and 'arr' returns the base address of the array which is equal to &arr[0].
    cout<<arr[4]<<endl;
    cout<<&arr[4]<<endl;

    int* ptr=arr;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;

    /* Trick Question */
    int i=0;
    cout<<"Value: "<<arr[i]<<endl;
    for(int i=0;i<4;i++){
        cout<<"Value: "<<i[arr]<<endl;
    }
    //The above statements arr[i] and i[arr] are working because in the backend, the given statements are resolved to *(arr+i) or *(i+arr).


    int brr[5]={10,20,30,40,50};
    int* p=brr;
    int* q=brr+2;
    cout<<brr<<endl;
    cout<<&brr<<endl;
    cout<<brr[0]<<endl;
    cout<<&brr[0]<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
    cout<<q<<endl;
    cout<<&q<<endl;
    cout<<*q<<endl;


    cout<<"Size of brr: "<<sizeof(brr)<<endl;
    cout<<"Size of p: "<<sizeof(p)<<endl;
}