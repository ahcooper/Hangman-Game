Hangman
A console-based Hangman game written in C++ that features multiple difficulty levels, input validation, duplicate guess prevention, an alphabet tracker, and a hidden Meridia's Beacon easter egg.

Features
Gameplay
Random word selection from a text-based word bank
Three difficulty levels:
Easy (10 guesses)
Normal (6 guesses)
Hard (4 guesses)
Case-insensitive letter guessing
Incorrect guess tracking
Duplicate guess prevention
Win and lose conditions
Replay functionality
User Interface
Main menu system
Difficulty selection menu
Alphabet tracker showing available letters
Hidden word display
Remaining guess counter
Input validation for all menu selections and guesses
Meridia's Beacon Easter Egg
A hidden easter egg can be triggered by:

Receiving the word beacon
Winning the game
Finishing with exactly one guess remaining
When triggered:

A NEW HAND TOUCHES THE BEACON!
Project Structure
Main Components
Menus
showMenu()
showDifficultyMenu()
Gameplay
selectWord()
checkWord()
getGuessCount()
Validation
checkInput()
validateDiff()
checkGuess()
Guess Tracking
isLetterAlreadyGuessed()
displayAlphabetBoard()
Beacon System
triggerBeacon()
displayBeacon()
Current Version
Version 1.0
Completed Features:

Difficulty system
Guess counter
Input validation
Duplicate guess prevention
Alphabet tracker
Word bank support
Win condition
Lose condition
Replay system
Meridia's Beacon easter egg
Separate Beacon module (Beacon.h / Beacon.cpp)
Project Status:

Feature Complete
Roadmap
Version 1.1 - Word Categories
Allow players to select themed word banks.

Planned categories:

Technology
Fantasy
Cyberpunk
Gaming
Random
Example:

1) Technology
2) Fantasy
3) Cyberpunk
4) Gaming
5) Random
Benefits:

Higher replay value
More focused word selection
Easier future expansion
Version 1.2 - Hint System
Provide optional hints during gameplay.

Possible hints:

Word category
First letter reveal
Random letter reveal
Word length reminder
Difficulty integration:

Easy   = 2 hints
Normal = 1 hint
Hard   = No hints
Version 1.3 - Statistics System
Track player performance.

Planned statistics:

Games Played
Games Won
Games Lost
Win Percentage
Hard Mode Wins
Total Words Solved
Example:

Games Played: 25
Games Won: 18
Games Lost: 7
Win Rate: 72%
Version 1.4 - Achievement System
Unlock achievements through gameplay.

Beacon Hunter
Trigger the Meridia's Beacon event.

Word Master
Win 10 games.

Untouchable
Win a game on Hard difficulty.

Alphabet Soup
Guess every letter of the alphabet across multiple games.

Lucky Guess
Win with exactly one guess remaining.

Netrunner
Win 25 games.

Future Ideas
Persistent statistics saved between sessions
Multiple word bank files
Additional easter eggs
Custom player profiles
Sound effects
Expanded achievement system
Technologies Used
C++
STL (vector, string, istream_iterator)
File I/O
Modular source/header architecture
Console-based interface
Developer Notes
The project was originally built as a learning exercise for:

Functions
Input validation
Loops
Vectors
File handling
Header/source separation
Git and GitHub workflow
The project evolved into a complete Hangman implementation featuring custom gameplay systems, replay support, and easter eggs.

License
Personal educational project.
