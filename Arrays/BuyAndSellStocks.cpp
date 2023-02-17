
/*
This program also aims to find the maximum profit that can be obtained by buying and selling stocks given the prices for a week.


The program takes input from the user for the prices of stocks for the week and passes the array to the MaxProfit function.

The MaxProfit function initializes the variables buy, sell, and profit to 0, and iterates over the array using a while loop. 
It checks for the condition where buy is 0, which means that it is the first stock to be bought, 
and sets the values of buy and sell to the current stock price. If it is not the first stock to be bought, 
it checks the conditions based on the current stock price and updates the values of buy, sell, and profit accordingly.


Finally, the function returns the profit, which is printed by the main function.

//This program has a better approach for solving the problem and provides the correct result for all cases. 
The time complexity of the program is also O(n), where n is the size of the array, as it only iterates over the array once. 
Therefore, it is more efficient than the previous program.
*/

#include<iostream>
using namespace std;

int MaxProfit(int arr[],int size)
{
    int buy=0,sell=0,profit=0,i=0;
    while(i<size)
    {
        if(buy==0)
        {
            buy=arr[i];
            sell=arr[i];
        }
        else
        {
            if(buy>=arr[i])
            {
                profit=profit+(sell-buy);
                buy=arr[i];
                sell=arr[i];
            }
            else if(sell<arr[i])
            {
                sell=arr[i];
            }
            else if(sell>arr[i])
            {
                profit=profit+(sell-buy);
                sell=0;
                buy=0;
            }
        }
        i++;
    }
    if(sell>buy)
    {
        profit=profit+(sell-buy);
    }
    return profit;
}



int main()
{
    int arr[7];
    cout<<"Enter the prices of stocks for the week: "<<endl;
    for(int i=0;i<7;i++)
    {
        cin>>arr[i];
    }
    cout<<"Maximum Profit: "<<MaxProfit(arr,7)<<endl;
    return 0;
}

























