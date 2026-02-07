class Environment:
    def __init__(self, planner):
        self.planner = planner

    def get_percept(self):
        return self.planner


class StudentStudyPlannerGoalAgent:
    def __init__(self):
        self.goal = "All subjects completed"

    def formulate_goal(self, percept):
        if percept["AI"] == "NO":
            self.goal = "AI"
        elif percept["MATH"] == "NO":
            self.goal = "MATH"
        elif percept["PHYSICS"] == "NO":
            self.goal = "PHYSICS"
        else:
            self.goal = "All subjects completed"

    def study_AI(self):
        return "Studying AI"

    def study_MATH(self):
        return "Studying Maths"

    def study_PHYSICS(self):
        return "Studying Physics"

    def update_AI(self, percept):
        percept["AI"] = "YES"

    def update_MATH(self, percept):
        percept["MATH"] = "YES"

    def update_PHYSICS(self, percept):
        percept["PHYSICS"] = "YES"

    def act(self, percept):
        self.formulate_goal(percept)
        if self.goal == "AI":
            print(self.study_AI())
            self.update_AI(percept)
        elif self.goal == "MATH":
            print(self.study_MATH())
            self.update_MATH(percept)
        elif self.goal == "PHYSICS":
            print(self.study_PHYSICS())
            self.update_PHYSICS(percept)


def run_Agent(agent, env):
    while True:
        percept = env.get_percept()
        action = agent.act(percept)

        if agent.goal == "All subjects completed":
            print("Goal Achieved: All subjects completed")
            break


PLANNER = {"AI": "NO", "MATH": "NO", "PHYSICS": "NO"}
env = Environment(PLANNER)
agent = StudentStudyPlannerGoalAgent()
run_Agent(agent, env)

