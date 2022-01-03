gcc main.c -lm -o main

./main 1000 5000 10 -1 -1 -1 -1 0.1 0.1 100 "logs/residues.csv" "logs/residues_fittest.csv"

# Compare Fitness Functions
./main 1000 5000 10 0 -1 -1 -1 0.1 0.1 100 "logs/fitness_compare/residues_MaxNorm.csv" "logs/fitness_compare/residues_fittest_MaxNorm.csv"
./main 1000 5000 10 1 -1 -1 -1 0.1 0.1 100 "logs/fitness_compare/residues_WeightedNorm.csv" "logs/fitness_compare/residues_fittest_WeightedNorm.csv"

# Compare Selection functions
./main 1000 5000 10 -1 0 -1 -1 0.1 0.1 100 "logs/selection_compare/residues_TournamentSelection_100.csv" "logs/selection_compare/residues_fittest_TournamentSelection_100.csv"
./main 1000 5000 10 -1 0 -1 -1 0.1 0.1 250 "logs/selection_compare/residues_TournamentSelection_250.csv" "logs/selection_compare/residues_fittest_TournamentSelection_250.csv"
./main 1000 5000 10 -1 0 -1 -1 0.1 0.1 500 "logs/selection_compare/residues_TournamentSelection_500.csv" "logs/selection_compare/residues_fittest_TournamentSelection_500.csv"


./main 1000 5000 10 -1 1 -1 -1 0.1 0.1 100 "logs/selection_compare/residues_RandomSelection.csv" "logs/selection_compare/residues_fittest_RandomSelection.csv"
./main 1000 5000 10 -1 2 -1 -1 0.1 0.1 100 "logs/selection_compare/residues_RouletteWheelSelection.csv" "logs/selection_compare/residues_fittest_RouletteWheelSelection.csv"
./main 1000 5000 10 -1 3 -1 -1 0.1 0.1 100 "logs/selection_compare/residues_StochasticUniversalSampling.csv" "logs/selection_compare/residues_fittest_StochasticUniversalSampling.csv"
./main 1000 5000 10 -1 4 -1 -1 0.1 0.1 100 "logs/selection_compare/residues_RankSelection.csv" "logs/selection_compare/residues_fittest_RankSelection.csv"

# Compare Crossover Functions
./main 1000 5000 10 -1 -1 0 -1 0.1 0.1 100 "logs/crossover_compare/residues_UniformCrossover_01.csv" "logs/crossover_compare/residues_fittest_UniformCrossover_01.csv"
./main 1000 5000 10 -1 -1 0 -1 0.25 0.1 100 "logs/crossover_compare/residues_UniformCrossover_025.csv" "logs/crossover_compare/residues_fittest_UniformCrossover_025.csv"
./main 1000 5000 10 -1 -1 0 -1 0.5 0.1 100 "logs/crossover_compare/residues_UniformCrossover_05.csv" "logs/crossover_compare/residues_fittest_UniformCrossover_05.csv"
./main 1000 5000 10 -1 -1 0 -1 1 0.1 100 "logs/crossover_compare/residues_UniformCrossover_1.csv" "logs/crossover_compare/residues_fittest_UniformCrossover_1.csv"

./main 1000 5000 10 -1 -1 1 -1 0.1 0.1 100 "logs/crossover_compare/residues_OnePointCrossover.csv" "logs/crossover_compare/residues_fittest_OnePointCrossover.csv"
./main 1000 5000 10 -1 -1 2 -1 0.1 0.1 100 "logs/crossover_compare/residues_TwoPointCrossover.csv" "logs/crossover_compare/residues_fittest_TwoPointCrossover.csv"

# Compare Mutation Functions
./main 1000 5000 10 -1 -1 -1 0 0.1 0 100 "logs/mutation_compare/residues_NoMutation.csv" "logs/mutation_compare/residues_fittest_NoMutation.csv"

./main 1000 5000 10 -1 -1 -1 0 0.1 0.1 100 "logs/mutation_compare/residues_BitFlipMutation_01.csv" "logs/mutation_compare/residues_fittest_BitFlipMutation_01.csv"
./main 1000 5000 10 -1 -1 -1 0 0.25 0.1 100 "logs/mutation_compare/residues_BitFlipMutation_025.csv" "logs/mutation_compare/residues_fittest_BitFlipMutation_025.csv"
./main 1000 5000 10 -1 -1 -1 0 0.5 0.1 100 "logs/mutation_compare/residues_BitFlipMutation_05.csv" "logs/mutation_compare/residues_fittest_BitFlipMutation_05.csv"
./main 1000 5000 10 -1 -1 -1 0 1 0.1 100 "logs/mutation_compare/residues_BitFlipMutation_1.csv" "logs/mutation_compare/residues_fittest_BitFlipMutation_1.csv"

./main 1000 5000 10 -1 -1 -1 1 0.1 0.1 100 "logs/mutation_compare/residues_Mutation1_01.csv" "logs/mutation_compare/residues_fittest_Mutation1_01.csv"
./main 1000 5000 10 -1 -1 -1 1 0.1 0.25 100 "logs/mutation_compare/residues_Mutation1_025.csv" "logs/mutation_compare/residues_fittest_Mutation1_025.csv"
./main 1000 5000 10 -1 -1 -1 1 0.1 0.5 100 "logs/mutation_compare/residues_Mutation1_05.csv" "logs/mutation_compare/residues_fittest_Mutation1_05.csv"
./main 1000 5000 10 -1 -1 -1 1 0.1 1 100 "logs/mutation_compare/residues_Mutation1_1.csv" "logs/mutation_compare/residues_fittest_Mutation1_1.csv"
