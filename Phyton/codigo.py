cuenta = int(input("Total de la cuenta:\n"))
personas = int(input("Cantidad de personas a pagar:\n"))
print("La propina sera tomada como un 10%")

total = cuenta + cuenta * 0.10
por_persona = total / personas

print("El total seria: $", total)
print("El total por persona seria: $", por_persona)