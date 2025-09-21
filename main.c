#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  // tom variable til input
  char input[50] ="";

  // array af spareparts
  const char *inventory[] = {
      [0] = "hydraulic pump", 
      [1] = "PLC module", 
      [2] = "servo motor"};
  const char *special_queries[] ={
      [0] = "Do you actually have any parts?", 
      [1] = "Is there anything in stock at all?"};
  int part_count = sizeof(inventory) / sizeof(inventory[0]);
  printf("Hej. Welcome to the spare parts inventory!\n"); // velkomstbesked
  
  while (1) {
    
    int found_part = 0;
    int found_special_q = 0;
    printf("Which part do you need?\n");
    fgets(input, sizeof(input),stdin);
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input,"quit") == 0){
      printf("Thanks for using the spare parts inventory! Farewell!\n");
      break;
    }
    for (size_t i = 0; i < part_count; i++){
      if (strcmp(inventory[i], input) == 0){
      found_part = 1;
      break;
      }
    }
      for (size_t s = 0; s < sizeof(special_queries) / sizeof(special_queries[0]); s++){
        if (strcmp(special_queries[s], input) == 0){
      found_special_q = 1;
      break;
      }
      }
  
    if (found_part == 1){
      printf("I have got %s here for you 😊. Bye!\n",input);
      break;
    }
    if (found_special_q == 1){
      printf("We have %d part(s)!\n",part_count);
      for(size_t i = 0; i < part_count; i++){
        printf("%s\n",inventory[i]);
      }
    }
    else { 
      printf("I am afraid we don't have any %s in the inventory 😔\n",input);
    }
  }
}
