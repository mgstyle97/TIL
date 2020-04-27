package abstractmethod;

public abstract class Animal {
    // field
    public String kind;

    // constructor

    // method
    public void breathe() {
        System.out.println("숨을 쉽니다.");
    }

    public abstract void sound();
}
