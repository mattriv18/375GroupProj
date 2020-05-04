

m_s_avg = 0
count = 0

file1 = open('matrixtimes_sparse.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.split(",")
    m_s_avg += int(linelist[1])
    count+=1

m_s_avg = m_s_avg / count
print("Average time for Matrix Dijkstra's with SPARSE graphs: " + str(m_s_avg) + "\n")



m_d_avg = 0
count = 0

file1 =open('matrixtimes_dense.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.split(",")
    m_d_avg += int(linelist[1])
    count+=1

m_d_avg = m_d_avg / count
print("Average time for Matrix Dijkstra's with DENSE graphs: " + str(m_d_avg) + "\n")



m_r_avg = 0
count = 0

file1 = open('matrixtimes_random.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.split(",")
    m_r_avg += int(linelist[1])
    count+=1

m_r_avg = m_r_avg / count
print("Average time for Matrix Dijkstra's with RANDOM graphs: " + str(m_r_avg) + "\n")


print("Combined Average time for Matrix Dijkstra's :" + (str((m_s_avg + m_d_avg + m_r_avg) / 3 )) + "\n")




h_s_avg = 0
count = 0

file1 = open('heaptimes_sparse.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.split(",")
    h_s_avg += int(linelist[1])
    count+=1

h_s_avg = h_s_avg / count
print("Average time for Heap Dijkstra's with SPARSE graphs: " + str(h_s_avg) + "\n")



h_d_avg = 0
count = 0

file1 = open('heaptimes_dense.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.split(",")
    h_d_avg += int(linelist[1])
    count += 1

h_d_avg = h_d_avg / count
print("Average time for Heap Dijkstra's with DENSE graphs: " + str(h_d_avg) + "\n")



h_r_avg = 0
count = 0

file1 = open('heaptimes_random.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.split(",")
    h_s_avg += int(linelist[1])
    count+=1

h_s_avg = h_s_avg / count
print("Average time for Heap Dijkstra's with RANDOM graphs: " + str(h_s_avg) + "\n")



print("Combined Average time for Heap Dijkstra's :" + (str((h_s_avg + h_d_avg + h_r_avg) / 3 )) + "\n")




lh_s_avg = 0
count = 0

file1 = open('lazyheaptimes_sparse.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.split(",")
    lh_s_avg += int(linelist[1])
    count+=1

lh_s_avg = lh_s_avg / count
print("Average time for Lazy Heap Dijkstra's with SPARSE graphs:" + str(lh_s_avg) + "\n")



lh_d_avg = 0
count = 0

file1 = open('lazyheaptimes_dense.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.split(",")
    lh_d_avg += int(linelist[1])
    count+=1

lh_d_avg = lh_d_avg / count
print("Average time for Lazy Heap Dijkstra's with DENSE graphs:" + str(lh_d_avg) + "\n")



lh_r_avg = 0
count = 0

file1 = open('lazyheaptimes_random.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.split(",")
    lh_r_avg += int(linelist[1])
    count+=1

lh_r_avg = lh_r_avg / count
print("Average time for Lazy Heap Dijkstra's with RANDOM graphs:" + str(lh_r_avg) + "\n")



print("Combined Average time for Lazy Heap Dijkstra's :" + (str((lh_s_avg + lh_d_avg + lh_r_avg) / 3) + "\n")
