import math

L = int(input())

for a in range(1, L + 1):
  for b in range(a, L + 1):
    c = math.sqrt(a**2 + b**2)
    r = a * b * c / math.sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c))
    