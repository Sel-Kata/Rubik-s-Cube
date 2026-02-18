# cub
The program solves a disassembled Rubik's cube. The cube's state is fed as input, and the program outputs the path (the steps needed to solve the current cube).

The program doesn't use an algorithm for solving, but uses two BFSs. One search is performed from the disassembled state, and the other from the assembled state (they move toward each other). Once the states match (the vertices intersect), the program outputs the matching path (the path from the disassembled BFS + the path from the assembled BFS). Using two BFSs minimizes memory and time consumption.
