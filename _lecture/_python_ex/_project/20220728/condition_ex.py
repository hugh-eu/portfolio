## 조건문
# 나의 점수가 90이상이면 용돈 받는다
"""
myScore = int(input("점수 : "))
if (90 <= myScore):
    print("용돈 받는다.")  # |-------
    print("야호!!")       # |코드블럭, □
#elif (70 <= myScore < 90):
#   print("용돈 할인...")
else:
    print("용돈 못 받는다.")
"""

"""
if True:
    print("True 입니다.")
    print("True임")
"""

"""
if False:
    print("False입니다...")  # 출력 안됨
"""

# 정수를 입력받아 양수, 음수, 0 판별
"""
num = int(input("정수를 입력하세요 : "))
if 0 < num:
    print("양수 입니다.")
if 0 > num:
    print("음수 입니다.")
if 0 == num:
    print("0 입니다.")
"""

# 제한속도 50km/h 속도위반시 경고
"""
speed = float(input("차량 속도(km/h) : "))
if speed > 50:
    print("제한속도 50km/h 위반입니다.")
"""

# 시간 오전 오후 구분하기
"""
import datetime as dt

now = dt.datetime.now()  # 시스템의 현재시간
weekday = ["월", "화", "수", "목", "금", "토", "일"]
"""
"""
print(now)
print(now.year)
print(now.month)
print(now.day)
print(weekday[now.weekday()])
print(now.hour)
print(now.minute)
print(now.second)
print("{}년 {}월 {}일 {}요일 {}시 {}분 {}초".format(
                                                now.year,
                                                now.month,
                                                now.day,
                                                weekday[now.weekday()],
                                                now.hour,
                                                now.minute,
                                                now.second))
print(f"{now.year}년 {now.month}월 {now.day}일 {weekday[now.weekday()]}요일 {now.hour}시 {now.minute}분 {now.second}초")
"""
"""
if now.hour < 12:
    print("오전입니다.")
if now.hour >= 12:
    print("오후입니다.")
"""
"""
if (3 <= now.month <= 5):
    print("이번 달은 {}월로 봄입니다!".format(now.month))
if (6 <= now.month <= 8):
    print("이번 달은 {}월로 여름입니다!".format(now.month))
if (9 <= now.month <= 11):
    print("이번 달은 {}월로 가을입니다!".format(now.month))
if (now.month == 12) or (1 <= now.month <= 2):
    print("이번 달은 {}월로 겨울입니다!".format(now.month))
"""

# 짝수 홀수 구분
"""
num = input("정수 입력 : ")
lastChar = int(num[-1])
if (lastChar == 0) \
        or (lastChar == 2) \
        or (lastChar == 4) \
        or (lastChar == 6) \
        or (lastChar == 8):
    print("짝수")
else:
    print("홀수")
"""
"""
num = input("정수 입력 : ")
lastChar = num[-1]
if lastChar in "02468":
    print("짝수")
else:
    print("홀수")
"""
"""
num = int(input("정수를 입력 : "))
if (num % 2) == 0:
    if num == 0:
        print("0")
    else:
        print("짝수")
else:
    print("홀수")
"""

# 오늘 날씨가 30도 이상이면 외출금지 아니면 외출허락
"""
tempToday = float(input("오늘 날씨(도) : "))
if tempToday >= 30:
    print("외출 금지")
if tempToday < 30:
    print("외출 가능")
"""
"""
tempToday = float(input("오늘 날씨(도) : "))
if tempToday >= 30:
    print("외출 금지")
else:
    print("외출 가능")
"""

# 성적 90 이상이면 a, 80이상 90미만 b, ...
"""
scoreTest = float(input("시험 점수 : "))
if 90 <= scoreTest:
    print("A")
elif 80 <= scoreTest < 90:
    print("B")
elif 70 <= scoreTest < 80:
    print("C")
elif 60 <= scoreTest < 70:
    print("D")
else:
    print("F")
"""

"""
smsTextMaxLength = 10
userMessage = input("메세지 입력하세요 : ")
lenUserMessage = len(userMessage)
if smsTextMaxLength < lenUserMessage:
    print("장문자 서비스 이용")
    pass  # 이후 작업 
else:
    print("단문자 서비스 이용")
    pass
print("메시지 전송 완료")
"""

# 계절 구하기
"""
import datetime as dt

now = dt.datetime.now()
month = now.month

if 3 <= month <= 5:
    print("현재는 봄입니다.")
elif 6 <= month <= 8:
    print("현재는 여름입니다.")
elif 9 <= month <= 11:
    print("현재는 가을입니다.")
else:
    print("현재는 겨울입니다.")
"""

# 안녕하세요 대답, 시간 대답하는 프로그램
"""
import datetime as dt

now = dt.datetime.now()
hourNow = now.hour
textGive = input("Q : ")
if "안녕" in textGive:
    print("A : 안녕하세요.")
elif ("몇 시" in textGive) or ("몇시" in textGive):
    print("지금은 {}시입니다.".format(hourNow))
else:
    print(textGive)
"""

# 나누어떨어지는 숫자
"""
num = int(input("정수를 입력해주세요 : "))
if num % 2 == 0:
    print("{}은 2로 나누어 떨어지는 숫자입니다.".format(num))
else:
    print("{}은 2로 나누어 떨어지는 숫자가 아닙니다.".format(num))
if num % 3 == 0:
    print("{}은 3으로 나누어 떨어지는 숫자입니다.".format(num))
else:
    print("{}은 3으로 나누어 떨어지는 숫자가 아닙니다.".format(num))
if num % 4 == 0:
    print("{}은 4로 나누어 떨어지는 숫자입니다.".format(num))
else:
    print("{}은 4로 나누어 떨어지는 숫자가 아닙니다.".format(num))
if num % 5 == 0:
    print("{}은 5로 나누어 떨어지는 숫자입니다.".format(num))
else:
    print("{}은 5로 나누어 떨어지는 숫자가 아닙니다.".format(num))
"""

# 다이어그램
"""
mileage = 1200
if mileage >= 1200:
    print("마일리지 사용가능")
else:
    print("마일리지 사용불가")
"""

# 자동주문 시스템, 다국어 지원식당, 1번을 누르면 한국어 2번 영어, 3번 중국어 , 그외 영어
"""
numInput = int(input('''\
Good morning. Nice to meet you.
Where are you from?
Please select a number
1. 대한민국  2. USA  3. 中國 '''))
if numInput == 1:
    print("주문하시겠어요?")
elif numInput == 2:
    print("Would you like to order?")
elif numInput == 3:
    print("您要订购吗？")
else:
    print("Would you like to order?")
"""

# 가구 인원수에 따른 국가재난지원금, 1인 40 2인 60 3인 80 4인 100
"""
numFamily = int(input("가구 인원수를 입력하세요 : "))
if numFamily == 1:
    print("국가재난 지원금은 400,000원 입니다.")
elif numFamily == 2:
    print("국가재난 지원금은 600,000원 입니다.")
elif numFamily == 3:
    print("국가재난 지원금은 800,000원 입니다.")
else:
    print("국가재난 지원금은 1,000,000원 입니다.")
"""

# 버스전용차로 단속, 버스 아닌 승용차 주행경우 단속, 토요일 및 공휴일 단속 x
"""
dayweek = int(input("요일. 1. 월-금, 2. 토요일, 3. 공휴일 "))
typeCar = input("차량 종류. 1. 버스 2. 이외 ")
if dayweek == 1:
    if typeCar > 1:
        print("버스전용차로 단속 대상입니다.")
    else:
        print("버스전용차로 단속 대상이 아닙니다.")
else:
    print("버스전용차로 단속일이 아닙니다.")
"""

# 출생연도 끝자리 endBirthYear 나이 age 입력.
# 요구사항에 맞춰 마스크 구매가능한 요일 출력, 끝자리 1 6월, 2 7화, 3 8수, 4 9목, 5 0금, 65세 이상 언제든지
"""
endBirthYear = int(input("출생연도 끝자리 입력 : "))
age = int(input("만 나이 입력 : "))
if age < 65:
    if (endBirthYear % 5) == 1:
        print("월요일 구매 가능합니다.")
    elif (endBirthYear % 5) == 2:
        print("화요일 구매 가능합니다.")
    elif (endBirthYear % 5) == 3:
        print("수요일 구매 가능합니다.")
    elif (endBirthYear % 5) == 4:
        print("목요일 구매 가능합니다.")
    else:
        print("금요일 구매 가능합니다.")
else:
    print("언제든지 구매 가능합니다.")
"""

# 고농도 미세먼지 비상저감조치 2부제, 오늘날짜 구하기, 차량번호 4자리, 짝수날 차량번호 짝수 입차, 홀수는 반대
"""
import datetime as dt
numCar = int(input("차량 번호 4자리를 입력하세요. "))
today = dt.datetime.now().day
print("오늘 날짜 : {}일".format(today))
if today % 2 == 0:
    print("오늘 입차 : 번호가 짝수인 차량")
else:
    print("오늘 입차 : 번호가 홀수인 차량")
print("귀하의 차량은 입차 {}합니다.".format("가능" if (numCar % 2) == (today % 2) else "불가"))
"""

# 심장 충격기를 시행한 시각에 따른 환자의 생존율, 걸린시간 입력 생존율 출력
"""
rateAlive = int()
timeAct = int(input("최초 장비를 사용하기까지 걸린 시간(초)를 입력하세요. "))
if timeAct <= 60:
    rateAlive = 85
elif 60 < timeAct <= 120:
    rateAlive = 76
elif 120 < timeAct <= 180:
    rateAlive = 66
elif 180 < timeAct <= 240:
    rateAlive = 57
elif 240 < timeAct <= 300:
    rateAlive = 47
else:
    rateAlive = 25
print("생존율 : {}%".format(rateAlive) if (rateAlive > 25) else ("생존율 : 25% 미만"))
"""

# 누진세, 전기사용량 입력 전기료 출력, 200이하 단가 99.3 기본 910, 400이하 단가 187.9 1600, 400 초과 280.6 7300
# 임의로 단순곱
"""
elecUsage = float(input("전기 사용량을 입력하세요. "))
basicPrice = int()
unitPrice = float()
if elecUsage <= 200:
    basicPrice = 910
    unitPrice = 99.3
elif 200 < elecUsage <= 400:
    basicPrice = 1600
    unitPrice = 187.9
else:
    basicPrice = 7300
    unitPrice = 280.6
totalPrice = unitPrice * elecUsage
print("사용량 : {} kwh".format(elecUsage))
print("기본요금 : {} 원".format(basicPrice))
print("단가 : {} 원".format(unitPrice))
print("전기 요금 : {} 원".format(basicPrice + totalPrice))
"""
