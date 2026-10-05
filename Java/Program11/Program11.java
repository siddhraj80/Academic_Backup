interface  Shape{

    public double area();

    public double perimeter();
}

class Rectangle implements Shape{

    double length = 0, width = 0;

    public Rectangle(double length, double width){

        this.length = length;
        this.width = width;
    }

    @Override 
    public double area() {
       
        return length * width;
    }

    @Override
    public double perimeter(){

        return 2 * (length + width);
    }
}

class Triangle implements Shape{

    double base=0, hight=0, aSide=0, bSide=0, cSide=0;

    public Triangle(double base, double hight, double aSide, double bSide){

        this.base = base;
        this.hight = hight;
        this.aSide = aSide;
        this.bSide = bSide;
    }

    @Override
    public double area() {
       
        return 0.5*(base*hight);
    }

    @Override
    public double perimeter(){
        return base + aSide + bSide ;
    }
}

class Circle implements Shape{

    double r = 0;

    public Circle(double r){

        this.r = r;
    }

    @Override
    public double area() {
       
        return Math.PI * r * r;
    }

    @Override
    public double perimeter(){
        return 2 * Math.PI * r;
    }
}

public class Program11 {
    public static  void main(String[] args){

        Shape rectangle = new Rectangle(5, 9);
        System.out.println("\nArea of rectangle :" + rectangle.area());
        System.out.println("Perimeter of rectangle :" + rectangle.perimeter());

        Shape triangle = new Triangle(5, 9, 5, 6);
        System.out.println("\nArea of Triangle :" + triangle.area());
        System.out.println("Perimeter of Triangle :" + triangle.perimeter());

        Shape circle = new Circle(4);
        System.out.println("\nArea of Circle :" + circle.area());
        System.out.println("Circumference of Circle :" + circle.perimeter());
    }
}
