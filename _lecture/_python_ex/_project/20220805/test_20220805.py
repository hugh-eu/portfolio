# sum = 0
# for i in range(1, 21):
#     sum += i
# print(sum)

# listInt = []
# for i in range(1, 101):
#     if (i % 3 == 0) and (i % 7 == 0):
#         listInt.append(i)
# print(f'3과 7의 공배수 {listInt}')
# print(f'3과 7의 최소공배수 {min(listInt)}')

# inputNum = int(input('정수를 입력하세요 : '))
# for i in range(1, 10):
#     print(f'{inputNum} X {i} = {inputNum * i}')

# for i in range(11):
#     if i % 2 == 0:
#         print(i, end=' ')

# for i in range(1, 50):
#     if i % 7 == 0:
#         print(i, end=' ')

# i = 1
# while i < 6:
#     print(i)
#     i += 1

# i = 1
# while i < 31:
#     if i % 2 == 1:
#         print(i, '홀수')
#     else:
#         print(i, '짝수')
#     i += 1

# i = 1
# while i < 10:
#     print(f'3 X {i} = {3*i}')
#     i += 1

# i = 1
# listInt = []
# while i < 100:
#     if i % 3 == 0 and i % 8 == 0:
#         listInt.append(i)
#     i += 1
# print(f'3과 8의 공배수 {listInt}')
# print(f'3과 8의 최소공배수 {min(listInt)}')

# for i in range(1, 101):
#     if not i % 5 == 0 and not i % 7 == 0:
#         print(i)

# num = 0
# while True:
#     print(num)
#     if num == 29:
#         break
#     num += 1

# i = 1
# flag = True
# while flag:
#     width = 2 * i
#     length = 3 * i
#     print(f'가로 {width}, 세로 {length}, 넓이 {width*length/2}')
#     if 150 < width * length / 2:
#         flag = False
#     i += 1

# width = 1
# length = 1
# flag = True
# areaList = []
# while flag:
#     print(f'가로 {width}, 세로 {length}, 넓이 {width * length}')
#     areaList.append(width * length)
#     if 150 < width * length:
#         flag = False
#     width += (2 if width > 1 else 1)
#     length += (3 if length > 1 else 2)
# print(f'가장 작은 사각형의 넓이 {min(areaList)}, 가장 큰 사각형의 넓이 {max(areaList)}')

# for i in range(1, 10):
#     for j in range(2, 10):
#         print(f'{j} X {i} = {i * j}', end=("   " if len(str(i * j)) == 1 else "  "))
#     print()

# for i in range(1, 6):
#     print(" " * (5 - i), end="")
#     print("*" * i)

# for i in range(1, 11):
#     print(" " * (10 - i), end="")
#     print('*' * (2 * i - 1))

# for i in range(1, 3):
#     if i == 1:
#         for j in range(1, 11):
#             print('*' * j)
#     else:
#         for j in range(9, 0, -1):
#             print('*' * j)

# for i in range(1, 100):
#     print(f'{i} : ', end="")
#     for j in str(i):
#         if (j == '3') or (j == '6') or (j == '9'):
#             print('짝!', end="")
#     print()

# for i in range(541):
#     if (i % 10 == 0) and (i % 25 == 0):
#         print(f'{9 + (i // 60)}시 {i % 60}분 충돌위험')
#     elif (i % 10 == 0) and (i % 30 == 0):
#         print(f'{9 + (i // 60)}시 {i % 60}분 충돌위험')
#     elif (i % 25 == 0) and (i % 30 == 0):
#         print(f'{9 + (i // 60)}시 {i % 60}분 충돌위험')

# correctPw = 'abcccc'
# adminPw = input('PW : ')
# cnt = 0
# while correctPw != adminPw:
#     cnt += 1
#     if cnt == 5:
#         break
#     print('암호를 다시 확인하세요!')
#     adminPw = input('PW : ')
# if correctPw == adminPw:
#     print('로그인 됐습니다.')
# else:
#     print('로그인 실패!! 횟수 초과!!!')

# inputInt = int(input('정수 : '))
# sumInt = 0
# for i in range(inputInt + 1):
#     sumInt += i
# print(f'0부터 {inputInt}까지의 합 : {sumInt}')

# sum = 0
# for i in range(1, 101):
#     if i % 7 == 0:
#         sum += i
# print(f'7의 배수들의 합 : {sum}')

# inputNum = int(input('양의 정수를 입력하세요 : '))
# result = 1
# for i in range(1, inputNum + 1):
#     result *= i
# print(f'{inputNum}! = {result}')

# import random
#
# randNum = random.randint(1, 100)
# inputNum = int(input('1부터 100까지의 정수 중 하나를 선택하세요. '))
# cnt = 0
# while randNum != inputNum:
#     cnt += 1
#     if cnt == 10:
#         break
#     if randNum > inputNum:
#         print('입력한 수보다 큰 숫자입니다.')
#     else:
#         print('입력한 수보다 작은 숫자입니다.')
#     print('틀렸습니다. 다시 입력하세요.')
#     inputNum = int(input('1부터 100까지의 정수 중 하나를 선택하세요. '))
# if randNum == inputNum:
#     print('정답입니다.')
# else:
#     print(f'정답은 {randNum}입니다.')
#     print('게임에 졌습니다.')

# students = {}
# for i in range(10):
#     studentName = input('이름 : ')
#     studentHeight = int(input('키(cm) : '))
#     studentWeight = int(input('몸무게(kg) : '))
#     students[studentName] = [studentHeight, studentWeight]
# for student in students:
#     bmi = students[student][1] / ((students[student][0] / 100) ** 2)
#     if bmi <= 18.5:
#         students[student].append('저체중')
#     elif 18.5 < bmi <= 22.9:
#         students[student].append('정상체중')
#     elif 22.9 < bmi <= 24.9:
#         students[student].append('과체중')
#     elif 24.5 < bmi <= 29.9:
#         students[student].append('비만')
#     else:
#         students[student].append('고도비만')
# for student in students:
#     print(f'{student} : {students[student][2]}')

# balls = ['baseball', 'basketball', 'tennisball', 'golfball', 'soccerball']
# for ball in balls:
#     print(ball)

# numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# numbers.append(10)
# print(f'numbers : {numbers}')

# manFavoriteColors = ['red', 'yellow', 'white']
# womanFavoriteColors = ['blue', 'purple', 'black']
# manFavoriteColors.extend(womanFavoriteColors)
# print(manFavoriteColors)

# toDoList = ['cleaning', 'shopping']
# for i in range(len(toDoList)):
#     print(toDoList.pop(0))
#     if len(toDoList) != 0:
#         print(toDoList)
#     else:
#         print('할일 끝~~!')

# referenceFruits = ['사과', '망고', '포도']
# fruits = ['사과', '망고', '당근', '수박', '포도', '참외', '토마토']
# tempFruits = fruits.copy()
# for fruit in tempFruits:
#     if fruit not in referenceFruits:
#         fruits.remove(fruit)
# print(fruits)

# scores = [55, 35, 40, 70, 65, 30]
# lowerFourty = 0
# totalScore = 0
# for i in scores:
#     if i < 40:
#         lowerFourty += 1
#     totalScore += i
# averageScore = round(totalScore / len(scores), 2)
# print(f'40점 미만 과목수 : {lowerFourty}')
# print(f'평균 점수 : {averageScore}')
# if lowerFourty == 0 and averageScore >= 60:
#     print('합격')
# else:
#     print('불합격')

# sports = ('태권도', '야구', '농구', '축구', '배구', '권투', '양궁')
# for idx, item in enumerate(sports):
#     if idx % 2 == 1:
#         print(item)

# names = ('박찬호', '이승엽', '박세리', '박지성', '이순철', '선동열', '손흥민', '홍길동')
# nameInput = input('이름을 입력하세요 : ')
# print(names.index(nameInput))

# scores = ('A', 'A+', 'F', 'B', 'A+', 'F', 'A')
# print(f'F학점 개수 : {scores.count("F")}')

# mathQuestion = (('3+2', '5', 3), ('5나누기2의 몫', '2', 5), ('10-2', '8', 3), ('10의2제곱X2', '200', 5), ('1-(10나누기4의 나머지)', '-1', 5), ('2의4제곱', '16', 3), ('4/2', '2', 3))
# totalScore = 0
# for i in range(len(mathQuestion)):
#     q = mathQuestion[i][0]
#     ca = mathQuestion[i][1]
#     a = input(f'{q} = ')
#     if a == ca:
#         totalScore += mathQuestion[i][2]
# print(f'수학시험 점수 : {totalScore}')

# members = {}
# inputNum = input('1. 회원가입, 2. 프로그램 종료 ')
# while inputNum != '1' and inputNum != '2':
#     print('정수로 올바르게 선택하세요.')
#     inputNum = input('1. 회원가입, 2. 프로그램 종료 ')
# while inputNum == '1':
#     inputId = input('ID : ')
#     if inputId in members.keys():
#         print('중복되는 아이디 입니다.')
#         continue
#     inputPw = input('PW : ')
#     members[inputId] = inputPw
#     inputNum = input('1. 회원가입, 2. 프로그램 종료 ')
#     while inputNum != '1' and inputNum != '2':
#         print('정수로 올바르게 선택하세요.')
#         inputNum = input('1. 회원가입, 2. 프로그램 종료 ')
# print('ID : PW')
# for key in members:
#     print(f'{key} : {members[key]}')

# classes = {'python':'5학점', 'c/c++':'5학점', 'HTML5':'3학점', 'Java':'5학점', 'Javascript':'3학점'}
# for key in classes:
#     if classes[key] == '3학점':
#         classes[key] = '5학점'
# print(classes)

# def calculatePlus():
#     print(f'덧셈 결과 : {num1 + num2}')
#
# def calculateMinus():
#     print(f'뺄셈 결과 : {num1 - num2}')
#
# def calculateMult():
#     print(f'곱셈 결과 : {num1 * num2}')
#
# def calculateDivision():
#     print(f'나눗셈 결과 : {round(num1 / num2, 2)}')
#
# num1 = int(input('첫번째 숫자를 입력하세요. '))
# operatorInput = input('1. 덧셈, 2. 뺄셈, 3. 곱셈, 4. 나눗셈 ')
# num2 = int(input('두번째 숫자를 입력하세요. '))
# if operatorInput == '1':
#     calculatePlus()
# elif operatorInput == '2':
#     calculateMinus()
# elif operatorInput == '3':
#     calculateMult()
# elif operatorInput == '4':
#     calculateDivision()

# cnt = 0
#
# def sayHello():
#     global cnt
#     cnt += 1
#     print('안녕하세요 **마트입니다.')
#     print(f'{cnt} 번째 손님입니다.')
#
# while True:
#     inputVisit = input('손님 방문시 e키 입력')
#     if inputVisit == 'E' or inputVisit == 'e' or inputVisit == 'ㄷ':
#         sayHello()

# def calculateFuct(x):
#     result = ((7 * x + 10) / 3) - ((2 * x - 6) / -(4 / 5))
#     return result
# numInput = float(input('x값 : '))
# print(calculateFuct(numInput))

# def calcChange():
#     totalPrice = 0
#     for cloth in clothes:
#         totalPrice += clothes[cloth][0] * clothes[cloth][1]
#     change = moneyTake - totalPrice
#     return change
#
# clothes = {'티셔츠':[20000], '바지':[25000], '반바지':[15000], '스커트':[18000], '모자':[10000]}
# clothes['티셔츠'].append(int(input('구입할 티셔츠 수량 : ')))
# clothes['바지'].append(int(input('구입할 바지 수량 : ')))
# clothes['반바지'].append(int(input('구입할 반바지 수량 : ')))
# clothes['스커트'].append(int(input('구입할 스커트 수량 : ')))
# clothes['모자'].append(int(input('구입할 모자 수량 : ')))
# moneyTake = int(input('지불 금액 : '))
# print(f'거스름돈 : {calcChange()}')

# def arrangeFigures(arr, n):
#     result = []
#     if n > len(arr):
#         return result
#     if n == 1:
#         for i in arr:
#             result.append([i])
#     elif n > 1:
#         for i in range(len(arr)):
#             ans = [i for i in arr]
#             ans.remove(arr[i])
#             for p in arrangeFigures(ans, n-1):
#                 result.append([arr[i]] + p)
#     return result
#
# figures = ['원', '삼각형', '사각형', '오각형', '육각형', '칠각형']
# for i in arrangeFigures(figures, 6):
#     print(i)

# def translateWord(strInput):
#     return words[strInput]
#
# words = {'apple':'사과', 'chair':'의자', 'doll':'인형', 'book':'책', 'piano':'피아노', 'clock':'시계'}
# strInput = input('단어를 입력하세요 : ')
# while strInput not in words.keys():
#     print('해당 단어의 한국어가 없습니다.')
#     strInput = input('단어를 입력하세요 : ')
# print(translateWord(strInput))

# def calculateDiscountPrice():
#     for key in priceItem:
#         priceItem[key].append(priceItem[key][0] * ((100 - salePercent) / 100))
#
# priceItem = {'쌀':[49900], '상추':[1900], '고추':[2900], '마늘':[10900], '통닭':[5600], '햄':[6900], '치즈':[3900]}
# print('''\
# -----------------------------------------
# -- 한빛마트 오늘의 할인 가격표 출력 시스템 --
# -----------------------------------------''')
# salePercent = int(input('오늘의 할인율을 입력하세요. '))
# calculateDiscountPrice()
# for key in priceItem:
#     print(f'{key+("  " if len(key) == 1 else "")}\t: {priceItem[key][0]} 원\t\t{salePercent} %DC -> {int(priceItem[key][1])} 원')

# def calculateMmToCm(l):
#     print(f'{l} mm --> {l / 10} cm')
#
# def calculateMmToM(l):
#     print(f'{l} mm --> {l / 1000} m')
#
# def calculateMmToInch(l):
#     print(f'{l} mm --> {l / 25.4} inch')
#
# def calculateMmToFt(l):
#     print(f'{l} mm --> {l / 304.8} ft')
#
# lengthInput = int(input('길이(mm)를 입력하세요. '))
# calculateMmToCm(lengthInput)
# calculateMmToM(lengthInput)
# calculateMmToInch(lengthInput)
# calculateMmToFt(lengthInput)
