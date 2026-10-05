import java.util.*;

public class Program1{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n;

        System.out.print("Enter Number : ");
        n = sc.nextInt();
        
        if(n <= 1)
        {

            System.out.println(n + " is Not Prime");
        }
        else
        {

            boolean prime = true;

            for(int i = 2; i <= n / 2; i++){

                if(n % i == 0){

                    prime = false;
                    break;
                }
            }

            if(prime){

                System.out.println(n + " is a Prime number");
            }else{

                System.out.println(n + " is Not Prime number");
            }
		}
        
        if(n > 0)
        {

            System.out.println(n + " is Greater than 0");
        }
        else
        {

            System.out.println(n + " is Less than 0");
        }

        System.out.println(" ");
        
        for(int i = 1; i<=10; i++){

            if(i == 6){

                continue;
            }

            if(i == 9){

                break;
            }

            System.out.println("For-Loop : " + i);
        }
        
        int j = 1;

        System.out.println(" ");

        while(j <= 8){

            System.out.println("while-Loop : " + j);
            j++;
        }
       
        int k = 1;

        System.out.println(" ");

        do{
            System.out.println("do-while-Loop : " + k);
            k++;
        }while(k <= 8);

        sc.close();
    }

}