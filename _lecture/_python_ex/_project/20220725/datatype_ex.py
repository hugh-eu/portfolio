# 변수
"""
num = 10  # 변수 선언과 초기화를 동시에 한다. 다른 언어들은 따로 혹은 동시에 함.
print(num)
num = 20.0
print(num)
num = "Hello"  # c, java 등은 자료형에 따른 메모리 할당 때문에 안됨, python은 가능,
print(num)
num = True
print(num)
num1 = 10
num2 = 20
num3 = num1 + num2
print(num1 + num2)
print(num3)
result = num1 == num2
print(num1 == num2)
print(result)
# = : 오른쪽의 값을 왼쪽에 할당한다. 할당연산자
# == : 좌변과 우변이 같다. 수학 등호
# "", " " 다르다
"""

# 변수 서로 교환하기
"""
var1 = 10
var2 = 20
print("var1 =", var1)
print("var2 =", var2)

tempVar1 = var1
var1 = var2
var2 = tempVar1
print("var1 =", var1)
print("var2 =", var2)
"""