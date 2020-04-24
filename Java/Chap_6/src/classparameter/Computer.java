package classparameter;

public class Computer {

    // 메소드
    int sum1(int[] values) {
        int sum = 0;
        for(int i = 0; i < values.length; i++) {
            sum += values[i];
        }
        return sum;
    }

    int sum2(int ... values) {
        int sum = 0;
        for(int i = 0; i < values.length; i++) {
            sum += values[i];
        }
        return sum;
    }

    int sum3(int ... values) {
        int sum = 0;
        for(int i : values) {
            sum += i;
        }
        return sum;
    }

}
