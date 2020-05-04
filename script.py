import os

# os.system("make")

# matrix

os.system("break>matrixtimes.txt")

for i in range(5,500):
	os.system("echo '\n" + str(i) + " vertices sparce graph:' >> matrixtimes_sparce.txt")
	os.system("./matrixDijkstras tests/sparse/test" + str(i) + "_sparse >> matrixtimes_sparce.txt")

	os.system("echo '\n" + str(i) + " vertices dense graph:' >> matrixtimes_dense.txt")
	os.system("./matrixDijkstras tests/dense/test" + str(i) + "_dense >> matrixtimes_dense.txt")

	os.system("echo '\n" + str(i) + " vertices random graph:' >> matrixtimes_random.txt")
	os.system("./matrixDijkstras tests/random/test" + str(i) + "_random >> matrixtimes_random.txt")

# heap
for i in range(5,500):
	os.system("echo '\n" + str(i) + " vertices sparce graph:' >> heaptimes_sparce.txt")
	os.system("./heapDijkstras tests/sparse/test" + str(i) + "_sparse >> heaptimes_sparce.txt")

	os.system("echo '\n" + str(i) + " vertices dense graph:' >> heaptimes_dense.txt")
	os.system("./heapDijkstras tests/dense/test" + str(i) + "_dense >> heaptimes_dense.txt")

	os.system("echo '\n" + str(i) + " vertices random graph:' >> heaptimes_random.txt")
	os.system("./heapDijkstras tests/random/test" + str(i) + "_random >> heaptimes_random.txt")

# lazy heap
for i in range(5,500):
	os.system("echo '\n" + str(i) + " vertices sparce graph:' >> lazyheaptimes_sparce.txt")
	os.system("./lazyheapDijkstras tests/sparse/test" + str(i) + "_sparse >> heaptimes_sparce.txt")

	os.system("echo '\n" + str(i) + " vertices dense graph:' >> lazyheaptimes_dense.txt")
	os.system("./lazyheapDijkstras tests/dense/test" + str(i) + "_dense >> lazyheaptimes_dense.txt")

	os.system("echo '\n" + str(i) + " vertices random graph:' >> lazyheaptimes_random.txt")
	os.system("./lazyheapDijkstras tests/random/test" + str(i) + "_random >> lazyheaptimes_random.txt")

