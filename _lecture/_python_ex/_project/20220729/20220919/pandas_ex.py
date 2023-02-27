# import numpy as np
# import pandas as pd
#
# def printLog(data_name, data):
#     print(f"{data_name} :\n{data}\n")

## Series
# nums = [1, 2, 3, 4, 5]
# sr = pd.Series(nums)  # Series, 1열
# printLog("sr", sr)
# printLog("sr.index", sr.index)  # 인덱스
# printLog("sr.values", sr.values)  # 벨류

# sr = pd.Series([80, 70, 60, 70, 30], index=["1번", "2번", "3번", "4번", "5번"])
# printLog("sr", sr)
# sr.index = ["1", "2", "3", "4", "5"]
# printLog("sr", sr)
# sr.loc["1"] = 90
# printLog("sr", sr)

# dic_scores = {"1번":90, "2번":76, "3번":46, "4번":86, "5번":96}  # 키값이 인덱스로
# sr = pd.Series(dic_scores)
# printLog("sr", sr)
# sr = pd.Series(dic_scores, name="학생 성적")
# printLog("sr", sr)
# sr.name = "students score"
# printLog("sr", sr)
# sr.index.name = "no."
# printLog("sr", sr)

# students_scores = {"no":[1, 2, 3, 4, 5],
#                    "name":["홍", "박", "이", "박", "김"],
#                    "age": [16, 25, 63, 12, 42],
#                    "major":["컴", "전", "정", "데", "헬"]}
# df = pd.DataFrame(students_scores)
# printLog("df", df)
# printLog("df.index", df.index)
# printLog("df.columns", df.columns)
# printLog("df.values", df.values)
# df.columns.name = "infos"
# printLog("df", df)
# df.index.name = "no."
# printLog("df", df)
# df = df.set_index(keys="no")
# printLog("df", df)
# df = pd.DataFrame(students_scores, index=["no1", "no2", "no3", "no4", "no5"], columns=["name", "age", "major", "no", "test"])
# printLog("df", df)
# df.index = ["1", "2", "3", "4", "5"]
# printLog("df", df)
# df.columns = ["N", "A", "M", "No", "T"]
# printLog("df", df)
# printLog("df.describe()", df.describe())
# printLog("df.loc[:, 'A'].sum()", df.loc[:, "A"].sum())
# printLog("df.loc[:, 'A'].mean()", df.loc[:, "A"].mean())

# np_array_2 = np.array([[1, 2, 3, 4, 5], ["홍", "박", "이", "박", "김"], [16, 25, 63, 12, 42], ["컴", "전", "정", "데", "헬"]])
# df = pd.DataFrame(np_array_2)
# printLog("df", df)
# df = pd.DataFrame(np_array_2).T  # .T 행렬바꾸기
# printLog("df", df)

# np_array_2 = np.array([[1, "홍", 16, "컴"], [2, "박", 25, "전"], [3, "이", 63, "정"], [4, "박", 12, "데"], [5, "김", 42, "헬"]])
# df = pd.DataFrame(np_array_2, index=["1", "2", "3", "4", "5"], columns=["no.", "name", "age", "major"])
# printLog("df", df)
# printLog("df['name']", df["name"])
# printLog("df['name', 'major']", df[["name", "major"]])
# printLog("df[0:2]", df[0:2])
# printLog('df.loc["1", "2", "3"]', df.loc[["1", "2", "3"]])
# printLog('df.loc["1", "name"]', df.loc["1", "name"])
# printLog('df.loc[["1", "2"], ["name", "major"]]', df.loc[["1", "2"], ["name", "major"]])

# df = pd.DataFrame(index=["1", "2", "3", "4", "5", "t", "e", "s", "t."], columns=["no.", "name", "age", "major"])
# printLog("df.head()", df.head())
# printLog("df.head(3)", df.head(3))
# printLog("df.tail()", df.tail())
# printLog("df.tail(3)", df.tail(3))


