# coding: utf-8
import Refseq

HBA1 = Refseq.HBA1
HBA2 = Refseq.HBA2

# 長い方を0番、短い方を1番、差を2番にして返す
def whichIsLong(g1,g2):
    diff = abs(len(g1)-len(g2))
    if len(g1) > len(g2):
        return g1,g2,diff
    else:
        return g2,g1,diff

# 同じ塩基であれば1を、そうでなければ0を配列にpushしていく
def is5Terminal(g1, g2):
    isSame = []
    for i in range(40):
        if g1[i] == g2[i]:
            isSame.append(1)
        else:
            isSame.append(0)
    return isSame

def is3Terminal(g1,g2):
    isSame = []
    long, short, diff = whichIsLong(g1,g2)
    for i in range(100):
        if short[len(short)-i-1] == long[len(long)-i-1-diff]:
            isSame.append(1)
        else:
            isSame.append(0)
    return isSame

def main():
    print(is5Terminal(HBA1,HBA2))
    print(is3Terminal(HBA1,HBA2))


if __name__=='__main__':
    main()