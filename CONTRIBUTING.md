## Contribution Guidelines

This repository focuses on reversing the game’s binary using IDA Pro to reconstruct its C++ structures, functions, classes, and inheritance while following a consistent naming convention.

## Contribution Rules
1. **Language**: All code must be written in C++.
2. **Member Variables**: Use the m_ prefix (e.g., m_health, m_position).
3. **Function Naming**: Use camelCase (e.g., initializeGame, loadResources).
4. **Structure & Class Reversal**:<br>
Identify structures with their methods, static fields, and members.<br>
Maintain inheritance relationships when reversing.<br>
Check size validation of structures/classes, If it's not matching with the game, you should properly research & reverse the class.<br>
If you break the rule of "loaded DLL" - suggesting the function that was not present in the application itself, your pull request might be ignored & closed.<br>

## Contribution Process
1. Fork & Clone the Repository.
2. Create a Branch (e.g., feature/reverse-class).
3. Reverse & Rename Properly.
4. Follow Naming Conventions.
5. Submit a Pull Request.

Documentation is optional but encouraged for clarity. Pull requests that do not follow any of the contribution rules will be closed immediately.