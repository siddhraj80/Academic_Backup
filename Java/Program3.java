import java.util.*;

public class Program3{
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter String : ");
		String str = sc.nextLine();
		str = str.toLowerCase(); 
		
		System.out.print("Enter char : ");
		String cr = sc.nextLine();
		cr = cr.toLowerCase();

		char ch = cr.charAt(0);

		int freq = 0, j = -1;
		int[] positions = new int[str.length()];
		
		for(int i = 0; i < str.length(); i++ ){

			if(str.charAt(i) == ch){
				
				j++;
				positions[j] = i;
				
				freq++;
			}
		}

		System.out.print("Character's position at : ");
		for(int k = 0; k <= j; k++){
			System.out.print(positions[k] + " ");
		}

		System.out.println("\n Character's Frequency: " + freq);

		sc.close();
	}
}