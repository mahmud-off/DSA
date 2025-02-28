#include <iostream>

#define MAP_SIZE 20

//search
//insert
//delete

typedef struct value {
    int key;
    int data;
}VALUE;

struct Node {
    struct Node* n;
    struct Node* p;
    int value;
};

typedef struct map {
    struct Node* tabl[MAP_SIZE];
}MAP;

struct Node* create_node(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->n = node;
    node->p = node;
    return node;
}

MAP* createMap() {
    MAP* map = (MAP*)malloc(sizeof(MAP));

    for(int i = 0; i < MAP_SIZE; i++) {
        map->tabl[i] = create_node(0); // по сути наш head в linked list изначально будет 0
    }

    return map;
}

int hach_func(int key) { //да-да, хач функ
    int hach = key % MAP_SIZE;
    return hach;
}


void add_value(MAP* map, VALUE* value) {
    int hach = hach_func(value->key);

    map->tabl[hach]->value = 1; // флаг записи числа.

    struct Node* node = create_node(value->data);
    node->n = map->tabl[hach]; // закольцевал с head'ом
    node->p = map->tabl[hach]->p; // соединил с прежыдущим
    map->tabl[hach]->p = node; // обновил предыдущий / закольцевал
    node->p->n = node; // связал предыдущую и новую
    return;
}

void delete_value(MAP* map, int key) {
    int hach = hach_func(key);

    if(map->tabl[hach]->value == 1) {
        struct Node* node = map->tabl[hach]->p;
        node->p->n = map->tabl[hach];//связал предыдущий и голову
        map->tabl[hach]->p = node->p;//связал голову и преыдущий
        free(node);
        if(map->tabl[hach]->n == map->tabl[hach]) {
            map->tabl[hach]->value = 0;
        }
    }
    else {
        std::cout<<"Value is not exist." << std::endl;
    }
    return;
}


VALUE* createValue(int key, int data) {
    VALUE * x = (VALUE*)malloc(sizeof(VALUE));
    x->data = data;
    x->key = key;
    return x;
}

void printTable(MAP* map) {
    for(int i = 0; i < MAP_SIZE; i++) {
        if(map->tabl[i]->value == 1) {
            std::cout << i << ": "; // наш хач

            struct Node* node = map->tabl[i]->n;
            while(node != map->tabl[i]) {
                std::cout << node->value << " ";
                node = node->n;
            }
            std::cout<<"\n";
        }
    }
}

void search(MAP* map, int key) {
    int hach = hach_func(key);
    if(map->tabl[hach]->value == 1) {
        std::cout << key << ": "; // ключ

        struct Node* node = map->tabl[hach]->n;
        while(node != map->tabl[hach]) {
            std::cout << node->value << " ";
            node = node->n;
        }
        std::cout<<"\n";
    }
}

int main()
{
    MAP * map = createMap();

    VALUE* a = createValue(13   , 14);
    VALUE* a1 = createValue(13, 17);

    add_value(map, a);
    add_value(map, a1);
    search(map, a->key);
    delete_value(map, a->key);
    search(map, a->key);

    std::cout << "Hash Table!" << std::endl;
    return 0;
}
