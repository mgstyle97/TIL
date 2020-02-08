public class CastingExample {
    public static void main(String[] args){
        int intValue = 44032;
        char charValue = (char)intValue;
        System.out.println(charValue);

        long lonValue = 500;
        intValue = (int)lonValue;
        System.out.println(intValue);

        double doubleValue = 3.14;
        intValue = (int)doubleValue;
        System.out.println(intValue);
    }
}
