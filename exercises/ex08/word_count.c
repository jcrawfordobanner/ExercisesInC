#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// gboolean finder(char* key, int value, gpointer user_data) {
//  return (strcmp(key,buf));
// }
void iterator(gpointer key, gpointer value, gpointer user_data) {
  printf("%s %d\n",(char*)key, *(int*)value);
}
int main(int argc, char** argv) {
  FILE *theboi;
  char buf[1000];
  char * hell;
  GHashTable* hash = g_hash_table_new(g_str_hash,g_str_equal);
  theboi = fopen("frank.txt","r");
  if(!theboi){
    return 1;
  }
  int i = 100;
  fgets(buf,1000,theboi);
  hell =strtok(buf," ");
  while(hell!=NULL){
    i-=1;
    if(g_hash_table_lookup(hash,hell)){
      int *v= malloc(sizeof(int*));
      *v=*(int*)g_hash_table_lookup(hash,hell)+1;
      g_hash_table_replace(hash,hell,v);
      hell =strtok(NULL," ");
    }
    else{
      int *v= malloc(sizeof(int*));
      *v=1;
      g_hash_table_insert(hash,hell,v);
      hell =strtok(NULL," ");
    }
  }
  g_hash_table_foreach(hash, (GHFunc)iterator, "The square of %s\n");
  g_hash_table_destroy(hash);
  fclose(theboi);
}
