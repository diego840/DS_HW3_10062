void sort_function(int a){
    long long int max;
    for (int i = 0; i < a; i++){
        scanf("%lld",&array[i]);
        for(int j=0;j < i; j++){
            if (array[i]<array[j]){
                max = array[j];
                array[j]=array[i];
                array[i]=max;
            }
        }
    }
}