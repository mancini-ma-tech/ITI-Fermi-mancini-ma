class Studente {
    String nome;

    Studente(String nome) {
        this.nome = nome;
    }

    void stampa() {
        System.out.println("Studente: " + this.nome);
    }

    public static void main(String[] args) {
        // STRUTTURA DATI DEL MAIN
        String[] alunni = { "Pino", "Gino", "Dino" };
        for (String item : alunni) {
            Studente s = new Studente(item);
            s.stampa(); // Aggiunto per stampare il nome dello studente
        }
    }
}