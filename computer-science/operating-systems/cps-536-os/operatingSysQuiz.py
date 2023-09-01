from collections import OrderedDict


# OS Quiz

class Question():
    def __init__(self, shortIdentifier, question, answer):
        self.ID = shortIdentifier
        self.q = question
        self.a = answer
        self.score = 0
        # Pandas - read a dataframe from the .csv!

    def __repr__(self):
        return "{}\nQuestion: {}\nAnswer: {}\nCurrent score: \n".format(self.ID, self.q, self.a, self.score)




if __name__ == "__main__":
    pass
