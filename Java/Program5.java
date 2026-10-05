class Utility{

    /* public static long factorial(long value){

    }

    public static boolean isPrime(int value){
        
    } */

    public static boolean isEven(int value){
        if(value %2 == 0){
            return true;
        }else{
            return false;
        }
    }

   /*  public static boolean isOdd(long value){
        
    } */
}

public class Program5 {
    public static void main(String[] args){

        int value = 9;

        boolean result = Utility.isEven(value);

        System.out.print(result);

    }
}
