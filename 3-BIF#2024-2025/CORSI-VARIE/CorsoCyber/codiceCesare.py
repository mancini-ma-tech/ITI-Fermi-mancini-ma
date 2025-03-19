''''Dati in input un testo e un numero intero n minore di 26,
restituire in uscita il testo crittografato con un Codice
di Cesare che sposti ogni lettera di n lettere.'''

def cesare_cipher(text, n):
    # Inizializza la stringa del risultato
    result = ""
    # Itera su ogni carattere del testo
    for char in text:
        # Controlla se il carattere è una lettera
        if char.isalpha():
            # Calcola lo spostamento effettivo
            shift = n % 26
            # Se il carattere è minuscolo
            if char.islower():
                # Applica lo spostamento e aggiungi al risultato
                result += chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
            # Se il carattere è maiuscolo
            elif char.isupper():
                # Applica lo spostamento e aggiungi al risultato
                result += chr((ord(char) - ord('A') + shift) % 26 + ord('A'))
        else:
            # Se il carattere non è una lettera, aggiungilo al risultato senza modifiche
            result += char
    # Restituisce il testo crittografato
    return result

# Esempio di utilizzo
text = input("Inserisci il testo da crittografare: ")
n = int(input("Inserisci il numero di spostamenti (minore di 26): "))
print("Testo crittografato:", cesare_cipher(text, n))