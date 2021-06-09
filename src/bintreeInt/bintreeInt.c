//
// Created by Kataee on 09/06/2021.
//

BintreeInt* createBintreeInt() {
    BintreeInt* root = (BintreeInt*)malloc(sizeof(BintreeInt));
    if(!root) {
        exit(1);
    }

    root->left = NULL;
    root->right = NULL;

    return root;
}
BintreeInt* insertBintreeInt (BintreeInt** node, int info) {
    if (*node == NULL) {
        *node = createBintreeInt();
        (*node)->left = (*node)->right = NULL;
        (*node)->info = info;
    } else if(info < (*node)->info) {
        (*node)->left = insertBintreeInt(&(*node)->left, info);
    } else if(info > (*node)->info) {
        (*node)->right = insertBintreeInt(&(*node)->right, info);
    }

    return *node;
}

void inorder(BintreeInt* node) {
    if(node == NULL) {
        return;
    }
    if (node->left) {
        inorder(node->left);

    }
    printf("%i ", node->info);
    if (node->right) {
        inorder(node->right);
    }

}

void preorder(BintreeInt* node) {
    printf("%i ", node->info);
    if (node->left) {
        preorder(node->left);
    }
    if (node->right) {
        preorder(node->right);
    }
}
void postorder(BintreeInt* node) {
    if (node->left) {
        postorder(node->left);
    }
    if (node->right) {
        postorder(node->right);

    }
    printf("%i ", node->info);
}

bool findBintreeInt(struct BintreeInt* node, int info) {
    if (node == NULL) {
        return false;
    }

    if (node->info == info) {
        return true;
    }
    bool res1 = findBintreeInt(node->left, info);
    if (res1) {
        return true;
    }

    bool res2 = findBintreeInt(node->right, info);
    return res2;
}

struct BintreeInt* deleteNodeBintreeInt(struct BintreeInt* root, int info) {
    // base case
    if (root == NULL) {
        return root;
    }

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (info < root->info) {
        root->left = deleteNodeBintreeInt(root->left, info);
    }

        // If the key to be deleted
        // is greater than the root's
        // key, then it lies in right subtree
    else if (info > root->info) {
        root->right = deleteNodeBintreeInt(root->right, info);
    }
        // if key is same as root's key,
        // then This is the node
        // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct BintreeInt *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BintreeInt *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct BintreeInt *temp = minValueNodeBintreeInt(root->right);

        // Copy the inorder
        // successor's content to this node
        root->info = temp->info;

        // Delete the inorder successor
        root->right = deleteNodeBintreeInt(root->right, temp->info);
    }
    return root;

}

struct BintreeInt* minValueNodeBintreeInt(struct BintreeInt* node) {
    struct BintreeInt* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct BintreeInt* maxValueNodeBintreeInt(struct BintreeInt* node) {
    struct BintreeInt* current = node;

    while (current && current->right != NULL) {
        current = current->right;
    }

    return current;
}

struct BintreeInt* nextNodeBintreeInt(struct BintreeInt* node) {
    if (node->left != NULL) {
        return node->left;
    }
    if (node->right != NULL) {
        return node->right;
    }
    printf("Nincs gyermeke");
    return NULL;
}

//inorder bejárással
struct BintreeInt* parentBintreeInt(BintreeInt* node, int info) {
    printf("run1 ");
    if(node == NULL) {
        printf("Nincs semmi sehol\n");
        return NULL;
    }
    printf("run2 ");
    if (node->info == info) {
        printf("The parent is the root\n");
        return NULL;
    }
    printf("run3 ");
    if (node->left->info == info || node->right->info == info) {
        printf("run ");
        return node;
    }
    printf("run4 ");
    if (node->left) {
        inorder(node->left);
    }
    if (node->right) {
        inorder(node->right);
    }
    //printf("%i ", node->info);
}



//#################
void fel2() {
    FILE *f;

    //open File
    if ((f = fopen("in.txt", "r")) == NULL) {
        printf("Error opening file");
        return;
    }

    //First line consists of an integer N, denoting size of S.
    int N;
    fscanf(f,"%i", &N);
    printf("N: %i\n", N);

    int* S = (int*)malloc(N*sizeof(int));
    if (S==NULL) {
        printf("Error allocating memory for S\n");
        exit(1);
    }

    //read the numbers into to array
    //Second line consists of N space separated integers, denoting elements of S
    for (int i=0; i<N; ++i) {
        fscanf(f, "%i", &S[i]);
    }

    //print the array
    printf("S: ");
    for(int i=0; i<N; ++i) {
        printf("%i ", S[i]);
    }
    printf("\n");


    //Next line consists of an integer Q, denoting number of operations
    int Q, value,pos;
    fscanf(f, "%i", &Q);
    printf("Q: %i\n",Q);
    printf("max: %i\n", findMax(S,N));


    //insert
    for (int i=0; i<Q; ++i) {
        print(S,N);
        fscanf(f, "%i", &value);
        printf("value: %i\n",value);
        int max = findMax(S, N);
        if (value == max)
            continue;

        if (hasValue(S, N,value) == 0) {
            if (value < max) {

                S = (int *) realloc(S, (N + 1) * sizeof(int));
                N++;
                printf("N: %i\n", N);

                //looking for where to put the vlaue in
                for (int j = 0; j < N - 1; ++j) {
                    if (S[j] > value) {
                        pos = j;
                        break;
                    }
                }

                //copy & insert
                for (int k = N - 1; k >= pos; --k) {
                    S[k] = S[k - 1];
                }
                S[pos] = value;
            }
            //printf("check\n");

            if (value > max) {
                S = (int *) realloc(S, (N + 1) * sizeof(int));
                N++;
                printf("N: %i\n", N);
                //looking for where to put the vlaue in
                for (int j = 0; j <= N - 1; ++j) {
                    if (S[j] == max) {
                        pos = j;
                        break;
                    }
                }

                //copy & insert
                for (int k = N - 1; k > pos; --k) {
                    S[k] = S[k - 1];
                }
                S[pos + 1] = value;
            }
            continue;
        }
        if (hasValue(S, N,value) == 1) {
            S = (int *) realloc(S, (N + 1) * sizeof(int));
            N++;
            printf("N: %i\n", N);
            //looking for where to put the value in
            //max position
            for (int j = 0; j <= N - 1; ++j) {
                if (S[j] == max) {
                    pos = j;
                    break;
                }
            }
            printf("max pos: %i\n",pos);
            //value position
            for (int j = pos; j < N-1; ++j) {
                if (S[j] > value) {
                    printf("ok, %i > %i ", S[j], value);
                    pos = j;
                    //break;
                }
            }
            printf("\n");

            print(S,N);
            printf("val pos: %i\n",pos);


            //copy & insert
            //here is problem
            int pos1;
            for (int k = N-1; k > pos+1; --k) {
                S[k] = S[k - 1];
                pos1=k;
            }
            printf("pos1: %i\n", pos1);

            //adjusting pos
            //pos = pos1;
            print(S,N);

            S[pos+1] = value;
            continue;
        }
        if (hasValue(S, N,value) == 2) {
            continue;
        }


        //print
        print(S,N);
    }

    print(S,N);



}

int findMax(int* S, int N) {
    int max = S[0];
    for (int i=1; i < N; ++i) {
        if (max < S[i]) {
            max = S[i];
        }
    }
    return max;
}

int hasValue(int* S, int N, int value) {
    int isThere = 0;
    for (int i=0; i<N; ++i) {
        if (value == S[i])
            isThere++;
    }
    printf("hasValue: %i - %i\n", isThere, value);
    return isThere;
}

void print(int* S, int N) {
    for (int i=0; i<N; ++i) {
        printf("%i ", S[i]);
    }
    printf("\n");
}