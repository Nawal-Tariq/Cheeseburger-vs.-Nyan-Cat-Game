## Cheeseburger vs. Nyan Cats – C++ Console Game 🍔

This is a **C++ console-based arcade game** where the player, represented by a Cheeseburger, must dodge falling Nyan Cats, collect Power-ups, and get help from Friends to survive and score high. The game demonstrates strong **Object-Oriented Programming (OOP)** principles, including **inheritance**, **polymorphism**, and **encapsulation**.

---

### Core Features

#### 1. Player (Cheeseburger) 👤

* Moves left and right to avoid Nyan Cats.
* Gains points by collecting power-ups and interacting with friends.
* Can activate abilities like:

  * Shield (temporary invincibility)
  * Speed boost
  * Score multiplier
* Loses lives when colliding with Nyan Cats unless shielded.

#### 2. Nyan Cats 🐱‍👓

* Fall from random positions at variable speeds.
* Reset position upon collision or reaching the bottom of the screen.
* Become faster as levels increase.

#### 3. Power-ups ⚡

* Appear randomly on the screen.
* Provide temporary benefits:

  * Shield
  * Speed Boost
  * Score Multiplier

#### 4. Friends

* Friendly characters that provide support (e.g., increase player lives).
* Have different support levels affecting the amount of help provided.

#### 5. Levels and Difficulty

* Difficulty increases based on score milestones (e.g., every 100 points).
* Introduces faster Nyan Cats and more frequent obstacles.

#### 6. Game Mechanics

* Implements collision detection between objects.
* Pause/Resume functionality via keyboard.
* Includes a basic menu:

  * Start Game
  * View High Scores
  * Instructions
  * Team Credits

#### 7. Graphics

* Uses ASCII characters to represent:

  * Cheeseburger (B)
  * Nyan Cats (N)
  * Friends (F)
* Color-coded text enhances visibility and gameplay experience.

#### 8. Game State Management

* Tracks and manages:

  * Player lives
  * Score
  * Current level
* Supports full reset after Game Over for replayability.

---

### Key Classes (OOP Design)

1. **GameObject** *(Abstract Base Class)*

   * Contains position, size, and collision logic.

2. **Cheeseburger** *(Player)*

   * Manages input, score, lives, and power-up effects.

3. **NyanCat** *(Enemy)*

   * Falls from the top and challenges the player.

4. **Powerup**

   * Provides temporary advantages when collected.

5. **Friend**

   * Support character increasing player lives.

6. **Game**

   * Coordinates gameplay, rendering, and event handling.
### Game Flow 🎮

* The player controls the Cheeseburger, avoiding enemies and collecting items.
* Power-ups and friends help maintain progress and survival.
* The game ends when all lives are lost.
* Players can restart with a fresh state to try and beat their previous score.

