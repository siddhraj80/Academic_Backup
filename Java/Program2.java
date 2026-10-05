public class Program2{ 
    public static void main(String[] args) {
        
		
        int[] num = new int[args.length];

        for (int k = 0; k < args.length; k++){

            num[k] = Integer.parseInt(args[k]);
        }

         
        System.out.println("\nsorted values:"); 

		for (int k = 0; k < num.length - 1; k++){

			for (int a = 0; a < num.length - 1 ; a++){
            
				if (num[a] > num[a + 1]){

					int temp = num[a];
					num[a] = num[a + 1];
					num[a + 1] = temp;
				}
			}
		}

        for (int b : num){

            System.out.println(b);
        }
        
        int minValue = num[0];
        int maxValue = num[num.length - 1];
			
        System.out.println("\nmax values:");
        System.out.println(maxValue);
			
        System.out.println("\nmin value:");
        System.out.println(minValue);
    } 
}