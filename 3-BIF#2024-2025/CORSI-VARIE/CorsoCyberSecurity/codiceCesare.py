import os

# Funzione per cambiare il caso delle lettere nel file
def change_case(file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    new_content = ""
    for char in content:
        if char.islower():
            new_content += char.upper()
        elif char.isupper():
            new_content += char.lower()
        else:
            new_content += char

    with open(file_path, 'w') as file:
        file.write(new_content)

# Funzione per riformattare il testo rimuovendo spazi extra
def reformat_text(file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    new_content = ' '.join(content.split())

    with open(file_path, 'w') as file:
        file.write(new_content)

# Funzione per crittografare il testo usando il Codice di Cesare
def caesar_cipher(file_path, shift):
    with open(file_path, 'r') as file:
        content = file.read()

    new_content = ""
    for char in content:
        if char.isalpha():
            shift_amount = shift % 26
            if char.islower():
                new_content += chr((ord(char) - ord('a') + shift_amount) % 26 + ord('a'))
            elif char.isupper():
                new_content += chr((ord(char) - ord('A') + shift_amount) % 26 + ord('A'))
        else:
            new_content += char

    with open(file_path, 'w') as file:
        file.write(new_content)

# Funzione principale che gestisce il menu e le scelte dell'utente
def main():
    file_path = input("Inserisci il percorso del file (.cpp, .txt, .py): ")

    if not os.path.isfile(file_path):
        print("Il file non esiste.")
        return

    print("Menu:")
    print("1. Cambiare da MAIUSCOLE a minuscole e viceversa")
    print("2. Riformattare il testo")
    print("3. Crittografare il testo con il Codice di Cesare")

    choice = input("Scegli un'opzione (1, 2 o 3): ")

    if choice == '1':
        change_case(file_path)
        print("Il caso del testo è stato cambiato con successo.")
    elif choice == '2':
        reformat_text(file_path)
        print("Il testo è stato riformattato con successo.")
    elif choice == '3':
        shift = int(input("Inserisci il numero di posizioni per il Codice di Cesare (N): "))
        if 0 < shift < 26:
            caesar_cipher(file_path, shift)
            print("Il testo è stato crittografato con successo.")
        else:
            print("Il numero di posizioni deve essere compreso tra 1 e 25.")
    else:
        print("Scelta non valida.")

if __name__ == "__main__":
    main()
