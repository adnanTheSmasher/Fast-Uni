import random

POP_SIZE = 6
CHROM_LENGTH = 5
GENERATIONS = 15
MUTATION_RATE = 0.1


def fitness(x):
    return x*x + 2*x


def binary_to_decimal(chrom):
    return int(chrom, 2)


def create_population():
    population = []
    for _ in range(POP_SIZE):
        chrom = ''.join(random.choice('01') for _ in range(CHROM_LENGTH))
        population.append(chrom)
    return population


def selection(population):
    population = sorted(population,
                        key=lambda c: fitness(binary_to_decimal(c)),
                        reverse=True)
    return population[:2]


def crossover(parent1, parent2):
    point = random.randint(1, CHROM_LENGTH-1)
    child1 = parent1[:point] + parent2[point:]
    child2 = parent2[:point] + parent1[point:]
    return child1, child2


def mutation(chrom):
    chrom = list(chrom)
    for i in range(len(chrom)):
        if random.random() < MUTATION_RATE:
            chrom[i] = '1' if chrom[i] == '0' else '0'
    return ''.join(chrom)


def genetic_algorithm():

    population = create_population()

    for gen in range(GENERATIONS):

        parents = selection(population)

        new_population = parents.copy()

        while len(new_population) < POP_SIZE:
            child1, child2 = crossover(parents[0], parents[1])
            child1 = mutation(child1)
            child2 = mutation(child2)

            new_population.append(child1)
            if len(new_population) < POP_SIZE:
                new_population.append(child2)

        population = new_population

    best = max(population, key=lambda c: fitness(binary_to_decimal(c)))
    best_x = binary_to_decimal(best)
    best_fit = fitness(best_x)

    print("="*45)
    print("GENETIC ALGORITHM RESULT")
    print("="*45)
    print("Best Chromosome :", best)
    print("Best x value    :", best_x)
    print("Best Fitness    :", best_fit)
    print("="*45)


genetic_algorithm()