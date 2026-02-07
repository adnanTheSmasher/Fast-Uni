class Environment:
    def __init__(self):
        self.grid = [
            "Safe", "Safe", "🔥",
            "Safe", "🔥", "Safe",
            "Safe", "Safe", "🔥",
        ]

    def get_percept(self, pos):
        return self.grid[pos]

    def extinguish_fire(self, pos):
        self.grid[pos] = "Safe"

    def display_grid(self, agentPos):
        print("\nCurrent Grid State")
        gridWithAgent = self.grid[:]
        gridWithAgent[agentPos] = "👩‍🚒"
        for i in range(0, 9, 3):
            print(" | ".join(gridWithAgent[i:i + 3]))
        print()

class SimpleReflexAgent:
    def __init__(self, env):
        self.env = env
        self.pos = 0

    def act(self):
        percept = self.env.get_percept(self.pos)
        if percept == "🔥":
            self.env.extinguish_fire(self.pos)
            return "Room Was on Fire But Now Safe"
        else:
            return "Room is Already Safe"

    def move(self):
        self.pos += 1

class Environment:
    def __init__(self):
        self.grid = [
            "Safe", "Safe", "🔥",
            "Safe", "🔥", "Safe",
            "Safe", "Safe", "🔥",
        ]

    def get_percept(self, pos):
        return self.grid[pos]

    def extinguish_fire(self, pos):
        self.grid[pos] = "Safe"

    def display_grid(self, agentPos):
        print("\nCurrent Grid State")
        gridWithAgent = self.grid[:]
        gridWithAgent[agentPos] = "👩‍🚒"
        for i in range(0, 9, 3):
            print(" | ".join(gridWithAgent[i:i + 3]))
        print()

class SimpleReflexAgent:
    def __init__(self, env):
        self.env = env
        self.pos = 0

    def act(self):
        percept = self.env.get_percept(self.pos)
        if percept == "🔥":
            self.env.extinguish_fire(self.pos)
            return "Room Was on Fire But Now Safe"
        else:
            return "Room is Already Safe"

    def move(self):
        self.pos += 1

def run_agent(agent, environment):
    for step in range(9):
        percept = environment.get_percept(agent.pos)
        action = agent.act()

        print(f"Step {step + 1}: Position {agent.pos} -> Percept - {percept}, Action - {action}")
        environment.display_grid(agent.pos)

        agent.move()

    print("Final Grid Status (All Fires Extinguished):")
    environment.display_grid(agent.pos - 1)


env = Environment()
agent = SimpleReflexAgent(env)
run_agent(agent, env)

env = Environment()
agent = SimpleReflexAgent(env)
run_agent(agent, env)