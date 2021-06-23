b, random, times =  [''], __import__('random'), int(input("How many scrambles would you like: "))
for i in range(times*20):
    while not (x:=random.choice(["U","F","L","R","B","D"])) == "".join(x for x in b[len(b)-1] if x.isalpha()) and len(b) <= 20*times: b.append(x + ("2" if (y:=random.randint(0,2) == 1) else "") + ("'" if y == 0 else ""))
print("\n".join([" ".join(b[i+1:i+21]) for i in range(0, len(b)-1, 20)]))