package fieldpolymorphism;

public class Car {
    // field
    Tire frontLeftTire = new HankookTire();
    Tire frontRightTire = new HankookTire();
    Tire backLeftTire = new HankookTire();
    Tire backRightTire = new HankookTire();

    // constructor

    // method
    void run() {
        this.frontLeftTire.roll();
        this.frontRightTire.roll();
        this.backLeftTire.roll();
        this.backRightTire.roll();
    }
}
