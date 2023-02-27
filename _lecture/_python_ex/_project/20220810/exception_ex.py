### 예외처리, exception,
### 많은 경험과 테스트를 통해 예외가 발생할 상황 찾기
### 전체 예외처리는 가능하면 하지 않도록, 시스템 부하 커짐
# n1 = input('n1 ')
# n2 = input('n2 ')
#
# def add(n1, n2):
#     try:
#         print(f'{n1} + {n2} = {int(n1) + int(n2)}')
#     except ValueError as e:  # except는 복수 사용 가능
#         print('예외 발생')  # 예외 발생시 실행코드, 필수
#         print(f'e : {e}')
#
# def sub(n1, n2):
#     try:
#         print(f'{n1} - {n2} = {int(n1) - int(n2)}')
#     except ValueError as e:  # except는 복수 사용 가능
#         print('예외 발생')  # 예외 발생시 실행코드, 필수
#         print(f'e : {e}')
#
# def mul(n1, n2):
#     try:
#         print(f'{n1} * {n2} = {int(n1) * int(n2)}')
#     except ValueError as e:  # except는 복수 사용 가능
#         print('예외 발생')  # 예외 발생시 실행코드, 필수
#         print(f'e : {e}')
#
# def div(n1, n2):
#     # flag = False
#     try:
#         print(f'{n1} / {n2} = {int(n1) / int(n2)}')  # 예외 발생 가능성 있는 코드, 필수
#         # flag = True  # 다른 언어 else가 없을때 사용
#     # Exception 클래스, 에러관리, 발생하는 에러 확인
#     except Exception as e:  # 초급자는 Exception사용, 경험이 많아 질수록 세분화
#         print('예외 발생')  # 예외 발생시 실행코드, 필수
#         print(f'e : {e}')
#         # flag = False
#     except ZeroDivisionError as e:
#         print('예외 발생')  # 예외 발생시 실행코드, 필수
#         print(f'e : {e}')
#         # flag = False
#     except ValueError as e:  # except는 복수 사용 가능
#         print('예외 발생')  # 예외 발생시 실행코드, 필수
#         print(f'e : {e}')
#         # flag = False
#     else:
#         print('예외 발생하지 않음')  # 예외 미발생시 실행코드, 옵션
#     # if flag is True:
#     #     pass
#     finally:
#         print('항상 실행')  # 예외 발생 여부와 상관없이 실행, 옵션
#
# add(n1, n2)
# sub(n1, n2)
# mul(n1, n2)
# div(n1, n2)

## 예외 클래스 커스텀
# class NotUsefulNumberException(Exception):
#     def __init__(self, data1, data2):
#         super().__init__(f'사용할 수 없는 데이터 : {data1, data2}')
#
# def calculator(f, s):
#     print(f'덧셈 연산 결과 : {f + s}')
#     if s != 0:
#         print(f'나눗셈 연산 결과 : {f / s}')  # 예외 발생 가능, try, except 발생시 메모리에 Exception 객체 생성
#     else:
#         raise NotUsefulNumberException(f, s)  # NotUsefulNumberException 객체 만들기 명령
#
# if __name__ == '__main__':
#     firstNum = int(input('첫번째 정수를 입력하세요. '))
#     secondNum = int(input('두번째 정수를 입력하세요. '))
#     try:
#         calculator(firstNum, secondNum)
#     except Exception as e:  # NotUsefulNumberException 상위 클래스이기때문에 사용가능
#         print(f'Error : {e}')
