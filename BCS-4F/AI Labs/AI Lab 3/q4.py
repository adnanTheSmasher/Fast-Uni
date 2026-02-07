class Environment:
    def __init__(self, restaurant=None):
        if restaurant is None:
            self.restaurant = {"A": [3, 7], "B": [5, 9]}
        else:
            self.restaurant = restaurant

    def get_percept(self):
        return self.restaurant

class UtilityBasedAgent:
    def __init__(self):
        pass

    def utility(self, distance, rating):
        return rating - distance

    def act(self, percept):
        best_restaurant = None
        best_utility = float("inf")

        for key, value  in percept.items():
            rest_utility = self.utility(value[0], value[1])
            print(f"Restaurant {key} Utility = {rest_utility}")
            if rest_utility < best_utility:
                best_utility = rest_utility
                best_restaurant = key

        return best_restaurant

def run_agent(agent, environment):
    percept = environment.get_percept()
    action = agent.act(percept)

    print(f"Selected Restaurant: {action}")

env = Environment()
agent = UtilityBasedAgent()
run_agent(agent, env)