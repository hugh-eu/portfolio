#### AI 머신러닝, 딥러닝
### numpy : 수치, 행렬
### pandas : 매트릭스 데이터셋
### matplot : 시각화

#### numpy, C --> python, 속도빠름
import numpy as np  # 대부분의 개발자들이 np로 사용

### python list, numpy보다 느림
# nums1 = [1, 2, 3, 4, 5, 6]
# nums2 = [1.0, 2.0, 3.0, 4.0, 5.0]
# print(f"nums1 : {nums1}\nnums2 : {nums2}\n")

#### np array 정의
### 1차원
# np_array_1 = np.array(nums1)
# np_array_2 = np.array(nums2)
# print(f"np_array_1 : {np_array_1}\nnp_array_2 : {np_array_2}\n")
## np 크기(모양)
# print(f"np_array_1.shape : {np_array_1.shape}\nnp_array_2.shape : {np_array_2.shape}\n")  # (6,) 6개인 1차원 배열
## np type(요소 타입)
# print(f"np_array_1.dtype : {np_array_1.dtype}\nnp_array_2.dtype : {np_array_2.dtype}\n")  # type 출력, 요소들의 타입

### 2차원
# np_array_3 = np.array([[1, 2, 3, 4, 5], [10, 20, 30, 40, 50], [100, 200, 300, 400, 500]])
# print(f"np_array_3 :\n{np_array_3}")
# print(f"np_array_3.shape : {np_array_3.shape}")
# print(f"np_array_3.dtype : {np_array_3.dtype}")

### 3차원
# np_array_4 = np.array([[[1, 2, 3], [10, 20, 30], [100, 200, 300]], [[11, 22, 33], [110, 220, 330], [1100, 2200, 3300]]])
# print(f"np_array_4 :\n{np_array_4}")
# print(f"np_array_4.shape : {np_array_4.shape}")
# print(f"np_array_4.dtype : {np_array_4.dtype}")

#### np 정의 함수, np.zeros(), np.ones(), np.arange(), np.reshape(), np.astype()
### 1차원
## np.zeros() : 0.0을 이용한 np array 생성
# np_zeros_1 = np.zeros(5)
# print(f"np_zeros_1 :  {np_zeros_1}")
# print(f"np_zeros_1.shape :  {np_zeros_1.shape}")
# print(f"np_zeros_1.dtype :  {np_zeros_1.dtype}")## np.zeros() : 0.0을 이용한 np array 생성
## np.ones() : 1.0을 이용한 np array 생성
# np_ones_1 = np.ones(5)
# print(f"np_ones_1 :  {np_ones_1}")
# print(f"np_ones_1.shape :  {np_ones_1.shape}")
# print(f"np_ones_1.dtype :  {np_ones_1.dtype}")
## np.arange(), 1씩 증가하는 1차원 배열, 1차원만
# np_arange_1 = np.arange(5)  # 0에서 4까지, range 비슷
# print(f"np_arange_1 : {np_arange_1}")
# print(f"np_arange_1.shape : {np_arange_1.shape}")
# print(f"np_arange_1.dtype : {np_arange_1.dtype}")
# np_arange_1 = np.arange(2, 10, 2)  # (시작, 끝+1, 스탭)
# print(f"np_arange_1 : {np_arange_1}")
# print(f"np_arange_1.shape : {np_arange_1.shape}")
# print(f"np_arange_1.dtype : {np_arange_1.dtype}")

### 2차원
# np_zeros_2 = np.zeros((5, 3))  # 튜플로
# print(f"np_zeros_2 : {np_zeros_2}")
# print(f"np_zeros_2.shape : {np_zeros_2.shape}")
# print(f"np_zeros_2.dtype : {np_zeros_2.dtype}")
# np_ones_2 = np.ones((5, 3))
# print(f"np_ones_2 : {np_ones_2}")
# print(f"np_ones_2.shape : {np_ones_2.shape}")
# print(f"np_ones_2.dtype : {np_ones_2.dtype}")

### 3차원
# np_zeros_3 = np.zeros((2, 5, 3))
# print(f"np_zeros_3 : {np_zeros_3}")
# print(f"np_zeros_3.shape : {np_zeros_3.shape}")
# print(f"np_zeros_3.dtype : {np_zeros_3.dtype}")
# np_ones_3 = np.ones((2, 5, 3))
# print(f"np_ones_3 : {np_ones_3}")
# print(f"np_ones_3.shape : {np_ones_3.shape}")
# print(f"np_ones_3.dtype : {np_ones_3.dtype}")

### reshape
# np_arange_1 = np.arange(12)
# print(f"np_array_1 :\n{np_arange_1}")
# np_arange_2 = np.reshape(np_arange_1, (3, 4))
# print(f"np_arange_2 :\n{np_arange_2}")
# np_arange_3 = np.reshape(np_arange_1, (2,2,3))
# print(f"np_arange_3 :\n{np_arange_3}")
# np_arange_4 = np.reshape(np_arange_1, (-1, 1))
# print(f"np_arange_4 :\n{np_arange_4}")

### 형변환, astype
# np_arange_1 = np.arange(10)
# print(f"np_arange_1 : {np_arange_1}")
# print(f"np_arange_1.dtype : {np_arange_1.dtype}")
# np_arange_2 = np_arange_1.astype("float64")
# print(f"np_arange_2 : {np_arange_2}")
# print(f"np_arange_2.dtype : {np_arange_2.dtype}")


#### np 기본연산 (+, -, *, /, %, //, **), 기본적으로 크기 모양 동일해야함
# np_array_1 = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]])
# np_array_2 = np.array([[10, 9, 8, 7, 6], [5, 4, 3, 2, 1]])
# print(f"np_array_1 :\n{np_array_1}\nnp_array_2 :\n{np_array_2}")
# print(f"np_array_1 + np_array_2 :\n{np_array_1 + np_array_2}")
# print(f"np_array_1 - np_array_2 :\n{np_array_1 - np_array_2}")
# print(f"np_array_1 * np_array_2 :\n{np_array_1 * np_array_2}")
# print(f"np_array_1 / np_array_2 :\n{np_array_1 / np_array_2}")
# print(f"np_array_1 % np_array_2 :\n{np_array_1 % np_array_2}")
# print(f"np_array_1 // np_array_2 :\n{np_array_1 // np_array_2}")
# print(f"np_array_1 ** np_array_2 :\n{np_array_1 ** np_array_2}")

### 모양 다른 것들의 연산, 브로드캐스트
# np_array_1 = np.array([[1, 2, 3, 4, 5]])  # (1, 5), [[1, 2, 3, 4, 5], [1, 2, 3, 4, 5]]로 브로드 캐스팅
# np_array_2 = np.array([[10, 9, 8, 7, 6], [5, 4, 3, 2, 1]])  # (2, 5)
# print(f"np_array_1 + np_array_2 :\n{np_array_1 + np_array_2}")
# print(f"np_array_1 - np_array_2 :\n{np_array_1 - np_array_2}")
# print(f"np_array_1 * np_array_2 :\n{np_array_1 * np_array_2}")
# print(f"np_array_1 / np_array_2 :\n{np_array_1 / np_array_2}")
# print(f"np_array_1 % np_array_2 :\n{np_array_1 % np_array_2}")
# print(f"np_array_1 // np_array_2 :\n{np_array_1 // np_array_2}")
# print(f"np_array_1 ** np_array_2 :\n{np_array_1 ** np_array_2}")

### np array 전체에 동일한 데이터 연산
# np_array_1 = np.array([1, 2, 3, 4, 5])
# print(f"np_array_1 + 10 : {np_array_1 + 10}")
# print(f"np_array_1 - 10 : {np_array_1 - 10}")
# print(f"np_array_1 * 10 : {np_array_1 * 10}")
# print(f"np_array_1 / 10 : {np_array_1 / 10}")
# print(f"np_array_1 % 10 : {np_array_1 % 10}")
# print(f"np_array_1 // 10 : {np_array_1 // 10}")
# print(f"np_array_1 ** 10 : {np_array_1 ** 10}")

#### np array 인덱싱, 슬라이싱
### 1차원
# np_array = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
# print(f"np_array : {np_array}")
# print(f"np_array.shape : {np_array.shape}")
# print(f"np_array.dtype : {np_array.dtype}")
## 인덱싱
# print(f"np_array[0] : {np_array[0]}")
# print(f"np_array[5] : {np_array[5]}")
# print(f"np_array[-3] : {np_array[-3]}")
## 슬라이싱
# print(f"np_array[1:4] : {np_array[1:4]}")
# print(f"np_array[1:] : {np_array[1:]}")
# print(f"np_array[:4] : {np_array[:4]}")
# print(f"np_array[-5:-2] : {np_array[-5:-2]}")
# print(f"np_array[1:-4:2]] : {np_array[1:-4:2]}")

### 2차원
# np_array = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10], [11, 12, 13, 14, 15], [16, 17, 18, 19, 20]])
# print(f"np_array : {np_array}")
# print(f"np_array.shape : {np_array.shape}")
# print(f"np_array.dtype : {np_array.dtype}")
# print(f"np_array[0,] : {np_array[0,]}")  # [행, 열]
# print(f"np_array[1, 1:5] : {np_array[1, 1:5]}")
# print(f"np_array[0:3] : {np_array[0:3]}")  # , 생략가능
# print(f"np_array[1:3, 3:] : {np_array[1:3, 3:]}")
# print(f"np_array[1:3, 1::2] : {np_array[1:3, 1::2]}")

#### 정렬, sort
# np_array_1 = np.array([[10, 3, 5, 1, 4], [6, 9, 8, 7, 2], [15, 14, 12, 13, 11]])
# print(f"np_array_1 :\n{np_array_1}")
#print(f"np_array_1.shape :\n{np_array_1.shape}")
### 오름차순
# np_array_row = np.sort(np_array_1, axis=0)  # 행 단위
# print(f"np_array_row :\n{np_array_row}")
# np_array_column = np.sort(np_array_1, axis=1)  # 열 단위
# print(f"np_array_column :\n{np_array_column}")
# np_array_1 = np.array([[10, 3, 5, 1, 4], [6, 9, 8, 7, 2], [15, 14, 12, 13, 11]])
### 내림차순
# np_array_row = np.sort(np_array_1, axis=0)[::-1]  # 행
# print(f"np_array_row :\n{np_array_row}")
# np_array_row = np.sort(np_array_1, axis=1)[:, ::-1]  # 열
# print(f"np_array_row :\n{np_array_row}")
### axis = None, 1차원으로 만들어 정렬
# np_sort_axis_none = np.sort(np_array_1, axis=None)  # 오름
# print(f"np_sort_axis_none : {np_sort_axis_none}")
# np_sort_axis_none = np.sort(np_array_1, axis=None)[::-1]  # 내림
# print(f"np_sort_axis_none : {np_sort_axis_none}")

#### np random 함수
# print(f"np.random.rand() :\n{np.random.rand()}")  # 0부터 1까지의 양수
# print(f"type(np.random.rand()) :\n{type(np.random.rand())}")
# print(f"np.random.rand() :\n{np.random.rand(3)}")  # 1차원, np array
# print(f"np.random.rand().dtype :\n{np.random.rand(3).dtype}")
# print(f"np.random.rand().shape :\n{np.random.rand(3).shape}")
# print(f"np.random.rand() :\n{np.random.rand(3, 4)}")  # 2차원, np array
# print(f"np.random.rand().dtype :\n{np.random.rand(3, 4).dtype}")
# print(f"np.random.rand().shape :\n{np.random.rand(3, 4).shape}")
# print(f"np.random.rand() :\n{np.random.rand(2, 3, 4)}")  # 3차원, np array
# print(f"np.random.rand().dtype :\n{np.random.rand(2, 3, 4).dtype}")
# print(f"np.random.rand().shape :\n{np.random.rand(2, 3, 4).shape}")

# print(f"np.random.randint(10) :\n{np.random.randint(10)}")  # 0이상 10미만의 정수
# print(f"np.random.randint(3, 10) :\n{np.random.randint(3, 10)}")  # 3이상 10미만의 정수

# print(f"np.random.randn() :\n{np.random.randn()}")  # 음수 포함 실수, 수학적 정의 확인
# print(f"np.random.randn(4) :\n{np.random.randn(4)}")  # 1차원
# print(f"np.random.randn(3, 4) :\n{np.random.randn(3, 4)}")  # 2차원
# print(f"np.random.randn(2, 3, 4) :\n{np.random.randn(2, 3, 4)}")  # 3차원

#### np sigh(), 음수는 -1, 0은 0, 양수는 1 반환
# np_array = np.array([[1, -2, 3, -4, 5], [-12, -23, 13, 4, -8], [31, 2, 3, -33, 7]])
# print(f"np_array :\n{np_array}")
# print(f"np.sign(np_array) :\n{np.sign(np_array)}")

#### np ceil, floor, rount 올림, 내림, 반올림
# np_array = np.random.randn(3, 5)
# print(f"np_array =\n{np_array}")
# print(f"np.ceil(np_array) :\n{np.ceil(np_array)}")
# print(f"np.floor(np_array) :\n{np.floor(np_array)}")
# print(f"np.round(np_array) :\n{np.round(np_array, 2)}")

#### np square(), sqrt() 제곱승, 제곱근
# np_array = np.array([[3, 45, 56, 2, 5], [4, 3, 4, 2, 1]])
# print(f"np.square(np_array) :\n{np.square(np_array)}")
# print(f"np.sqrt(np_array) :\n{np.sqrt(np_array)}")

#### ip isnan, NaN데이터 확인, Not a Number
# np_array = np.array([[3, np.NaN, 56, 2, 5], [4, np.NaN, 4, 2, np.NaN]])
# print(f"np_array :\n{np_array}")
# print(f"np.isnan(np_array) :\n{np.isnan(np_array)}")

#### np sum, mean 합, 평균
# np_array = np.array([[3, 45, 56, 2, 5], [4, 3, 4, 2, 1]])
# print(f"np_array :\n{np_array}")
# print(f"np.sum(np_array) :\n{np.sum(np_array)}")
# print(f"np.sum(np_array, axis=0) :\n{np.sum(np_array, axis=0)}")
# print(f"np.sum(np_array, axis=1) :\n{np.sum(np_array, axis=1)}")
# print(f"np.mean(np_array) :\n{np.mean(np_array)}")
# print(f"np.mean(np_array, axis=0) :\n{np.mean(np_array, axis=0)}")
# print(f"np.mean(np_array, axis=1) :\n{np.mean(np_array, axis=1)}")
