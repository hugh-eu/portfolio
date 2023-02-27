### open(), read(), write(), close()
# # file1 = open('D:/hugh_park/python_ex/project/_pycharm_ex/20220810/openTest1.txt', 'w')  # 파일이 없으면 생성, 있으면 불러오기, 'w' 쓰기모드,
# file2 = open('./res/openTest2.txt', 'w')  # 동급, ../ 상위, / 루트
# result = file2.write('Hello python')  # result 텍스트 길이를 확인하기 위해
# # file1.close()
# file2.close()
# print(result)

# file2 = open('./res/openTest2.txt', 'r')
# result = file2.read()
# print(f'result : {result}')

# with open('./res/openTest2.txt', 'r') as file:  # with 클로즈 없이도 쉽게 리드, 클로즈를 안쓰는 실수를 줄이기 위해 쉽게 사용
#     result = file.read()
#     print(result)

# file2 = open('./res/openTest2.txt', 'w')  # 'w' 쓰기모드, 파일이 있으면 덮어씌움, 'w+'
# file2.write('Hello Python')
# file2.close()

# file2 = open('./res/openTest2.txt', 'a')  # 'a' 쓰기모드, 파일이 있으면 덧붙임
# file2.write('\nHello Java')
# file2.close()

# file2 = open('./res/openTest2.txt', 'x')  # 'x' 쓰기모드, 파일이 있으면 에러발생
# file2.write('\nHello Java')
# file2.close()

# file2 = open('./res/openTest2.txt', 'r')  # 'r' 읽기모드, 'r+'
# print(file2.read())
# file2.close()

## 리스트 타입의 데이터를 파일에 쓰기
# list = ['hello python', 'hello c/c++', 'hello java']
# with open('./res/test.txt','a') as f:
#   for i in list:
#         f.write(i)
# with open('./res/test.txt', 'a') as f:
#     f.writelines(list)

## readlines()
# with open('./res/test.txt', 'r') as f:
#     tempList = f.readlines()  # 개행을 기준으로 \n을 포함하여 리스트형태로 읽어옴
#
#     print(f'templist : {tempList}')
#     print(f'templist type : {type(tempList)}')
#
# tempTempList = []
# for s in tempList:
#     tempTempList.append(s.replace('\n', ""))
# tempList = tempTempList
# print(tempList)

## readline(), 한줄씩 읽음, 읽고 다시 읽으면 다음줄로
# with open('./res/test.txt', 'r') as f:
#     line = f.readline()  # str, \n까지 포함
#
#     while line != '':
#         print(line, end='')
#         line = f.readline()

## 가계부, 입출금, 입금액, 출금액, 입금내역, 출금내역, 기존잔액, 입금후잔액, txt에 로그
# import datetime
#
# class Deposit:
#     def __init__(self, a, h):
#         self.name = 'd'
#         self.depositAmount = a
#         self.depositHistory = h
#
# class Withdraw:
#     def __init__(self, a, h):
#         self.name = 'w'
#         self.withdrawAmount = a
#         self.withdrawHistory = h
#
# class AccountBook:
#     def __init__(self, tm):
#         self.totalMoney = tm
#
#     def setTotalMoney(self, c):
#         if c.name == 'd':
#             self.totalMoney += c.depositAmount
#         elif c.name == 'w':
#             self.totalMoney -= c.withdrawAmount
#
#     def getTotalMoney(self):
#         return self.totalMoney
#
#     def setLog(self, c):
#         now = datetime.datetime.now()
#         with open('./res/accountBook.txt', 'a', encoding='UTF-8-sig') as f:
#             if c.name == 'd':
#                 f.write('-' * 30)
#                 f.write('\n' + now.strftime('%Y-%m-%d %H:%M:%S'))
#                 f.write(f'\n[입금]{c.depositHistory} : {c.depositAmount}원')
#                 f.write(f'\n[잔액]{self.totalMoney}원')
#                 f.write('\n')
#             elif c.name == 'w':
#                 f.write('-' * 30)
#                 f.write('\n' + now.strftime('%Y-%m-%d %H:%M:%S'))
#                 f.write(f'\n[출금]{c.withdrawHistory} : {c.withdrawAmount}원')
#                 f.write(f'\n[잔액]{self.totalMoney}원')
#                 f.write('\n')
#
# def app():
#     try:
#         with open('./res/accountBook.txt', 'x', encoding='UTF-8-sig') as f:
#             f.write('[잔액]0원\n')
#             totalMoney = 0
#     except:
#         with open('./res/accountBook.txt', 'r', encoding='UTF-8-sig') as f:
#             line = f.readlines()[-1]
#             line = line.replace('[잔액]', '')
#             line = line.replace('원\n', '')
#             totalMoney = int(line)
#     accountBook = AccountBook(totalMoney)
#     while True:
#         print('아래의 항목을 선택하세요')
#         selectFunc = input('1. 입금\t2. 출금\t3. 종료\n')
#         if selectFunc == '1':
#             print('입금액을 입력하세요.')
#             depositAmount = int(input())
#             print('입금 내역을 입력하세요.')
#             depositHistory = input()
#             deposit = Deposit(depositAmount, depositHistory)
#             print(f'기존 잔액 : {accountBook.getTotalMoney()}')
#             accountBook.setTotalMoney(deposit)
#             print(f'입금 후 잔액 : {accountBook.getTotalMoney()}')
#             accountBook.setLog(deposit)
#             print('입금이 완료되었습니다.')
#         elif selectFunc == '2':
#             print('출금액을 입력하세요.')
#             withdrawAmount = int(input())
#             print('출금 내역을 입력하세요.')
#             withdrawHistory = input()
#             withdraw = Withdraw(withdrawAmount, withdrawHistory)
#             print(f'기존 잔액 : {accountBook.getTotalMoney()}')
#             accountBook.setTotalMoney(withdraw)
#             print(f'출금 후 잔액 : {accountBook.getTotalMoney()}')
#             accountBook.setLog(withdraw)
#             print('출금이 완료되었습니다.')
#         elif selectFunc == '3':
#             break
#
# if __name__ == '__main__':
#     app()
