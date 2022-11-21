class Node:

	def __init__(self, key, value, left=None, right=None):
		self.key = key
		self.value = value
		self.left = left
		self.right = right


class BST:

	def __init__(self):
		self.root = None

	def search(self, key):
		node = self.root
		while True:
			if node == None:
				return False
			if key == node.key:
				return True
			elif key < node.key:
				node = node.left
			else:
				node = node.right

	def add_node(self, node, key, value):
		if key == node.key:
			return False
		if key < node.key:
			if node.left == None:
				node.left = Node(key, value)
			else:
				self.add_node(node.left, key, value)
		else:
			if node.right == None:
				node.right = Node(key, value)
			else:
				self.add_node(node.right, key, value)
		return True

	def add(self, key, value):
		if self.root == None:
			self.root = Node(key, value)
			return True
		return self.add_node(self.root, key, value)

	def inorder_trav(self, node, visit):
		if node != None:
			self.inorder_trav(node.left, visit)
			visit(f'[{node.key}] : {node.value}')
			self.inorder_trav(node.right, visit)

	def printBST(self):
		self.inorder_trav(self.root, print)

	def del_single(self, parent, node):
		if parent == None:
			self.root = None
		else:
			if parent.left == node:
				parent.left = None
			else:
				parent.right = None
		return self.root

	def del_twins(self, parent, node):
		min_right_parent = node
		min_right = node.right
		while min_right.left != None:
			min_right_parent = min_right
			min_right = min_right.left
		if min_right_parent.left == min_right:
			min_right_parent.left = min_right.right
		# else:
		# 	min_right_parent.right = min_right.right
		node.key = min_right.key
		node.value = min_right.value
		node = min_right

	def del_mono(self, parent, node):
		child = None
		if node.left: child = node.left
		else: child = node.right
		if node == self.root:
			self.root = child
		else:
			if node == parent.left:
				parent.left = child
			else:
				parent.right = child

	def remove(self, key):
		if self.root == None:
			return None
		node = self.root
		parent = None
		while node != None and node.key != key:
			parent = node
			if key < node.key: node = node.left
			else: node = node.right
		if node == None: return None
		if node.left == None and node.right == None:
			return self.del_single(parent, node)
		if node.left and node.right:
			return self.del_twins(parent, node)
		return self.del_mono(parent, node)


class Set:

	def __init__(self):
		self.tree = None

	def create(self):
		self.tree = BST()
		return self.tree

	def add(self, value):
		self.tree.add(value, value)

	def search(self, value):
		return self.tree.search(value)

	def delete(self, value):
		return self.tree.remove(value)
	def inorder_trav(self, node, visit):
			if node != None:
				self.inorder_trav(node.left, visit)
				visit(node.key, node.value)
				self.inorder_trav(node.right, visit)
	def union(self, target):
		new_set = Set()
		new_set.create()
		self.inorder_trav(self.tree.root, new_set.tree.add)
		self.inorder_trav(target.tree.root, new_set.tree.add)
		return new_set

	def intersection(self, target):
		def add_in_common(node):
			if target.search(node.value):
				new_set.add(node.value)
		new_set = Set()
		new_set.create()
		self.inorder_trav(self.tree.root, new_set.tree.add)
		return new_set

	def __add__(self, other):
		return self.union(other)
		
	def printSet(self, str="all"):
		print(f"<{str}>")
		self.tree.printBST()
		print("=" * 10)


s1 = Set()
s1.create()
datas1 = [2, -6, 14, 3, -1, 2, 5]
s2 = Set()
s2.create()
datas2 = [14, -1, -5, 9, 5, 9]
for i in datas1:
	s1.add(i)
for i in datas2:
	s2.add(i)
s1.printSet()
s2.printSet()
print("does 3 exist in s1", str(s1.search(3)))
s1.union(s2).printSet("after union s1, s2")
s1.intersection(s2).printSet("after intersection")
(s1 + s2).printSet("s1 + s2")
