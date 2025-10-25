import time
import sys

# Definição do nó da árvore
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Função para inserir um novo nó na BST (de forma iterativa)
# Isso evita o estouro do limite de recursão do Python
def insert(root, key):
    new_node = Node(key)
    
    # Se a árvore está vazia, o novo nó é a raiz
    if root is None:
        return new_node
    
    current = root
    while True:
        if key < current.key:
            # Vai para a esquerda
            if current.left is None:
                current.left = new_node
                return root # Retorna a raiz original
            current = current.left
        else:
            # Vai para a direita (ou igual)
            if current.right is None:
                current.right = new_node
                return root # Retorna a raiz original
            current = current.right

# Função para buscar uma chave na BST (de forma iterativa)
def search(root, key):
    current = root
    while current is not None:
        if key == current.key:
            return True # Encontrou
        elif key < current.key:
            current = current.left
        else:
            current = current.right
    return False # Não encontrou

# --- PARÂMETROS PARA AJUSTAR A INTENSIDADE ---

# AVISO: Estes números são BEM MENORES que a versão C++.
# Python é muito mais lento para esta tarefa.

# O custo de construção é O(N^2), então 50.000 já é pesado.
NUM_NODES = 50000  # 50 mil nós (em vez de 1 milhão)

# O custo de busca é O(M*N).
NUM_SEARCHES = 100000 # 100 mil buscas (em vez de 500 milhões)

# ---------------------------------------------

# Python não tem um limite de "int" como C, mas 
# é bom saber o limite de recursão (que evitamos)
# print(f"Limite de recursao do Python: {sys.getrecursionlimit()}")

root = None

print(f"Iniciando criacao da arvore desbalanceada com {NUM_NODES} nos...")
print("(Isso ja vai ser O(N^2) e pode demorar um pouco)...")

start_insert = time.perf_counter() # Medidor de tempo mais preciso

# Inserindo em ordem para forçar o pior caso (O(N^2) no total)
for i in range(NUM_NODES):
    root = insert(root, i)
    
end_insert = time.perf_counter()
insert_duration = end_insert - start_insert
print(f"Arvore criada em {insert_duration:.4f} segundos.")


print(f"Iniciando {NUM_SEARCHES} buscas (pior caso)...")
print("(Isso pode demorar e vai usar bastante CPU)")

start_search = time.perf_counter()

result = False
for i in range(NUM_SEARCHES):
    # Buscamos por -1, que não existe, forçando a percorrer 
    # o caminho mais longo (O(N)) todas as vezes.
    result = search(root, -1) 

end_search = time.perf_counter()
search_duration = end_search - start_search

print("Buscas concluidas.")
print(f"Tempo total das buscas: {search_duration:.4f} segundos.")

# Em Python, a limpeza de memória (Garbage Collection) é automática.
# Apenas definimos root como None para sinalizar que não usamos mais.
root = None 
print("Concluido.")