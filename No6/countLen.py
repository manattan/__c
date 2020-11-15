# coding: utf-8
import Refseq

HBA1 = Refseq.HBA1
HBA2 = Refseq.HBA2

def main():
    minLen = 0
    same = 0
    different = 0
    if len(HBA1) > len(HBA2):
        minLen=len(HBA2)
    else:
        minLen=len(HBA1)

    for i in range(minLen):
        if HBA1[i] == HBA2[i]:
            same +=1
        else:
            different +=1

    print('同じ塩基は {} つ, 違う塩基は {} つ, 塩基長の差は {} つ.'.format(same, different, abs(len(HBA1)-len(HBA2))))

if __name__=='__main__':
    main()



