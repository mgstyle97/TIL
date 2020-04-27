package abstractclass;

public class SmartPhone extends Phone {
    // field

    // constructor
    public SmartPhone(String owner) {
        super(owner);
    }

    // method
    public void internetSearch() {
        System.out.println("인터넷 검색을 합니다.");
    }
}
