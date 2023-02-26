import numpy as np

x = [['1','2'], ['3','4']]
print(x)
print(np.array(x).astype(int))
print(np.asarray(x).astype(int))

f = open("myfile.txt", "a")
f.write("Now the file has more content!")
f.write("e has more content!")
f.close()