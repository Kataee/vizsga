//
// Created by Kataee on 09/06/2021.
//

#include "heap.h"
HEAP* createHeap(int max) {
    HEAP* h = (HEAP*)malloc(sizeof(HEAP));
    h->size = 0;
    h->maxSize = max;
    h->data = (int*)malloc(max * sizeof(int));
    return h;
}

void insertHeap(HEAP* h, int Element) {
    h->size++;
    h->data[h->size] = Element;
    upHeap(h, h->size);
}

void upHeap(HEAP* h, int i) {
    int seged;
    while((i > 1) && (h->data[i/2] < h->data[i])) {
        seged = h->data[i/2];
        h->data[i/2] = h->data[i];
        h->data[i] = seged;
        i/=2;
    }
}

void downHeap(HEAP* h, int i) {
    while (2*i <= h->size) {
        int j=2*i;
        if (j < h->size && h->data[j] < h->data[j+1]) {
            j++;
        }

        if (h->data[j] <= h->data[i]) {
            break;
        }
        //swap(&h->data[i], &h->data[j]);
        swap(&h->data[i], &h->data[j]);
        i=j;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void kupacrendez(HEAP* h) {
    for (int i = h->size/2; i>=1; i--) {
        downHeap(h,i);
    }

    for (int i=1; 1 <= h->size; ++i) {
        printf("X: %i   ", torolmax(h));
        swap(&h->data[1], &h->data[h->size-i+1]);
        downHeap(h,1);
    }
    printf("\n");
}

int max(HEAP* h) {
    int max = h->data[1];
    for (int i=1; i<h->size; ++i) {
        if (max < h->data[i]) {
            max = h->data[i];
        }
    }
    return max;
}

int torolmax(HEAP* h) {
    int seged = h->data[1];
    h->data[1] = h->data[h->size];
    h->data[h->size] = seged;
    //printf("size-- %i ", h->size-1);
    h->size--;
    return seged;
}

//Két kupac összeolvasztása
HEAP* two(HEAP* h1, HEAP* h2) {
    int size = h1->size + h2->size;
    HEAP* asd = createHeap(size);
    int index;
    for (int i=1; i <=  h1->size; ++i) {
        asd->data[i] = h1->data[i];
        index = i;
    }
    //next location
    index++;
    //for (int i=index; )



    return asd;
}

void printHeap (HEAP* h) {
    for (int i=1; i <= h->size; ++i) {
        printf("%i ", h->data[i]);
    }
}


//fel2################################
//##############################################################
//EUR

void fel22() {
    FILE *f;

    //open File
    if ((f = fopen("in.txt", "r")) == NULL) {
        printf("Error opening file");
        return;
    }

    //First line gives the number of lines
    int length;
    fscanf(f,"%i", &length);
    printf("Length: %i\n", length);

    HEAP* h = createHeap(length * 3);

    int year, month, eur, filler = 0, eurData;
    int* data;
    bool printIfTrue = false;
    data = (int*)malloc((length*3)*sizeof(int));
    if (!data){
        printf("Error allocating data array");
        exit(2);
    }

    for (int i=0, j=0; i<length; i++, j+=3) {
        //---------
        fscanf(f, "%i", &year);
        fscanf(f, "%i", &month);
        fscanf(f, "%i", &eur);
        eurData=eur;
        filler = eur%100;
        eur /=100;
        //---------

        data[j] = year;
        data[j+1]=month;
        data[j+2] = eurData;
        insertHeap(h, eurData);

        //--------
        if (printIfTrue) {
            printf("Year: %i, month: ", year);
            switch (month) {
                case 1:
                    printf("Januar ");
                    break;
                case 2:
                    printf("Februar ");
                    break;
                case 3:
                    printf("Marcius ");
                    break;
                case 4:
                    printf("Aprilis ");
                    break;
                case 5:
                    printf("Majus ");
                    break;
                case 6:
                    printf("Junius ");
                    break;
                case 7:
                    printf("Julius ");
                    break;
                case 8:
                    printf("Augusztus ");
                    break;
                case 9:
                    printf("Szeptember ");
                    break;
                case 10:
                    printf("Oktober ");
                    break;
                case 11:
                    printf("November ");
                    break;
                case 12:
                    printf("December ");
                    break;
                default:
                    printf("Hibas honap adat\n ");
            }
            printf(" eur: %i, filler: %i\n", eur, filler);
        }

    }
    printf("Maximum: %i\n", max(h));

    int amx = data[2];
    for (int i=2; i < length*3; i+=3) {
        if (amx < data[i]) {
            amx = data[i];
        }
    }
    printf("Amx: %i\n", amx);
}