import java.util.Scanner;
public class InverseUsingEuclidian {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int num1, num2;
        System.out.println("Enter the two numbers: ");
        num1 = scan.nextInt();
        num2 = scan.nextInt(); 
        int init_num = num1;
        int quo, res, y1 = 0, y2 = 0, y = 1;
        while(num1 != 1 && num2 != 0){
            y1 = y2;
            y2 = y;
            quo = num1 / num2;
            res = num1 % num2;
            y = y1 - (y2 * quo);
            num1 = num2;
            num2 = res;
        }
        if(y2 < 0)
            y2 = init_num + y2;
        System.out.println("Multiplicative Inverse: " + y2);
        scan.close();
    }
}
