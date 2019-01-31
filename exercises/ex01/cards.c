#include <stdio.h>
#include <stdlib.h>


/*
Takes in a card name and returns the value associtated
with the card name

card_name: the last inputted card
*/
int cardValue(char card_name[]){
  int val;
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    default:
      val = atoi(card_name);
  }
  return val;
}


/*
Takes the card value and the last registered count
and increases or decreases the count based upon the card value

count: the last count val:the last card value
*/
int countaddr(int count, int val){
  if ((val > 2) && (val < 7)) {
    count++;
  }

  else if (val == 10) {
    count--;
  }
  return count;
}

/*
Gets the card name from the user

card_name: place holder for the user's value
*/
char getEntry(char card_name[]){
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
  return card_name;
}


/*
Counts cards by taking in a card from the user and calculating
a value based upon the cards the user has inputted.
*/
int main()
{
    int val = 0;
    char card_name[3];
    int count = 0;
    while (card_name[0] != 'X') {
      getEntry(card_name);
      val = cardValue(card_name);
      if((val < 1) || (val > 10)) {
        puts("I don't understand that value!");
        continue;
      }
      count = countaddr(count,val);
      printf("Current count: %i\n", count);
    }
    return 0;
}
