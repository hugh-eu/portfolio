import random

class Dice:
    def __init__(self, n):
        self.nd = n
        self.diceNums = []

    def rollDice(self, c):
        self.diceNums = []
        while len(self.diceNums) < c:
            self.diceNums.append(random.randint(1, self.nd))

    def getDiceNums(self):
        return self.diceNums

class PlayDiceGame:
    def __init__(self, nd, np, nt):
        self.numDice = nd
        self.numPlayers = np
        self.numThrows = nt
        self.finalResults = {}
        self.sumFinalResults = {}
        self.sortedKeys = []

    def rollDice(self):
        dice = Dice(self.numDice)
        for i in range(1, self.numPlayers + 1):
            dice.rollDice(self.numThrows)
            self.finalResults[i] = dice.getDiceNums()

    def setSum(self):
        for key in self.finalResults:
            self.sumFinalResults[key] = sum(self.finalResults[key])

    def getSum(self):
        return self.sumFinalResults

    def printResult(self):
        for key in self.finalResults:
            print(f'Gamer{key} : {self.finalResults[key]}')
            print(f'Sum of Gamer{key} : {sum(self.finalResults[key])}')
            print("-" * 30)
        self.setSum()
        self.sortedKeys = sorted(self.sumFinalResults, key=self.sumFinalResults.get, reverse=True)
        print('=' * 30)
        i = 1
        for key in self.sortedKeys:
            print(f'{i}등 : Gamer{key}({self.sumFinalResults[key]}점)\tWIN!!' if i == 1 else f'{i}등 : Gamer{key}({self.sumFinalResults[key]}점)')
            i += 1
        print('=' * 30)
