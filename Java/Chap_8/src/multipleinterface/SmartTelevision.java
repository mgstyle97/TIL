package multipleinterface;

public class SmartTelevision implements RemoteControl, Searchable {
    // field
    private int volume;

    // constructor

    // method
    public void turnOn() {
        System.out.println("TV를 켭니다.");
    }

    public void turnOff() {
        System.out.println("TV를 끕니다.");
    }

    public void setVolume(int volume) {
        if(volume > implementclass.RemoteControl.MAX_VOLUME) {
            this.volume = implementclass.RemoteControl.MAX_VOLUME;
        } else if(volume < implementclass.RemoteControl.MIN_VOLUME) {
            this.volume = implementclass.RemoteControl.MIN_VOLUME;
        } else {
            this.volume = volume;
        }
        System.out.println("현재 TV 볼륨: " + this.volume);
    }

    public void search(String url) {
        System.out.println(url + "을 검색합니다.");
    }
}
