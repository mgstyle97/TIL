package fieldpolymorphism;

public class Tire {
    // field
    public int maxRotation;
    public int accumulateRotation;
    public String location;

    // constructor
    public Tire (String location, int maxRotation) {
        this.location = location;
        this.maxRotation = maxRotation;
    }

    // method
    public boolean roll() {
        ++this.accumulateRotation;
        if(this.accumulateRotation < this.maxRotation) {
            System.out.println(this.location + " Tire 수명: " + (this.maxRotation - this.accumulateRotation) + "회");
            return true;
        } else {
            System.out.println("*** " + this.location + " Tire 펑크 ***");
            return false;
        }
    }
}
