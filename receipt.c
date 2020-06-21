//Jonathan Liao
//Receipt.c

#include <stdio.h>
#include <stdlib.h>
#include "retail_item.h"
#include "receipt.h"

receipt * create_receipt() {
return NULL; //linked list is empty
}

void add_item(receipt ** rec_ptr, retail_item it){
receipt * rec = *rec_ptr;
receipt * prev = NULL; //I don't really need this, but vandegrift insists

//case1
if(rec == NULL) {
  rec = (receipt *)malloc(sizeof(receipt) );
  rec->item = it;
  rec->next = NULL;
  *rec_ptr = rec;
  return;
}
//case2
if(it.number >= rec->item.number) {//item ID# of added item is greater than the item ID# of previous item
  receipt * newRec = (receipt *)malloc(sizeof(receipt) );
  newRec->item = it;
  newRec->next = *rec_ptr;
  *rec_ptr = newRec;
  return;
}
//case3
if(it.number < rec->item.number) {
  receipt * newRec = (receipt *)malloc(sizeof(receipt) );
  newRec->item = it;
  newRec->next = NULL; //for now

  rec = *rec_ptr; //assigned rec as starting head value DO I REALLY NEED THIS??????????????????????
  while(rec->next != NULL) {
	if(it.number >= rec->next->item.number) {
    	    newRec->next = rec->next;
	    rec->next = newRec;
	    return;
        }
	rec = rec->next;
  }
//case4 (inside case 3 since if the loop traverses through the entire linked list and reaches where
//rec->next == NULL, that means we've reached the end. The difference of Case 3/4 is case 4 assigns
//newRec->NULL since it's the end
  if(rec->next == NULL) {
	rec->next = newRec;
	newRec->next = NULL;
	return;
  }
}


}

int delete_item(receipt ** rec_ptr, int item_num){
  receipt * rec = *rec_ptr;
  receipt * prev = NULL;
  //case1, the receipt is empty to begin with
  if(rec == NULL) {
	printf("Nothing to delete. Receipt is empty\n");
	return 0;
  }
  //case2, first item in receipt is thing we want to delete
  if(rec->item.number == item_num) {
	*rec_ptr = rec->next;
	free(rec);
	printf("Succesfully deleted item %d\n", item_num);
	return 1;
  }
  //case3, item wanted to delete is somewhere in the receipt. Must traverse through  
  if(rec->item.number != item_num) {
	
	while(rec->next != NULL) {
	prev = rec; //keep track of previous node before moving to next one
	rec = rec->next;
	   if(rec->item.number == item_num) {		
    	    	prev->next =rec->next;
	   	free(rec);
		printf("Succesfully deleted item %d\n", item_num);
	    	return 1;
           }
	}
  printf("could not find item %d. Failed to delete\n", item_num);
  return 0;
  }
}	


void print_receipt(receipt * rec){
int sum = 0;
printf("Receipt:\n");
  while(rec != NULL) {
     print(rec->item);
     sum += rec->item.price_cents;
     rec = rec->next;
  }
  printf("Total sum of this receipt is $%.02f\n\n", ((double)sum/100.00) );
  return;
  //Below, I tried to use a recursive function, but was problematic for printing $sum total

  /*if(rec == NULL) { 
    return; Nothing to print. The receipt is empty
  }
  else {
    print(rec->item);
    print_receipt(rec->next);
    return;
  }
  */

}

void free_receipt(receipt * rec){
  if(rec == NULL) {
    return; //nothing to free
  }
  if(rec->next == NULL) {
    free(rec); //nothing else to free after this
    return;
  }
  else {
    free_receipt(rec->next);
    free(rec); 
    return;
  }
}




