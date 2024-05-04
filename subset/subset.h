struct subset_node {
    int key;
    subset_node *left;
    subset_node *right;
};

bool init(subset_node **sn); // инициализация пустого дерева (аналогично списку, пустое дерево это указатель на NULL)
bool insert(subset_node **sn, int k); // добавление элемента в дерево, дубли игнорировать (ничего не добавлять в дерево, если там уже есть элемент с таким же key) и возвращать false
bool remove(subset_node **sn, int k); // удаление элемента из дерева (если элемента не нашлось, то ничего не удалять и вернуть false)
subset_node* find(subset_node *sn, int k); // поиск элемента в дереве, нужно вернуть указатель на элемент с тем же key или, если такого элемента не нашлось, то NULL
unsigned int size(subset_node *sn); // количество элементов в дереве
unsigned int height(subset_node *sn); // высота дерева
void destructor(subset_node **sn); // очистить всю используемую память
int* DFS (subset_node *sn); //обход в глубину, возвращает указатель на массив из динамической памяти (кучи)

bool init(subset_node **sn){
    *sn=NULL;
    return true;
}

subset_node* find(subset_node *sn, int k){
    if(!sn) {return NULL;}
    if(sn->key==k) return sn;
    if(k>sn->key) return find(sn->right,k);
    else return find(sn->left,k);
    return NULL;
}
subset_node** find_pointer(subset_node **sn, int k){
    if(!sn) {return NULL;}
    if((*sn)->key==k) return sn;
    if((*sn)->left){
        if((*sn)->left->key==k)
            return &(*sn)->left;
        if(k < (*sn)->key)
            return find_pointer(&(*sn)->left,k);
    }
    if((*sn)->right){
        if((*sn)->right->key==k)
            return &(*sn)->left;
        if(k > (*sn)->key)
            return find_pointer(&(*sn)->right,k);
    }
    return NULL;
}

int maxm(unsigned int a, unsigned int b){
    if(a>b) return a;
    return b;
}

bool insert(subset_node **sn, int k){
    if(!(*sn)){
        subset_node *tmp = new subset_node();
        tmp->key=k;
        tmp->left=NULL;
        tmp->right=NULL;
        *sn=tmp;
        return true;
    }
    if((*sn)->key==k){ return false;}
    if(k<(*sn)->key) insert(&(*sn)->left,k);
    else insert(&(*sn)->right,k);
    return true;
}
subset_node** most_left(subset_node **sn){
    if(!sn) return NULL;
    if(!(*sn)) return NULL;
    if(!(*sn)->left) return sn;
    return most_left(&(*sn)->left);
}

bool remove(subset_node **sn, int k){//Возвращать ** из мост лефт и файнд
    if(!(*sn)) return false;
    subset_node** to_delete = find_pointer(sn, k);
    if(!(to_delete) or !(*to_delete)) return false;
    subset_node* delete_l = (*to_delete)->left;
    subset_node* delete_r = (*to_delete)->right;
    delete *to_delete;
    if(delete_r){
        subset_node** m_left = most_left(&delete_r->left);
        *to_delete=delete_r;
        if(m_left){
            (*m_left)->left=delete_l;
        }
        else{
            delete_r->left = delete_l;
        }
    }
    else if(delete_l){
        *to_delete=delete_l;
    }
    else{
        *to_delete=NULL;
    }

    return true;
};
unsigned int size(subset_node *sn){
    if(!sn)return 0;
    if(sn->left==NULL and sn->right==NULL) return 1;
    if(sn->left==NULL) return size(sn->right)+1;
    if(sn->right==NULL) return size(sn->left)+1;
    return size(sn->left) + size(sn->right)+1;
};
unsigned int height(subset_node *sn){
    if(!sn) return 0;
    if(sn->left==NULL and sn->right==NULL) return 1;
    return maxm(height(sn->left)+1,height(sn->right)+1);
};
void destructor(subset_node **sn){
    if(!sn) return;
    if(!(*sn)) return;
    if((*sn)->left==NULL and (*sn)->right==NULL){
        delete *sn;
        *sn=NULL;
        return;
    }
    destructor(&(*sn)->left);
    destructor(&(*sn)->right);
    return;
};

void go_through(subset_node *sn, int* out, int* id){
    if(!sn) return;
    go_through(sn->left,out,id);
    out[*id]=sn->key;
    *id = *id + 1;
    go_through(sn->right,out,id);
    return;
}

int* DFS (subset_node *sn){
    if(!sn) return new int(0);
    int* out = new int[size(sn)];
    int* id = new int(0);
    go_through(sn,out,id);
    delete id;
    return out;
};

