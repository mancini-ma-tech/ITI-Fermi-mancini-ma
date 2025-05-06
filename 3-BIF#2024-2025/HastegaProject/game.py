import random
import tkinter as tk
from tkinter import messagebox

class Player:
    def __init__(self, name):
        self.name = name
        self.health = 100
        self.level = 1
        self.experience = 0
        self.inventory = []

    def take_damage(self, amount):
        self.health = max(self.health - amount, 0)

    def heal(self, amount):
        self.health = min(self.health + amount, 100)

    def is_alive(self):
        return self.health > 0

    def gain_experience(self, amount):
        self.experience += amount
        while self.experience >= 100:
            self.level_up()

    def level_up(self):
        self.level += 1
        self.experience -= 100
        self.health = 100
        messagebox.showinfo("Livello Up", f"🎉 Congratulazioni! Sei salito al livello {self.level}!")

class GameApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Hastega Project")
        self.player = None

        self.main_frame = tk.Frame(root)
        self.main_frame.pack(pady=20)

        self.start_screen()

    def start_screen(self):
        for widget in self.main_frame.winfo_children():
            widget.destroy()

        tk.Label(self.main_frame, text="🎮 Benvenuto nel gioco di sopravvivenza!", font=("Arial", 16)).pack(pady=10)
        tk.Label(self.main_frame, text="Inserisci il tuo nome:").pack(pady=5)
        self.name_entry = tk.Entry(self.main_frame)
        self.name_entry.pack(pady=5)
        tk.Button(self.main_frame, text="Inizia", command=self.start_game).pack(pady=10)

    def start_game(self):
        name = self.name_entry.get().strip()
        self.player = Player(name or "Avventuriero")
        self.main_menu()

    def main_menu(self):
        for widget in self.main_frame.winfo_children():
            widget.destroy()

        tk.Label(self.main_frame, text=f"✨ Benvenuto, {self.player.name}!", font=("Arial", 16)).pack(pady=10)
        tk.Button(self.main_frame, text="Esplora", command=self.explore).pack(pady=5)
        tk.Button(self.main_frame, text="Controlla lo stato", command=self.display_status).pack(pady=5)
        tk.Button(self.main_frame, text="Usa un oggetto", command=self.use_item).pack(pady=5)
        tk.Button(self.main_frame, text="Esci dal gioco", command=self.exit_game).pack(pady=5)

    def explore(self):
        event = random.choice(["enemy", "treasure", "nothing"])
        if event == "enemy":
            self.encounter_enemy()
        elif event == "treasure":
            self.find_treasure()
        else:
            messagebox.showinfo("Esplorazione", "🌿 Non è successo nulla di interessante.")

    def encounter_enemy(self):
        enemy_health = random.randint(20, 50)
        while enemy_health > 0 and self.player.is_alive():
            action = messagebox.askquestion("Nemico!", f"⚔️ Un nemico ti attacca! Salute nemico: {enemy_health}\nVuoi attaccare?")
            if action == "yes":
                damage = random.randint(10, 20)
                enemy_health -= damage
                if enemy_health > 0:
                    enemy_damage = random.randint(5, 15)
                    self.player.take_damage(enemy_damage)
                    if not self.player.is_alive():
                        messagebox.showerror("Game Over", "💀 Sei morto. Game Over.")
                        self.root.quit()
            else:
                messagebox.showinfo("Fuga", "🏃 Sei fuggito!")
                return

        if enemy_health <= 0:
            messagebox.showinfo("Vittoria", "🎉 Hai sconfitto il nemico!")
            self.player.gain_experience(50)

    def find_treasure(self):
        item = random.choice(["pozione di guarigione", "spada", "scudo", "oro"])
        self.player.inventory.append(item)
        messagebox.showinfo("Tesoro", f"💎 Hai trovato: {item}.")
        if item == "pozione di guarigione":
            self.player.heal(20)
            messagebox.showinfo("Guarigione", "❤️ Hai recuperato 20 punti salute!")

    def display_status(self):
        status = (
            f"👤 Nome: {self.player.name}\n"
            f"❤️ Salute: {self.player.health}\n"
            f"⭐ Livello: {self.player.level}\n"
            f"🔮 Esperienza: {self.player.experience}/100\n"
            f"🎒 Inventario: {', '.join(self.player.inventory) if self.player.inventory else 'Vuoto'}"
        )
        messagebox.showinfo("Stato del giocatore", status)

    def use_item(self):
        if not self.player.inventory:
            messagebox.showinfo("Inventario", "🎒 Il tuo inventario è vuoto.")
            return

        item = self.player.inventory.pop(0)
        if item == "pozione di guarigione":
            self.player.heal(20)
            messagebox.showinfo("Oggetto usato", "❤️ Hai usato una pozione di guarigione e recuperato 20 punti salute!")
        else:
            messagebox.showinfo("Oggetto usato", f"✨ Hai usato: {item}.")

    def exit_game(self):
        self.root.quit()

if __name__ == "__main__":
    root = tk.Tk()
    app = GameApp(root)
    root.mainloop()
