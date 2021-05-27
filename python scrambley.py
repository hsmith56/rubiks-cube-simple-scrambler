import random
moves, b = ["U","F","L","R","B","D"], []
b.append(random.choice(moves))
for i in range(19):
	while (x:=random.choice(moves)) == "".join(x for x in b[len(b)-1] if x.isalpha()): pass
	b.append(("2" if (y:=random.randint(0,2) == 1) else "") + x + ("'" if y == 0 else ""))
print(f'[{" ".join(b)}]')
