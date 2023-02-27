from kor import gimchi
from kor import gimbap

from chn import jjajang
from chn import jjambbong

from jpn import sushi
from jpn import udon


def app():
    print('한식 주문')
    gimchi.makeGimchi()
    gimbap.makeGimbap()

    print('중식 주문')
    jjajang.makeJjajang()
    jjambbong.makeJJambbong()

    print('일식 주문')
    sushi.makeSushi()
    udon.makeUdon()

if __name__ == '__main__':
    app()
