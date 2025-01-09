import random

N = 8
POP_SIZE = 100
GEN_SIZE = 1000
MUT_RATE = 0.05

class Individual:
    def __init__(self):
        self.board = list(range(N))
        random.shuffle(self.board)
        self.fitness = self.calculate_fitness()
    
    def calculate_fitness(self):
        fitness = 0
        for i in range(N):
            for j in range(i+1,N):
                if self.board[i]!=self.board[j] and abs(self.board[j]-self.board[i])!=(j-i):
                    fitness += 1
        return fitness

def selection(population:list):
    best = random.choice(population)

    for _ in range(3):
        opponent = random.choice(population)
        if opponent.fitness > best.fitness:
            best = opponent
    return best

def crossover(parent1:Individual, parent2:Individual):
    start = random.randint(0, N-1)
    end = random.randint(start, N-1)

    child_board = [-1]*N
    child_board[start:end] = parent1.board[start:end]

    remaining_values = []
    for i in parent2.board:
        if i not in child_board:
            remaining_values.append(i)

    for i in range(N):
        if child_board[i] == -1:
            child_board[i] = remaining_values.pop(0)
    
    child = Individual()
    child.board = child_board
    child.fitness = child.calculate_fitness()
    return child

def mutation(child:Individual):
    if random.random() < MUT_RATE:
        pos1, pos2 = random.sample(range(N), 2)
        child.board[pos1], child.board[pos2] = child.board[pos2], child.board[pos1]
        child.fitness = child.calculate_fitness()

def genetic_algorithm():
    population = [Individual() for _ in range(POP_SIZE)]

    for generation in range(GEN_SIZE):
        population.sort(key = lambda ind:ind.fitness, reverse=True)

        if population[0].fitness == 28:
            print(f"Solution found in generation {generation} :\n")
            for row in range(N):
                line = ""
                for col in range(N):
                    if population[0].board[col] == row:
                        line+="Q "
                    else:
                        line+=". "
                print(line)
            return
        
        new_pop = []
        for _ in range(POP_SIZE):
            parent1 = selection(population)
            parent2 = selection(population)
            child = crossover(parent1, parent2)
            mutation(child)
            new_pop.append(child)
        
        population = new_pop

    print("No solution found")

if __name__ == "__main__":
    for _ in range(1000000000):
        genetic_algorithm()