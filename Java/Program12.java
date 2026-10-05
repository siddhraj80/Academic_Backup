class NegativeValueException extends Exception{
    NegativeValueException(String str){
        super(str);
    }
}

public class Program12 {
    public static void main(String[] args){

        int[] arr = new int[args.length];

            for(int i = 0;i<args.length;i++){
                
                try{
                    int temp = Integer.parseInt(args[i]);

                    if(temp >= 0){
                        arr[i] = temp;
                    }else{
                        throw new NegativeValueException("Negative Value not allowed\n");
                        
                    }
                }catch (Exception e){
                    System.out.print("\n" + e);
                }
                 
            }

            for(int i = 0;i<arr.length;i++){

                System.out.println(arr[i]);
            }
    }
}
