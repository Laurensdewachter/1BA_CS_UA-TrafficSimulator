# Traffic Simulation

### Parameters
- `-f [FILENAME]`: the file from which the simulation must be loaded (required)
- `-r [REPETITIONS]`: the amount of times the simulation must be run (required)
- `-sg`: simple graphics
- `-g`: normal graphics
- `-i [SIZE]`: create images of the simulation with the given size

### Images
For the `-i` flag to work, there must be a directory names `images` and the engine itself must be in the working directory.

### Tests
The tests need the directories `testInput` & `testOutput` to run.  
- `testInput` contains all the files that are compared to the test results and therefore need to be established before
  running the tests. Only files containing "HappyDay" can be  removed as these are created automatically by the tests.
- `testoutput` can be completely empty and all files in this directory are safe to be deleted.