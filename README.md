# Maze Generation

mazeGeneration is a repo dedicated to my first attempt at generating a maze using recursive backtracking displayed to a window using [SFML](https:://www.sfml-dev.org).

## Breakdown

This program utilizes 2 custom made classes:
 - ___Grid___
    - __Usage__
      - Stores a vector of all Cells.
      - Performs checks between Cells in the vector.
      - Stores a vector of pointers to Cells previously visited for backtracking.
      - Begins with a randomly selected Cell and picks the next cell according to a list of the four neighboring cells.
    - __Methods__
      - ADD LATER
 - ___Cell___
    - __Usage__
      - Contains a array of boolean values to determine which walls are active or inactive.
    - __Methods__
      - ADD LATER

## Compile and Run

Utilizes a very generalized _Makefile_ to link required files together.
To run the program, simply clone the repository, or download it locally, and run the following command in a terminal.
```
$ make
$ make run
```

Simple as that.
