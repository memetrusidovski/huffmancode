typedef bool (*compare_function)(const void *, const void *);
typedef void (*free_function)(void *);   

struct node {
    struct node *next;
    void *data;
};

struct node *create_node(const void * data) {
    struct node *new_node = malloc(sizeof *new_node);
    
    if(new_node) {
        new_node->data = (void*)data;
        new_node->next = NULL;
    }
    
    return new_node;
}

struct node *insert(struct node **head, const void *data) {
    struct node *new_node = create_node(data);
    
    if(new_node) {
        new_node->next = *head;
        *head = new_node;
    }

    return new_node;
}

struct node *append(struct node **head, const void *data) {
    struct node *new_node = create_node(data);
    struct node **walk = head;
    
    if(new_node) {
        while(*walk)
            walk = &(*walk)->next;
        *walk = new_node;
    }

    return new_node;
}

struct node *find(struct node **head, const void *data, compare_function cmp) {
    struct node *walk = *head;

    while(walk) {
        if(cmp(walk->data, data)) break;
        walk = walk->next;
    }

    return walk;
}

size_t size(struct node **head) {
    size_t ret = 0;
    struct node *walk = *head;
    
    while(walk) {
        walk = walk->next;
        ret++;
    }

    return ret;
}
              
// Pre:
//    node exists in list pointed to by head
void delete(struct node **head, struct node *node, free_function ff) {
    struct node **walk = head;

    while(*walk != node) {
        walk = &(*walk)->next;
    }

    *walk = node->next;
    ff(node->data);
    free(node);
}
