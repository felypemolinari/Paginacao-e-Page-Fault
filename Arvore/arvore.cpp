#include <iostream>
#include <chrono> // Para medir o tempo

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    // Construtor
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Função para inserir um novo nó na BST
// Retorna a nova raiz da subárvore
Node* insert(Node* node, int key) {
    // Se a árvore/subárvore estiver vazia, cria um novo nó
    if (node == nullptr) {
        return new Node(key);
    }

    // Caso contrário, desce pela árvore
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    // Retorna o ponteiro do nó (inalterado)
    return node;
}

// Função para buscar uma chave na BST
// Retorna true se a chave for encontrada, false caso contrário
bool search(Node* root, int key) {
    Node* current = root;
    while (current != nullptr) {
        if (key == current->key) {
            return true; // Encontrou
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false; // Não encontrou
}

// Função para deletar a árvore e liberar memória (evitar memory leaks)
void deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Node* root = nullptr;

    //PARÂMETROS PARA AJUSTAR A INTENSIDADE
    
    // Número de nós a inserir na árvore
    // Inserir em ordem cria o pior caso (lista encadeada)
    const int NUM_NODES = 1000000; // 1 milhão de nós

    // Número de buscas a realizar.
    // Buscamos por um valor inexistente para forçar a busca completa
    const long long NUM_SEARCHES = 500000000; // 500 milhões de buscas
    

    cout << "Iniciando criacao da arvore desbalanceada com " << NUM_NODES << " nos..." << endl;
    
    auto start_insert = chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_NODES; ++i) {
        root = insert(root, i);
    }
    auto end_insert = chrono::high_resolution_clock::now();
    chrono::duration<double> insert_duration = end_insert - start_insert;
    cout << "Arvore criada em " << insert_duration.count() << " segundos." << endl;


    cout << "Iniciando " << NUM_SEARCHES << " buscas (pior caso)..." << endl;
    cout << "(Isso pode demorar e vai usar bastante CPU)" << endl;

    auto start_search = chrono::high_resolution_clock::now();
    
    volatile bool result = false; // volatile para evitar otimizações do compilador
    
    for (long long i = 0; i < NUM_SEARCHES; ++i) {
        // Buscamos por -1, que não existe, forçando a percorrer 
        // o caminho mais longo (até o fim da "lista") todas as vezes.
        result = search(root, -1); 
    }
    
    auto end_search = chrono::high_resolution_clock::now();
    chrono::duration<double> search_duration = end_search - start_search;
    
    cout << "Buscas concluidas." << endl;
    cout << "Tempo total das buscas: " << search_duration.count() << " segundos." << endl;

    // Limpa a memória
    cout << "Limpando memoria..." << endl;
    deleteTree(root);
    cout << "Concluido." << endl;

    return 0;
}