def safe_print_list(my_list=[], x=0):
	try:
		ans = []
		i = 0
		for _ in range(x):
			print(my_list[i], end = '')
			i += 1
		print()
		return i

	except IndexError as e:
		print()
		return i
