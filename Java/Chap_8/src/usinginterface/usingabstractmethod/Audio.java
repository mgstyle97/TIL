package usinginterface.usingabstractmethod;


public class Audio implements RemoteControl {
    // field
    private int volume;

    // constructor

    // method

    public void turnOn() {
        System.out.println("Audio를 켭니다.");
    }

    public void turnOff() {
        System.out.println("Audio를 끕니다.");
    }

    public void setVolume(int volume) {
        if(volume > implementclass.RemoteControl.MAX_VOLUME) {
            this.volume = implementclass.RemoteControl.MAX_VOLUME;
        } else if(volume < implementclass.RemoteControl.MIN_VOLUME) {
            this.volume = RemoteControl.MIN_VOLUME;
        } else {
            this.volume = volume;
        }
        System.out.println("현재 Audio 볼륨: " + this.volume);
    }
}
