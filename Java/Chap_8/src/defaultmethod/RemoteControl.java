package defaultmethod;

public interface RemoteControl {
    // constant
    int MAX_VOLUME = 10;
    int MIN_VOLUME = 0;

    // abstract method
    void turnOn();
    void turnOff();
    void setVolume(int volume);

    // default method
    default void setMute(boolean mute) {
        if(mute) {
            System.out.println("무음 처리합니다.");
        } else {
            System.out.println("무음 해제합니다.");
        }
    }
}
