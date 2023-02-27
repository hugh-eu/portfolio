from abc import ABCMeta, abstractmethod

class Goods:
    def __init__(self, n, p=150):
        self.name = n
        self.price = p

    def getName(self):
        return self.name

class Machine(metaclass=ABCMeta):
    def __init__(self):
        pass

    @abstractmethod
    def addGoods(self):
        pass

    @abstractmethod
    def removeGoods(self):
        pass

class BendingMachine(Machine):
    def __init__(self, tm=5000):
        self.goods = []
        self.totalMoney = tm

    def addGoods(self, soda):
        self.goods.append(soda)

    def removeGoods(self):
        if len(self.goods) > 0:
            print(f'판매 전 잔고 : {self.totalMoney}')
            print(f'음료수 가격 : {self.goods[0].price}')
            self.totalMoney += self.goods[0].price
            print(f'판매 후 잔고 : {self.totalMoney}')
            self.goods.pop(0)

    def getTotalMoney(self):
        return self.totalMoney

if __name__ == '__main__':
    bendingMachine = BendingMachine()
    print(bendingMachine)

    bendingMachine.addGoods(Goods('Cola'))
    bendingMachine.addGoods(Goods('Cider'))
    bendingMachine.addGoods(Goods('Fanta'))

    for g in bendingMachine.goods:
        print(g.getName())

    bendingMachine.removeGoods()

    for g in bendingMachine.goods:
        print(g.getName())

    bendingMachine.addGoods(Goods('Cola'))
    bendingMachine.addGoods(Goods('Cola'))

    for g in bendingMachine.goods:
        print(g.getName())
