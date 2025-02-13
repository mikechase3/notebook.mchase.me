# Coindash Design Doc

Mike Chase | CPS 592 Godot! | Notes:`notebook.mchase.me/Compscidev/Game-Development/coindash-design-doc`

## 1. **Introduction**

![](../../../../compscidev/game-development/design-document/CleanShot%202024-09-23%20at%2022.03.13@2x.png)

* **Working Title**: _Foxy’s Golden Space Adventure_
* **Genre**: Casual arcade; satire.
* **Platforms**: PC, Mac.
* **Concept Statement**: Foxy and friends explore outer space to collect coins because, like the ultra-wealthy, they’re chasing more wealth (even in space because that’s what rich people do these days?). Players control a fox collecting coins and dodge moon rocks, highlighting the absurdity of wealth accumulation in space while real-world problems persist.

## 2. **Goals**

* **Primary Goal**: The player collects as many coins as possible within a time limit while avoiding obstacles.
* **Secondary Goal**: Satirically engage players by mocking the pursuit of wealth for wealth’s sake, framed against space exploration.
* **Player Emotions**: Fun, silliness, and light-hearted mockery.

## 3. **Game World**

The game world is a blend of a few layers of Gimp’s default map. This is the foundation for the setting:

![Created in Gimp](../../../../compscidev/game-development/design-document/CleanShot%202024-09-23%20at%2022.08.09@2x.png)

* **Setting**: The game takes place on the moon, where coins are scattered across the surface. The environment is minimalist, keeping the focus on gameplay, with pixel art that gives it a casual, comedic feel.
* **Visuals**: The moon is rendered using tiles. The game features a relatively crappy moon/crater like backdrop, moon rocks as obstacles, and a colorful wormhole that acts as a power-up. The fox character is also in pixel art. The rocks aren’t implemented yet, but might be by midnight.
* **Mood**: A light and humorous atmosphere with a minimalist outer space aesthetic. ![Blended Textures via Transparency](../../../../compscidev/game-development/design-document/CleanShot%202024-09-23%20at%2022.09.58@2x.png)

## 4. **Mechanics**

* **Core Gameplay Loop**:
* Foxy, the sprite, is controlled via arrow keys.
  * He/She coins to increase score and race against the timer.
  * Player tries to avoid moon rocks, which act as rolling obstacles.
* Collecting powerups (currently bolts; wormholes if I have time) will prolong the game by adding to the time-to-death number on the HUD.
  * The game ends when the above runs out or foxy gets hit by a rock, and players can restart for a high score (warning- moon rocks & leaderboard not implemented yet)
* **Objectives**:
  * Collect coins before the timer expires.
  * Avoid obstacles and take advantage of powerups to extend playtime.
* **Player Actions**:
  * **Movement**: Arrow keys or touch controls.
  * **Interactions**: Move into coins or powerups to collect them.
* **Challenges**:
  * Moon rocks that roll across the screen. (Todo - modify; currently shrubberies)
  * A countdown timer that forces players to strategize their movements.

## 5. **Characters/Obstacles**

![](../../../../compscidev/game-development/design-document/CleanShot%202024-09-19%20at%2022.07.45.gif)

* **Foxy!**: A fox sprite representing the player. The fox’s mission is to gather as many coins as possible in space, symbolizing the satire of wealth accumulation.
* **Obstacles**: Moon rocks, which act as rolling obstacles. If hit, they end the game.
* **Non-playable elements**: Coins scattered across the moon and wormhole powerups that add time to the game.

## 6. **Story**

* **Narrative Summary**: Foxy, a space explorer, has gone to the moon, not to discover new worlds, but to collect coins because, like the rich, that's what they do when they've exhausted Earth’s resources. The game pokes fun at the pursuit of wealth, especially in absurd places like space.
* **Tone**: Satirical and humorous, with a focus on absurdity and mockery of wealth for wealth’s sake.

## 7. **UI**

* A HUD score display that shows the number of pairs of coins collected (they come in sets of two; it’s totally a feature not a bug)
* A timer that counts down, indicating how much time the player has left.
* A start button begins the game upon being pressed.
* **Future Updates**:
  * A scoreboard to display high scores.
  * **User Input**: Arrow keys for PC/Mac or touch controls for Android to move the fox.

## 8. **Audio**

* **Style**: Space-themed sound effects and lighthearted, custom piano music.
* **Sound Effects**:
  * **CoinSound**: Plays when coins are collected.
  * **EndSound**: Plays when the game ends.
  * **PowerupSound**: Plays when powerups are collected.
* **LevelUpSound**: My quick/dirty audacity recording gets played upon leveling up.
* **SkillSound**: audacity recording pitchbended plays every five levels.
* **YouSuckSound**: plays if you die before level 5 is reached.
* **Background Music**: Custom space music composed on a piano, divided into different levels using Audacity.
* **Future Plans**: Different sound effects for obstacles, powerup jingles, and better audio production.

## 9. **Monetization**

* **Monetization Strategy**: Free and open-source under a Creative Commons license, requiring users to cite the authors of the game’s assets.

## 10. **Conclusion**

The game is designed to be a short, fun experience with satirical elements that engage players both through its gameplay and its underlying commentary on wealth. Through humorous visuals, mechanics, and sound, _Foxy and Friend's Space Adventure_ aims to entertain while subtly mocking the absurdities of space exploration for the rich.

## Works Cited & Disclaimers

* Also [https://ansimuz.itch.io/sunny-land-pixel-game-art](https://ansimuz.itch.io/sunny-land-pixel-game-art)
* Book resources from [https://github.com/PacktPublishing/Godot-4-Game-Development-Projects-Second-Edition/tree/main/](https://github.com/PacktPublishing/Godot-4-Game-Development-Projects-Second-Edition/tree/main/)
