### 클래스는 객체지향프로그래밍 언어, OOP(object oriented programming)의 꽃,
### 객체를 만들기 위해 클래스 정의, 객체 = 속성 + 기능
# class Grandeur:  # 클래스명 첫글자 대문자
#     def __init__(self, color, weight):  # 속성 정의
#         self.color = color
#         self.weight = weight
#
#     def doDrive(self):  # 기능 정의
#         pass

## 그랜저 객체 만들기, 속성:색상,크기,배기량, 기능:전진,후진,정차,터보,자동차의 정보 출력
# class Grandeur:
# # "__init__", 생성자, 구문에 의해 클래스안에서 객체를 생성 -> 메모리 할당, 속성 초기화
#     def __init__(self, name, color, size, displacement):  # self, 다른언어 this, 선언된 함수들이 Grandeur것, Grandeur 의미
#         print('__init__ called')
#         self.name = name
#         self.color = color
#         self.size = size
#         self.displacement = displacement
#
# # 기능
#     def doForward(self):
#         print('doForward() called')
#
#     def doBackward(self):
#         print('doBackward() called')
#
#     def doStop(self):
#         print('doStop() called')
#
#     def doTurbo(self):
#         print('doTurbo() called')
#
#     def printCarInfo(self):
#         print('printCarInfo() called')
#
# # 객체 생성 in 메모리
# print('0')
# myCar = Grandeur('myCar', 'black', '5m', '3000cc')  # myCar, reference 변수, 객체의 메모리 주소값을 가짐, 속성의 초기값 입력, __new__ -> __init__
# print(myCar)
# myCar.doForward()  # 메소드, method 호출,
# myCar.doBackward()
# myCar.doTurbo()
# myCar.doStop()
# print(myCar.name)  # 속성
# print(myCar.color)
# print(myCar.size)
# print(myCar.displacement)
#
# # 객체의 속성 변경
# myCar.color = 'white'
# myCar.displacement = '5000cc'
# print(myCar.color)
# print(myCar.displacement)

## 연습
# class Person:
#     def __init__(self, name, height, weight):
#         self.name = name
#         self.height = height
#         self.weight = weight
#
#     def doWalk(self):
#         print('터벅터벅')
#
#     def doRun(self):
#         print('후다닥')
#
#     def doEat(self):
#         print('냠냠')
#
#     def doSleep(self):
#         print('쿨쿨')
#
# hugh = Person('hugh', '183', '90')
# print(hugh.name)
# print(hugh.height)
# print(hugh.weight)
# hugh.doWalk()
# hugh.doEat()
# hugh.doRun()
# hugh.doSleep()

## 회원, 회원관리 시스템 클래스,  회원등록 및 삭제 등을 하는 프로그램
## 회원 속성 mId, mPw
## 회원관리 속성 members(dict), 메서드 addMember(), loginMember(), removeMember(), printMembers()
# class Member:
#     def __init__(self, mId, mPw):
#         self.mId = mId
#         self.mPw = mPw
#
# class MemberManager:
#     def __init__(self):
#         ## 접근제한자, public, private
#         self.members = {}  # public
#         self.__foundingDate = '2022.01.01'  # private, MemberManager 내부적으로 사용가능
#
#     def getFoundingDate(self, adminPw):  # getter
#         if adminPw == '1234':
#             return self.__foundingDate  # 내부적으로 값을 참조 가능하기때문에 외부로 값만 리턴하여 확인가능
#         else:
#             return None
#
#     def setFoundingDate(self, adminPw, dt):  # setter
#         if adminPw == '1234':
#             self.__foundingDate = dt
#         else:
#             print('관리자만 설정 가능합니다.')
#
#     def addMember(self, m):
#         #print(f'설립일 : {self.__foundingDate}')
#         if m.mId in self.members:
#             print('중복되는 아이디 입니다.')
#             return
#         self.members[m.mId] = m.mPw
#
#     def loginMember(self, m):
#         isMember = m.mId in self.members
#         if isMember is True:
#             if self.members[m.mId] == m.mPw:
#                 print(f'{m.mId}님 로그인 성공')
#             else:
#                 print('로그인 실패. 비밀번호가 틀립니다.')
#         else:
#             print('가입된 아이디가 없습니다.')
#
#     def removeMember(self, m):
#         isMember = m.mId in self.members
#         if isMember is True:
#             if self.members[m.mId] == m.mPw:
#                 del self.members[m.mId]
#                 print(f'{m.mId}님 회원 삭제 성공')
#             else:
#                 print('아이디 삭제 실패. 비밀번호가 틀립니다.')
#         else:
#             print('가입된 아이디가 없습니다.')
#
#     def printMembers(self):
#         for memberId in self.members.keys():
#             print(f'ID : {memberId}\tPW : {self.members[memberId]}')
#
# def app():
#     # 시스템 객체 생성
#     mm = MemberManager()
#     mm.setFoundingDate(input('adminPw : '), input('설립일 : '))  # 접근제한자 변경, getter와 setter를 적절히 이용해 데이터 보호
#     print(mm.getFoundingDate(input('adminPw : ')))  # 접근제한자 접근
#     while True:
#         selFunc = input('1. 로그인 2. 회원추가 3. 회원삭제 4. 회원목록 0. 종료 ')
#         if selFunc != '1' and selFunc != '2' and selFunc != '3' and selFunc != '4' and selFunc != '0':
#             print('정확하게 선택하세요.')
#             continue
#         if selFunc == '1':
#             # 회원 로그인
#             mm.loginMember(Member(input('ID : '), input('PW : ')))
#         elif selFunc == '2':
#             # 회원추가
#             mm.addMember(Member(input('ID : '), input('PW : ')))
#         elif selFunc == '3':
#             # 회원 삭제
#             mm.removeMember(Member(input('ID : '), input('PW : ')))
#         elif selFunc == '4':
#             # 모든회원 출력
#             mm.printMembers()
#         else:
#             break
#
# if __name__ == '__main__':
#     app()

## 클래스는 상속(inheritance) 가능, 기존의 클래스를 그대로 가져와, 업그레이드 등에 활용
## 부모(parent) 클래스
# class ParentCls1:
#     def __init__(self, n):
#         print('ParentCls1 __init__() called')
#         self.num = n
#
#     def doParentMethod(self):
#         print('[ParentCls1]doParentMethod called')
#
# # class ParentCls2:
# #     def __init__(self, n):
# #         print('ParentCls2 __init__() called')
# #         self.num = n
# #
# #     def doParentMethod(self):
# #         print('[ParentCls2]doParentMethod called')
#
# class ChildCls(ParentCls1):  # 상속, 2개 이상 다중 상속(ParentCls1, ParentCls2), 가능하면 사용안함, 마 자신있으면 써라!
#     def __init__(self):
#         #ParentCls1.__init__(self, 10)  # 자식호출시 부모의 __init__호출이 안되기 때문에 수동 호출
#         super().__init__(10)  # super는 ParentCls를 가리킴, 윗줄보다 세련된 표현
#         print('ChildCls __init__() called')
#         #super().doParentMethod()
#
#     # def doParentMethod(self):
#     #     print('[ChildCls]doParentMethod called')
#
# childCls = ChildCls()
# childCls.doParentMethod()  # 본인 1순위, 다중상속의 경우 먼저 불러온것 2순위 ...
# print(childCls.num)

## 오버라이딩(overriding), 기존의 기능은 두고 자식 클래스에서 같은이름의 메서드로 재정의
# from abc import ABCMeta, abstractmethod  # 일반을 추상화하는 모듈
#
# class ParentRestaurant(metaclass=ABCMeta):  # 추상 클래스 명시
#     def __init__(self):
#         print('ParentsRestaurant __init__ called')
#
#     def makeJj(self):
#         print('ParentsRestaurant makeJj called')
#
#     def makeJb(self):
#         print('ParentsRestaurant makeJb called')
#
#     @abstractmethod  # 추상 메소드 명시
#     def makeTs(self):  # 추상 abstract 메소드, 기능 구현되지 않은 메소드, 사용자(자식)가 반드시 직접 구현해야되는 부분, 구현하지 않으면 상위클래스 사용불가하도록 하는 등의 강제성, 추상 메소드를 포함한 클래스를 추상 클래스
#         print('abstractmethod')
#
# class ChildRestaurant(ParentRestaurant):
#     def __init__(self):
#         super().__init__()
#         print('ChildRestaurant __init__ called')
#
#     def makeBb(self):
#         print('ChildRestaurant makeBb called')
#
#     def makeJj(self, flag):
#         if flag == 'p':
#             super().makeJj()
#         else:
#             print('ChildRestaurant more HOT makeJj called')
#
#     def makeTs(self):
#         print('ChildRestaurant makeTs called')
#
# childRestaurant = ChildRestaurant()
# # 경우에 따라 부모 짜장, 아들 짜장
# childRestaurant.makeJj('p')
# childRestaurant.makeJb()
# childRestaurant.makeBb()
# childRestaurant.makeTs()

## 세명이 주사위 5번씩 굴려서 나온 합을 구하는 프로그램, 주사위 클래스
# import _diceGame as dg
#
# def app():
#     numberOfDicesplane = int(input('주사위 면의 수 : '))
#     numberOfPlayers = int(input('플레이어의 수 : '))
#     numberOfThrows = int(input('던지는 횟수 : '))
#     diceGame = dg.PlayDiceGame(numberOfDicesplane, numberOfPlayers, numberOfThrows)
#     diceGame.rollDice()
#     diceGame.printResult()
#
# if __name__ == '__main__':
#     app()


## 음료수 자판기
## 자판기, 음료수 종류, 돈관리, 음료수 넣고 빼기, 2대 만들기
# from bendingMachine import _bendingMachine as bm
#
# def checkGoodsCount(machineName, machineObject):
#     for g in machineObject.goods:
#         print(f'{machineName} goods name : {g.getName()}')
#     print(f'{machineName} goods count : {len(machineObject.goods)}')
#     print(f'{machineName} total money : {machineObject.getTotalMoney()}')
#
#
# def app():
#     bendingMachine1 = bm.BendingMachine(10000)
#     bendingMachine2 = bm.BendingMachine(20000)
#
#     # print(bendingMachine1)
#     # print(bendingMachine2)
#
#     # 음료 추가
#     bendingMachine1.addGoods(bm.Goods('Cola', 200))
#     bendingMachine1.addGoods(bm.Goods('Cola', 200))
#     bendingMachine1.addGoods(bm.Goods('Cola', 200))
#     bendingMachine1.addGoods(bm.Goods('Cider', 300))
#     bendingMachine1.addGoods(bm.Goods('Cider', 300))
#     bendingMachine1.addGoods(bm.Goods('Fanta', 400))
#     checkGoodsCount('bendingMachine1', bendingMachine1)
#
#     bendingMachine2.addGoods(bm.Goods('ColaZ', 250))
#     bendingMachine2.addGoods(bm.Goods('ColaZ', 250))
#     bendingMachine2.addGoods(bm.Goods('CiderZ', 350))
#     bendingMachine2.addGoods(bm.Goods('CiderZ', 350))
#     bendingMachine2.addGoods(bm.Goods('CiderZ', 350))
#     bendingMachine2.addGoods(bm.Goods('FantaZ', 450))
#     bendingMachine2.addGoods(bm.Goods('FantaZ', 450))
#     bendingMachine2.addGoods(bm.Goods('FantaZ', 450))
#     bendingMachine2.addGoods(bm.Goods('FantaZ', 450))
#     checkGoodsCount('bendingMachine2', bendingMachine2)
#
#     # 손님이 음료 구매
#     bendingMachine1.removeGoods()
#     checkGoodsCount('bendingMachine1', bendingMachine1)
#
#     bendingMachine2.removeGoods()
#     checkGoodsCount('bendingMachine2', bendingMachine2)
#
# if __name__ == '__main__':
#     app()
