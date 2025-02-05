package Java.basic_class;

class OuterClass {
    private String outerField = "Outer Field";

    class InnerClass {
        void display() {
            System.out.println("This is the inner class, accessing: " + outerField);
        }
    }

    void createInner() {
        InnerClass inner = new InnerClass();  // Create instance of inner class
        inner.display();
    }
}

public class InnerClassExample {
    public static void main(String[] args) {
        OuterClass outer = new OuterClass();
        outer.createInner();  // Calling method that creates inner class instance
    }
}
