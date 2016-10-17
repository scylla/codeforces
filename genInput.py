import random
numbers = random.sample(xrange(0, 1000000000000), 100000)
with open("/Users/amit/Documents/programming/c++/codeforces/dp/xorin.txt", "w") as out_file:
	out_file.write(str(100000) + "\n");
	for x in numbers:
		out_file.write(str(x) + "\n")

