#### 자료구조, list, tuple, dictionary, 컨테이너 자료형
### list
## [], 선형 나열, 데이터 변경 가능
# fruits = ['사과', '딸기', '수박', '바나나', '복숭아', '자두']  # 리스트 변수에 사과의 메모리주소 저장
# print(fruits)
# print(type(fruits))
# print(fruits[0])
# print(type(fruits[0]))

# listEx = ['사과', 2, '수박', 3.14, '복숭아', [2, ['h', 'e', 'l', 'l', 'o'], 4.123, "테스트"]]
# print(listEx[5][1][0])
# print(listEx[7])  # 인덱스 범위 에러
# print(len(listEx))
# print(len(listEx) - 1)  # 마지막 인덱스

# balls = ['야구공', '축구공', '배구공', '농구공', '골프공', '탁구공']
# for idx, ball in enumerate(balls):  # enumerate() 인덱스와 인덱스에 해당하는 값을 반환 (idx, data)
#     print(idx, ball)

# i = 0
# while i < len(balls):
#     print(balls[i])
#     i += 1

# sports = ['baseball', 'basketball', 'tennis', 'golf', 'soccer']
# print(sports[len(sports)-1])

# languages = ['c/c++', 'c#', 'python', 'java', 'python']
# # print(languages.index('python'))
# idxPython = []
# for idx, language in enumerate(languages):
#     if language == 'python':
#         idxPython.append(idx)
# print(idxPython)

## 리스트 아이템 추가하기
# sports = ['football', 'baseball', 'volleyball']

# sports.append('basketball')
# print(sports)

# tempSports = []
# for idx, item in enumerate(sports):
#     if idx == 1:
#         tempSports.append("basketball")
#     tempSports.append(item)
# sports = tempSports
# print(sports)

# sports.insert(1, 'basketball')
# print(sports)

## 누락 숫자 추가, 1 -10
# numbers = [1, 2, 3, 4, 5, 7, 8, 9]

# print('numbers : ', numbers)
# numbers.insert(5, 6)
# numbers.append(10)
# print('numbers : ', numbers)

# for idx, item in enumerate(numbers):
#     if idx + 1 != item:
#         numbers.insert(idx, (idx + 1))
# numbers.append(10)
# print(numbers)

## 리스트를 확장하는 방법
# list1 = [1, 2, 3, 4]
# list2 = [5, 6, 7, 8]
# list1.extend(list2)
# print(list1)
# list1 = [1, 2, 3, 4]
# list2 = [5, 6, 7, 8]
# list1 = list1 + list2
# print(list1)
# print(list1 * 3)

## 변경
# list1 = [1, 2, 3, 4, 5, 6, 7]
# list1[0] = '하나'
# print(list1)
# list1[1:3] = ['둘', '셋']
# print(list1)
# list1[5:7] = ['여섯', '일곱', '여덟']
# print(list1)

## 리스트에서 아이템을 삭제
# sports = ['football', 'baseball', 'volleyball']
# sports.pop()  # 마지막 아이템 제거
## delVal = sports.pop()  # 제거된 데이터 반환
# print(sports)
# sports.pop(1)  # 제거하고 싶은 인덱스
# print(sports)
# del sports[1]
# print(sports)
# del sports[1:3]
# print(sports)
# sports.remove('baseball')
# print(sports)
# sports.clear()  # 모두 제거
# print(sports)

# min(), max(), sum()

# join()

# toDoList = ['cleaning', 'shopping', 'TOEIC study', 'exercise']
# print('오늘 할 일 : ', toDoList)
# for i in range(len(toDoList)):
#     print('끝난 일 : ', toDoList.pop(0))
#     if len(toDoList) != 0:
#         print('남은 일 : ', toDoList)
#     else:
#         print("오늘 할 일 끝")

# languages = ['java', 'java', 'c/c++', 'c#', 'java', 'python', 'java', 'java']
# tempLanguages = languages.copy()
# for language in tempLanguages:
#     if language == 'java':
#         languages.remove('java')
# print(languages)

# languages = ['java', 'java', 'c/c++', 'c#', 'java']
# while True:
#     if languages.count('java') > 0:
#         languages.remove('java')
#     else:
#         break
# print(languages)

## 홍길동, 2020 공인중개사 시험성적, 합격기준 만족 구하는 프로그램
## 매과목 100점 만점, 40점 이상
## 평균 60점 이상
# scores = [55, 35, 40, 70, 65, 30]
# sumScore = 0
# chkEach = 0
# for idx, score in enumerate(scores):
#     sumScore += score
#     if score < 40:
#         print('불합격')
#         break
#     if idx == (len(scores) - 1):
#         aveScore = sumScore / len(scores)
#         if aveScore >= 60:
#             print('합격')
#         else:
#             print('불합격')

## 리스트 정렬
# numbers = [4, 1, 5, 2, 3, 6]
# numbers.reverse()  # 역순
# print(numbers)
# numbers.sort()  # 오름차순 정렬, reverse=False
# print(numbers)
# numbers.sort(reverse=True)  # 내림차순 정렬
# print(numbers)
# numbers.reverse()
# print(numbers)

## 어떤학생의 성적, 가장 높은 점수와 낮은 점수 출력
# scores = [72, 80, 90, 55, 90, 81, 67, 55]
# scores.sort()
# lowestScores = []
# highestScores = []
# for score in scores:
#     if score == scores[0]:
#         lowestScores.append(score)
#     elif score == scores[len(scores) - 1]:
#         highestScores.append(score)
# print('가장 높은 점수 {}, 가장 낮은 점수 {}'.format(highestScores, lowestScores))

# names = ['홍길동', '김길동', '이길동', '박길동', '정길동']
# names.sort(reverse=True)
# print(names)

## 리스트 슬라이싱
# animals = ['호랑이', '사자', '곰', '여우', '늑대']
# print(animals[1:4])
# print(animals)
# sliceAnimals = animals[1:4]
# print(sliceAnimals)
# print(animals[0:5:2])  # 시작:끝:단계

# alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
# alphabet.reverse()
# print(alphabet)
# print(alphabet[2:6])
# print(alphabet[:5])
# print(alphabet[3:8])
# print(alphabet[5:])
# print(alphabet[3:9])

## 출석부 관리 시스템, 리스트 이용 학급의 학생명단 관리,
## 학급학생수 10명, 가나다순 정렬, 박찬호 제거후 전체 학생과 학생수 출력, 선생님을 돕기위한 학생 앞에서 3명,
## 이병규 전학, 자리바꾸기 역순, 정우람이 정잘남 개명
# studentList = ['정우람', '박으뜸', '배힘찬', '천영웅', '신석기', '배민규', '전민수', '박건우', '박찬호', '이승엽']
# studentList.sort()
# print('가나다순 :', studentList)
# studentList.remove('박찬호')
# print('찬호 전학간 후 전체 학생 {}, 학생수 {}'.format(studentList, len(studentList)))
# print('선생님 도울 학생 : {}'.format(studentList[:3]))
# studentList.append('이병규')
# print('이병규 전학옴 :', studentList)
# studentList.sort(reverse=True)
# print('역순으로 자리바꾸기 :', studentList)
# tempStudentList = studentList.copy()
# for idx, student in enumerate(tempStudentList):
#     if student == '정우람':
#         studentList.remove('정우람')
#         studentList.insert(idx, '정찰남')
#         break
# print('정우람이 정찰남으로 개명 :', studentList)

## 헌혈 10명의 기부자, 혈액 리스트 보관, 혈액형 종류별로 몇팩씩 보유하는지 보여주는 프로그램
# bloodTypes = []
# while True:
#     print('헌혈해 주셔서 감사합니다. 혈액형을 선택하세요')
#     inputBlood = input('A, B, AB, O : ').upper()
#     while (inputBlood != 'A') and (inputBlood != 'B') and (inputBlood != 'AB') and (inputBlood != 'O'):
#         print('정확한 혈액형을 입력하세요')
#         inputBlood = input('A, B, AB, O : ').upper()
#     bloodTypes.append(inputBlood)
#     if len(bloodTypes) == 10:
#         break
# print("-" * 30)
# print('혈액 : {}팩'.format(len(bloodTypes)))
# print("-" * 30)
# print('''\
# A형  : {}팩
# B형  : {}팩
# AB형 : {}팩
# O형  : {}팩
# '''.format(bloodTypes.count('A'), bloodTypes.count('B'), bloodTypes.count('AB'), bloodTypes.count('O')), end="")
# print("-" * 30)

### tuple
## (), 선형 나열, 데이터 변경 불가
## 리스트하고 같지만 최초 초기화된 데이터(아이템) 수정, 추가, 삭제 불가, 사용 예, 월급, 설립일, 공휴일, 혈액형 종류 등등
# fruits = ('사과', '배', (1, 2.4), [1, '딸기'])
# print(type(fruits))
# for fruit in fruits:
#     print(fruit)

## 데이터 조회
# fruits = ('사과', '포도', '수박', '참외', '배', '자두', '복숭아', '바나나')
# print(fruits[0])
# # print(fruits[100])  #범위 오류
# print(fruits[len(fruits) - 1])

## sports 튜플에서 인덱스 홀수인 아이템 출력
# sports = ('태권도', '야구', '농구', '축구', '배구', '권투', '양궁')
# for idx, item in enumerate(sports):
#     if idx % 2 == 1:
#         print(idx, item)

# fruits = ('사과', '포도', '수박', '참외', '배', '자두', '복숭아', '바나나')
# print(fruits.index('수박'))

## 선수입력하면 이름에 해당하는 인덱스
# names = ('박찬호', '이승엽', '박세리', '박지성', '이순철', '선동열', '손흥민', '김연아')
# inputName = input('선수이름 입력 : ')
# while inputName not in names:
#     print('리스트에 없습니다.')
#     inputName = input('선수이름 입력 : ')
# print('이름 : {}, 해당 인덱스 : {}'.format(inputName, names.index(inputName)))

## in, not in
# colors = ('red', 'orange', 'yellow', 'black', 'green', 'blue')
# print('yellow' in colors)
# print('white' in colors)
# print('white' not in colors)

## scores는 1학기 성적 튜플 , F학점이 있으,면 경고
# scores = ('a', 'A+', 'B', 'B-', 'F')
# if 'F' in scores:
#     print('경고')
# print('F {}개'.format(scores.count('F')))

## count(), 특정 아이템의 개수 파악
# students = ('박찬호', '홍길동', '박지성', '손흥민', '박세리', '홍길동')
# print(students.count('홍길동'))
# print(students.count('박찬호'))
# print(students.count('김연아'))

## 튜플 결합(+), 리스트와 다르게 extend() 샤용 불가, 데이터 변경 불가하기 때문
# tuple1 = (1, 2, 3)
# tuple2 = (4, 5, 6)
# print(tuple1 + tuple2)
# tuple3 = tuple1 + tuple2
# print(tuple3)

## 튜플 슬라이싱
# students = ('박찬호', '홍길동', '박지성', '손흥민', '박세리', '홍길동')
# print(students[:3])
# print(students[3:])
# print(students[3:4])
# print(students[::2])
# print(students[-2:])
# print(students[len(students) - 2:])
# print(students[-5:-2])

## fruits 튜플 , 2-4, 0-3, 3부터끝 슬라이싱
# fruits = ('apple', 'banana', 'plum', 'watermelon', 'peach')
# print(fruits[2:5])
# print(fruits[:4])
# print(fruits[3:])

## 튜플 데이터를 변경할 수도 있어야 한다.(리스트 <-> 튜플)
# colors = ('red', 'yellow', 'black', 'white', 'indigo_blue', 'sky_blue')
# print(type(colors))
# colors = list(colors)
# print(type(colors))
# colors[0] = 'pink'
# print(colors)
# colors = tuple(colors)
# print(colors)
# print(type(colors))

## 아이템하나인 튜플 선언
# nums1 = [1]
# print(type(nums1))
# nums2 = (1)
# print(type(nums2))
# nums3 = (1,)
# print(type(nums3))

## 아이템 정렬
# colors = ('red', 'yellow', 'black', 'white', 'indigo_blue', 'sky_blue')
# print(colors)
# print(type(colors))
# colors = sorted(colors)
# print(colors)
# print(type(colors))

# colors = ('red', 'yellow', 'black', 'white', 'indigo_blue', 'sky_blue')
# cs = sorted(colors)
# cs.sort(reverse=True)
# print(cs)
# cs.sort(reverse=False)
# print(cs)

### dictionary
## {}, 키값과 벨류값이 쌍을 이룸
## 키값은 보통 숫자와 문자, but 모든 데이터들로 키와 벨류 만들수 있음, 키 중복 불가
# ages = {'박찬호':52, '박세리':51, '박지성':45, '홍길동':1}
# print(ages)
# print(type(ages))
# print(ages['박찬호'])

# names = {1:'박찬호', 2:'박세리', 3:None, '사':['홍', '홍홍']}
# print(names)
# print(names['사'])
# myData = {'이름':'name', '나이':'943599147579139123875', '주소':'지구', '취미':['스포츠', '멍'], '성별':'남'}
# testScores = {'c/c++':'A', 'Java':'B+', '네트워킹':'C', '보안':'A+', '해킹':'F', '시스템':'C+'}

## 조회
# dictContainer = {'이름':'name', '나이':'943599147579139123875', '주소':'지구', '취미':['스포츠', '멍']}
# print(dictContainer['주소'])
# print(dictContainer['취미'])
# print(len(dictContainer['취미']))
# dictContainer['취미'].append('코딩')
# print(dictContainer['취미'])
# # print(dictContainer['성별']) # 에러
# print(len(dictContainer))
## get(), 존재하지 않는 키에 접근할때 에러대신 None 반환
# print(dictContainer.get('이름'))
# print(dictContainer.get('성별'))

## 데이터 수정
# dictContainer = {'이름':'name', '나이':943599147579139123875, '주소':'지구', '취미':['스포츠', '멍']}
# dictContainer['혈액형'] = 'ABO'  # 추가
# print(dictContainer)
# dictContainer['나이'] = 99  # 변경
# print(dictContainer)
# del dictContainer['나이']  # 삭제
# print(dictContainer)

## 딕셔너리에서 모든 키값 모든 벨류값 구하는 방법
# dictContainer = {'이름':'name', '나이':943599147579139123875, '주소':'지구', '취미':['스포츠', '멍']}
# print(dictContainer.keys())
# print(type(dictContainer.keys()))
# print(dictContainer.values())
# print(type(dictContainer.values()))

# keys = dictContainer.keys()
# for key in keys:
#     print(key)
# for idx, key in enumerate(keys):
#     print(idx, key)

# for key in dictContainer:  # 딕셔너리를 for 사용시 키값
#     print(key)

# values = dictContainer.values()
# for value in values:
#     print(value)
# for idx, value in enumerate(values):
#     print(idx, value)

# for key in dictContainer.keys():
#     print(key, dictContainer[key])

## 중간고사 성적관리, c/c++ a, java b+, 모바일 c,  보안, a+, 해킹 f, 시스템 c+ 딕셔너리,
## Java, 시스템 성적 조회, 파이썬 a os a+ 삽입, java f, 시스템 a수정, 전체 과목과 성적 조회 최종성적표 출력
# testScores = {'C/C++':'A', 'Java':'B+', '모바일':'C', '보안':'A+', '해킹':'F', '시스템':'C+'}
# print('Java 성적 : {}, 시스템 성적 : {}'.format(testScores['Java'], testScores['시스템']))
# testScores['파이썬'] = 'A'
# testScores['OS'] = 'A+'
# testScores['Java'] = 'F'
# testScores['시스템'] = 'A'
# print('성적표'.center(20))
# print(f' 과목     성적 ')
# for key in testScores.keys():
#     print(f'{key:10s}{testScores[key]:10s}')

## 수학시험 문제 및 정답, 튜플에 문제 저장, 사용자가 답을 입력하면 채점
# mathQuestion = (('3+2', '5', 3), ('5%2의 몫', '2', 5), ('10-2', '8', 3), ('10^2 X 2', '200', 5), ('1-(10%4의 나머지)', '-1', 5), ('2^4', '16', 3), ('4/2', '2', 3))
# correctAnswer = 0
# wrongAnswer = 0
# totalScore = 0
# for question in mathQuestion:
#     print('문제 : {}'.format(question[0]))
#     answer = input('정답을 입력하세요. ')
#     if question[1] == answer:
#         correctAnswer += 1
#         totalScore += question[2]
#     else:
#         wrongAnswer += 1
# print('-' * 30)
# print('''\
# 정답 개수 : {}
# 오답 개수 : {}
# Total Score : {}'''.format(correctAnswer, wrongAnswer, totalScore))
# print('-' * 30)

## 다음 네단계를 따라 회원가입프로그램 만들기,
## 회원가입 프로그램 종료 선택 출력,1 입력시 회원가입, 2입력 종료,
## 종료시 전체 아이디 비밀번호 출력, 회원가입 아이디 비밀번호 입력 딕셔너리 저장, 회원가입 끝나면 1단계
# memberLists = {}
# selction = input('1. 회원가입, 2. 프로그램 종료  ')
# while (selction != '1') and (selction != '2'):
#     print('1 또는 2를 입력하세요.')
#     selction = input('1. 회원가입, 2. 프로그램 종료  ')
# while selction == '1':
#     usrId = input('아이디를 입력하세요.   ')
#     if usrId in memberLists.keys():
#         print('중복되는 아이디 입니다.')
#         continue
#     usrPw = input('비밀번호를 입력하세요. ')
#     memberLists[usrId] = usrPw
#     selction = input('1. 회원가입, 2. 프로그램 종료  ')
#     while (selction != '1') and (selction != '2'):
#         print('1 또는 2를 입력하세요.')
#         selction = input('1. 회원가입, 2. 프로그램 종료  ')
# print('-' * 30)
# print('아이디 : 비밀번호')
# print('-' * 30)
# for key in memberLists.keys():
#     print('{} : {}'.format(key, memberLists[key]))

# numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# output = [[], [], []]
# for number in numbers:
#     output[number % 3 - 1].append(number)
# print(output)
# for i in range(0, len(numbers) // 2):
#     j = 2 * i + 1
#     print(f'i = {i}, j = {j}')
#     numbers[j] = numbers[j] ** 2
# print(numbers)

# pets = [{'name':'구름', 'age':5}, {'name':'초코', 'age':3}, {'name':'아지', 'age':1}, {'name':'호랑이', 'age':1}]
# print('# 우리 동네 애완 동물들')
# for pet in pets:
#     print(f'{pet["name"]}\t{pet["age"]}살')

# numbers = [1, 4, 3, 4, 6, 8, 4, 7, 3, 9, 6, 4, 3, 2, 5, 6, 8, 9, 1, 1]
# counter = {}
# for number in numbers:
#     if number in counter.keys():
#         counter[number] += 1
#     else:
#         counter[number] = 1
# print(counter)

# character = {
#     'name':'기사',
#     'level':12,
#     'items':{
#         'sword':'불꽃의 검',
#         'armor':'풀플레이트'
#     },
#     'skill':['베기', '세게 베기', '아주 세게 베기']}
# for key in character:
#     if (type(character[key]) is str) or (type(character[key]) is int) or (type(character[key]) is float):
#         print(f'{key} : {character[key]}')
#     elif type(character[key]) is list:
#         for item in character[key]:
#             print(f'{key} : {item}')
#     elif type(character[key]) is dict:
#         for item in character[key]:
#             print(f'{item} : {character[key][item]}')

# key_list = ['name', 'hp', 'mp', 'level']
# value_list = ['기사', 200, 30, 5]
# character = {}
# for idx, key in enumerate(key_list):
#     character[key] = value_list[idx]
# print(character)

# limit = 10000
# i = 1
# sum_value = 0
# while True:
#     sum_value += i
#     if sum_value >= 10000:
#         break
#     i += 1
# print(f'{i}를 더할 때 10000을 넘으며 그때의 값은 {sum_value}입니다.')

# max_value = 0
# a = 0
# b = 0
# for i in range(1, 100):
#     j = 100 - i
#     if i * j > a * b:
#         a = i
#         b = j
#         max_value = i * j
# print(f'최대가 되는 경우: {a} * {b} = {max_value}')

# numList = [1, 2, 3, 4, 1, 2, 3, 1, 4, 1, 2, 3]
# cntNum = {}
# for i in numList:
#     if i in cntNum.keys():
#         cntNum[i] += 1
#     else:
#         cntNum[i] = 1
# print('''\
# {}에서
# 사용된 숫자의 종류는 {}개입니다.
# 참고: {}'''.format(numList, len(cntNum), cntNum))

# dna = input('염기 서열을 입력해 주세요: ')
# a = 0
# t = 0
# g = 0
# c = 0
# for i in dna:
#     if i == 'a':
#         a += 1
#     elif i == 't':
#         t += 1
#     elif i == 'g':
#         g += 1
#     elif i == 'c':
#         c += 1
# print(a, t, g, c)

# dna = input('염기 서열을 입력해 주세요: ')
# codonCnt = {}
# for i in range(0, len(dna) - 1, 3):
#     key = dna[i:i+3]
#     if len(key) == 3:
#         if key not in codonCnt.keys():
#             codonCnt[key] = 1
#         else:
#             codonCnt[key] += 1
# print(codonCnt)

# nums = ['a', 'k', ['i', 's'], 'a', ['d', 'b'], ['s', 'k']]
# tempNums = nums.copy()
# k = 0
# for idx, num in enumerate(tempNums):
#     if type(num) == list:
#         nums.remove(num)
#         for n in num:
#             nums.insert(idx + k, n)
#             if 1 < len(num):
#                 k += 1
# tempNums = []
# for num in nums:
#     if type(num) == list:
#         tempNums += num
#     else:
#         tempNums.append(num)
# nums = tempNums
# print(nums)
# print(nums)




### 파이썬은 numpy(선형), pandas(매트릭스)와 함께 사용하는 경우가 많음
