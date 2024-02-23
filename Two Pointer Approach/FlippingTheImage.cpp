#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>>image = {{1,1,0},{1,0,1},{0,1,0}};
    int start, end;
    for(int i = 0; i < image.size(); i++){
        start = 0;
        end = image.size() - 1;
        while(start <= end){
            swap(image[i][start],image[i][end]);
            start++;
            end--;
        }
    }

    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image.size(); j++){
            if(image[i][j] == 1)
                image[i][j] = 0;
            else
                image[i][j] = 1;
        }
        cout << endl;
    }

    cout << "Printing after flipping the image: " << endl;
    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image.size(); j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}