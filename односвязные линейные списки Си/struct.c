#include <stdio.h>
#include <stdlib.h>


typedef struct MyCustomStruct{
  int value;
  char symbol;
  struct MyCustomStruct *next;
} MyCustomStruct;

struct MyCustomStruct *init(int a, char symbol){
  struct MyCustomStruct *new;
  new = (struct MyCustomStruct*)malloc(sizeof(struct MyCustomStruct));
  new -> value = a;
  new -> symbol = symbol;
  new -> next = NULL;
  return new;
}

struct MyCustomStruct *addelem(MyCustomStruct *lst, int number, char symbol){
  MyCustomStruct *temp, *p;
  temp = (struct MyCustomStruct*)malloc(sizeof(struct MyCustomStruct));
  p = lst->next; // сохранение указателя на следующий узел
  lst->next = temp; // предыдущий узел указывает на создаваемый
  temp->value = number; // сохранение поля данных добавляемого узла
  temp->symbol = symbol;
  temp->next = p; // созданный узел указывает на следующий элемент
  return(temp);
}

void listprint(MyCustomStruct *lst)
{
  MyCustomStruct *newList;
  newList = lst;
  do {
    printf("%d%c\n", newList->value, newList->symbol); // вывод значения элемента p
    newList = newList->next; // переход к следующему узлу
  } while (newList != NULL);
}


int main(int argc, char const *argv[]) {
  MyCustomStruct *head, *newList;
  int number, value;
  char symbol;
  int i = 0;
  printf("number = "); scanf("%d",&number);

  while(i<number)
  	{
  		printf("Введите элемент: "); scanf("%d%c", &value, &symbol);
  		if (i == 0)
  		{
  			newList = init(value, symbol);
  			head = newList;
  		}
  		else {
        newList = addelem(newList, value, symbol);
      }
      i++;
  	}

listprint(head);
  return 0;
}
