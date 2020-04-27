package parentmethodcall;

public class SupersonicAirplane extends Airplane{
    // field
    public static final int NORMAL = 1;
    public static final int SUPERSONIC = 2;

    public int flyMode = NORMAL;

    // constructor

    // method
    @Override
    public void fly() {
        if(flyMode == SUPERSONIC) {
            System.out.println("초음속비행합니다.");
        } else {
            // Airplane 객체의 fly() 메소드 호출
            super.fly();
        }
    }
}
