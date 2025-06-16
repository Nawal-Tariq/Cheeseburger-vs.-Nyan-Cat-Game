# 🍔 Cheeseburger vs. Nyan Cats - C++ Console Game
This is a C++ console-based arcade game where the player, represented by a Cheeseburger 🍔, must dodge falling Nyan Cats 🐱, collect Power-ups ⚡, and get support from Friends 🧑‍🤝‍🧑 to survive and score high! The game emphasizes core Object-Oriented Programming (OOP) principles such as inheritance, polymorphism, and encapsulation.

🎯 Core Features
1. 👤 Player (Cheeseburger)
Moves left ⬅️ and right ➡️ to avoid Nyan Cats.

Gains points by:

Collecting power-ups ⚡

Interacting with friends 🧑‍🤝‍🧑

Abilities include:

🛡️ Shield activation

💨 Speed boost

✨ Score multiplier

Loses lives on collision with Nyan Cats unless shielded.

2. 🐱 Nyan Cats
Fall from random positions at varying speeds depending on difficulty.

Reset to the top after collisions or exiting the screen.

Become faster and more frequent as the game progresses.

3. ⚡ Power-Ups
Spawn randomly with special abilities:

🛡️ Shield – temporarily protects the player.

🚀 Speed Boost – increases movement speed.

💎 Score Multiplier – boosts points earned.

4. 🧑‍🤝‍🧑 Friends
Friendly game objects that assist the player:

Provide extra lives ❤️

Help based on varying support levels.

5. 📈 Levels & Difficulty
Game difficulty increases with score milestones (e.g., +100 pts).

Nyan Cats fall faster and more frequently at higher levels.

6. ⚙️ Game Mechanics
Collision detection handles object interactions.

⏸️ Pause/Resume functionality via keyboard input.

🧭 Menu System:

Start Game

View High Scores

Read Instructions

See Team Credits

7. 🖼️ Graphics
ASCII symbols represent all game objects:

B for Cheeseburger

N for Nyan Cats

F for Friends

🎨 Color-coded text enhances visual clarity.

8. 💾 Game State Management
Tracks:

Player lives ❤️

Current score 🏆

Active level 📊

Allows replay by resetting the state after Game Over.

🧱 Key Classes (OOP Structure)
🧩 GameObject (Abstract Base Class)

Common attributes: position, size

Handles basic collision detection

🍔 Cheeseburger (Player)

Manages movement, score, lives, and active power-ups

🌈 NyanCat (Enemy)

Falls vertically with speed variation

⚡ Powerup

Temporarily boosts player stats

👥 Friend

Increases lives based on support level

🎮 Game

Controls rendering, input handling, and core game logic

🔁 Game Flow
Move the Cheeseburger ⬅️ ➡️ to avoid Nyan Cats and collect Power-ups.

Power-ups and Friends help sustain you by offering boosts and lives.

Survive as long as you can — the game ends when lives reach 0.

Replay with a fresh state to try and beat your previous score!
