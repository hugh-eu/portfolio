## input(항상 str 타입)

"""
userData = input("나이를 입력하세요 : ")
print("나이 :", userData + "세")
"""

"""
userName = input("이름 : ")
userAge = input("나이 : ")
print("사용자 이름 :", userName)
print("사용자 나이 :", userAge)
"""


"""
userName = input("이름 : ")
userMail = input("메일 : ")
userId = input("아이디 : ")
userPw = input("비밀번호 : ")
print()
print("To.", userMail)
print("- 아이디 및 비밀번호 확인")
print(" ", userName, "고객님 안녕하세요.")
print(" ", userName, "고객님의 아이디와 비밀번호는 아래와 같습니다.")
print("  아이디 :", userId)
print("  비밀번호 :", userPw)
"""


"""
userMail = input("이메일 주소를 입력하세요 : ")
userName = input("이름을 입력하세요 : ")
print()
print("To. " + userMail)
print("- 아이디 및 비밀번호 확인")
print("  " + userName + " 고객님 안녕하세요.")
print("  " + userName + " 고객님의 아이디와 비밀번호는 아래와 같습니다.")
print("  아이디 :", userMail.split("@")[0])
print("  비밀번호 : 1293959")
"""

"""
dayData = input("날짜 : ")
dayWeek = input("요일 : ")
lowestTemp = input("최저기온 : ")
highestTemp = input("최고기온 : ")
rainPercent = input("비올확률 : ")
microDust = input("미세먼지 : ")
sunRise = input("일출시간 : ")
sunSet = input("일몰시간 : ")
waveSouth = input("남해파고 : ")
waveEast = input("동해파고 : ")
waveWest = input("서해파고 : ")
print()
print("내일 날씨 예보입니다")
print(dayWeek + "인 " + dayData + "의 아침 최저 기온은 " + lowestTemp + "도, 낮 최고 기온은 " + highestTemp + "도로 예보됐습니다.")
print("비올 확률은 " + rainPercent + "%이고, 미세먼지는 " + microDust + " 수준일 것으로 예상됩니다.")
print("일출 시간은 " + sunRise + "이고, 일몰 시간은 " + sunSet + "입니다.")
print("바다의 물결은 남해 앞바다 " + waveSouth + "m, 동해 앞바다 " + waveEast + "m, 서해 앞바다 " + waveWest + "m 높이로 일겠습니다.")
print("지금까지 " + dayData, dayWeek + " 날씨 예보였습니다.")
"""

## 데이터 타입 맞추기, 자료형 형변환, casting, int(), float(), str(), bool()
"""
print(type(int("10")))  # 정수 형변환
print(int("10"))
print(type(float(10)))  # 실수 형변환
print(float(10))
print(type(str(10)))  # 문자열 형변환
print(str(10))
print(type(bool("True")))  # 불 형변환
print(bool("True"))
"""

"""
str = "hello"
print(type(str))
"""

"""
userAge = input("나이 : ")
print(userAge)
print(type(userAge))
#print(userAge + 1)  # 타입 에러 input의 경우 str로 저장
print(int(userAge) + 1)
"""

# ex. 엄마와 자식의 나이를 입력받아 나이 차이를 출력하는 프로그램
"""
ageMom = input("엄마 나이 : ")
ageChild = input("자식 나이 : ")
print()
print("나이 차 " + str(abs(int(ageMom) - int(ageChild))) + "살")  # abs() 절대값
"""

# int(), float() 조합
"""
input_a = int(input("첫번째 숫자(정수) : "))
input_b = float(input("두번째 숫자(실수) : "))

print("+ :", input_a + input_b)
print("- :", input_a - input_b)
print("* :", input_a * input_b)
print("/ :", input_a / input_b)
"""

# ValueError
#int("안녕하세요")
#float("안녕하세요")  # 숫자가 아닌것
#int("23.451")  # 실수형을 정수로

## ex. 모 회사에서 1분기 수익, 매출액과 매입액을 입력하여 수익, 수익률 계산
"""
sales = int(input("1분기 매출 : "))
purchase = int(input("1분기 매입 : "))
profit = sales - purchase
profitRate = profit / purchase * 100

print("1분기 수익 : " + format(profit, ","))  # format()으로 "," 찍기, str 값
print("1분기 수익률 : " + str(profitRate))
"""

## ex
"""
import math

str = "52.673"
# 실수 형변환
floatStr = float(str)
# 정수 형변환
print(int(floatStr))
print(type(int(floatStr)))
print(math.trunc(floatStr))
print(type(math.trunc(floatStr)))
# 소수점 첫째자리에서 반올림
print(round(floatStr, 0))
# 올림
print(math.ceil(floatStr))
# 내림
print(math.floor(floatStr))
"""

## ex. 사용자가 inch의 길이를 입력하면 cm로 변환
lengthInch = input("inch 단위의 길이를 입력하세요. : ")
print()
print(lengthInch + " inch는 " + str(float(lengthInch) * 2.54) + " cm")