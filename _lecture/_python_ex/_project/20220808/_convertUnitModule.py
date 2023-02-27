def convertUnit(lenMm):
    unitDict = {}
    unitDict['cm'] = lenMm * 0.1
    unitDict['m'] = lenMm * 0.001
    unitDict['inch'] = lenMm * 0.03937
    unitDict['ft'] = lenMm * 0.003281
    return unitDict

def printLength(originalData, lengths):
    for len in lengths.keys():
        print(f'{originalData}mm ---> {lengths[len]} {len}')