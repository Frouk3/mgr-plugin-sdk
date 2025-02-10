## Contribution Guidelines

This repository focuses on reversing the game’s binary using IDA Pro to reconstruct its C++ structures, functions, classes, and inheritance while following a consistent naming convention.

## Contribution Rules
1. **Language**: All code must be written in C++.
2. **Member Variables**: Use the m_ prefix (e.g., m_health, m_position).
3. **Function Naming**: Use camelCase (e.g., initializeGame, loadResources).
4. **Structure & Class Reversal**:</br>
Identify structures with their methods, static fields, and members.</br>
Maintain inheritance relationships when reversing.</br>
Check size validation of structures/classes, If it's not matching with the game, it will require changes.</br>

## Contribution Process
1. Fork & Clone the Repository.
2. Create a Branch (e.g., feature/reverse-class).
3. Reverse & Rename Properly.
4. Follow Naming Conventions.
5. Submit a Pull Request.

Documentation is optional but encouraged for clarity. Contributions that don’t follow naming conventions will require changes.
