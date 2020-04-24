package classparameter;

public class Calculator {

    // 필드
    boolean statement;

    // 생성자
    Calculator() {
        this.statement = false;
    }

    // 메소드
    void powerOn() {
        this.statement = true;
        System.out.println("전원을 켭니다.");
    }

    int plus(int x, int y) {
        int result = x + y;
        return result;
    }

    double divide(int x, int y) {
        double result = (double)x / (double)y;
        return result;
    }

    void powerOff() {
        this.statement = false;
        System.out.println("전원을 끕니다.");
    }

}
