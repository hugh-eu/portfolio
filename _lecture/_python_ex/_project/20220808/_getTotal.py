def calcTotalPrice(gps):
    totalPrice = 0
    dcRate = 0
    if len(gps) == 1:
        dcRate = 5
    elif len(gps) == 2:
        dcRate = 10
    elif len(gps) == 3:
        dcRate = 20
    elif len(gps) >= 4:
        dcRate = 30

    for price in gps:
        totalPrice += price * (1 - dcRate / 100)

    return (totalPrice, dcRate)

def app():
    print(f'Total Price : {int(calcTotalPrice([100, 200, 300, 400, 500]))}')

if __name__ == '__main__':
    app()
