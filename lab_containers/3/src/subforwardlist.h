struct subforwardlist {
    int data;
    subforwardlist* next;
};

void init(subforwardlist **sfl); 	//инициализация пустого недосписка
void push_back(subforwardlist **sfl, int d); 	//добавление элемента в конец недосписка
void pop_back(subforwardlist **sfl); 	//удаление элемента с конца недосписка, если пустой - возвращать 0
void push_forward(subforwardlist **sfl, int d); 	//добавление элемента в начало недосписка
void pop_forward(subforwardlist **sfl); 	//удаление элемента из начала недосписка, если пустой - возвращать 0
void push_where(subforwardlist **sfl, unsigned int where, int d); //добавление элемента с порядковым номером where
void erase_where(subforwardlist **sfl, unsigned int where);	//удаление элемента с порядковым номером where, если пустой - возвращать 0
unsigned int size(subforwardlist  **sfl);	//определить размер недосписка
void clear(subforwardlist  **sfl);//очистить содержимое недосписка

void init(subforwardlist **sfl){
    *sfl = NULL;
}

void push_back(subforwardlist **sfl, int d){
    if(!(*sfl)) {
        *sfl = new subforwardlist();
        (*sfl)->data = d;
        (*sfl)->next = NULL;
    }
    subforwardlist *current_node=*sfl;
    while(current_node->next){
        current_node=current_node->next;
    }
    subforwardlist *new_el= new subforwardlist();
    new_el->data=d;
    new_el->next=NULL;
    current_node->next=new_el;
}
void pop_back(subforwardlist **sfl){
    if(!(*sfl)) return;
    if(!(*sfl)->next){
        int tmp_data = (*sfl)->data;
        delete *sfl;
        *sfl = NULL;
    }
    subforwardlist *current_node = *sfl;
    while(current_node->next->next){
        current_node = current_node->next;
    }
    int tmp_data = current_node->next->data;
    delete current_node->next;
    current_node->next = NULL;
}
void push_forward(subforwardlist **sfl, int d){
    subforwardlist *new_start = new subforwardlist();
    new_start->data = d;
    new_start->next = *sfl;
    *sfl = new_start;
}
void pop_forward(subforwardlist **sfl){
    if(!(*sfl)) return;
    int tmp_data = (*sfl)->data;
    subforwardlist *tmp = (*sfl)->next;
    delete *sfl;
    *sfl = tmp;
}
void push_where(subforwardlist **sfl, unsigned int where, int d) //добавление элемента с порядковым номером where
{
    if(!(*sfl)){
        push_forward(sfl,d);
    }
    subforwardlist *current_node=*sfl;
    unsigned int n = 0;
    if(where == 0) push_forward(sfl,d);
    if(where >= size(sfl)) return;
    while(n<where-1){
        current_node=current_node->next;
        n++;
    }
    subforwardlist *new_el = new subforwardlist();
    new_el->data = d;
    new_el->next = current_node->next;
    current_node->next=new_el;
}
void erase_where(subforwardlist **sfl, unsigned int where)	//удаление элемента с порядковым номером where, если пустой - возвращать 0
{
    if(!(*sfl)) return;
    subforwardlist *current_node=*sfl;
    unsigned int n=0;
    if(where >= size(sfl)) return;
    while(n<where-1){
        current_node=current_node->next;
        n++;
    }
    int tmp_data = current_node->next->data;
    subforwardlist *nextnext_node = current_node->next->next;
    delete current_node->next;
    current_node->next=nextnext_node;
}

unsigned int size(subforwardlist  **sfl)	//определить размер недосписка
{
    if(!(*sfl)) return 0;
    int len=1;
    subforwardlist *current_node=*sfl;
    while (current_node->next)
    {
        current_node = current_node->next;
        len++;
    }
    return len;


}

void clear(subforwardlist  **sfl){
    if(!(*sfl)) return;
    clear(&(*sfl)->next);
    delete *sfl;
    *sfl=NULL;
}
