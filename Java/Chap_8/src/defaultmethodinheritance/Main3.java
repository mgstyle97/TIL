package defaultmethodinheritance;

public class Main3 {

    public static void main(String ... args) {

        ChildInterface3 ci3 = new ChildInterface3() {
            @Override
            public void method2() {
                /*실행문*/
            }

            @Override
            public void method3() {
                /*실행문*/
            }

            @Override
            public void method1() {
                /*실행문*/
            }
        };

        ci3.method1();
        ci3.method2();
        ci3.method3();

    }

}
