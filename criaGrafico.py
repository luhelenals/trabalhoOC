import matplotlib.pyplot as plt
nome = input("Nome do arquivo: ")
file_path = r"C:\Users\luiza\OneDrive\Área de Trabalho\projetos\C\2023.1\projetoOC\\" + nome

# Read the file and extract data
with open(file_path, "r") as file:
    linhas = file.readlines()

# Extract x and y values from the file
valoresX = []
valoresY = []
for numero, linha in enumerate(linhas, start=1):
    valoresX.append(numero)
    valoresY.append(float(linha.strip()))

# Plot the graph
plt.plot(valoresX, valoresY)
#plt.xlabel("Número ")
plt.ylabel("Valor em milissegundos")
plt.title("Registros dos tempos do arquivo " + nome)
plt.show()