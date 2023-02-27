import random

num = random.randint(1, 100)
print(num)
num = random.random()
print(num)
num = random.uniform(1, 100)
print(num)
num = random.randrange(1, 101, 3)
print(num)
num = random.choice([1, 2, 3, 4, 5, 6])
print(num)
num = random.sample([1, 2, 3, 4, 5, 6], 3)
print(num)
item = [1, 2, 3, 4, 5, 6]
num = random.shuffle(item)
print(item)
