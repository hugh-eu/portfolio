from random import randint

engQuiz = []

def presentQuiz():
    quiz = getEngQuiz()
    print(f'영어 : {quiz[0]}')
    userInput = input('한글을 입력하세요.(종료시 "종료" 입력) ')
    if userInput != '종료':
        if isCorrectOrWrong(engQuiz, userInput):
            print("정답입니다!!")
        else:
            print("틀렸습니다!!")
            print(f'정답 : {engQuiz[1]}')
    return userInput

def setEngQuiz(quizzes):
    global engQuiz

    if type(quizzes) is not dict:
        print('딕셔너리 자료를 사용해야 합니다.')
        print('게임이 종료됩니다.')
        return False

    randKey = randint(0, len(quizzes) - 1)
    engQuiz = quizzes[randKey]
    return True

def getEngQuiz():
    return engQuiz

def isCorrectOrWrong(quiz, answer):
    if quiz[1] == answer:
        return True
    else:
        return False

if __name__ == '__main__':
    pass
