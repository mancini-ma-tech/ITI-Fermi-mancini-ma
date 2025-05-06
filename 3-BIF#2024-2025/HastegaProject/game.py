import random
import time

class Player:
    def __init__(self, name):
        self.name = name
        self.health = 100
        self.level = 1
        self.experience = 0
        self.inventory = []

    def take_damage(self, amount):
        self.health = max(self.health - amount, 0)  # Evita valori negativi

    def heal(self, amount):
        self.health = min(self.health + amount, 100)  # Limita la salute a 100

    def is_alive(self):
        return self.health > 0

    def gain_experience(self, amount):
        self.experience += amount
        while self.experience >= 100:  # Supporta più livelli in un colpo
            self.level_up()

    def level_up(self):
        self.level += 1
        self.experience -= 100
        self.health = 100  # Ripristina la salute al massimo
        print(f"🎉 Congratulazioni! Sei salito al livello {self.level}!")

    def display_status(self):
        print("\n📜 Stato del giocatore:")
        print(f"👤 Nome: {self.name}")
        print(f"❤️ Salute: {self.health}")
        print(f"⭐ Livello: {self.level}")
        print(f"🔮 Esperienza: {self.experience}/100")
        print(f"🎒 Inventario: {', '.join(self.inventory) if self.inventory else 'Vuoto'}")

class Game:
    def __init__(self):
        self.player = None

    def start(self):
        print("🎮 Benvenuto nel gioco di sopravvivenza!")
        name = input("Inserisci il tuo nome: ").strip()
        self.player = Player(name or "Avventuriero")  # Nome predefinito se vuoto
        print(f"✨ Benvenuto, {self.player.name}! La tua avventura inizia ora.")
        self.main_loop()

    def main_loop(self):
        while self.player.is_alive():
            print("\nCosa vuoi fare?")
            print("1. Esplora")
            print("2. Controlla lo stato")
            print("3. Usa un oggetto")
            print("4. Esci dal gioco")
            choice = input("> ").strip()

            actions = {
                "1": self.explore,
                "2": self.player.display_status,
                "3": self.use_item,
                "4": self.exit_game
            }

            action = actions.get(choice)
            if action:
                action()
            else:
                print("❌ Scelta non valida. Riprova.")

        if not self.player.is_alive():
            print("💀 Sei morto. Game Over.")

    def explore(self):
        print("\n🔍 Esplorando...")
        time.sleep(1)
        event = random.choice(["enemy", "treasure", "nothing"])
        if event == "enemy":
            self.encounter_enemy()
        elif event == "treasure":
            self.find_treasure()
        else:
            print("🌿 Non è successo nulla di interessante.")

    def encounter_enemy(self):
        print("⚔️ Un nemico ti attacca!")
        enemy_health = random.randint(20, 50)
        while enemy_health > 0 and self.player.is_alive():
            print(f"👹 Salute del nemico: {enemy_health}")
            print("1. Attacca")
            print("2. Fuggi")
            action = input("> ").strip()

            if action == "1":
                damage = random.randint(10, 20)
                print(f"💥 Hai inflitto {damage} danni al nemico.")
                enemy_health -= damage
                if enemy_health > 0:
                    enemy_damage = random.randint(5, 15)
                    print(f"👊 Il nemico ti infligge {enemy_damage} danni.")
                    self.player.take_damage(enemy_damage)
            elif action == "2":
                print("🏃 Sei fuggito!")
                return
            else:
                print("❌ Azione non valida.")

        if enemy_health <= 0:
            print("🎉 Hai sconfitto il nemico!")
            self.player.gain_experience(50)

    def find_treasure(self):
        print("💎 Hai trovato un tesoro!")
        item = random.choice(["pozione di guarigione", "spada", "scudo", "oro"])
        print(f"🎁 Hai trovato: {item}.")
        self.player.inventory.append(item)
        if item == "pozione di guarigione":
            self.player.heal(20)
            print("❤️ Hai recuperato 20 punti salute!")

    def use_item(self):
        if not self.player.inventory:
            print("🎒 Il tuo inventario è vuoto.")
            return

        print("\n🎒 Inventario:")
        for i, item in enumerate(self.player.inventory, 1):
            print(f"{i}. {item}")
        choice = input("Scegli un oggetto da usare (numero): ").strip()

        try:
            index = int(choice) - 1
            if 0 <= index < len(self.player.inventory):
                item = self.player.inventory.pop(index)
                if item == "pozione di guarigione":
                    self.player.heal(20)
                    print("❤️ Hai usato una pozione di guarigione e recuperato 20 punti salute!")
                else:
                    print(f"✨ Hai usato: {item}.")
            else:
                print("❌ Scelta non valida.")
        except ValueError:
            print("❌ Inserisci un numero valido.")

    def exit_game(self):
        print("👋 Grazie per aver giocato!")
        exit()

if __name__ == "__main__":
    game = Game()
    game.start()