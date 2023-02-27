# print('친구야~ 안녕~~')
# print('선배님 안녕하세요.')
# print('교수님 안녕하세요.')

# print(3+5)
# print(17*234)
# print(123-30*4/5)

# import operator
# print(operator.add(3, 5))
# print(operator.mul(17, 234))
# print(operator.sub(123, (operator.truediv(operator.mul(30, 4), 5))))

# helloHi = 'Hello world'
# print(helloHi)
# print(10 + 20 - 2 * 3 / 2)
# print(7 * 2 / 2)

# myName = '박현승'
# myMajor = '헬리콥터조종학'
# print(myName, myMajor)

# intro = 'Hello'
# print(intro)
# intro = '안녕하세요'
# print(intro)

# korHello = '안녕하세요'
# engHello = 'Hello'
# print('''
# 한국의 인사말 : {}
# 미국의 인사말 : {}
# '''.format(korHello, engHello))

# wordVar = 'I am a boy'
# print(wordVar)

# userName = input('이름 : ')
# userEmail = input('이메일 : ')
# userId = input('ID : ')
# userPassword = input('PW : ')
# print('''
# To. {}
# - 아이디 및 비밀번호 확인
#   {} 고객님 안녕하세요.
#   {} 고객님의 아이디와 비밀번호는 아래와 같습니다.
#   아이디 : {}
#   비밀번호 : {}
# '''.format(userEmail, userName, userName, userId, userPassword))

# varStr = 'Good morning.'
# print((varStr+'\n') * 3)

# var = 10
# print(var)
# var = 'Hello Python'
# print(var)

# korScore = input('국어 점수 : ')
# engScore = input('영어 점수 : ')
# matScore = input('수학 점수 : ')
# print('국어 : {}점, 영어 : {}점, 수학 : {}점'.format(korScore, engScore, matScore))

# inputNum1 = int(input('첫번째 정수를 입력 : '))
# inputNum2 = int(input('두번째 정수를 입력 : '))
# sumNumber = inputNum1 + inputNum2
# aveNumber = sumNumber / 2
# print('합 : {}, 평균 : {}'.format(sumNumber, aveNumber))

# print('사용자 정보를 입력하세요.')
# userName = input('이름 : ')
# userPhone = input('연락처 : ')
# userMail = input('메일 : ')
# userJob = input('직업 : ')
# print('''\
# {}
# {}
# {}
# {}
# '''.format(userName, userPhone, userMail, userJob))

# var1 = 10
# var2 = 20
# tempVar1 = var1
# var1 = var2
# var2 = tempVar1
# print('var1 : {}, var2 : {}'.format(var1, var2))

# inputNumber = int(input('Good morning 반복횟수 : '))
# varStr = 'Good morning\n'
# outputStr = varStr * inputNumber
# print(outputStr)

# totalBread = 97
# splitBread = 3
# print(f'최대 {totalBread // splitBread}명의 학생에게 3개씩 나누어 주고 {totalBread % splitBread}개가 남는다')

# day = int(input('감염병 일차 : '))
# numInfect = (2 ** day) if (0 < day) else 0
# print('{}일차의 예상 전체 감염자 수 : {}명'.format(day, numInfect))

# incoming = int(input('수입 : '))
# outgoing = int(input('지출 : '))
# if incoming >= outgoing:
#     print('흑자')
# else:
#     print('적자')

# import operator
# userInput = int(input('정수 입력 : '))
# solveOut = operator.pow(userInput, 3)
# print('{}의 세거듭제곱은 {}'.format(userInput, solveOut))

# userScore = int(input('점수 : '))
# if userScore >= 70:
#     print('Pass')

# number = int(input('양의 정수를 입력하세요 : '))
# if number % 2 == 0:
#     print('짝수!')
# else:
#     print('홀수!')

# machineTemperature = float(input('기계 온도(도) : '))
# if machineTemperature >= 40:
#     print('팬(Fan)을 가동')
# else:
#     print('팬(Fan)을 중지')

# mleage = 1200
# if mleage >= 1000:
#     print('마일리지 사용가능')
# else:
#     print('마일리지 사용불가')

# familyNum = int(input('가구 인원수를 입력하세요 : '))
# grant = 0
# if familyNum == 1:
#     grant = 400000
# elif familyNum == 2:
#     grant = 600000
# elif familyNum == 3:
#     grant = 800000
# else:
#     grant = 1000000
# print('국가재난지원금은 {}원 입니다.'.format(format(grant, ",")))

# bmi = float(input('BMI지수 : '))
# state = ""
# if bmi <= 90:
#     state = "저체중"
# elif 90 < bmi <= 110:
#     state = "정상체중"
# elif 110 < bmi <= 120:
#     state = "과체중"
# elif 120 < bmi <= 140:
#     state = "비만"
# else:
#     state = "고도비만"
# print(state)

# dayweek = int(input('1. 토요일 및 공휴일, 2. 그 외 요일 '))
# if dayweek == 1:
#     print('단속요일 아님')
# else:
#     carType = int(input('1. 버스, 2. 그 외 '))
#     if carType == 1:
#         print('단속대상 아님')
#     else:
#         print('단속대상 경고')

# age = int(input('나이 : '))
# availableDay = ""
# if age < 65:
#     endBirthYear = int(input('출생연도 끝자리 : '))
#     if endBirthYear % 5 == 1:
#         availableDay = "월"
#     elif endBirthYear % 5 == 2:
#         availableDay = "화"
#     elif endBirthYear % 5 == 3:
#         availableDay = "수"
#     elif endBirthYear % 5 == 4:
#         availableDay = "목"
#     else:
#         availableDay = "금"
# else:
#     availableDay = "제한없음"
# print('공적마스크 구매가능 요일 : {}'.format(availableDay))

# testScore = float(input('시험점수 : '))
# print('success' if testScore >= 85 else 'fail')

# testScore = float(input('시험점수 : '))
# if testScore >= 85:
#     print('success')
# else:
#     print('fail')

# num = int(input('정수 입력 : '))
# if num % 3 == 0:
#     print('3의 배수')
# else:
#     print('3의 배수 아님')

# import random
# ranNum = random.randint(1, 100)
# print(ranNum, '홀' if ranNum % 2 == 1 else '짝')

# import random
# ranNum = random.randint(1, 3)
# if ranNum == 1:
#     print('가위')
# elif ranNum == 2:
#     print('바위')
# else:
#     print('보')

# testScore = int(input('시험 점수 : '))
# resultTest = ''
# if testScore >= 90:
#     resultTest = '수'
# elif 80 <= testScore < 90:
#     resultTest = '우'
# elif 70 <= testScore < 80:
#     resultTest = '미'
# elif 60 <= testScore < 70:
#     resultTest = '양'
# else:
#     resultTest = '가'
# print(resultTest if testScore >= 50 else resultTest+'\n재시험')

# lowestTemp = float(input('아침 최저 기온 : '))
# highestTemp = float(input('오후 최고 기온 : '))
# outputStr = ''
# if (highestTemp - lowestTemp) >= 10:
#     outputStr = '감기 조심하세요.'
# else:
#     if highestTemp >= 28:
#         outputStr = '초여름 날씨입니다.'
# print(outputStr)

# userMessage = input('메시지를 입력하세요 : ')
# msgLen = len(userMessage)
# if msgLen <= 50:
#     print('SMS로 발송됩니다.')
# else:
#     print('MMS로 발송됩니다.')
