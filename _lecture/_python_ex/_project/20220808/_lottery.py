import random

userNumbers = []
randNumbers = []
correctNumbers = []

def setUserNumbers():
    global userNumbers

    print('1부터 45까지의 정수 6개를 입력하세요.')
    for i in range(1, 7):
        userNumber = input(f'Number {i} : ')
        while (userNumber.isdigit() is False) \
                or (int(userNumber) in userNumbers) \
                or ((1 < int(userNumber)) and (45 < int(userNumber))):
            print('1부터 45까지의 정수 중 하나를 중복되지 않도록 선택하세요.')
            userNumber = input(f'Number {i} : ')
        userNumbers.append(int(userNumber))
    userNumbers.sort()

def getUserNumbers():
    return userNumbers

def setRandNumbers():
    global randNumbers

    randNumbers = random.sample(range(1, 46), 6)
    randNumbers.sort()

def getRandNumbers():
    return randNumbers

def checkNumbers():
    global userNumbers
    global randNumbers
    global correctNumbers

    for n in userNumbers:
        if n in randNumbers:
            correctNumbers.append(n)
    correctNumbers.sort()
    return correctNumbers

if __name__ == '__main__':
    pass
