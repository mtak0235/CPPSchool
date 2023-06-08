def cal(monomer, A):
	rate = (20.06) / (100. + 3. + 0.22 + 20.06)
	return monomer * 100. / (A * rate)
for i in range(3):
	monomer = float(input("monomer"))
	A = float(input("A"))
	print(cal(monomer, A))

