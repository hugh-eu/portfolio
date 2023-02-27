### 모듈 (module)
## 프로그램 개발시간 단축
## 이미 검증되어 오류가 적음
## 팀원들이 기능구현을 분업화하고 공유할 수 있어 전체적인 작업속도 향상 가능

# import random
#
# print(random.randint(1, 100))

## 필요없는 것 빼고 import, 메모리 절약
# # import _calculator
# # from _calculator import *  # _calculator 안쓰기위해
# from _calculator import addition, subtraction
# 
# addition(10, 20)
# subtraction(10, 20)
# multiplication(10, 20)  # 에러
# # _calculator.division(10, 20)
# # _calculator.rest(10, 20)
# # _calculator.portion(10, 20)

# import _convertUnitModule
#
# inputData = int(input('길이(mm)를 입력하세요. '))
# result = _convertUnitModule.convertUnit(inputData)
# _convertUnitModule.printLength(inputData, result)

## 사용자 3과목 시험점수, 총점 평점, 통과 여부 출력 모듈, 평균 60이상, 각과목 40이상 pass 아니면 fail, 약어사용
# import _gradeScores as gs
#
# inputScores = []
# for i in range(3):
#     i += 1
#     inputScores.append(int(input(f'score{i} 입력 : ')))
#
# gs.setTotalScore(inputScores)
# gs.setAverageScore(inputScores)
# totalScore = gs.getTotalScore()
# aveScore = gs.getAverageScore()
# result = gs.isPassOrFail(inputScores)
# print(f'총점 : {totalScore}, 평균 : {round(aveScore, 2)}, 합격여부 : {"Pass" if result else "Fail"}')

## 할인율 적용 프로그램, 상품 많이 구입할수록 많이 할인, 1개 5, 2개 10프로, 3개 20프로, 4개 30프로
# import _getTotal as gt
#
# def app():
#     flag = True
#     goodPrices = []
#
#     while flag:
#         purchase = int(input('상품을 구매 하시겠어요? 1. 구매 2. 종료 '))
#         if purchase == 1:
#             price = int(input('구매한 상품의 금액을 입력하세요. '))
#             goodPrices.append(price)
#         elif purchase == 2:
#             flag = False
#
#     print(f'할인율 : {gt.calcTotalPrice(goodPrices)[1]} %, 총 금액 : {int(gt.calcTotalPrice(goodPrices)[0])} 원')
#
# if __name__ == '__main__':
#     app()

### if __name__ == '__main__': 을 통해 실행구문 메인 일경우만 실행하게 만듬, 모듈화

### 모듈의 패키지화, 폴더안에 __init__.py 파일 만들기, 안만들어도 됨

### site-packages 폴더, pip를 통한 모듈설치 폴더, 개인적인 패키지 파일 생성 가능 
# from myPackages import myCalculator
#
# print(myCalculator.add(1, 2))
# print(myCalculator.sub(1, 2))

### math 모듈
# import math
#
# print(f'{math.fabs(-3.14)}')  # 절대값
# print(f'{math.ceil(-3.14)}')  # 올림
# print(f'{math.floor(-3.14)}')  # 내림
# print(f'{math.trunc(-3.14)}')  # 버림
# print(f'{math.gcd(9, 21)}')  # 최대공약수
# print(f'{math.factorial(3)}')  # 팩토리얼
# print(f'{math.sqrt(9)}')  # 제곱근

## 수학과 관련된 파이썬 함수
# sum()  # 전체합
# max()  # 최대값
# min()  # 최소값
# abs()  # 절대값
# pow()  # 거듭제곱
# round()  # 반올림

### random
# import random
#
# num = random.randint(1, 100)  # 1이상 100이하 정수 난수
# print(num)
# num = random.randrange(1, 101, 3)  # 1이상 101미만 정수 난수
# print(num)
# num = random.random()  # 0이상 1미만 실수 난수
# print(num)
# num = random.uniform(1, 100)  # 실수
# print(num)
# num = random.choice([1, 2, 3, 4, 5, 6])  # 무작위 한개 뽑기
# print(num)
# num = random.sample([1, 2, 3, 4, 5, 6], 3)  # 3개 뽑기
# print(num)
# item = [1, 2, 3, 4, 5, 6]
# item = random.shuffle([1, 2, 3, 4, 5, 6])  # 무작위로 섞기
# print(item)

### time
# import time

# time.localtime()  # 현재 시스템 시간
# print(time.gmtime())  # UTC
# time.strftime()  # 표현 형식

# wds = ['월', '화', '수', '목', '금', '토', '일']

# now = time.localtime()
# print(now)
# print(f'연 : {now.tm_year}')
# print(f'월 : {now.tm_mon}')
# print(f'일 : {now.tm_mday}')
# print(f'시 : {now.tm_hour}')
# print(f'분 : {now.tm_min}')
# print(f'초 : {now.tm_sec}')
# print(f'요일 : {wds[now.tm_wday]}')

# gmtNow = time.gmtime()
# print(gmtNow)
# print(f'연 : {gmtNow.tm_year}')
# print(f'월 : {gmtNow.tm_mon}')
# print(f'일 : {gmtNow.tm_mday}')
# print(f'시 : {gmtNow.tm_hour}')
# print(f'분 : {gmtNow.tm_min}')
# print(f'초 : {gmtNow.tm_sec}')
# print(f'요일 : {wds[gmtNow.tm_wday]}')

# print(time.strftime('%Y-%m-%d %p%I:%M:%S(%H:%M:%S)', time.localtime()))

### 로또 프로그램
# import _lottery as lt
#
# def app():
#     lt.setUserNumbers()
#     myNums = lt.getUserNumbers()
#     lt.setRandNumbers()
#     randNums = lt.getRandNumbers()
#     result = lt.checkNumbers()
#     print(f'이번주 로또 번호 : {randNums}')
#     print(f'내가 선택한 번호 : {myNums}')
#     print(f'일치하는 숫자 : {result if len(result) > 0 else "없음"}')
#
# if __name__ == '__main__':
#     app()

# from urllib import request
#
# target = request.urlopen('https://google.com')
# output = target.read()
#
# print(output)

### 단어장에서 무작위로 출력되는 영단어 맞추는 게임
# import _engQuiz as eq
#
# questions = {0: ['Football', '축구'],
#                  1: ['Pencil', '연필'],
#                  2: ['Eraser', '지우개'],
#                  3: ['Car', '차'],
#                  4: ['Doll', '인형'],
#                  5: ['Clock', '시계'], }
#
# def app():
#     availableQuiz = eq.setEngQuiz(questions)
#     if availableQuiz:
#         userInput = eq.presentQuiz()
#         return userInput
#     else:
#         return availableQuiz
#
# if __name__ == '__main__':
#     while True:
#         chkQuit = app()
#         if chkQuit == '종료' or chkQuit is False:
#             break
#         print()
