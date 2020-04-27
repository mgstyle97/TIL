package parentconstructor;

public class Student extends People {
    // field
    public int studentNo;

    // constructor
    public Student(String name, String ssn, int studentNo) {
        super(name, ssn);
        this.studentNo = studentNo;
    }
}
