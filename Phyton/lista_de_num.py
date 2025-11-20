numeros = []

cantidad = int(input("Cuantos numeros queres ingresar?\n"))

for i in range(cantidad):
num = int(input("Ingresar numero: "))
numeros.append(num)

print("\nLista completa: ", numeros)

mayor = max(numeros)
menor = min(numeros)
promedio = sum(numeros)/len(numeros)

print("mayor: ", "menor: ", menor "promedio", promedio)


