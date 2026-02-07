import random

class Environment:
    def __init__(self, state = "Rest"):
        self.state = state

    def get_percept(self):
        return self.state

    def go_Play(self):
        self.state = "Play"
        return 5

    def go_Rest(self):
        self.state = "Rest"
        return 1


class LearningBasedAgent:
    def __init__(self, action):
        self.Q = {}
        self.action = action
        self.alpha = 0.1
        self.gamma = 0.9
        self.epsilon = 0.1

    def get_Q_value(self, state, action):
        return self.Q.get((state, action), 0.0)

    def select_action(self, state):
        if random.uniform(0, 1) < self.epsilon:
            return random.choice(self.action)
        else:
            return max(self.action, key = lambda a:self.get_Q_value(state, a))

    def learn(self, state, action, reward, next_state):
        old_Q = self.get_Q_value(state, action)
        best_future_Q = max([self.get_Q_value(next_state, a) for a in self.action])
        self.Q[(state, action)] = old_Q + self.alpha * (reward + self.gamma * best_future_Q - old_Q)

    def act(self, state):
        action = self.select_action(state)
        return action


def run_agent(agent, env, steps):
    for step in range(steps):
        percept = env.get_percept()
        action = agent.act(percept)
        reward = 0
        if action == "Rest":
            reward += env.go_Rest()
            print(f"Steps: {step + 1}, Percept: {percept}, Action: {action}, Reward: {reward}")
        else:
            reward += env.go_Play()
            print(f"Steps: {step + 1}, Percept: {percept}, Action: {action}, Reward: {reward}")

        next_percept = env.get_percept()
        agent.learn(percept, action, reward, next_percept)


env = Environment()
agent = LearningBasedAgent(['Play', 'Rest'])

run_agent(agent, env, 10)