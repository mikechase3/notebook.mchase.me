from collections import OrderedDict


# OS Quiz

class Quiz():
    def __init__(self, qa: dict):
        self.qa = qa
        self.score = 0

    def __repr__(self):
        return "Questions, Answers\n======\n\n {}".format(str(self.qa))

    def play(self):
        # Receive input from user. Prompt with question. Check the answer with some string formatting methods.
        pass

qa = {  # question, answer
    "", ""
}



if __name__ == "__main__":
    q = Quiz(qa)
    q.play()
