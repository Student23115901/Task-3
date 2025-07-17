# Graphical Snake Game using SFML  
### Author: Anushk Singh  
### Internship ID: CT06DF1877  
### Company: CodeTech IT Solutions Pvt Ltd  
### Internship Duration: 30/05/2025 – 15/07/2025  

---

## Project Overview  

As part of my third internship task, I developed a **Graphical Snake Game** using the **SFML (Simple and Fast Multimedia Library)** in C++. This project was focused on creating an interactive, visually appealing 2D snake game that closely resembles the classic arcade snake gameplay, but built entirely from scratch using modern C++ and SFML graphics handling.  

The main objective was to design a responsive and professional-grade game application that showcased my understanding of event handling, game loops, collision detection, and graphical rendering in a structured and efficient manner.  

---

## Key Features  

- ✅ **Real-Time Snake Movement & Controls**  
- ✅ **Food Generation with Randomized Positions (Avoiding Wall & Snake Body Overlap)**  
- ✅ **Score Tracking**  
- ✅ **Collision Detection with Walls, Snake Body, and Food**  
- ✅ **Game Over Condition upon Collision**  
- ✅ **Simple User Interface with SFML Window Events**  
- ✅ **Clean, Professional Code Structure for Easy Scalability**  

---

## Technologies Used  

- **Language:** C++17  
- **Graphics Library:** SFML (Simple and Fast Multimedia Library)  
- **Compiler:** GCC / MinGW with SFML linking  
- **Development Environment:** MSYS2 with MinGW64  

---

## How to Compile & Run  

1️⃣ Make sure SFML is installed and linked correctly.  

2️⃣ Compile with SFML libraries:  
```bash
g++ snake_game.cpp -o snake_game -lsfml-graphics -lsfml-window -lsfml-system
```  

3️⃣ Run the game:  
```bash
./snake_game
```  

---

## Game Description (Task Summary)  

The **Graphical Snake Game** recreates the classic arcade snake mechanics where the player controls a snake that grows in length after consuming food. The player must avoid collisions with the walls or the snake's own body.  

**Gameplay Highlights:**  
- The snake moves in a grid-like environment with adjustable speed.  
- The player uses arrow keys for movement control.  
- Red food blocks appear randomly on the field, never overlapping the snake or spawning on walls.  
- On consuming food, the snake grows longer, increasing the difficulty.  
- If the snake hits a wall or its own body, the game ends with a “Game Over” message.  

The implementation of this task required a solid grasp of several programming concepts, including:  
- Real-time event polling with SFML event handlers  
- Frame rate control to ensure smooth gameplay  
- Dynamic object management (snake segments)  
- Simple collision detection algorithms  
- User interaction design within a graphical environment  

Special attention was paid to ensuring that the game logic remained consistent and free from bugs such as unexpected food placement or collision miscalculations — common pitfalls in game development.  

---

## My Learning from this Task  

- Hands-on experience with SFML for 2D game graphics and window handling  
- Understanding of the game loop architecture and event-driven programming  
- Real-time input handling and frame rate management  
- Improved problem-solving in handling dynamic gameplay mechanics  
- Importance of structured code organization for scalability and maintenance  

---

## Conclusion  

The **Graphical Snake Game** not only strengthened my understanding of graphical programming with C++ and SFML but also provided a foundation for more advanced game development.  

This project refined my coding practices and problem-solving skills, which are essential for building user-centric applications — a key aspect of my professional training at **CodeTech IT Solutions Pvt Ltd**.  

---

