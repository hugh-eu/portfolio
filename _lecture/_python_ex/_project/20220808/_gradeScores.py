totalScore = 0
averageScore = 0

def setTotalScore(scores):
    global totalScore

    totalScore = sum(scores)

def getTotalScore():
    return totalScore

def setAverageScore(scores):
    global averageScore

    averageScore = getTotalScore() / len(scores)

def getAverageScore():
    return averageScore

def isPassOrFail(scores):
    for i in scores:
        if i < 40:
            return False
    if getAverageScore() < 60:
        return False
    return True
