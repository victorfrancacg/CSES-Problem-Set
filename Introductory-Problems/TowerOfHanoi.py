def hanoi(discos, start, end, aux):
	if(discos == 0): return

	hanoi(discos - 1, start, aux, end)

	out.append([start, end])

	hanoi(discos - 1, aux, end, start)

n = int(input())

out = []

hanoi(n, 1, 3, 2)

print(len(out))

for x, y in out:
	print(str(x) + " " + str(y))
