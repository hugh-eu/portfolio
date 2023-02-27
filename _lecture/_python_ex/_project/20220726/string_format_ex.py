## 문자열의 format 사용
# 학생의 시험점수(국, 영, 수)를 입력받아 합과 평균을 출력하자.
"""
korScore = int(input('국어 점수 : '))
engScore = int(input('영어 점수 : '))
matScore = int(input('수학 점수 : '))
print()
print('국어 점수 : {}'.format(korScore))
print('영어 점수 : {}'.format(engScore))
print('수학 점수 : {}'.format(matScore))
print('국어 점수 : {}, 영어 점수 : {}, 수학 점수 : {}'.format(korScore, engScore, matScore))  # 순서가 정해져 있으면 0, 1, 2... 차례대로
print('수학 점수 : {2}, 영어 점수 : {1}, 국어 점수 : {0}'.format(korScore, engScore, matScore))  # 순서를 바꾸고 싶으면 인덱스 설정
sumScore = korScore + engScore + matScore
print('총합 : {}'.format(sumScore))
aveScore = sumScore / 3
print('평균 : {}'.format(round(aveScore, 2)))
print('총합 : {}, 평균 : {}'.format(sumScore, round(aveScore, 2)))
"""

# 참고
"""
print("{}".format(10, 20))
print("{1}".format(10, 20))
"""

#
"""
format_a = "{}만 원".format(5000)
format_b = "파이썬 열공하여 첫 연봉 {}만 원 만들기".format(5000)
format_c = "{} {} {}".format(3000, 4000, 5000)
format_d = "{} {} {}".format(1, "문자열", True)
print(format_a)
print(format_b)
print(format_c)
print(format_d)
"""

'''
var1 = 10; var2 = 20; var3 = 30;

var4 = "var1 : {}, var2 : {}, var3 : {}".format(var1, var2, var3)
print(var4)
'''

'''
# format 참조
output_a = "{:d}".format(52)
print(output_a)
output_b = "{:5d}".format(52)
print(output_b)
output_c = "{:10d}".format(52)
print(output_c)
output_d = "{:05d}".format(52)
print(output_d)
output_e = "{:010d}".format(-52)
print(output_e)
output_f = "{:+d}".format(52)
output_g = "{:+d}".format(-52)
# 등등
'''

