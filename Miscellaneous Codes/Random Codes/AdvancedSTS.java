// -------------------- Sorting the array ----------------------
// import java.util.*;
// public class AdvancedSTS {
//     public static void main(String args[]){
//         Scanner scan = new Scanner(System.in);
//         int arr[] = new int[10];
//         System.out.println("Enter the Array: ");
//         for(int i = 0; i < 10; i++){
//             arr[i] = scan.nextInt();
//         }
//         Arrays.sort(arr);
//         System.out.println("Sorted Array: ");
//         for(int i = 0; i < 10; i++){
//             System.out.print(arr[i] + " ");
//         }
//         scan.close();
//     }
// }


// ---------------------- Minimum Stack --------------------------
// import java.util.*;
// public class AdvancedSTS {
//     static Stack<Integer> stk = new Stack<>();
//     static Stack<Integer> minstk = new Stack<>();
//     public static void main(String[] args){
//         Scanner sc = new Scanner(System.in);
//         int data;
//         for(int i = 0; i < 5; i++){
//             data = sc.nextInt();
//             stk.push(data);
//         }
//         stk.pop();
//         if(stk.isEmpty())
//             System.out.println("Stack is empty.");
//         else{
//             System.out.println("Stack is not empty.");
//             int top = stk.lastElement();
//             System.out.println("Top Element: " +top);
//         }
//         System.out.println("Printing the elements: ");
//         while(!stk.isEmpty()){
//             System.out.print(stk.lastElement() + " ");
//             stk.pop();
//         }
//         sc.close();
//     }    
// }


import java.util.*;
class AdvancedSTS{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int num = 4;
        int arr[][] = new int[num][num];
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                arr[i][j] = sc.nextInt();
            }
        }
        // Row
        int row, col = 0;
        for(int i = 0; i < num; i++){
            row = 0;
            for(int j = 0; j < num; j++){
                if(arr[i][j] == 0)
                    row++;
            }
            if(row == 4){
                col = 0;
                for(int k = 0; k < num; k++){
                    if(arr[k][i] == 1)
                        col++;
                }
                if(col == num - 1)
                    System.out.println("Celebrity Found = " + i);
                    break;
            }
        }
        if(col != num - 1)
            System.out.println("Celebrity not found.");
    }
}