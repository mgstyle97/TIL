package fieldpolymorphism;

public class KumhoTire extends Tire {
    // field

    // constructor
    public KumhoTire(String loaction, int maxRotation) {
        super(loaction, maxRotation);
    }

    // method
    @Override
    public boolean roll() {
        ++this.accumulateRotation;
        if(this.accumulateRotation < this.maxRotation) {
            System.out.println(location + " KumhoTire 수명: " + (this.maxRotation - this.accumulateRotation) + "회");
            return true;
        } else {
            System.out.println("*** " + this.location + " KumhoTire 펑크 ***");
            return false;
        }
    }
}
