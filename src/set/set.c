//
// Created by Kataee on 08/06/2021.
//

#include "set.h"

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void printElements(Set set) {
    if (set.size == 0) {
        printf("Nincs a halmaznak eleme");
    }
    for (int i=0; i < set.size; ++i) {
        printf("%i ", set.elements[i]);
    }
    printf("   size: %i\n", set.size);
}

Set* createSet(Set* set) {
    (*set).elements = (int*)malloc(0 * sizeof(int));
    (*set).size = 0;
    if ( !(set)) {
        return NULL;
    }
    //see above, line 20
    //pset->size = 0;
    return set;
}

int size(Set set) {
    return set.size;
}

bool isEmpty(Set set) {
    if (set.size == 0) {
        return true;
    }
    return false;
}

void insert(Set* set, int element) {
    for (int i=0; i < (*set).size; ++i) {
        if (element == (*set).elements[i] ) {
            printf("Ez a szam: %i mar eleme a halmaznak\n", element);
            return;
        }
    }
    (*set).size++;
    (*set).elements = (int*)realloc((*set).elements, (*set).size * sizeof(int));

    if ((*set).size) {
        (*set).elements[(*set).size-1] = element;
    } else { exit(1); }

    qsort((*set).elements, (*set).size, sizeof(int), cmpfunc);
}

void erase(Set* set, int element) {
    bool isElement = false;
    int index;
    for (int i=0; i < (*set).size; ++i) {
        if (element == (*set).elements[i]) {
            isElement = true;
            index = i; //keep the index of the element
            break;
        }
    }

    if (isElement) {
        int temp;
        temp = (*set).elements[(*set).size-1];
        (*set).elements[index] = (*set).elements[(*set).size-1];
        (*set).size--;
        (*set).elements = (int*)realloc((*set).elements, (*set).size * sizeof(int));
        qsort((*set).elements, (*set).size, sizeof(int), cmpfunc);
    } else {
        printf("Ez az elem nem letezik a halmazban.\n");
        return;
    }
}

void erasePos(Set* set, int position) {
    if (position < 0 || position > (*set).size-1) {
        printf("Ez a pozicio nem letezik\n");
        return;
    }
    (*set).elements[position] = (*set).elements[(*set).size-1];
    (*set).size--;
    (*set).elements = (int*)realloc((*set).elements, (*set).size * sizeof(int));
    qsort((*set).elements, (*set).size, sizeof(int), cmpfunc);
}

void clear(Set* set) {
    (*set).elements = (int*)realloc((*set).elements, 0);
}

int find(Set set, int element) {
    int position;
    for (int i=0; i < set.size; ++i ) {
        if (element == set.elements[i]) {
            printf("A keresett elem pozicioja: %i\n", i);
            return i;
        }
    }
    printf("Nem talaltuk meg a keresett elemet.\n");
    return -1;
}

int lowerBound(Set set, int element) {
    int lowerBound, index=0;

    do {
        lowerBound = set.elements[index];
        index++;
    } while (element >= set.elements[index]);
    printf("A lowerBound: %i\n", lowerBound);
    return lowerBound;
}

int upperBound(Set set, int element) {
    int upperBound, index=0;

    do {
        upperBound = set.elements[index];
        if (element < set.elements[0]) {
            printf("Az upperBound: %i\n", upperBound);
            return upperBound;
        }
        if (element == set.elements[index]) {
            printf("Az upperBound: %i\n", upperBound);
            return upperBound;
        }
        index++;
        if (index == set.size-1) {
            printf("Az upperBound: %i\n", set.elements[index]);
            return set.elements[index];
        }
    } while (index < set.size);

}


//--------------------------------------
//1. egyesítés
//2. metszet
//3. kívonás
//4. részhalmazok meghatározása

//egyesítés
void uniteSet(Set* set1, Set* set2, Set* set3) {
    int element;
    for (int i=0, j=0; i < (*set1).size, j<(*set2).size; ++i, ++j) {
        //printf("%i ", (*set1).elements[i]);
        insert(set3, (*set1).elements[i]);
        insert(set3, (*set2).elements[j]);
    }
}

void crossSection(Set* set1, Set* set2, Set* set4) {
    for (int i=0; i < (*set1).size; ++i) {
        if (find(*set2, (*set1).elements[i]) != -1) {
            insert(set4, (*set1).elements[i]);
        }
    }
}

void substraction(Set* set1, Set* set2, Set* set5) {
    for (int i=0; i < (*set1).size; ++i) {
        if (find(*set2, (*set1).elements[i]) == -1) {
            insert(set5, (*set1).elements[i]);
        }
    }
}

void subset(Set* set1, Set* set6, int lowerBoundInt, int upperBoundInt) {
    if ((*set1).size==0) {
        printf("A halmaz ures");
        exit(1);
    }
    int lowerBoundIndex, upperBoundIndex;
    lowerBoundIndex = find(*set1, lowerBound(*set1, lowerBoundInt));
    upperBoundIndex = find(*set1, upperBound(*set1, upperBoundInt));

    for (int i=lowerBoundIndex; i<=upperBoundIndex; ++i) {
        insert(set6, (*set1).elements[i]);
    }
}
