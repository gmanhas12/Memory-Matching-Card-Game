# Memory-Matching-Card-Game





<img width="580" alt="Screenshot 2025-01-17 at 12 27 30 AM" src="https://github.com/user-attachments/assets/9748d8f1-b172-4329-8379-b41f28de5ab0" />







Overview
This is a two-player Memory Matching Card Game built in C. Players take turns flipping cards to find matching pairs. The player with the most matches wins!

How to Play: 
Cards are arranged face down in a grid.
Players pick two cards per turn:
If the cards match, the player keeps them and takes another turn.
If not, the turn passes to the other player.
The game ends when all cards are matched, and the player with the most matches is declared the winner.




Features
A shuffled 52-card deck with suits and values.
Turn-based gameplay with input validation.
Match detection and tracking using linked lists.
Cross-platform compatibility for clearing the screen.




How to Run





Compile: gcc main.c card_LList.c gameObjects.c gameFunctions.c -o memory_game



Run: ./memory_game



File Overview


card_LList.c: Manages players’ winning piles using linked lists.
gameObjects.c: Handles deck initialization and player setup.
gameFunctions.c: Implements game logic like matching and input validation.
main.c: Runs the game loop and handles user interaction.
