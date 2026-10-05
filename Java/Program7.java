class Circle{
    private int x, y;
    private double r;

    public Circle(){
        this.x = 3;
        this.y = 3;
        this.r = 3.3;
    }
    
    public Circle(int x, int y, double r){
        this.x = x;
        this.y = y;
        this.r = r;
    }

    public double area(){
        return Math.PI * Math.pow(this.r, 2);
    }

    public double circumference(){
        return 2 * Math.PI * this.r;
    }
}

public class Program7 {
    public static void main(String[] args){

        System.out.println("Default constructor:");
        Circle cr = new Circle();
        System.out.println("Area of Circle:" + cr.area()); 
        System.out.println("Circumference of Circle:" + cr.circumference());

        System.out.println("Parameterized constructor:");

        Circle cr2 = new Circle(3,3,3.3);

        System.out.println("Area of Circle:" + cr2.area()); 
        System.out.println("Circumference of Circle:" + cr2.circumference());

    }
}