t = int(raw_input())
for i in range(0,t):
	n = int(raw_input())
	s = 2**n
	s1 = str(s)
	ans = 0
	for g in s1:
		ans = ans + int(g)
	print ans