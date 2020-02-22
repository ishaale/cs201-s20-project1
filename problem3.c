/*
 *Problem 3
 *Author: Elisha Ishaal
*/

 #include <stdio.h>

int main(){

    int n;
	scanf("%d", &n);

	//convert to array of binary with least significant digit first
	int binary[32];
	for (int i = 0; i < 32; i++){
        binary[i] = 0;
    }
    int j = 0;
    while (n > 0) {
        binary[j] = n % 2;
        n = n / 2;
        j++;
    }

    //split into two different binary arrays
    int abin[32];
    int bbin[32];
    for (int i = 0; i < 32; i++){
        abin[i] = 0;
        bbin[i] = 0;
    }

    int swap = 1;//determines which binary to put the 1
    for (int i = 0; i < 32; i++) {
        if (binary[i] == 1){
            if (swap == 1){
                abin[i] = binary[i];
                swap = 2;
            }
            else{
                bbin[i] = binary[i];
                swap = 1;
            }
        }
    }

    //convert back to decimal
    int a = 0;
    // Initialize base value to 2^0 = 1 which increses by power of 2 with each iteration
    int base = 1;
    for (int i = 0; i < 32; i++) {
        if (abin[i] == 1) a += base;
        base = base * 2;
    }

    int b = 0;
    // Initialize base value to 2^0 = 1 which increses by power of 2 with each iteration
    base = 1;
    for (int i = 0; i < 32; i++) {
        if (bbin[i] == 1) b += base;
        base = base * 2;
    }

    printf("%d ", a);
    printf("%d", b);

	return 0;
}
