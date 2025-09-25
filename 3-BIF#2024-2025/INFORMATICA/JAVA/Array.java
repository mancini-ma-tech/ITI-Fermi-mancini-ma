import java.util.Scanner;

public class Array {
    private String[] names;

    public Array(int size) {
        names = new String[size];
    }

    public void readNames() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < names.length; i++) {
            System.out.print("Enter name: ");
            names[i] = scanner.nextLine();
        }
    }

    public void printNames() {
        for (String name : names) {
            System.out.println(name);
        }
    }

    public static void main(String[] args) {
        Array array = new Array(3);
        array.readNames();
        array.printNames();
    }
}
