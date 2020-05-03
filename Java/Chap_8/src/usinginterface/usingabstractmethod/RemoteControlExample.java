package usinginterface.usingabstractmethod;

public class RemoteControlExample {

    public static void main(String ... args) {

        RemoteControl rc = null;

        rc = new Television();
        rc.turnOn();
        rc.turnOff();

        rc = new Audio();
        rc.turnOn();
        rc.turnOff();

    }

}
