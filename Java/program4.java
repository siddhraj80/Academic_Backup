import java.util.*;

public class program4{
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        
        int[][] matrix1 = new int[3][3];
        int[][] matrix2 = new int[3][3];
        int[][] multimatrix = new int[3][3];
        int[][] addmatrix = new int[3][3];
        int[][] submatrix = new int[3][3];


        System.out.println("Enter first Matrix:");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){

                matrix1[i][j] = sc.nextInt();
            }
        }

        System.out.println("Enter Second Matrix:");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){

                matrix2[i][j] = sc.nextInt();
            }
        }


        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){

                    multimatrix[i][j] += matrix1[i][j] * matrix2[k][j];
                }
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                
                addmatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                
                submatrix[i][j] = matrix1[i][j] - matrix2[i][j];
                
            }
        }

        System.out.println("Addition of two matrix:");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                
                System.out.print(addmatrix[i][j] + " ");
            }
            System.out.print("\n");
        }

        System.out.println("Subtraction of two matrix:");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                
                System.out.print(submatrix[i][j] + " ");
            }
            System.out.print("\n");
        }

        System.out.println("Multiplication of two matrix:");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){

                System.out.print(multimatrix[i][j] + " ");
            }
            System.out.print("\n");
        }

        sc.close();

    }
}