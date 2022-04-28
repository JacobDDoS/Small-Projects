#include <bits/stdc++.h>

void increment(int *p) {
    *p = (*p) + 1;
}

int sumOfElements(int A[], int size) {
    int sum = 0;
    // int size = sizeof(A)/sizeof(A[0]);
    for (int i=0;;i++) {
        sum+= A[i];
    }
    return sum;
}

void Double(int A[], int size) {
    for (int i=0;i<size;i++) {
        A[i]*=2;
    }
}

void Print(char* C) {
    while (*C != '\n') {
        printf("%c ", *C);
        C++;
    }
}

// int *Add(int* a, int* b) {
//     int* c = (int*)malloc(sizeof(int));
//     *c = (*a) |+ (*b);
//     return c;
// }

int Add(int a, int b) {
    return a+b;
}

void printHelloWorld() {
    std::cout << "Hello World!" << std::endl;
}

void A() {
    printf("hello");
}

void B(void (*ptr)()) {
    ptr(); //call-back function that "ptr" points to
}

void bubbleSort(int A[], int n, int (*compare)(int,int)) {
    int i,j,temp;
    for (i=0;i<n;i++) {
        for (j=0;j<n-1;j++) {
            if (compare(A[j], A[j+1]) > 0) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

// int compare(int a, int b) {
//     if (a>b) return 1;
//     return -1;
// }

int compare(const void* a, const void* b) {
    int A = *((int*)a);
    int B = *((int*)b);
    return A-B;
}

int absoluteCompare(int a, int b) {
    if (abs(a) > abs(b)) return 1;
    return -1;
}

int cash = 100;

void Play(int bet) {
    char* C = (char*)malloc(3*sizeof(char)); // C++ -> char *C = new char[3];
    C[0] = 'J'; C[1] = 'Q'; C[2] = 'K';
    printf("Shuffling...");
    srand(time(NULL));
    for (int i=0;i<5;i++) {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }
    int playersGuess;
    printf("What's the position of queen - 1, 2, or 3?\n");
    scanf("%d", &playersGuess);
    if (C[playersGuess-1] == 'Q') {
        cash += 3*bet;
        printf("You Win! Result = %c%c%c Total Cash = %d\n", C[0],C[1],C[2], cash);
    }
    else {
        cash -= bet;
        printf("You lose! Result = %c%c%c Total Cash = %d\n", C[0], C[1], C[2], cash);
    }
    free(C);
}

int main() {
    // int a;
    // int *p;
    // a = 10;
    // p = &a;

    // *p = 12;
    // int b= 20;
    // *p = b;
    // printf("%d\n", p);
    // printf("%d\n", *p);

    // int a = 10;
    // int* p = &a;
    // printf("%d\n", p+1);

    // int a = 1025;
    // int *p;
    // p = &a;
    // printf("Size of integer is %d\n", sizeof(int));
    // printf("Address = %d, value = %d\n", p, *p);
    // void* p0;
    // printf("Size of char is %d\n", sizeof(char));
    // printf("Address = %d, value=%d\n", p0);

    // printf("Address = %d, value = %d \n", p0);

    // int x = 5;
    // int* p = &x;
    // *p = 6;
    // int** q = &p;
    // int*** r = &q;
    // printf("%d\n", *p);
    // printf("%d\n", *q);
    // printf("%d\n", **q);
    // printf("%d\n", **r);
    // printf("%d\n", ***r);
    // ***r = 10;
    // printf("x = %d\n", x);
    // **q = *p +2;
    // printf("x = %d\n", x);

    // int a;
    // a = 10;
    // increment(&a);
    // printf("a = %d\n", a);

    // int A[5] = {2,4,5,8,1};
    // printf("%d\n", A);
    // printf("%d\n", &A[0]);
    // printf("%d\n", A[0]);
    // printf("%d\n", *A);

    // for (int i=0;i<5;i++) {
    //     printf("Address = %d\n", &A[i]);
    //     printf("Address = %d\n", A+i);
    //     printf("Value = %d\n", A[i]);
    //     printf("Value = %d\n", *(A+i));
    // }
    // int size = sizeof(A)/sizeof(A[0]);
    // Double(A, size);
    // for (int i=0;i<size;i++) {
    //     printf("%d ", A[i]);
    // }

    // int total = sumOfElements(A, size);
    // printf("The total is %d\n", total);

    // char c[5];
    // c[0] = 'J';
    // c[1]='o';
    // c[2] = 'h';
    // c[3] = 'n';
    // c[4] = '\0';

    // std::string c = "JOHN";

    // std::cout << sizeof(char) * c.size() << std::endl;

    // int a; // Goes on stack
    // int *p; // Goes on stack
    // p = (int*) malloc(sizeof(int)); // Goes on heap

    // *p = 10;
    // free(p);
    // p = (int*) malloc(sizeof(int));

    // *p = 20;
    // free(p);

    // int a;
    // int *p;
    // p = new int;
    // *p = 10;
    // delete p;
    // p = new int[20];
    // delete[] p;

    // int n;
    // printf("Enter size of array\n");
    // scanf("%d", &n);
    // int *A = (int*)calloc(n, sizeof(int));
    // for (int i=0;i<n;i++) {
    //     A[i] = i+1;
    // }
    // int *B = (int*)realloc(A, 2*n*sizeof(int));

    // for (int i=0;i<2*n;i++) {
    //     printf("%d ", B[i]);
    // }
    // free(A);
    // free(B);

    // int a = 2, b = 4;
    // int* ptr = Add(&a, &b);

    // printf("Sum = %d\n", *ptr);
    // int c;
    // int (*p)(int,int);
    // p = Add;
    // c = p(2,3);
    // printf("%d\n", c);

    // void (*p)() = A;
    // B(p);
    // int A[] = {-31,22,-1,50,-6,4};
    // bubbleSort(A, 6, absoluteCompare);
    // for (int i=0;i<6;i++) printf("%d ", A[i]);
    // qsort(A,6,sizeof(int), compare);
    // for (int i=0;i<6;i++) printf("%d ", A[i]);

    int bet;
    while (cash > 0) {
        printf("Total Cash: %d\n", cash);
        printf("What's your bet? $");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash) continue;
        Play(bet);
    }

}