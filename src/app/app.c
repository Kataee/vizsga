#include "app.h"

#include <time.h>

double time_function(void (*callback)()) {
    time_t start = clock();
    callback();
    time_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

void intArrayRun() {
    //intarray
    IntArray* array1 = createArray(7);
/*
    char fileName[20];
    printf("Ird be a file nevet.\n");
    scanf("%s", fileName);
*/
    char fileName[]="in.txt";
    readArray(fileName, &array1);
    printArray(array1);

    IntArray* array2 = createArray(15);
    fillArray(array2->elements, array2->size, 0, 20);
    printArray(array2);
    //file beolvasás, file nevét a console-ban írjuk be
/*
    char outFile[20];
    printf("Ird be a kimeno file nevet.\n");
    scanf("%s", outFile);
  */
    char outFile[] = "out.txt";
    printArrayToFile(outFile, array2);
    //printArray(array2);
    sortArray(array2);
    printArray(array2);


    deleteElement(array2, -6);
    printArray(array2);
    printf("A legkisebb elem: %i\n", minimum(array2));
    printf("A legnagyobb elem: %i\n", maximum(array2));

    IntArray* array3 = createArray(15);
    copy(array3, array2);
    printf("Array3: ");
    printArray(array3);

    printf("A kereses: %i\n", linearSearch(array3, 11));
    printf("A binaris: %i\n", binarySearch(array3, 0,13,18));
}
void wordArrayRun() {
    //wordarray
    wordarray_t *arr = wordarray_create(25);
    char* s = "asd";
    wordarray_add(arr, s);

    wordarray_print(arr);

    printf("%d \n", wordarray_count(arr));
    wordarray_add(arr, "dsdfsdf");
    wordarray_add(arr, "dsdfsd234f");
    wordarray_add(arr, "dsdfsdf23");
    wordarray_print(arr);
    wordarray_delete(arr, "choke"); //error here if we add element more than 2 times, strcpy

    wordarray_print(arr);
    //printf("qqq: %s", arr->chr[10]);

    hashtable_t* hash = hashtable_create(10);
    if (hash == NULL) {
        printf("error: failed to createBintreeInt hash table.\n");
        return;
    }

    hashtable_add(hash, "asd");
    hashtable_add(hash, "asb");
    hashtable_add(hash, "asc");


    hashtable_print(hash);
    hashtable_delete(hash, "asd");
    hashtable_print(hash);

    char *result = hashtable_search(hash, "asd");
    if (result == NULL) {
        printf("asd not found\n");
    } else {
        printf("asd was found");
    }
//#################################################################################
    printf("Binaris kereso fa\n");

    bintree_t *bintree = bintree_create("hello");
    bintree_insert(bintree, "world");

    printf("%d ", bintree_count(bintree));

    bintree_print(bintree);

    bintree_insert(bintree, "test");
    bintree_remove(bintree, "world");

    bintree_print(bintree);
//#######################################################################################
    printf("\nLancolt lista\n");

    linkedlist_t *linkedlist = NULL;

    list_insert(&linkedlist, "hello");
    list_insert(&linkedlist, "world");

    printf("%d ", list_count(linkedlist));

    list_print(linkedlist);

    list_insert(&linkedlist, "test");
    list_remove(&linkedlist, "world");

    list_print(linkedlist);

}
void stackRun() {
    //stack with year, month, day

    STACK* stack1 = createStack(15);
    //pushInStack(stack1, 1990, 02, 24);
    //pushInStack(stack1, 2000, 02, 24);
    //pushInStack(stack1, 2500, 02, 24);
    //printf("Pop: %i\n", popStackS(stack1)->year[0]);
    //printf("Top: %i\n", topStackS(stack1)->year[0]);
    stackIsEmpty(stack1) ? printf("A stack ures\n") : printf("A stack nem ures\n");
    readStack("in.txt", stack1);
    printf("Top: %i\n", topStackS(stack1)->year[0]);
    int* stat = (int*)calloc(9, sizeof(int));
    if (stat == NULL) {
        printf("Error creating stat\n");
        return;
    }
    int yearStat;
    while (!stackIsEmpty(stack1)) {
        yearStat = popStackS(stack1)->year[0];
        yearStat %= 100;
        yearStat /= 10;
        stat[yearStat]++;
    }
    printf("Stat: ");
    for (int i=0; i < 10; ++i) {
        printf("%i ", stat[i]);
    }
    printf("\n");

}
void stackDinamikRun() {
    STACKNODE *topPtr = NULL;
    createStackD(&topPtr);
    for (int i=0; i<5; ++i) {
        pushStackD(&topPtr,i);
    }
    printStackD(topPtr);
    printf("\n");

    printf("top: %i \n", topStackD(topPtr));
    printStackD(topPtr);
    printf("\n");
    popStackD(&topPtr);
    //printf("pop: %i \n", pop(&topPtr));
    printStackD(topPtr);
    printf("\n");
}
void setRun() {
    Set set, set1, set2, set3, set4, set5, set6;
    createSet(&set);


    printf("Size: %i\n", size(set));
    isEmpty(set) ? printf("isEmpty: true\n") : printf("isEmpty: false\n");

    for (int i=15; i>10; --i) {
        insert(&set, i);
        printElements(set);
    }
    erase(&set, 14);
    printElements(set);

    erasePos(&set, 2);
    printElements(set);

    find(set, 16);
    lowerBound(set, 13);
    upperBound(set, 12);


    //unite
    createSet(&set1);
    createSet(&set2);
    createSet(&set3);
    createSet(&set4);
    createSet(&set5);
    createSet(&set6);
    printf("check\n");

    for (int i=1; i<11; i++) {
        insert(&set1, i);
        insert(&set2, i+4);

    }
    printElements(set1);
    printElements(set2);
    uniteSet(&set1, &set2, &set3);
    printf("A ket halmaz egyesitve: ");
    printElements(set3);
    printf("\n");

    //cross Section
    crossSection(&set1, &set2, &set4);
    printf("A ket halmaz metszete: ");
    printElements(set4);
    printf("\n");

    //substraction
    substraction(&set1, &set2, &set5);
    printf("A ket halmaz kulombsege: ");
    printElements(set5);
    printf("\n");

    //subset
    subset(&set1, &set6, -234,7);
    printf("A reszhalmaz: ");
    printElements(set6);
    printf("\n");
}
void queueRun() {

    QUEUENODE *asd;
    createQueue(&asd, 10);
    isEmptyQueue(asd) ? printf("A queue ures\n") : printf("A queue nem ures\n");
    isFullQueue(asd) ? printf("A queue tele\n") : printf("A queue nincs tele\n");
    insertQueue(asd, 365);
    printQueue(asd);
    printf("Remove first item: %i\n", removeFirstItemQueue(asd));
    fillQueue(asd);
    printQueue(asd);
    topItemQueue(asd);
    printf("Remove first item: %i\n", removeFirstItemQueue(asd));
    printf("Remove first item: %i\n", removeFirstItemQueue(asd));
    printf("Remove first item: %i\n", removeFirstItemQueue(asd));
    insertQueue(asd, 9);
    printQueue(asd);

}
void queueDinamikRun() {
    QUEUENODED* asd;
    createQueueD(&asd);
    deleteFirstQueueD(&queueDFront);

    insertQueueD(&queueDFront, &queueDLast, 1);
    insertQueueD(&queueDFront, &queueDLast, 2);
    insertQueueD(&queueDFront, &queueDLast, 3);
    insertQueueD(&queueDFront, &queueDLast, 4);
    printQueueD(queueDFront);
    deleteFirstQueueD(&queueDFront);
    deleteFirstQueueD(&queueDFront);
    printQueueD(queueDFront);
    printf("\n");
    isQueueDEmpty(asd) ? printf("QueueD ures\n") : printf("QueueD nem ures\n");
}
void singleLinkedListRun() {
    NodeType *asd = NULL;
    inicializalas();
    Create(&asd);
    /*
    ListaBejaras();
    ElemBeszurasElore(1);
    ElemBeszurasElore(2);
    ElemBeszurasElore(3);
    ElemBeszurasElore(4);
    ListaBejaras();
    ElemBeszurasVegere(9);
    ListaBejaras();

    BeszurasMegadottHelyre(99,3);
    ListaBejaras();

    TorlesElsoElem();
    ListaBejaras();

    TorlesUtolsoElem();
    ListaBejaras();

    ListabolTorles(2);
    ListaBejaras();

    ListabanKereses(1) ? printf("VAN\n") : printf ("nincs\n");

    ListaTeljesTorlese();
    ListaBejaras();
     */
    ListaBejaras();
    ElemBeszurasSorrendben(5);
    ElemBeszurasSorrendben(6);
    ElemBeszurasSorrendben(4);
    ElemBeszurasSorrendben(1);
    ListaBejaras();
}
void doublyLinkedListRun() {
    /* Start with the empty list */
    struct Node* head = NULL;

    // Insert 6.  So linked list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the beginning. So linked list becomes
    // 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning. So linked list becomes
    // 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So linked list becomes
    // 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8, after 7. So linked list becomes
    // 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    printf("Created DLL is: ");
    printList(head);

    deleteNode(&head, head->next->next->next);
    printList(head);

}
void bintreeIntRun() {
    BintreeInt * asd =NULL;
    //27, 14, 35, 10, 19, 31, 42
    insertBintreeInt(&asd, 27);
    insertBintreeInt(&asd, 14);
    insertBintreeInt(&asd, 35);
    insertBintreeInt(&asd, 10);
    insertBintreeInt(&asd, 19);
    insertBintreeInt(&asd, 31);
    insertBintreeInt(&asd, 42);

    printf("inorder ");
    inorder(asd);
    printf("\n");
    printf("preorder ");
    preorder(asd);
    printf("\n");
    printf("postorder ");
    postorder(asd);
    printf("\n");
    findBintreeInt(asd, 7) ? printf("True\n") : printf("False\n");

    //deleteNode(asd, 8);
    inorder(asd);
    printf("Max: %i \n", maxValueNodeBintreeInt(asd)->info);
    printf("Min: %i \n", minValueNodeBintreeInt(asd)->info);
    nextNodeBintreeInt(asd) ? printf("Next: %i \n", asd->right->info) : printf("Nincsz\n");
    printf("Min: %i \n", minValueNodeBintreeInt(asd)->info);

    //struct Node* temp = parent(asd,5);
    //printf("parent: %i\n", temp->info);


    fel2();
    //haha ez a B sequence nem clean code + még
    // lehetne fÜggvényesíteni is, de sokat gondolkodtam rajta
    //mire egészen összeállt az egész, ezért hagytam benne mindenféle kiírást is
    //hogy lássék benne a munkám, nem mindenkinek megy ám olyan könnyen, hiába
    //easy level a feladat #kellazátmenő
}
void bintreeRun() {
    bintree_t* binword;
    binword = bintree_create("egy");
    bintree_insert(binword, "ketto");
    bintree_insert(binword, "harom");
    bintree_insert(binword, "negy");
    bintree_print(binword);
    printf("\nMegtalalva: %s\n", bintree_search(binword, "egy")->word);
    bintree_remove(binword, "egy");
    bintree_print(binword);
    printf("Count: %i\n", bintree_count(binword));
    bintree_free(binword);
}
void heapRun() {

    HEAP *h = createHeap(32);
    FILE *f = fopen("in.txt", "r");
    int buffer;
    while (fscanf(f, "%i", &buffer) != EOF) {
        insertHeap(h, buffer);
    }
    printf("Print as it is:\n");
    printHeap(h);
    printf("\nmax: %i\n", max(h));
    printf("size: %i\n", h->size);
    printf("Print: \n");
    printHeap(h);
    printf("Max: %i\n", torolmax(h));
    printHeap(h);
    fclose(f);

    //fel22();

}