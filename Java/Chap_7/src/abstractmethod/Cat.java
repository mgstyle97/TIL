package abstractmethod;

public class Cat extends Animal {
    // field

    // constructor
    public Cat() {
        this.kind = "포유류";
    }

    // method
    @Override
    public void sound() {
        System.out.println("야옹");
    }
}
