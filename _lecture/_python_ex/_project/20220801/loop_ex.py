## for, while
## for : 횟수가 정해져 있는 반복
# for i in range(1, 6, 1):  # iterable 객체, 각각은 item
#     print(i, 'hello')

# 정수 2에서 8까지 짝수만 출력하는 for문
# for i in range(2, 9, 1):
#     if i % 2 == 0:
#         print(i)

# 사용자가 입력한 횟수만큼 '메일 발송' 문자열 출력하기
# inputNum = int(input('발송 횟수 : '))
# for i in range(0, inputNum, 1):
#     print('메일 발송')

# 1에서 10 사이의 정수를 출력하되 정수가 3의 배수이면 '3의 배수' 문자열을 출력
# for i in range(1, 11, 1):
#     print(str(i) + (" 3의 배수" if (i % 3 == 0) else ""))

# 구구단 5단을 출력
# for i in range(1, 10, 1):
#     print('5 * {} = {}'.format(i, (5 * i)))

# 1부터 10까지의 정수의 합을 출력하는 프로그램
# sumInt = 0
# for i in range(1, 11, 1):
#     sumInt += i
# print('1부터 10까지의 합 : {}'.format(sumInt))

# 1부터 10까지의 짝수의 합
# sumEven = 0
# for i in range(1, 11, 1):
#     if i % 2 == 0:
#         sumEven += i
# print('1부터 10까지 짝수들의 합 : {}'.format(sumEven))

# 1부터 10까지의 홀수의 합
# sumOdd = 0
# for i in range(1, 11, 1):
#     if i % 2 == 1:
#         sumOdd += i
# print('1부터 10까지 홀수들의 합 : {}'.format(sumOdd))

# for문을 이용 1 - 100 까지 정수중 3과 7의 공배수와 최소 공배수 출력
# commonMultiple = ""
# leastCommonMultiple = 0
# for i in range(1, 101, 1):
#     if (i % 3 == 0) and (i % 7 == 0):
#         commonMultiple += str(i) + ", "
# commonMultiple = commonMultiple.rstrip(", ")
# for i in commonMultiple.split(", "):
#     if i == commonMultiple.split(', ')[0]:
#         leastCommonMultiple = int(i)
#     elif int(i) < leastCommonMultiple:
#         leastCommonMultiple = int(i)
# print('3과 7의 공배수 : {}'.format(commonMultiple))
# print('3과 7의 최소공배수 : {}'.format(leastCommonMultiple))

# 문자열 가능
# for c in 'hello':  # character c 자주 사용
#     print(c)

# for ~ else, for문이 종료되고 else 한번실행, 파이썬에만 있는듯?
# for num in range(1, 6):
#     print(num)
# else:
#     print('반복문 종료')

## while : 특정 조건이 만족하는 동안 반복
# 0 부터 5까지 정수 출력
# i = 0
# while i < 5:
#     print(i, 'hello')
#     i += 1

# 1부터 30까지의 정수 중 홀수와 짝수를 구분하여 출력, while
# i = 1
# oddNum = ""
# evenNum = ""
# while i < 31:
#     if i % 2 == 0:
#         evenNum += str(i) + ", "
#     else:
#         oddNum += str(i) + ", "
#     i += 1
# print('홀수 :', oddNum.rstrip(", "))
# print('짝수 :', evenNum.rstrip(", "))

# 0-100까지 정수중 3과 8의 공배수와 최소공배수를 출력
# i = 0
# commonMultiple = ""
# leastCommonMultiple = 0
# while i < 100:
#     i += 1
#     if (i % 3 == 0) and (i % 8 == 0):
#         commonMultiple += str(i) + ", "
# commonMultiple = commonMultiple.rstrip(", ")
# for j in commonMultiple.split(", "):
#     if j == commonMultiple.split(', ')[0]:
#         leastCommonMultiple = int(j)
#     elif int(j) < leastCommonMultiple:
#         leastCommonMultiple = int(j)
# print('3과 8의 공배수 :', commonMultiple)
# print('3과 8의 최소공배수 :', leastCommonMultiple)

# 무한 루프 : 논리적인 오류로 인한 최악의 사태 발생(시스템 터짐)
# num = 0
# while num < 3:
#     print('hi')
#     num += 1  # 없으면 무한루프

## range() : 범위 설정하는 함수
# range(시작, 끝, 단계) range(0, 100, 1) 0 - 99, 1씩증가
# for i in range(0, 100, 1):
#     print(i)

# 1씩 증가하는 경우 단계를 생략가능 range(0, 100) 0 - 99, 1씩증가
# for i in range(0, 100):
#     print(i)

# 단계 생략시 시작생략 가능, 0부터 시작 range(100) 0 - 99, 1씩증가
# for i in range(100):
#     print(i)

# 감소 가능
# for i in range(10, 0, -1):  # 1까지
#     print(i)

## 반복문 내 실행 제어, continue, break, pass
# continue : 반복문 처음으로 돌아가 다음 반복 실행, continue 이하 실행 X

# continue를 이용하여 1부터 10까지의 정수중 홀수만 출력
# for i in range(1, 11):
#     if i % 2 == 0:
#         continue
#     print(i)

# break : 반복문 종료, 빠져나옴

# 1부터 10까지의 정수를 더하되 결과가 30 이상이 될때 정수를 찾는 프로그램
# sumInt = 0
# for i in range(1, 11):
#     sumInt += i
#     if 30 <= sumInt:
#         print(i)
#         break

# 삼각형 넓이, 가로 세로의 변화에 따른 삼각형의 넓이, 가로 2부터 2배수, 세로 3부터 3배수, 넓이 150보다 크면 종료
# i = 1
# width = 0
# height = 0
# area = 0
# while 150 >= area:
#     width = i * 2
#     height = i * 3
#     area = width * height / 2
#     print('가로 : {}, 세로 : {}, 넓이 : {}'.format(width, height, area))
#     i += 1

## 중첩 반복문, 가능하면 두번까지만
# for num1 in range(1, 6):
#     for num2 in range(num1):
#         print('*', end="")
#     print()

# num1 = int(input('첫번째 수 : '))
# num2 = int(input('두번째 수 : '))
# for i in range(1, 10):
#     for j in range((num1 if (num2 > num1) else num2), (num2 if (num2 > num1) else num1) + 1):
#         print(f'{j} X {i} = {j * i}', end=(("   ") if len(str(j * i)) == 1 else ("  ")))
#     print()

# 중첩 반복문, * 가 트리모양
# numInput = int(input('원하는 트리의 층수 : '))
# for i in range(1, numInput + 1):
#     for j in range(numInput - i):
#         print(" ", end="")
#     print("*" * ((i - 1) * 2 + 1))

# 369게임 1부터 99 까지 1씩 증가, 3, 6, 9에 짝
# for i in range(1, 100):
#     print(i, end=" ")
#     for j in str(i):
#         if j == "3":
#             print('짝!', end=" ")
#         elif j == "6":
#             print('짝!', end=" ")
#         elif j == "9":
#             print('짝!', end=" ")
#     print()

# 한빛역 3개 노선 열차 오전 9시부터 오후6시까지 교차 운행 3대의 열차가 교차하는 시간 열차충돌사고 막기
# (매일 오전9시 시작 a 10분간격, b 25, c 30, 오후 6시 마지막차)
# h = 9
# m = 0
# for i in range(1, 109):
#     chkTime = 5 * i
#     m = chkTime % 60
#     if chkTime % 60 == 0:
#         h += 1
#     if (chkTime % 10) == 0 and (chkTime % 25) == 0:
#         print('{}시 {}분'.format(h, m))
#     elif (chkTime % 10) == 0 and (chkTime % 30) == 0:
#         print('{}시 {}분'.format(h, m))
#     elif (chkTime % 25) == 0 and (chkTime % 30) == 0:
#         print('{}시 {}분'.format(h, m))

# 시스템 관리자 로그인 기능,
# 로그인 시도 암호가 틀리면 암호를다시확인하세요 출력 다시 암호 물어보기,
# 5회이상 로그인 실패시 로그인 실패 횟수초과
# 암호 맞으면 로그인됐습니다.
# correctPw = 'abcdf'
# inputPw = input('관리자 암호를 입력하세요. ')
# cnt = 0
# while correctPw != inputPw:
#     cnt += 1
#     if cnt == 5:
#         print('로그인 실패!! 횟수 초과!!!')
#         break
#     print('암호를 다시 확인하세요!')
#     inputPw = input('관리자 암호를 입력하세요 : ')
# if correctPw == inputPw:
#     print('로그인 됐습니다.')

# 사용자가 입력한 값으로 팩토리얼
# inputNum = int(input('팩토리얼을 구할 정수 : '))
# int_result = 1
# for i in range(inputNum, 0, -1):
#     int_result *= i
# print(int_result)

# 1부터 100 난수, 사용자가 난수를 맞힐때까지 계속 물어봄, 정답, 틀력 다시입력, 10회제한, 게임 졌습니다. 틀릴때마다 비교 크고 작음 출력, 게임종료전 난수 출력
# import random
#
# cnt = 0
# randomNum = random.randint(1, 100)
# inputNum = int(input('1부터 100까지의 수 :'))
# while randomNum != inputNum:
#     cnt += 1
#     print('틀렸습니다.')
#     if cnt == 10:
#         print('10번의 기회 소진, 게임종료, 정답은 {}입니다.'.format(randomNum))
#         break
#     if randomNum < inputNum:
#         print('입력한 값보다 작습니다.')
#     else:
#         print('입력한 값보다 큽니다.')
#     inputNum = int(input('1부터 100까지의 수 :'))
# if randomNum == inputNum:
#     print('정답입니다.')



## 참고, 다른언어, do ~ while : while 문과 같으나 차이점은 최소 1번은 실행