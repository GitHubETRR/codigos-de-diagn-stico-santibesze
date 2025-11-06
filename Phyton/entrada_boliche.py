nombre = input("¿Como te llamas?\n")

edad = int(input("¿Cual es tu edad?\n"))

if edad < 18:
    print("No podes pasasr al boliche ", nombre)
else:
    print("Podes pasar", nombre)
