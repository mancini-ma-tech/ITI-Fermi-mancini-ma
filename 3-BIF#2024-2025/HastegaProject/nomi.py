# Creazione di una lista con 5 nomi
nomi = ["Alice", "Marco", "Giulia", "Luca", "Sara"]

# Aggiunta di due nomi
nomi.append("Francesco")
nomi.append("Elena")

# Rimozione di un nome
nomi.remove("Luca")

# Stampa della lista finale
print("Lista aggiornata dei nomi: ", nomi)

# Estrazione dei primi tre nomi
primi_tre = nomi[:3]
print("Primi tre nomi: ", primi_tre)

# Estrazione degli ultimi tre nomi
ultimi_tre = nomi[-3:]
print("Ultimi tre nomi: ", ultimi_tre)