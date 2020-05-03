package fieldpolymorphismarray;

public class Car {
    // field
    Tire[] tires = {
            new HankookTire(),
            new HankookTire(),
            new HankookTire(),
            new HankookTire()
    };

    // constructor

    // method
    void run() {
        for(Tire tire : this.tires) {
            tire.roll();
        }
    }
}
