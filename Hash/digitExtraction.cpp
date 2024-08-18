long int midSquare(long int seed)
{
    seed = seed * seed;
    seed /= 100;
    return seed % 10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
   int tmp[1000];
    for(int i = 0;i < 1000; i++) tmp[i] = -1;
    int i = 0;
    while(seed > 0){
        tmp[i] = seed % 10;
        seed /= 10;
        i++;
    }
    long int result = 0;
    long int n = 1;
    int j = 0;
    while(size){
        result = result * 10 + tmp[i - extractDigits[j] - 1];
        j += 1;
        n *= 10;
        size --;
        
    }
    return result;
}