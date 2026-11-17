# Blackjack – C Project

A terminal-based Blackjack game written in C.

## Features

- 52-card deck with four copies of each card value
- Fisher-Yates shuffle algorithm
- Hit or Stand gameplay
- Automatic Ace handling (1 or 11)
- Blackjack detection
- Dealer follows the standard hit-until-17 rule
- Betting and balance system
- Win, loss, push and bankruptcy conditions
- Multiple rounds

## Technologies

- C
- Standard C libraries (`stdio.h`, `stdlib.h`, `time.h`)
- CS50 Library (`cs50.h`)
- GCC

## How to Run

Compile the program:

```bash
gcc main.c -o blackjack -lcs50
```

Run the game:

```bash
./blackjack
```

## About

This project was created to practice C programming and explore concepts such as arrays, functions, pointers, loops, random number generation and game logic.
