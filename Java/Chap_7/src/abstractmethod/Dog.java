package abstractmethod;

public class Dog extends Animal {
    // field

    // constructor
    public Dog() {
        this.kind = "포유류";
    }

    // method
    @Override
    public void sound() {
        System.out.println("멍멍");
    }
}
