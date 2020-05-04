import os

# os.system("make")

# matrix

os.system("break>matrixtimes.txt")


os.system("echo '\n" + str(5) + " vertices sparce graph:' >> matrixtimes.txt")
os.system("./matrixDijkstras tests/sparse/test" + str(5) + "_sparse >> matrixtimes.txt")

os.system("echo '\n" + str(5) + " vertices dense graph:' >> matrixtimes.txt")
os.system("./matrixDijkstras tests/dense/test" + str(5) + "_dense >> matrixtimes.txt")

os.system("echo '\n" + str(5) + " vertices random graph:' >> matrixtimes.txt")
os.system("./matrixDijkstras tests/random/test" + str(5) + "_random >> matrixtimes.txt")


# heap
# os.system("./heapDijkstras")

# lazy heap
# os.system("./lazyheapDijkstras")

