public class VariableScopeExample {
    public static void main(String[] args){
        int v1 = 15;
        /*                      if 블록 내에 지역 변수이기 때문에 메소드 블록에서는 변수가 사라진다.
        if(v1 > 10){
            int v2 = v1 - 10;
        }
        */
        int v3 = v1 + /*v2 +*/ 5;   // 메소드 블록에서는 존재하지 않는 변수이기 때문에 에러가 발생한다.

        System.out.println(v3);
    }
}
