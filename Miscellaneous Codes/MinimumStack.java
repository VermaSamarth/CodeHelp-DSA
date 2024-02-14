import java.util.*;
public class MinimumStack {
    static Stack<Integer> stk;
    static Stack<Integer> minstk;
    MinimumStack(){
        stk = new Stack<>();
        minstk = new Stack<>();
    }
    public static void push(int data){
        stk.push(data);
        if(minstk.empty() || minstk.peek() > data){
            minstk.push(data); 
        }
    }
    public static void main(String argsp[]){
        Scanner sc = new Scanner(System.in);
        MinimumStack obj = new MinimumStack();
        int n = sc.nextInt();
        for(int i = 0; i < n; i++){
            int data = sc.nextInt();
            obj.push(data);
        }
        int min = minstk.peek();
        System.out.println(min);
    }
}
