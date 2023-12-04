#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

list_ptr list_new(void)
{
  list_ptr ma_liste;
  ma_liste = NULL;
  return ma_liste;
}

list_ptr list_add(sprite_t sprite, list_ptr list)
{
  list_ptr mlp;
  mlp = malloc(sizeof(struct list_node));
  mlp->data = sprite;
  mlp->next = list;
  return mlp;
}

int list_length(list_ptr l)
{
  int taille_liste = 0;
  while(l)
  {
    taille_liste++;
    l = l->next;
  }
  return taille_liste;
}

void list_reverse(list_ptr * l)
{
  int i = list_length(*l);
  list_ptr p;
  p = *l;
  while(i != 0)
  {
    *l = (p+i);
    i--;
    *l = (*l)->next;
  }
}

list_ptr list_clone(list_ptr list)
{
  list_ptr mlp = malloc(sizeof(struct list_node));
  mlp->data = list->data;
  mlp->next = list->next;
  return mlp;
}

bool list_is_empty(list_ptr l)
{
  if(l)
    return false;
  else
    return true;
}

sprite_t list_head_sprite(list_ptr l)
{
  return l->data;
}

list_ptr list_next(list_ptr l)
{
  if(l->next == NULL)
  {
	return NULL;
  }
  else
  {
  return l->next;
  }
}

sprite_t list_pop_sprite(list_ptr * l)
{
  sprite_t sp;
  list_ptr loc = list_new();
  loc = *l;
  while(loc != NULL)
  {
    if(loc->next->next == NULL)
    {
      sp = loc->data;
      loc->next = NULL;
      break;
    }
    loc = loc->next;
  }
  return sp;
}

void list_remove(list_ptr elt, list_ptr *l)
{
  list_ptr ptr = *l;
  list_ptr prev_ptr = NULL;

  if(*l != NULL){
    if(*l == elt){
      *l = (*l)->next;
    }else{
      while(ptr != elt){
        prev_ptr = ptr;
	ptr = ptr->next;
      }
      prev_ptr->next = ptr->next;
      free(ptr->data);
      free(ptr);
    }
  }
}

void list_free(list_ptr l)
{
  list_ptr ptr;
  while(l != NULL){
    ptr = l->next;
    free(l->data);
    free(l);
    l = ptr;
  }
  free(l);
}
