import os

os.system("break>matrixtimes_sparse.txt")
os.system("break>matrixtimes_dense.txt")
os.system("break>matrixtimes_random.txt")
os.system("break>heaptimes_sparse.txt")
os.system("break>heaptimes_dense.txt")
os.system("break>heaptimes_random.txt")
os.system("break>lazyheaptimes_sparse.txt")
os.system("break>lazyheaptimes_dense.txt")
os.system("break>lazyheaptimes_random.txt")

# matrix
print("Running maxtrixDijkstras...")
for i in range(5,501):
    if (not os.path.exists("tests/sparse/test" + str(i) + "_sparse")):
        continue
    print(i)
    #print("Running maxtrixDijkstras sparse...");
    os.system("./matrixDijkstras tests/sparse/test" + str(i) + "_sparse >> matrixtimes_sparse.txt")

    #print("Running maxtrixDijkstras dense...");
    os.system("./matrixDijkstras tests/dense/test" + str(i) + "_dense >> matrixtimes_dense.txt")

    #print("Running maxtrixDijkstras random...");
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
print("Running heapDijkstras...")
for i in range(5,501):
    if (not os.path.exists("tests/sparse/test" + str(i) + "_sparse")):
        continue
    print(i)
    #print("Running heapDijkstras sparse...");
    os.system("./heapDijkstras tests/sparse/test" + str(i) + "_sparse >> heaptimes_sparse.txt")

    #print("Running heapDijkstras dense...");
    os.system("./heapDijkstras tests/dense/test" + str(i) + "_dense >> heaptimes_dense.txt")

    #print("Running heapDijkstras random...");
    os.system("./heapDijkstras tests/random/test" + str(i) + "_random >> heaptimes_random.txt")

# lazy heap
print("Running lazyheapDijkstras...")
for i in range(5,501):
    if (not os.path.exists("tests/sparse/test" + str(i) + "_sparse")):
        continue
    print(i)
    #print("Running lazyheapDijkstras sparse...");
    os.system("./lazyheapDijkstras tests/sparse/test" + str(i) + "_sparse >> heaptimes_sparse.txt")

    #print("Running lazyheapDijkstras dense...");
    os.system("./lazyheapDijkstras tests/dense/test" + str(i) + "_dense >> lazyheaptimes_dense.txt")

    #print("Running lazyheapDijkstras random...");
    os.system("./lazyheapDijkstras tests/random/test" + str(i) + "_random >> lazyheaptimes_random.txt")

print("SCRIPT COMPLETE");

