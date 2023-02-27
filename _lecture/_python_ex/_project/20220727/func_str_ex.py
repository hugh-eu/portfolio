## 참고
# 행삭제 : ctrl + y
# 행복제 : ctrl + d
# 주석처리 : ctrl + /

## 문자열관련 함수
# upper(), lower() 대소문자 변경
'''
a = "Hello Python Programming...!"
print(a.upper())
print(a.lower())
'''

# strip(), lstrip(), rstrip()
"""
a = '''
    안녕하세요
문자열 함수
'''
print(a)
print(a.strip())

b = '''
  왼쪽
오른쪽           


'''
print(b.lstrip())
print(b.rstrip())
"""

# 문자열구성확인 is...
'''
isalnum()
isalpha()
isidentifier()
isdecimal()
isdigit()
isspace()
islower()
isupper()
# 참고하고 필요하면 검색하여 사용
'''
'''
print("TrainA10".isalnum())
print("10".isdigit())
'''

# 문자열 찾기 find()//왼쪽부터, rfind()//오른쪽부터
'''
str = "안녕안녕하세요"
print(str.find("안녕"))
print(str.rfind("안녕"))
'''

# in 연산자
'''
print("안녕" in "안녕하세요")
print("잘자" in "안녕하세요")
'''

# split()
'''
str = 'ident@host.com'
splitStr = str.split("@")
print(splitStr)
print(splitStr[0], splitStr[1])
'''
'''
a = "10 20 30 40 50 60 70 80 90 100"
splitA = a.split(" ")
print(splitA)
'''