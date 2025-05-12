import matplotlib.pyplot as plt # type: ignore

# Tamanhos dos vetores
tamanhos = [100, 1000, 10000, 100000]

# Dados de exemplo coletados manualmente
tempos = {
    'Inserção': [0, 2, 29, 2049],
    'Bolha':    [0, 3, 88, 13702],
    'Seleção': [0, 3, 33, 2041],
}

comparacoes = {
    'Inserção': [2448, 255815, 24799589, 2501919881],
    'Bolha':    [4884, 496497, 49987740, 4999872579],
    'Seleção': [4950, 499500, 49995000, 4999950000],
}

movimentacoes = {
    'Inserção': [2450, 255819, 24799603, 2501919890],
    'Bolha':    [7053, 764460, 74368812, 7505459673],
    'Seleção': [285, 2976, 29961, 299964],
}

def plotar_grafico(titulo, dados, ylabel):
    for algoritmo, valores in dados.items():
        plt.plot(tamanhos, valores, marker='o', label=algoritmo)
    
    plt.title(titulo)
    plt.xlabel("Tamanho do vetor")
    plt.ylabel(ylabel)
    plt.legend()
    plt.xscale("log")   
    plt.yscale("log")   
    plt.grid(True)
    plt.show()

plotar_grafico("Tempo de Execução (ms)", tempos, "Tempo (ms)")
plotar_grafico("Número de Comparações", comparacoes, "Comparações")
plotar_grafico("Número de Movimentações", movimentacoes, "Movimentações")
