
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

class Student{

    String sname;
    int rollno;
    float marks1, marks2, marks3;

    public void setSDetails(String name, int rollno, float marks1, float marks2, float marks3){

        this.sname = name;
        this.rollno = rollno;
        this.marks1 = marks1;
        this.marks2 = marks2; 
        this.marks3 = marks3;
    }

    public void filewrite(){

        String f1 = "Student.txt";
        
        File file1 = new File(f1);

        try{

            FileWriter f1FileWriter = new FileWriter(file1,true);

            f1FileWriter.append("\nRoll No :" + this.rollno + "\t Student Name :" + this.sname  
                                + "\t Marks 1 :" + this.marks1 + "\t Marks 2 :" + marks2 
                                + "\t Marks 3 :" + marks3 + "\n");

            
            System.out.println("\nFile written successfully");

            f1FileWriter.close();

        }catch(Exception e){

            e.printStackTrace();
        }
    }
}


public class Program14{
    public static void main(String[] args){

        Student st = new Student();
        
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Student Name:");
        String name = sc.nextLine();

        System.out.print("Enter Student Roll no:");
        int rollno = sc.nextInt();

        System.out.print("Enter Student Marks 1:");
        float marks1 = sc.nextInt();

        System.out.print("Enter Student Marks 2:");
        float marks2 = sc.nextInt();

        System.out.print("Enter Student Marks 3:");
        float marks3 = sc.nextInt();

        st.setSDetails(name, rollno, marks1, marks2, marks3);
        st.filewrite();

        sc.close();
    }
}