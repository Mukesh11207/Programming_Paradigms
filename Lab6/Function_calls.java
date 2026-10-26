class Student {
    String name;
    int age;
    int marks;
}
public class Function_calls {
    public static void callByValue(int x) {
        x = 100;
        System.out.println("Inside function: " + x);
    }
    public static void callByReference(Student s) {
        s.marks = 300;
    }
    public static void display() {
        display(10);
    }
    public static void display(int x) {
        System.out.println("Default value: " + x);
    }
    public static void keywordParameter(Student s) {
        System.out.println("Name: " + s.name);
        System.out.println("Age: " + s.age);
        System.out.println("Marks: " + s.marks);
    }

    public static void main(String[] args) {
        int a = 10;

        System.out.println("Call by Value");
        System.out.println("Before: " + a);
        callByValue(a);
        System.out.println("After: " + a);

        System.out.println("\nCall by Address");
        System.out.println("Java does not support call by address");

        System.out.println("\nCall by Reference");
        Student student = new Student();
        student.name = "Mukesh";
        student.age = 18;
        student.marks = 50;

        System.out.println("Before: " + student.marks);
        callByReference(student);
        System.out.println("After: " + student.marks);

        System.out.println("\nDefault Parameter");
        display();

        System.out.println("\nKeyword Parameter");
        Student s = new Student();
        s.name = "Rahul";
        s.age = 20;
        s.marks = 90;

        keywordParameter(s);
    }
}




