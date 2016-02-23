Meep!
======
Author: Ailyn Tong

Overview
---------
Meep! is a 1v1 arcade-style shooter game. Players control characters called Meeps and shoot Bullets through each other. To win, a Player must score 3 points. A Player gains a point when successfully shooting the enemy Meep; however, he/she will lose a point if the enemy Player takes the Life powerup at the bottom of the screen. There are also obstacles scattered around the game in the form of coloured, patterned squares. They will slow any Meeps above them.

NOTES:
Click SFMLGame1.exe to run the game.
After every game close the console (not the game window, that freezes) to close the game. This is also the only way to restart.

Controls
---------
Player 1:
 * WASD to move
 * Space to shoot

Player 2:
 * IJKL to move
 * " (Quote) to shoot

NOTE: Players must be moving to be able to shoot. The bullet will travel in a straight line in the direction of movement until it hits an edge of the game screen, where it terminates. Players cannot shoot another bullet until the previous one has terminated.

Class Documentation
--------------------
### Resources
Contains constants, simple data structures, and static methods.

Methods:
 * static int rng(): generates a random int within the specified range. Credits to Neelay Junnarkar.
 * static bool collision(): checks collision between two Entities by using their hitBoxes
 * static Point gen_position(): generates a random position on the game screen for an Entity

### Point
A simple data structure with x- and y-coords.

### Dimension
A simple data structure with width and height.

### MoveDirection
An enum for MovingEntities. Uses binary and bit operations to represent multiple directions simultaneously.

### Entity
An Entity is any game element that can interact with other game elements. There are 4 types of Entities in this game: Meep, Bullet, Obstacle, Life.

Fields:
 * Point point: current location in game
 * std::string file: file path of spritesheeet
 * sf::Texture spritesheet: spritesheet image referenced by the sprite
 * sf::Sprite sprite: image drawn onto game screen
 * float scale: amount sprite is scaled by when rendered

Methods:
 * void draw(): draws sprite onto game screen
 * sf::FloatRect getHitBox(): returns bounding box of sprite in global coordinates

### Obstacle
Superclass: Entity
Obstacles are colourful squares that slow any Meeps over them. They are generated at random positions on the game screen and do not move throughout the game.

### Life
Superclass: Entity
A one-time powerup that gives Player a life by reducing enemy score by 1.  
NOTE: will do nothing if enemy score is 0.

Fields:
 * bool isTaken: whether or not life has been taken

Methods:
 * void take(): takes a life from specified player
 * void draw(): renders sprite only if it has not beeen taken

### MovingEntity
Superclass: Entity  
A MovingEntity is a type of Entity that can be controlled by Players. They cannot move beyond the bounds of the game screen. Meeps and Bullets are MovingEntities.

Fields:
 * std::map spriteMap: maps directions to sprite images
 * int moveSpeed: movement speed

Methods: 
 * virtual void update(): updates MovingEntity every frame; is implemented by subclasses
 * bool hitBounds(): detects collision with edges of game screen

### Meep
Superclass: MovingEntity
Meeps are the characters controlled by Players. There are different colours of Meeps, and each Meep can face 8 different positions. Meeps can die, but they will respawn after a certain number of updates. Running over obstacles will slow their movement speed temporarily.

Fields:
 * int spriteNum: index of current sprite being rendered
 * bool dead: whether or not Meep is dead and waiting to respawn
Methods:
 * void update(): updates Meep with specified direction; inherited from MovingEntity
 * void die(): kills Meep and moves it off-screen
 * void respawn(): respawns Meep in a random location

### Bullet
Superclass: MovingEntity
Players can shoot bullets through the enemy Meep to kill it. A Bullet travels in a straight line in the direction the Player's Meep is moving when it is shot, and continues until it hits an edge of the game screen. NOTE: Players cannot shoot bullets if their Meep is not moving.

Fields:
 * int dX: change in x-coord each update
 * int dY: change in y-coord each update
 * bool initialized: whether or not this bullet has been initialized and is being shot

Methods:
 * void init(): when shot, initializes bullet with a direction, spriteNum, and starting point; bullet will always shoot from the Meep's leaf
 * void update(): updates Bullet's position if it is initialized; inherited from MovingENtity
 * void disable(): disables bullet when it hits an edge of the game screen

### Player
A Player is composed of a Meep and a Bullet, and controls the behaviour of the Meep and Bullet based on user input.

Fields:
 * Meep meep: character that Player moves around the screen
 * Bullet bullet: Player shoots this bullet from the Meep
 * bool slow: whether or not the Meep has been slowed by obstacle(s)
 * int respawnCount: current number of updates Player has been waiting to respawn
 * int score: Player's current score
 * std::array keyMap: maps a specific key to a MoveDirection or combination thereof

Methods:
 * void init(): initializes Player with a keyMap and a starting point
 * void update(): updates Meep and Bullet based on user input
 * bool checkHit(): checks if Meep has collided with another entity's hitBox
 * void moveOverride(): toggle's Meep's movement speed between slow and normal
 * void die(): kills Meep
 * void respawn(): respawns Meep and resets respawnCount
 * void draw(): draws Meep and Bullet onto game screen if allowed
 * void modifyScore(): changes score

### Screen
An image that fills the game screen. Used for start and end of game.

Fields:
 * sf::Texture texture: image referenced by sprite
 * sf::Sprite sprite: encapsulates image to be rendered

Methods:
 * void init(): gives texture an image file and initializes sprite
 * void display(): renders Screen onto specified RenderWindow

### Game
The Game class links all components of the game: RenderWindow, Screens, Players, Obstacles, Life. The Game class also contains overall game control methods: collision detection, slow detection, start/end

Fields:
 * bool start: whether or not startScreen is enabled
 * Screen startScreen, endScreen: two Screens for the start and end of game
 * sf::RenderWindow window: window in which game components are drawn
 * Player p1, p2: players
 * std::array obstacles: array of all obstacles in game
 * Life life: life powerup

Methods:
 * void run(): opens window and runs game
 * void drawObstacles(): draws all obstacles onto window
 * void checkCollision(): meep-bullet collision detection
 * void checkSlow(): meep-obstacle slow detection
 * void checkLife(): meep-life collision detection
 * bool win(): checks if game has been won (a player has reached a score of 3)
 * void end(): ends game with correct Screen and prints messages onto console
 * void printScores(): prints scores of players onto console