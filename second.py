class Polynomial:

	def __init__(self, arr=None) -> None:
		if arr:
			self.p = arr
		else:
			self.p = []

	def degree(self):
		return len(self.p)

	def read_poly(self):
		size = int(input('다항식의 최고 차수를 입력하시오:\t')) + 1
		self.p = [0 for _ in range(size)]
		for i in range(size - 1, -1, -1):
			self.p[i] = int(input('x^' + str(i) + '의 계수:\t'))

	def evaluate(self, scalar):
		ret = 0
		for idx, i in enumerate(self.p):
			ret += i * (scalar**idx)
		return ret

	def add(self, scalar):
		ret = [0 for _ in range(max(len(scalar.p), len(self.p)))]
		for idx, i in enumerate(self.p):
			ret[idx] += i
		for idx, i in enumerate(scalar.p):
			ret[idx] += i
		return ret

	def inverse(self):

		def inv(a):
			return a * (-1)

		self.p = list(map(inv, self.p))

	def display(self, s):
		to_print = []
		for i in range(len(self.p) - 1, -1, -1):
			to_print.append("(" + str(self.p[i]) + 'x^' + str(i) + ")")
		print(s + '+'.join(to_print))


p = Polynomial()
p.read_poly()
p.display("A(x) =\t")
q = Polynomial()
q.read_poly()
q.display("B(x) =\t")
print(f"A({3}) = {p.evaluate(3)}")
addT = Polynomial(p.add(q))
addT.display('A(x) + B(y) =\t')
p.inverse()
p.display("inv(A(x)) =\t")
