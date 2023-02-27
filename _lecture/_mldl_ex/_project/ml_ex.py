##캐글 데이터, https://www.kaggle.com/

########## k 최근접 이웃
from sklearn.neighbors import KNeighborsClassifier  # k nearest neighbors 알고리즘 구현 클래스
from sklearn.model_selection import train_test_split  # 훈련 세트와 테스트세트 자동 분리
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.pyplot as plt
# bream_length = [25.4, 26.3, 26.5, 29.0, 29.0, 29.7, 29.7, 30.0, 30.0, 30.7, 31.0, 31.0,
#                 31.5, 32.0, 32.0, 32.0, 33.0, 33.0, 33.5, 33.5, 34.0, 34.0, 34.5, 35.0,
#                 35.0, 35.0, 35.0, 36.0, 36.0, 37.0, 38.5, 38.5, 39.5, 41.0, 41.0]
# bream_weight = [242.0, 290.0, 340.0, 363.0, 430.0, 450.0, 500.0, 390.0, 450.0, 500.0, 475.0, 500.0,
#                 500.0, 340.0, 600.0, 600.0, 700.0, 700.0, 610.0, 650.0, 575.0, 685.0, 620.0, 680.0,
#                 700.0, 725.0, 720.0, 714.0, 850.0, 1000.0, 920.0, 955.0, 925.0, 975.0, 950.0]
# smelt_length = [9.8, 10.5, 10.6, 11.0, 11.2, 11.3, 11.8, 11.8, 12.0, 12.2, 12.4, 13.0, 14.3, 15.0]
# smelt_weight = [6.7, 7.5, 7.0, 9.7, 9.8, 8.7, 10.0, 9.9, 9.8, 12.2, 13.4, 12.2, 19.7, 19.9]
# length = bream_length + smelt_length
# weight = bream_weight + smelt_weight
# fish_data = [[l, w] for l, w in zip(length, weight)]  # 길이와 무게 2차원 배열 만들기
# fish_target = [1] * 35 + [0] * 14  # 도미가 1, 빙어가 0
#
# kn = KNeighborsClassifier()  # 객체 생성
# kn.fit(fish_data, fish_target)  # 도미를 찾기위한 기준 학습, training
# print(kn.score(fish_data, fish_target))  # 트레이닝을 통한 알고리즘 구현 모델 평가
# print(kn.predict([[30, 600], [10, 600], [20, 200], [10, 40]]))  # 주어진 데이터의 정답 예측
#
# print(kn._fit_X)
# print(kn._y)  # k nearest neighbors 는 fit() 메서드에 데이터를 모두 저장하고, 참조하여 구분, 직접 훈련 없음
#
# kn49 = KNeighborsClassifier(n_neighbors=49)  # 기본 참조 데이터는 5개, 49개로 변경한 kn49 모델
# kn49.fit(fish_data, fish_target)
# print(kn49.score(fish_data, fish_target))  # 49개중 도미가 다수, 모두 도미로 예측
# print(35/49)

# fish_length = [25.4, 26.3, 26.5, 29.0, 29.0, 29.7, 29.7, 30.0, 30.0, 30.7, 31.0, 31.0,
#                 31.5, 32.0, 32.0, 32.0, 33.0, 33.0, 33.5, 33.5, 34.0, 34.0, 34.5, 35.0,
#                 35.0, 35.0, 35.0, 36.0, 36.0, 37.0, 38.5, 38.5, 39.5, 41.0, 41.0, 9.8,
#                 10.5, 10.6, 11.0, 11.2, 11.3, 11.8, 11.8, 12.0, 12.2, 12.4, 13.0, 14.3, 15.0]
# fish_weight = [242.0, 290.0, 340.0, 363.0, 430.0, 450.0, 500.0, 390.0, 450.0, 500.0, 475.0, 500.0,
#                 500.0, 340.0, 600.0, 600.0, 700.0, 700.0, 610.0, 650.0, 575.0, 685.0, 620.0, 680.0,
#                 700.0, 725.0, 720.0, 714.0, 850.0, 1000.0, 920.0, 955.0, 925.0, 975.0, 950.0, 6.7,
#                 7.5, 7.0, 9.7, 9.8, 8.7, 10.0, 9.9, 9.8, 12.2, 13.4, 12.2, 19.7, 19.9]
# fish_data = [[l, w] for l, w in zip(fish_length, fish_weight)]
# fish_target = [1] * 35 + [0] * 14
#
# kn = KNeighborsClassifier()
#
# # train_input = fish_data[:35]
# # train_target = fish_target[:35]
# # test_input = fish_data[35:]
# # test_target = fish_target[35:]  # 훈련 샘플과 테스트 셈플에 오류, 골고루 섞이지 않음
# #
# # kn = kn.fit(train_input, train_target)
# # print(kn.score(test_input, test_target))
#
# input_arr = np.array(fish_data)
# target_arr = np.array(fish_target)
#
# np.random.seed(42)
# index = np.arange(49)
# np.random.shuffle(index)  # 데이터와 타겟을 램덤하게 섞기위해 인덱스를 섞음
#
# train_input = input_arr[index[:35]]
# train_target = target_arr[index[:35]]
# test_input = input_arr[index[35:]]
# test_target = target_arr[index[35:]]
#
# # plt.scatter(train_input[:, 0], train_input[:, 1])
# # plt.scatter(test_input[:, 0], test_input[:, 1])
# # plt.xlabel("length")
# # plt.ylabel("weight")
# # plt.show()
#
# kn = kn.fit(train_input, train_target)
# print(kn.score(test_input, test_target))
#
# print(kn.predict(test_input))
# print(test_target)
#
# print(kn.predict([[25, 150]]))

# fish_length = [25.4, 26.3, 26.5, 29.0, 29.0, 29.7, 29.7, 30.0, 30.0, 30.7, 31.0, 31.0,
#                 31.5, 32.0, 32.0, 32.0, 33.0, 33.0, 33.5, 33.5, 34.0, 34.0, 34.5, 35.0,
#                 35.0, 35.0, 35.0, 36.0, 36.0, 37.0, 38.5, 38.5, 39.5, 41.0, 41.0, 9.8,
#                 10.5, 10.6, 11.0, 11.2, 11.3, 11.8, 11.8, 12.0, 12.2, 12.4, 13.0, 14.3, 15.0]
# fish_weight = [242.0, 290.0, 340.0, 363.0, 430.0, 450.0, 500.0, 390.0, 450.0, 500.0, 475.0, 500.0,
#                 500.0, 340.0, 600.0, 600.0, 700.0, 700.0, 610.0, 650.0, 575.0, 685.0, 620.0, 680.0,
#                 700.0, 725.0, 720.0, 714.0, 850.0, 1000.0, 920.0, 955.0, 925.0, 975.0, 950.0, 6.7,
#                 7.5, 7.0, 9.7, 9.8, 8.7, 10.0, 9.9, 9.8, 12.2, 13.4, 12.2, 19.7, 19.9]
#
# fish_data = np.column_stack((fish_length, fish_weight))
# fish_target = np.concatenate((np.ones(35), np.zeros(14)))
#
# train_input, test_input, train_target, test_target = train_test_split(fish_data, fish_target, stratify=fish_target, random_state=42)  # 25퍼의 테스트비율, 샘플 비율을 맞추기 위해 stratify=타겟데이터
# kn = KNeighborsClassifier()
# kn.fit(train_input, train_target)
# print(kn.score(test_input, test_target))
# print(kn.predict([[25, 150]]))
#
# distances, indexes = kn.kneighbors([[25, 150]])
# plt.scatter(train_input[:, 0], train_input[:, 1])
# plt.scatter(25, 150, marker="^")
# plt.scatter(train_input[indexes, 0], train_input[indexes, 1], marker="D")
# plt.xlim(0, 1000)
# plt.xlabel("length")
# plt.ylabel("weight")
# plt.show()
# print(distances)
#
# mean = np.mean(train_input, axis=0)  # np 배열 평균
# std = np.std(train_input, axis=0)  # np 배열 표준편차
# print(mean, std)
# train_scaled = (train_input - mean) / std  # 표준점수, 평균빼고 표준편차로 나누기, 데이터 전처리, 단위의 스케일 맞추기
# new = ([25, 150] - mean) / std
#
# plt.scatter(train_scaled[:, 0], train_scaled[:, 1])
# plt.scatter(new[0], new[1], marker="^")
# plt.xlabel("length")
# plt.ylabel("weight")
# plt.show()
#
# kn = KNeighborsClassifier()
# kn.fit(train_scaled, train_target)
#
# mean = np.mean(test_input, axis=0)
# std = np.std(test_input, axis=0)
# test_scaled = (test_input - mean) / std
#
# print(kn.score(test_scaled, test_target))
# print(kn.predict([new]))
# distances, indexes = kn.kneighbors([new])
# plt.scatter(train_scaled[:, 0], train_scaled[:, 1])
# plt.scatter(new[0], new[1], marker="^")
# plt.scatter(train_scaled[indexes, 0], train_scaled[indexes, 1], marker="D")
# plt.xlabel("length")
# plt.ylabel("weight")
# plt.show()

########## k 최근접 이웃 회귀
import numpy as np
from sklearn.model_selection import train_test_split  # 훈련 세트와 테스트세트 자동 분리
from sklearn.neighbors import KNeighborsRegressor  # k 최근접 이웃 회귀 알고리즘
from sklearn.metrics import mean_absolute_error  # 타깃과 예측의 절대값 오차 평균
from sklearn.linear_model import LinearRegression

perch_length = np.array([8.4, 13.7, 15.0, 16.2, 17.4, 18.0, 18.7, 19.0, 19.6, 20.0, 21.0,
       21.0, 21.0, 21.3, 22.0, 22.0, 22.0, 22.0, 22.0, 22.5, 22.5, 22.7,
       23.0, 23.5, 24.0, 24.0, 24.6, 25.0, 25.6, 26.5, 27.3, 27.5, 27.5,
       27.5, 28.0, 28.7, 30.0, 32.8, 34.5, 35.0, 36.5, 36.0, 37.0, 37.0,
       39.0, 39.0, 39.0, 40.0, 40.0, 40.0, 40.0, 42.0, 43.0, 43.0, 43.5,
       44.0])
perch_weight = np.array([5.9, 32.0, 40.0, 51.5, 70.0, 100.0, 78.0, 80.0, 85.0, 85.0, 110.0,
       115.0, 125.0, 130.0, 120.0, 120.0, 130.0, 135.0, 110.0, 130.0,
       150.0, 145.0, 150.0, 170.0, 225.0, 145.0, 188.0, 180.0, 197.0,
       218.0, 300.0, 260.0, 265.0, 250.0, 250.0, 300.0, 320.0, 514.0,
       556.0, 840.0, 685.0, 700.0, 700.0, 690.0, 900.0, 650.0, 820.0,
       850.0, 900.0, 1015.0, 820.0, 1100.0, 1000.0, 1100.0, 1000.0,
       1000.0])

plt.scatter(perch_length, perch_weight)
plt.xlabel("length")
plt.ylabel("weight")
plt.show()

train_input, test_input, train_target, test_target = train_test_split(perch_length, perch_weight, random_state=42)
train_input = train_input.reshape(-1, 1)
test_input = test_input.reshape(-1, 1)

knr = KNeighborsRegressor()

knr.fit(train_input, train_target)
print(knr.score(test_input, test_target))  # R^2 결정계수
test_prediction = knr.predict(test_input)
mae = mean_absolute_error(test_target, test_prediction)  # 타깃과 예측의 절대값 오차 평균
print(mae)

print(knr.score(train_input, train_target))  # 과소적합, 모델이 단순하거나, 크기가 작아 발생, 과대적합의 경우 반대

knr.n_neighbors = 3  # 이웃의 크기가 작아지면 국지적 패던에 민감, 일반적패턴 보다 복잡해짐
knr.fit(train_input, train_target)
print(knr.score(train_input, train_target))
print(knr.score(test_input, test_target))

x = np.arange(5, 100,).reshape(-1, 1)
knr.n_neighbors = 3
knr.fit(train_input, train_target)
prediction = knr.predict(x)  # 길이 5-45의 예측값, 무게
plt.scatter(train_input, train_target)
plt.plot(x, prediction)  # 예측값을 선그래프로 그림, x축 길이, y축 예측무게
plt.xlabel("length")
plt.ylabel("weight")
plt.show()  # 최대값 이상의 것들은 근처 최대값을 따라가 오류

# 선형 회귀
lr = LinearRegression()
lr.fit(train_input, train_target)
prediction = lr.predict(x)
plt.scatter(train_input, train_target)
plt.plot(x, prediction)
plt.xlabel("length")
plt.ylabel("weight")
plt.show()