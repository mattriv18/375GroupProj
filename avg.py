

m_s_avg = 0
count = 0

open('matrixtimes_sparse.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    m_s_avg += linelist[1]
    count++

m_s_avg = m_s_avg / count
print("Average time for Matrix Dijkstra's with SPARSE graphs: " + m_s_avg + "\n")



m_d_avg = 0
count = 0

open('matrixtimes_dense.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    m_d_avg += linelist[1]
    count++

m_d_avg = m_d_avg / count
print("Average time for Matrix Dijkstra's with DENSE graphs: " + m_d_avg + "\n")



m_r_avg = 0
count = 0

open('matrixtimes_random.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    m_r_avg += linelist[1]
    count++

m_r_avg = m_r_avg / count
print("Average time for Matrix Dijkstra's with RANDOM graphs: " + m_r_avg + "\n")


print("Combined Average time for Matrix Dijkstra's :" + ((m_s_avg + m_d_avg + m_r_avg) / 3 ) + "\n")




h_s_avg = 0
count = 0

open('heaptimes_sparse.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    h_s_avg += linelist[1]
    count++

h_s_avg = h_s_avg / count
print("Average time for Heap Dijkstra's with SPARSE graphs: " + h_s_avg + "\n")



h_d_avg = 0
count = 0

open('heaptimes_dense.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    h_d_avg += linelist[1]
    count++

h_d_avg = h_d_avg / count
print("Average time for Heap Dijkstra's with DENSE graphs: " + h_d_avg + "\n")



h_r_avg = 0
count = 0

open('heaptimes_random.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    h_s_avg += linelist[1]
    count++

h_s_avg = h_s_avg / count
print("Average time for Heap Dijkstra's with RANDOM graphs: " + h_s_avg + "\n")



print("Combined Average time for Heap Dijkstra's :" + ((h_s_avg + h_d_avg + h_r_avg) / 3 ) + "\n")




lh_s_avg = 0
count = 0

open('lazyheaptimes_sparse.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    lh_s_avg += linelist[1]
    count++

lh_s_avg = lh_s_avg / count
print("Average time for Lazy Heap Dijkstra's with SPARSE graphs:" + lh_s_avg + "\n")



lh_d_avg = 0
count = 0

open('lazyheaptimes_dense.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    lh_d_avg += linelist[1]
    count++

lh_d_avg = lh_d_avg / count
print("Average time for Lazy Heap Dijkstra's with DENSE graphs:" + lh_d_avg + "\n")



lh_r_avg = 0
count = 0

open('lazyheaptimes_random.txt', 'r') 
lines = file1.readlines() 
  
for l in lines: 
    linelist = l.strip(",")
    lh_r_avg += linelist[1]
    count++

lh_r_avg = lh_r_avg / count
print("Average time for Lazy Heap Dijkstra's with RANDOM graphs:" + lh_r_avg + "\n")



print("Combined Average time for Lazy Heap Dijkstra's :" + ((lh_s_avg + lh_d_avg + lh_r_avg) / 3 ) + "\n")

