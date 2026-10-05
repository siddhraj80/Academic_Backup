
import java.io.File;
import java.io.FileWriter;

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

            System.out.print(file1.length());

            f1FileWriter.append("\n\nRoll No :" + this.rollno + "\t Student Name :" + this.sname  
                                + "\t Marks 1 :" + this.marks1 + "\t Marks 2 :" + marks2 
                                + "\t Marks 3 :" + marks3);

            
            System.out.print("File written successfully");

            f1FileWriter.close();

        }catch(Exception e){
                e.printStackTrace();
        }
    }
}


public class Pro14{
    public static void main(String[] args){

        Student st = new Student();
        
        st.setSDetails("Siddhraj", 44, 89, 90, 78);
        st.filewrite();
    }
}