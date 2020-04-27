package fieldpolymorphism;

public class HankookTire extends Tire {
    // field

    // constructor
    public HankookTire(String loaction, int maxRotation) {
        super(loaction, maxRotation);
    }

    // method
    @Override
    public boolean roll() {
        ++this.accumulateRotation;
        if(this.accumulateRotation < this.maxRotation) {
            System.out.println(location + " HankookTire 수명: " + (this.maxRotation - this.accumulateRotation) + "회");
            return true;
        } else {
            System.out.println("*** " + this.location + " HankookTire 펑크 ***");
            return false;
        }
    }
}
