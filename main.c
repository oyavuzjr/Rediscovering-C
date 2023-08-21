#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TODO_LENGTH 18

struct Todo{
    char text[TODO_LENGTH];
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
        printf("  \t#%i  %-17s%s\n",i+1,list->todos[i].text,list->todos[i].completed==true?"✅":"❌");
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
        printf("\n4. Exit.\n");
    }
}

void dispatch_choice(struct TodoList* list){
    int number;
    scanf("%d", &number);
    getchar(); // Consume the newline character left in the input buffer

    switch (number)
    {
    case 1:
        printf("Enter Todo:");
        char newTodo[TODO_LENGTH];
        fgets(newTodo, sizeof(newTodo), stdin);
        // Remove newline character if present
        newTodo[strcspn(newTodo, "\n")] = '\0';
        add_todo(list,newTodo);
        break;
    
    default:
        break;
    }

}

int main() {
    struct TodoList *list = (initialize_todolist());
    add_todo(list,"Hello, World!");
    while(true){
        print_prompt(list);    
        dispatch_choice(list);
    }
}
