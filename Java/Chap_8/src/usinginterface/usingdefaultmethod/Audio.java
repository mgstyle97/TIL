package usinginterface.usingdefaultmethod;


public class Audio implements RemoteControl {
    // field
    private int volume;
    private boolean mute;

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

    @Override
    public void setMute(boolean mute) {
        this.mute = mute;
        if(mute) {
            System.out.println("Audio 무음 처리합니다.");
        } else {
            System.out.println("Audio 무음 해제합니다.");
        }
    }
}
