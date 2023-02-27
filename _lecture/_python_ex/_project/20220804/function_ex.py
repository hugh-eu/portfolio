### 함수, 코드의 모듈화, 재활용, 반복사용, 코드 수정 용이
## 간단해도 되고 복잡해도 됨, 필요에 의해 만들어 쓰거나, 가져다씀,
## 내장함수(기본 제공 함수), 사용자 함수(필요에 의해 개발자가 만든 함수)로 나누어짐, 혼합가능
# def greet():
#     print('안녕하세요.')
#     print('반갑습니다.')
# greet()

# 손님이 매장에 들어오면 '안녕하세요' 라는 문자열을 출력한다
# def sayHello():
#     print('안녕하세요')
# 
# while True:
#     visitor = int(input('1. 들어옴 ') )
#     if visitor == 1:
#         sayHello()
#     visitor = 0

## 함수명을 작명하는 일반적인 방법
# 사용자 함수명이 내장함수명과 일치하면 안됨
# 첫글자는 소문자가 관례, 두단어 이상인 경우 카멜, 스네이크
# 함수명의 첫글자로 안되는 것, 숫자, _를 제외한 특수문자
# convertUnit(), sendMessage(), calculateDistance()  # 함수명은 동사로 시작하는것이 관례

# def startTemperatureSensor():
#     print('온도센서 시작')
# def stopTemperatureSensor():
#     print('온도센서 정지')
# startTemperatureSensor()
# stopTemperatureSensor()

# def convertCmToInch(cm):
#     inch = cm * 0.39
#     return inch
#
# lengthCm = float(input('길이(cm)를 입력하세요 : '))
# print(f'{lengthCm}cm는 {round(convertCmToInch(lengthCm), 2)}inch입니다.')

# def calculateDistance(climbingHour, climbingVelocity):
#     climbingDistance = climbingHour * climbingVelocity
#     return climbingDistance
#
# climbingHour = float(input('등산 시간 : '))
# climbingVelocity = float(input('등산 속도 : '))
# print(f'이동 거리 : {round(calculateDistance(climbingHour, climbingVelocity), 2)}km')

## 함수내에서 또다른 함수 호출
# def fun1():
#     print('fun1() called')
#
# def fun2():
#     print('fun2() called')
#
# def fun3():
#     fun1()
#     fun2()
#     print('fun3() called')
#
# fun3()

## 출신국가 선택, 국가의 인사말 출력
# def sayHello():
#     if numInput == '1':
#         print('안녕하세요')
#     elif numInput == '2':
#         print('Hello')
#     elif numInput == '3':
#         print('こんにちは')
#     else:
#         print('Сайн уу')
#
# numInput = input('where are you from? 1. 한국, 2. USA, 3. Japan ')
# sayHello()

# def sayKor():
#     print('안녕')
#
# def sayEng():
#     print('hi')
#
# def sayJpn():
#     print('こんにちは')
#
# def greet():
#     numInput = input('where are you from? 1. 한국, 2. USA, 3. Japan ')
#     if numInput == '1':
#         sayKor()
#     elif numInput == '2':
#         sayEng()
#     elif numInput == '3':
#         sayJpn()
#     else:
#         sayEng()
#
# greet()

## 사용자가 숫자 두개 연산자선택 연산결과 출력
# def doAddtion():
#     print(f'덧셈 결과 : {num1 + num2}')
#
# def doSubtraction():
#     print(f'뺄셈 결과 : {num1 - num2}')
#
# def doMultiplication():
#     print(f'곱셈 결과 : {num1 * num2}')
#
# def doDivision():
#     print(f'나눗셈 결과 : {num1 / num2}')
#
# def divergeOperation():
#     if operator == '1':
#         doAddtion()
#     elif operator == '2':
#         doSubtraction()
#     elif operator == '3':
#         doMultiplication()
#     else:
#         doDivision()
#
# num1 = input('정수를 입력하세요. ')
# while num1.isdigit() is False:
#     print('정수만 입력하세요.')
#     num1 = input('정수를 입력하세요. ')
# num1 = int(num1)
# operator = input('연산자를 입력하세요. 1. 덧셈, 2. 뺄셈, 3. 곱셈, 4. 나눗셈 ')
# while (operator != '1') and (operator != '2') and (operator != '3') and (operator != '4'):
#     print('1부터 4까지의 정수로 선택하세요')
#     operator = input('연산자를 입력하세요. 1. 덧셈, 2. 뺄셈, 3. 곱셈, 4. 나눗셈 ')
# num2 = input('정수를 입력하세요. ')
# while num2.isdigit() is False:
#     print('정수만 입력하세요.')
#     num2 = input('정수를 입력하세요. ')
# num2 = int(num2)
# divergeOperation()

# def judgeInt():
#     if numInput % 2 == 0:
#         print('입력한 정수는 짝수 입니다.')
#     else:
#         print('입력한 정수는 홀수 입니다.')
#
# numInput = int(input('정수를 입력하세요. '))
# judgeInt()

## 슈퍼마켓의 상품가격표, 영수증 출력하는 함수. 구매개수 사용자 입력, 받은돈 거스름돈
# def calcPrice(allPrices, product):
#     price = allPrices[product][0] * allPrices[product][1]
#     return price
#
# def calcTotalPrice(priceSwk, priceBbb, priceCcp, priceMds):
#     totalPrice = priceSwk + priceBbb + priceCcp + priceMds
#     return totalPrice
#
# def calcChange(moneyReceived, totalPrice):
#     change = moneyReceived - totalPrice
#     return change
#
# allPrices = {'swk':[1200], 'bbb':[400], 'ccp':[500], 'mds':[1500]}
# allPrices['swk'].append(int(input('새우깡 구매 개수 : ')))
# allPrices['bbb'].append(int(input('비비빅 구매 개수 : ')))
# allPrices['ccp'].append(int(input('초코파이 구매 개수 : ')))
# allPrices['mds'].append(int(input('맛동산 구매 개수 : ')))
# priceSwk = calcPrice(allPrices, 'swk')
# priceBbb = calcPrice(allPrices, 'bbb')
# priceCcp = calcPrice(allPrices, 'ccp')
# priceMds = calcPrice(allPrices, 'mds')
# totalPrice = calcTotalPrice(priceSwk,priceBbb, priceCcp, priceMds)
# print(f'''\
# =========================================
# 새우깡 구매 금액   : {format(priceSwk, ',')} 원
# 비비빅 구매 금액   : {format(priceBbb, ',')} 원
# 초코파이 구매 금액 : {format(priceCcp, ',')} 원
# 맛동산 구매 금액   : {format(priceMds, ',')} 원
# =========================================
# 총 구매 금액      : {format(totalPrice, ',')}
# =========================================''')
# moneyReceived = int(input('받은 돈 : '))
# change = calcChange(moneyReceived, totalPrice)
# print(f'거스름 돈 : {change} 원')
# print(f'만원 : {change // 10000}장, '
#       f'오천원 : {(change % 10000) // 5000}장, '
#       f'천원 : {((change % 10000) % 5000) // 1000}장, '
#       f'오백원 : {(((change % 10000) % 5000) % 1000) // 500}개, '
#       f'백원 : {((((change % 10000) % 5000) % 1000) % 500) // 100}개, '
#       f'십원 : {(((((change % 10000) % 5000) % 1000) % 500) % 100) // 10}개')


### 변수, 지역변수(local variable), 전역변수(global variable), 선언시 이름 다르게 하는게 쉽다, 매개변수
# num = 10
# def fun1():
#     num = 20
#     print(f'inner {num}')
# print(f'outter1 {num}')
# fun1()
# print(f'outter2 {num}')

# num = 10
# def fun1():
#     global num  # 전역 선언
#     num = 20
#     print(f'inner {num}')
# print(f'outter1 {num}')
# fun1()
# print(f'outter2 {num}')

## 웹사이트 방문 여부 입력받아 웹사이트 누적 방문 횟수 출력
# flag = True
# totalVisitor = 0
#
# def countVisitor():
#     global totalVisitor
#     totalVisitor += 1
#
# while flag:
#     inputData = int(input('1. 웹사이트 방문\t2. 종료'))
#     if inputData == 1:
#         countVisitor()
#         print(f'누적 방문자 수 : {totalVisitor}')
#     else:
#         flag = False

## 매개변수, 인수와 매개변수의 수는 같아야 함
# def printInsa(word):  # 매개변수
#     print(f'{word}')
# printInsa('Hello')  # 인수

# def forecastWeather(h, l, r):
#     print('날씨예보 입니다.')
#     print(f'최고 온도 : {h}')
#     print(f'최저 온도 : {l}')
#     print(f'비올 확률 : {r}')
# forecastWeather(36, 25, 20)

## 인수의 개수를 알수 없는 경우
# 시험 점수 출력(시험 과목 3 -> 4 -> 5 > 2 등으로 변하는 상황)
# def printAverageScore(a, b, *scores):  # 혼합가능, 가변매개변수는 맨 마지막
#     totalScore = sum(scores)
#     averageScore = totalScore / len(scores)
#     print(f'totalScore : {totalScore}')
#     print(f'averageScore : {round(averageScore, 2)}')
#     print(f'highestScore : {max(scores)}')
#     print(f'lowestScore : {min(scores)}')
#
# printAverageScore(80, 90, 70, 100)
# printAverageScore(80, 90, 70, 100, 85)
# printAverageScore(80, 90)
# printAverageScore(80, 90, 60)
# printAverageScore(80, 90, 80)

## 문자 100자 이하 sms 50원, 초과 mms 100원, 구별해서 돈부과
# def checkMessage(msg):
#     if len(msg) > 100:
#         print('mms로 전송됩니다. 100원이 부과됩니다.')
#     else:
#         print('sms로 전송됩니다. 50원이 부과됩니다.')
#
# checkMessage(input('메시지를 입력하세요.\n'))

## 인수와 매개변수의 순서가 일치하지 않는 경우, 매개변수 이름 지정
# def printMemberInfo(name, mail, major, grade):
#     print(f'name: {name}\nmail: {mail}\nmajor: {major}\ngrade: {grade}')
#
# printMemberInfo(mail='g@g.com', grade=3, name='홍길동', major='computer')

## 매개변수의 기본값 설정
# def setSalary(name, pay=9000000):
#     print(f'{name}의 급여는 {pay}원입니다.')
#
# setSalary('윤건', 10000000)
# setSalary('영빈', 11000000)
# setSalary('근태')

### 함수 데이터 반환(return)
# def addFunction(n1, n2):
#     sum = n1 + n2
#     return sum
#
# result = addFunction(10, 2)
# print(result)

## 함수 실행을 중지 시킬때 return
# def increaseStart():
#     print('*')
#     print('**')
#     print('***')
#     return
#     print('****')
#     print('*****')
#     print('******')
#
# result = increaseStart()
# print(result)

## 두개의 정수를 입력받아 사칙연산을 하는 함수를 만들고 그 결과를 반환하는 프로그램을 만들
# def calcurator(num1, num2):
#     result1 = num1 + num2
#     result2 = num1 - num2
#     result3 = num1 * num2
#     result4 = num1 / num2
#     return (result1, result2, result3, result4)
#
# inputData1 = int(input('정수를 입력하세요.'))
# inputData2 = int(input('정수를 입력하세요.'))
#
# result = calcurator(inputData1, inputData2)
# print(f'사칙연산 결과 : {result}')

### 중첩 함수
# def divFunction(n1, n2):
#     def divOperator(num1, num2):
#         return num1 / num2
#     if n2 != 0:
#         result = divOperator(n1, n2)
#     elif n2 == 0:
#         result = '0으로 나눌 수 없습니다.'
#     return result
# endResult = divFunction(10, 0)
# print(endResult)

### 재귀함수 : 함수안에서 같은 함수를 다시 호출
## 어떤 정수에서 0까지 출력하는 함수
# def recursionfun(num):
#     if num >= 0:
#         print(num)
#         recursionfun(num - 1)
# recursionfun(10)

## 사용자가 입력한 정수를 이용해서 팩토리얼 계산을 실행하는 프로그램, 재귀함수 이용
# def calculateFactorial(num):
#     if num == 0:
#         return 1
#     else:
#         return num * calculateFactorial(num - 1)
#
# num = int(input('팩토리얼을 계산할 정수 : '))
# result = calculateFactorial(num)
# print(f'{num}! = {result}')

# f = 1
# def calculateFactorial(num):
#     global f
#     if num >= 1:
#         f *= num
#         calculateFactorial(num - 1)
#
# num = int(input('팩토리얼을 계산할 정수 : '))
# calculateFactorial(num)
# print(f'{num}! = {f}')

## 하노이탑
# startPole = 'A탑'
# endPole = 'B탑'
# assistantPole = 'C탑'
# def runHanoiTop(plate, s, e, a):
#     if plate == 1:
#         print(f'{s} -> {e}')
#     elif plate >= 2:
#         runHanoiTop(plate - 1, s, a, e)
#         print(f'{s} -> {e}')
#         runHanoiTop(plate - 1, a, e, s)
# plate = int(input('원판의 개수 : '))
# runHanoiTop(plate, startPole, endPole, assistantPole)
# print(f'이동 횟수는 {2**plate-1}회입니다.')

## 피보나치, 딕셔너리를 사용한 메모화, 처리 속도 개선
# import time
#
# def fibonacci(n):
#     if n == 1:
#         return 1
#     if n == 2:
#         return 1
#     else:
#         return fibonacci(n - 1) + fibonacci(n - 2)
#
# n = int(input('피보나치 구할 수 : '))
# startT = time.time()
# print(f'fibonacci({n}) : {fibonacci(n)}')
# print(time.time() - startT)

# import time
#
# dictionary = {1:1, 2:1}
#
# def fibonacci(n):
#     if n in dictionary:
#         return dictionary[n]
#     else:
#         output = fibonacci(n - 1) + fibonacci(n - 2)
#         dictionary[n] = output
#         return output
# n = int(input('피보나치 구할 수 : '))
# startT = time.time()
# print(f'fibonacci({n}) : {fibonacci(n)}')
# print(time.time() - startT)
