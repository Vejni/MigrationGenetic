# MigrationGenetic

This repo contains code to solve Genetic Algorithms assignment in the Optimization course of the UAB master's in Modelling for Science and Engineering. The repo structure is as follows:

- docs: Contains the problem statement, and report about the project.
- logs: Contains the output files, fitness scores and corresponding parametrisations.
- src: Contains the source code.
- plot: Script for plotting and outputs.

Main executable: main or get_results.sh to do a batch of problems.

Arguments (in order):

| Parameter      | Functionality                                                               | Range  | Default                      |
|----------------|-----------------------------------------------------------------------------|--------|------------------------------|
| autopilot      | Determines if the GA can change parameters if stuck.                        | 0, 1   | 1                            |
| n_iter         | Maximum number of generations.                                              | 1+     | 500                          |
| pop_size       | Number of Individuals in each generation.                                   | 1+     | 1000                         |
| unchanged_max  | Number of Generations with no better fittnes before program is stopped.     | 1+     | 40                           |
| fitness_case   | Determines the fitness function.                                            | 0, 1   | 0                            |
| select_case    | Determines the parent selection function.                                   | 0 - 4  | 0                            |
| crossover_case | Determines the crossover function.                                          | 0 - 2  | 0                            |
| mutation_case  | Determines the mutation function.                                           | 0 - 3  | 0                            |
| crossover_prob | The probability in uniform crossover.                                       | [0, 1] | 0.1                          |
| mutation_prob  | The probability of single and multiple bitflip mutations.                   | [0, 1] | 0.1                          |
| k              | The number of individuals selected at random for tournament (in selection). | 1+     | 100                          |
| path           | Path for logging.                                                           | -      | "logs/fittness.csv"          |
| fittest_path   | Path for parameter and residual logging.                                    | -      | "logs/residues\_fittest.csv" |
