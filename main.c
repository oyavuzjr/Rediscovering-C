#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Todo{
    char text[20];
    bool completed;
};

struct TodoList{
    struct Todo *todos;
    int size;
};

struct TodoList* initialize_todolist(){
    struct TodoList *list = (struct TodoList *)malloc(sizeof(struct TodoList));
    list->todos=NULL;
    list->size=0;
    return list;
};

void add_todo(struct TodoList *list,char *text){
    list->todos = (struct Todo*)realloc(list->todos,((list->size+1)*sizeof(struct Todo)));
    strcpy((*list).todos[list->size].text,text);
    list->size++;
}

void print_todos(struct TodoList *list){
    for(int i=0; i<list->size; i++){
        printf("  %s\t#%i %s\n",list->todos[i].completed==true?"✅":"❌",i+1,list->todos[i].text);
    }
}

void toggle_todo(struct TodoList *list, int i){
    list->todos[i-1].completed=!(list->todos[i-1].completed);
}

void print_prompt(struct TodoList *list){
    printf("🔥🤯🔥  NEXT GEN TODO LIST 🔥🤯🔥\n");
    printf("---------------------------------\n");
    print_todos(list);
    printf("\nSelect Option\n-------------\n");
    //Options
    printf("1. Add Todo\n");
    if(list->size>0){
        printf("2. Mark Done\n");
        printf("3. Remove Todo\n");
    }
}

int main() {
    struct TodoList *list = (initialize_todolist());
    add_todo(list,"Hello, World!");
    print_prompt(list);    
}
