/*Scrivere la classe moto e stampare la targa

Consegnare lo stamp del lavoro svolto e il codice nel file java

Grazie */
/*
 Classe Mot
 JAVA
*/

public class Moto {
    String modello;
    String targa;

    public Moto(String m, String t) {
        this.modello = m;
        this.targa = t;
    }

    public void stampaTarga() {
        System.out.println("Targa: " + targa);
    }

    public class Moto {
        String modello;
        String targa;

        public Moto(String m, String t) {
            this.modello = m;
            this.targa = t;
        }

        public void stampaTarga() {
            System.out.println("Targa: " + targa);
        }

        public static void main(String[] args) {
            Moto m1 = new Moto("BMV", "1234ABCD");
            Moto m2 = new Moto("Mercedesi", "5678EFGH");
            System.out.println(m2.modello);
            System.out.println(m1.modello);
        }
    }
}
