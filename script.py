import os

# os.system("make")

# matrix

os.system("break>matrixtimes.txt")

for i in range(5,501):
    if (!path.exists("tests/sparse/test" + str(i) + "_sparse"))
        continue
    os.system("./matrixDijkstras tests/sparse/test" + str(i) + "_sparse >> matrixtimes_spare.txt")

    os.system("./matrixDijkstras tests/dense/test" + str(i) + "_dense >> matrixtimes_dense.txt")

    os.system("./matrixDijkstras tests/random/test" + str(i) + "_random >> matrixtimes_random.txt")

'''
m_sparce_avg = 0
count = 0

open('myfile.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    m_sparse_avg += linelist[1]
    count++
'''

# heap
for i in range(5,501):
    if (!path.exists("tests/sparse/test" + str(i) + "_sparse"))
        continue

    os.system("./heapDijkstras tests/sparse/test" + str(i) + "_sparse >> heaptimes_sparse.txt")

    os.system("./heapDijkstras tests/dense/test" + str(i) + "_dense >> heaptimes_dense.txt")

    os.system("./heapDijkstras tests/random/test" + str(i) + "_random >> heaptimes_random.txt")

# lazy heap
for i in range(5,501):
    if (!path.exists("tests/sparse/test" + str(i) + "_sparse"))
        continue

    os.system("./lazyheapDijkstras tests/sparse/test" + str(i) + "_sparse >> heaptimes_sparse.txt")

    os.system("./lazyheapDijkstras tests/dense/test" + str(i) + "_dense >> lazyheaptimes_dense.txt")

    os.system("./lazyheapDijkstras tests/random/test" + str(i) + "_random >> lazyheaptimes_random.txt")

