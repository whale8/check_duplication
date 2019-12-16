from time import time
from copy import copy


def check_duplication(list_A, elem):
	"""
	list_A: sorted deque
	elem: num
	"""
	for a in reversed(list_A):
		if a > elem:
			return False
		elif a < elem:
			list_A.pop()
		else:
			list_A.pop()
			return True


def enumerate_duplication(list_A, list_B):
	return [b for b in reversed(list_B) if check_duplication(list_A, b)]


if __name__ == "__main__":

	list_A = [29, 20, 17, 10, 8, 6, 5, 3, 1]
	list_B = [29, 22, 19, 17, 16, 12, 10, 8, 4]

	list_a = copy(list_A)
	list_b = copy(list_B)
	
	print(enumerate_duplication(list_a, list_b))


	num = 100000
	t1 = time()
	for i in range(num):
		list_a = copy(list_A)
		list_b = copy(list_B)
		enumerate_duplication(list_a, list_b)

	t2 = time()

	for i in range(num):
		list_ = []
		list_a = copy(list_A)
		list_b = copy(list_B)
		for a in list_a:
			for b in list_b:
				if a == b:
					list_.append(a)

	t3 = time()

	print("[proposal] elapsed time: ", t2-t1, "[s]")
	print("[baseline] elapsed time: ", t3-t2, "[s]")

	
