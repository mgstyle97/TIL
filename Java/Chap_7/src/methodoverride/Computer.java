package methodoverride;

public class Computer extends Calculator{
    // field

    // constructor

    // method
    @Override
    public double areaCircle(double r) {
        System.out.println("Computer 객체의 areaCircle() 실행");
        return Math.PI * r * r;
    }
}
