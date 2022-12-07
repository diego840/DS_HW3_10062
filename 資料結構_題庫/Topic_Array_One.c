#include <stdio.h>
char fnumber[1000][1000] = {
    "*****", // 0   (index:0)
    "*   *",
    "*   *",
    "*   *",
    "*****",
    "    *", // 1   (index:5)
    "    *",
    "    *",
    "    *",
    "    *",
    "*****", // 2   (index:10)
    "    *",
    "*****",
    "*    ",
    "*****",
    "*****", // 3   (index:15)
    "    *",
    "*****",
    "    *",
    "*****",
    "*   *", // 4   (index:20)
    "*   *",
    "*****",
    "    *",
    "    *",
    "*****", // 5   (index:25)
    "*    ",
    "*****",
    "    *",
    "*****",
    "*    ", // 6   (index:30)
    "*    ",
    "*****",
    "*   *",
    "*****",
    "*****", // 7   (index:35)
    "    *",
    "    *",
    "    *",
    "    *",
    "*****", // 8   (index:40)
    "*   *",
    "*****",
    "*   *",
    "*****",
    "*****", // 9   (index:45)
    "*   *",
    "*****",
    "    *",
    "    *"};
void number_display(int *store_num){
  for (int i = 0; i <= 4; i++){
    for (int j = 0; j < 4; j++){
      if (j<3){
        printf("%s ",fnumber[store_num[j] * 5 + i]);
      }else{
        printf("%s",fnumber[store_num[j] * 5 + i]);
      }
    }
    printf("\n");
  }
}
int main(){
  int Input_number,a_number,j=0;
  int store_num[10];
  while (scanf("%d",&Input_number) != EOF){
    for (int i = 1000; i > 1; i=i/10){
      a_number = Input_number/i;
      store_num[j] = a_number;
      Input_number=Input_number-(i*a_number);
      j++;
    }
    store_num[j] = Input_number;
    number_display(store_num);
    j=0;
  }
  return 0;
}