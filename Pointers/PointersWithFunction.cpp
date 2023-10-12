#include<iostream>
using namespace std;
void solve(int arr[]){
    cout<<"Size of the array in the function: "<<sizeof(arr)<<endl;
}
int update(int *p){
    *p=*p+20;
    return *p;
}
void modify(int* a, int* b){
    *a=60;
    *b=70;
}
int main(){
    int arr[10]={10,20,30,40};
    cout<<"Size of the array: "<<sizeof(arr)<<endl;
    solve(arr);

    //Number updation using pointers with function
    int num=10;
    cout<<endl<<endl<<"Address of the number: "<<&num<<endl;
    int* ptr=&num;
    cout<<"Address stored in ptr: "<<ptr<<endl;
    cout<<"Address of the ptr: "<<&ptr<<endl;
    cout<<"Value stored in the ptr: "<<*ptr<<endl<<endl;
    update(ptr);
    cout<<"Successfully updated!!!"<<endl;
    cout<<"Address stored in ptr: "<<ptr<<endl;
    cout<<"New value stored in the ptr: "<<*ptr<<endl<<endl;

    //Array updation using pointers with function
    int array[10]={10,20,30,40,50};
    cout<<"Array before updation: "<<endl;
    for(int i=0;i<10;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;
    int* p=&array[0];
    int* q=&array[1];
    modify(p,q);
    cout<<"Array after updation: "<<endl;
    for(int i=0;i<10;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;
}