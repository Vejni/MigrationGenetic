gcc main.c -lm -o main

# Compare Fitness Functions
echo "Comparing Fitness Functions"
./main 1 100 1000 100 0 0 0 0 0.1 0.1 100 "logs/fittness_MaxNorm.csv" "logs/residues_fittest_MaxNorm.csv"
./main 1 100 1000 100 1 0 0 0 0.1 0.1 100 "logs/fittness_WeightedNorm.csv" "logs/residues_fittest_WeightedNorm.csv"

# Compare Selection functions
echo "Comparing Selection Functions"
./main 0 100 1000 10 0 0 0 0 0.1 0.1 100 "logs/selection_compare/fittness_TournamentSelection_100.csv" "logs/selection_compare/residues_fittest_TournamentSelection_100.csv"
./main 0 100 1000 10 0 0 0 0 0.1 0.1 250 "logs/selection_compare/fittness_TournamentSelection_250.csv" "logs/selection_compare/residues_fittest_TournamentSelection_250.csv"
./main 0 100 1000 10 0 0 0 0 0.1 0.1 500 "logs/selection_compare/fittness_TournamentSelection_500.csv" "logs/selection_compare/residues_fittest_TournamentSelection_500.csv"

./main 0 100 1000 10 0 1 0 0 0.1 0.1 100 "logs/selection_compare/fittness_RouletteWheelSelection.csv" "logs/selection_compare/residues_fittest_RouletteWheelSelection.csv"
./main 0 100 1000 10 0 2 0 0 0.1 0.1 100 "logs/selection_compare/fittness_StochasticUniversalSampling.csv" "logs/selection_compare/residues_fittest_StochasticUniversalSampling.csv"
./main 0 100 1000 10 0 3 0 0 0.1 0.1 100 "logs/selection_compare/fittness_RankSelection.csv" "logs/selection_compare/residues_fittest_RankSelection.csv"
./main 0 100 1000 10 0 4 0 0 0.1 0.1 100 "logs/selection_compare/fittness_RandomSelection.csv" "logs/selection_compare/residues_fittest_RandomSelection.csv"

# Compare Crossover Functions
echo "Comparing Crossover Functions"
./main 0 100 1000 10 0 0 0 0 0.1 0.1 100 "logs/crossover_compare/fittness_OnePointCrossover.csv" "logs/crossover_compare/residues_fittest_OnePointCrossover.csv"
./main 0 100 1000 10 0 0 1 0 0.1 0.1 100 "logs/crossover_compare/fittness_TwoPointCrossover.csv" "logs/crossover_compare/residues_fittest_TwoPointCrossover.csv"

./main 0 100 1000 10 0 0 2 0 0.1 0.1 100 "logs/crossover_compare/fittness_UniformCrossover_01.csv" "logs/crossover_compare/residues_fittest_UniformCrossover_01.csv"
./main 0 100 1000 10 0 0 2 0 0.25 0.1 100 "logs/crossover_compare/fittness_UniformCrossover_025.csv" "logs/crossover_compare/residues_fittest_UniformCrossover_025.csv"
./main 0 100 1000 10 0 0 2 0 0.5 0.1 100 "logs/crossover_compare/fittness_UniformCrossover_05.csv" "logs/crossover_compare/residues_fittest_UniformCrossover_05.csv"
./main 0 100 1000 10 0 0 2 0 1 0.1 100 "logs/crossover_compare/fittness_UniformCrossover_1.csv" "logs/crossover_compare/residues_fittest_UniformCrossover_1.csv"

# Compare Mutation Functions
echo "Comparing Mutation Functions"
./main 0 100 1000 10 0 0 0 0 0.1 0 100 "logs/mutation_compare/fittness_NoMutation.csv" "logs/mutation_compare/residues_fittest_NoMutation.csv"

./main 0 100 1000 10 0 0 0 0 0.1 0.1 100 "logs/mutation_compare/fittness_SingleBitFlipMutation_01.csv" "logs/mutation_compare/residues_fittest_SingleBitFlipMutation_01.csv"
./main 0 100 1000 10 0 0 0 0 0.25 0.1 100 "logs/mutation_compare/fittness_SingleBitFlipMutation_025.csv" "logs/mutation_compare/residues_fittest_SingleBitFlipMutation_025.csv"
./main 0 100 1000 10 0 0 0 0 0.5 0.1 100 "logs/mutation_compare/fittness_SingleBitFlipMutation_05.csv" "logs/mutation_compare/residues_fittest_SingleBitFlipMutation_05.csv"
./main 0 100 1000 10 0 0 0 0 1 0.1 100 "logs/mutation_compare/fittness_SingleBitFlipMutation_1.csv" "logs/mutation_compare/residues_fittest_SingleBitFlipMutation_1.csv"

./main 0 100 1000 10 0 0 0 1 0.1 0.1 100 "logs/mutation_compare/fittness_BitSwapMutation.csv" "logs/mutation_compare/residues_fittest_BitSwapMutation.csv"

./main 0 100 1000 10 0 0 0 2 0.1 0.1 100 "logs/mutation_compare/fittness_BitFlipMutation_01.csv" "logs/mutation_compare/residues_fittest_BitFlipMutation_01.csv"
./main 0 100 1000 10 0 0 0 2 0.25 0.1 100 "logs/mutation_compare/fittness_BitFlipMutation_025.csv" "logs/mutation_compare/residues_fittest_BitFlipMutation_025.csv"
./main 0 100 1000 10 0 0 0 2 0.5 0.1 100 "logs/mutation_compare/fittness_BitFlipMutation_05.csv" "logs/mutation_compare/residues_fittest_BitFlipMutation_05.csv"
./main 0 100 1000 10 0 0 0 2 1 0.1 100 "logs/mutation_compare/fittness_BitFlipMutation_1.csv" "logs/mutation_compare/residues_fittest_BitFlipMutation_1.csv"

./main 0 100 1000 10 0 0 0 3 0.1 0.1 100 "logs/mutation_compare/fittness_RandomResetMutation.csv" "logs/mutation_compare/residues_fittest_RandomResetMutation.csv"
