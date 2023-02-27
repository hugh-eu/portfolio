### 연산자
## 산술연산자: +, -, *, /, //, %, **
"""
num1 = 0.1
num2 = 20

print(num1 + num2)
print(num1 - num2)
print(num1 * num2)
print(num1 / num2)
print(num2 / num1)
print(type(num1 + num2))
print(type(num1 - num2))
print(type(num1 * num2))
print(type(num1 / num2))
print(type(num2 / num1))
"""
"""
num3 = 0.5
num4 = 3

print(num3 // num4)
print(num3 % num4)
print(num3 ** num4)
print(type(num3 // num4))
print(type(num3 % num4))
print(type(num3 ** num4))
"""

# 제곱근 참조
"""
import math

print(math.sqrt(4))
print(math.sqrt(2))
"""

## 할당연산자, 복합연산자: =, +=, -=, *=, /=, //=, %=, **=
"""
num = 10
num = num + 10
print(num)
num = 10
num += 10
print(num)

num = 10
num = num - 10
print(num)
num = 10
num -= 10
print(num)

num = 10
num = num * 10
print(num)
num = 10
num *= 10
print(num)

num = 10
num = num / 10
print(num)
num = 10
num /= 10
print(num)

num = 10
num = num // 10
print(num)
num = 10
num //= 10
print(num)

num = 10
num = num % 10
print(num)
num = 10
num %= 10
print(num)

num = 10
num = num ** 10
print(num)
num = 10
num **= 10
print(num)
"""

## 비교연산자: ==, !=, <=, >=, <, >, 결과 boolean
"""
num1 = 10; num2 = 20
print(num1 == num2)  # False
print(num1 != num2)  # True
print(num1 <= num2)  # True
print(num1 >= num2)  # False
print(num1 < num2)  # True
print(num1 > num2)  # False
"""
# 신장 120이상 이면 True, 미만이면 False 출력
"""
height = float(input("신장: "))
print(120 <= height)
"""
# 문자 비교(아스키 코드, ASCII)
"""
print('a' == 'b')
print('a' != 'b')
print('a' > 'b')
print('a' >= 'b')
print('a' < 'b')
print('a' <= 'b')
"""
# 문자열(크거나 작은 것도 결과가 나오지만 사용하지 않음)
"""
print('hello' == 'HELLO')
print('hello' != 'HELLO')
"""

## 논리연산자: and, or, not
"""
var1 = True; var2 = False; var3 = True
print(var1 and var2)  # False
print(var1 or var2)  # True
print(not var1)  # False
print(not (var1 and var2))  # True
print(var1 and var2 and var3)  # False
"""
# 신장 120이상, 170미만 탑승 가능, 여부
"""
height = float(input("신장: "))
print((height >= 120) and (height < 170))
"""
# and의 경우 앞부분에 False가 나오는 경우 뒷부분 영향 없음
"""
num = 10
abc  # Error
"""
"""
num = 10
print(num < 5 and abc)  # False
"""
# or의 경우 앞부분에 True가 나오는 경우 뒷부분 영향 없음

## 삼항연산자: A if 조건식 else B
"""
passScore = 90
myScore = int(input("나의 시험 점수: "))
print("합격" if passScore <= myScore else "불합격")
"""
"""
income = float(input("수입: "))
spending = float(input("지출: "))
print()
print("흑자" if income >= spending else "적자")
"""

## operator 모듈(1 + 1의 경우 내부엔진에서 operator.add(1, 1)의 과정을 거침, 생략을 위해 알아두기
#print(10 + 20)
"""
import operator
print(operator.add(10, 20))
print(operator.sub(10, 20))
print(operator.mul(10, 20))
print(operator.truediv(10, 20))
print(operator.mod(10, 20))  # 나머지
print(operator.floordiv(10, 20))  #몫
print(operator.pow(10, 20))  # 제곱승
"""
"""
import operator
num1 = 10
num2 = 3
print(operator.eq(num1, num2))  # ==
print(operator.ne(num1, num2))  # !=
print(operator.gt(num1, num2))  # >
print(operator.ge(num1, num2))  # >=
print(operator.lt(num1, num2))  # <
print(operator.le(num1, num2))  # <=
"""
"""
import operator
flag1 = True
flag2 = False
print(operator.and_(flag1, flag2))  # and
print(operator.or_(flag1, flag2))  # or
print(operator.not_(flag1))  # not
"""
# 월소득 4000000 이하, 기타 지원금 받지 않을 경우 지원 대상, 대상자 여부 확인
"""
import operator
monthlyIncome = float(input("월 소득: "))
otherGrant = float(input("기타 지원금 수급액: "))
condition1 = operator.ge(4000000, monthlyIncome)
condition2 = operator.eq(otherGrant, 0)
target = operator.and_(condition1, condition2)
print("대상자" if target else "비대상자")
"""
# 해수면 10m 내려갈때마다 0.7도 감소, 수심을 입력하면 수온 계산, 해수면 20도
"""
depth = float(input("수심을 입력하세요(m): "))
stepTemp = 0.7
seaLevelTemp = 20
targetTemp = seaLevelTemp - ((depth / 10) * stepTemp)
print(f"수온 : {round(targetTemp, 1)}")
"""

# 속도, 시간 입력받아 주행거리 구하기
"""
velocityCruise = float(input("주행 속도(km/h) : "))
timeCruise = float(input("주행 시간(시간) : "))
distanceCruise = velocityCruise * timeCruise
print(f"주행 이동 거리 : {distanceCruise}km")
"""

# 속도구하기
"""
distanceCruise = float(input("주행 거리(km) : "))
timeCruise = float(input("주행 시간(시간) : "))
velocityCruise = distanceCruise / timeCruise
print(f"주행 속도 : {velocityCruise}km")
"""

# 시간구하기
"""
distanceCruise = float(input("주행 거리(km) : "))
velocityCruise = float(input("주행 속도(km/h) : "))
secCruise = int((distanceCruise / velocityCruise) * 3600)
print(f"주행 시간 : {secCruise // 3600}시간 {(secCruise % 3600) // 60}분 {(secCruise % 3600) % 60}초")
"""

# 3대의 컴퓨터 8시간일하면 하루 업무 처리, 단축근무하면 필요한 컴퓨터, 근무시간 입력시 필요한 컴퓨터 수량
"""
import math
workTime = float(input("근무시간 : "))
comQty = math.ceil(24 / workingTime)
print(f"필요한 컴퓨터 수량 : {comQty}대")
"""
"""
time = float(input("근무시간 : "))
com = 3 * 8 // time
addCom = 1 if 3 * 8 % time > 0 else 0
print(f"필요한 컴퓨터 수량 : {com + addCom}대")
"""

# 한개에 340원 마스크를 x개 구매 y원 지불했을 경우 거스름돈
"""
qty = int(input("마스크 구매 수량 : "))
pay = int(input("지불 금액 : "))
price = 340
result = pay - price * qty
print(f"거스름돈 : {result}")
"""

# 13시 30분 25초 를 초로
"""
hour = 13  # int(input("시간 : ")
min = 30  # int(input("분 : ")
sec = 25  # int(input("초 : ")
print(hour * 3600 + min * 60 + sec)
"""

# 국어 영어 수학 입력하면 총점과 평균
"""
korScore = int(input("국어 점수 : "))
engScore = int(input("영어 점수 : "))
matScore = int(input("수학 점수 : "))
totalScore = korScore + engScore + matScore
aveScore = round((totalScore / 3), 2)
print(f"총점 : {totalScore}, 평균 : {aveScore}")
"""

# 밤 최저기온과 낮 최고기온 입력시 일교차 출력
"""
highestTemp = float(input("낮 최고기온 : "))
lowestTemp = float(input("밤 최저기온 : "))
changeTemp = round((highestTemp - lowestTemp), 2)
print(f"일교차 : {changeTemp}도")
"""

# 길이cm 입력시 inch로 환산 1cm == 0.39inch
"""
cmLen = float(input("길이(cm) : "))
inchLen = round((cmLen * 0.39), 2)
print(f"{inchLen}inch")
"""
