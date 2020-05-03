package defaultmethodinheritance;

public class Main {

    public static void main(String ... args) {

        ChildInterface1 ci1 = new ChildInterface1() {
            @Override
            public void method3() {
                /*실행문*/
            }

            @Override
            public void method1() {
                /*실행문*/
            }
        };
        ci1.method1();
        ci1.method2();  // ParentInterface의 method2() 호출
        ci1.method3();

    }

}
