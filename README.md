# Phantom Of Memories: The Twins

A 2D action-adventure game developed in C++ using the `graphics.h` library for a college programming course. The game features twin characters with unique abilities battling through waves of enemies in a dark, atmospheric setting.

## 🎮 Game Overview

**Phantom Of Memories: The Twins** is a side-scrolling action game where players control twin characters who can exist as light and shadow. The twins are unaware of each other's existence but are forever connected, as light and shadow cannot exist in the same place yet are always together.

### Game Features
- **Twin Character System**: Play as interconnected twin characters with unique abilities
- **Combat System**: Multi-hit combo attacks with directional combat
- **Special Abilities**: Two distinct special moves (E and Q keys)
- **Enemy Variety**: Two enemy types - Melee and Ranged attackers
- **Stage Progression**: Multiple stages with increasing difficulty
- **Health & Regeneration System**: Health regeneration through combat
- **Dodge Mechanics**: Defensive dodge rolling with i-frames
- **Dynamic Backgrounds**: Parallax scrolling environments

## 🎯 Gameplay Mechanics

### Controls
- **A/D**: Move left/right
- **Space**: Jump
- **Left Mouse Button**: Attack (combo system)
- **Shift**: Dodge roll
- **E**: Special Ability 1 (Sister Attack)
- **Q**: Special Ability 2 (Longing/Ultimate)
- **ESC**: Exit/Menu navigation

### Combat System
- **5-hit combo chain**: Each attack in the sequence deals different damage
- **Directional attacks**: Different animations for left and right attacks
- **Stagger system**: Some enemies can be immune to stagger
- **Special abilities**: Always cause stagger and provide damage immunity during casting

### Enemy Types
1. **Melee Enemies**: Close-range fighters that charge at the player
2. **Ranged Enemies**: Shoot projectiles from a distance

## 🎨 Technical Features

### Graphics Implementation
- **Sprite Animation System**: Frame-based animation with timing controls
- **Image Masking**: Custom masking system for transparent backgrounds
- **Double Buffering**: Smooth animation using page flipping
- **Sprite Collision Detection**: Hitbox-based collision system

### Asset Structure
```
adversary/          - Enemy sprites (left/right animations)
attack left/right/  - Player attack animations
brother walk gif/   - Player walking animations  
dodgel/dodger/      - Dodge roll animations
environment/        - Background and world assets
sister left/right/  - Special ability animations
longing/           - Ultimate ability animations
skill/             - UI and HUD elements
soundtrack/        - Game music and sound effects
```

### Audio System
- Background music with looping
- Different tracks for menu, battle, and ending
- Dynamic music changes based on game state

## 🛠️ Development Details

### Technology Stack
- **Language**: C++
- **Graphics Library**: graphics.h (Borland Graphics Interface)
- **Audio**: Windows API (PlaySound)
- **Platform**: Windows

### Code Architecture
The game is structured using object-oriented programming with the following main classes:

- **`System`**: Game state management, menu, death/ending screens
- **`Player`**: Character movement, combat, abilities, animation
- **`Enemy`**: Enemy AI, movement patterns, attack behaviors
- **`World`**: Level generation, background rendering, collision
- **`Hitbox`**: Collision detection and damage calculation

### Key Programming Concepts Demonstrated
- Object-Oriented Programming (Classes and Inheritance)
- Game Loop Implementation
- State Management
- Sprite Animation Systems
- Collision Detection
- Memory Management with malloc/free
- File I/O for asset loading

## 🚀 Installation & Setup

### Prerequisites
- Windows operating system
- Graphics library support (BGI)
- C++ compiler with graphics.h support (Turbo C++ or compatible)

### Running the Game
1. Clone the repository
2. Ensure all asset folders are in the project directory
3. Compile and run `main.cpp`
4. **Important**: The game is optimized for 1536x864 resolution

### Build Files
- `main.cpp`: Complete game implementation
- `webuiltthishoue.cpp`: Early prototype/test version
- `ProglanProject.cbp`: Code::Blocks project file

## 🎵 Game Progression

### Stage System
- **Stage 0**: Tutorial stage (3 waves)
- **Stage 1**: Mixed combat introduction (3 waves)
- **Stage 2**: Intense combat scenarios (3 waves)
- **Stage 3**: Victory condition

### Difficulty Scaling
- Enemy count increases with each wave
- New enemy types introduced progressively
- Special abilities unlock as stages progress

## 🏆 Educational Aspects

This project demonstrates several important computer science concepts:
- **Game Development**: Complete game loop, state management, user input
- **Graphics Programming**: Sprite rendering, animation, visual effects
- **Data Structures**: Arrays, classes, memory management
- **Algorithm Design**: Collision detection, AI behavior patterns
- **Software Architecture**: Modular design, separation of concerns

## 🎯 Game Story & Theme

The game explores themes of duality, connection, and the relationship between light and shadow. The twin characters represent complementary forces that, while unable to coexist in the same space, are eternally bound together. Players experience this through the combat system where both characters' abilities are needed to progress.

## 📝 Credits

Developed as a college programming project demonstrating advanced C++ concepts and graphics programming techniques. The game showcases custom sprite masking techniques that allow for transparent backgrounds - a significant technical achievement using the limitations of the graphics.h library.

---

*Note: This game represents a comprehensive example of C++ graphics programming and game development principles, created within the constraints of academic requirements and classic graphics libraries.*