import java.util.*;

class Student{
    String name;
    int rollNo;
    float marks;

    public Student(String name, int rollNo, float marks){
        this.name = name;
        this.rollNo = rollNo;
        this.marks = marks;
    }

    public void displayDetails(){
        System.out.println("Student's Name : " + this.name);
        System.out.println("Student's roll no : " + this.rollNo);
        System.out.println("Student's marks : " + this.marks);
    }
}

public class Program6 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter name : ");
        String name = sc.nextLine();

        System.out.print("Enter roll no : ");
        int rollNo = sc.nextInt();

        System.out.print("Enter marks : ");
        float marks = sc.nextFloat();

        Student st = new Student(name, rollNo, marks);
        
        st.displayDetails();

        sc.close();
    }
}