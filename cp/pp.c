#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int coff;
	int expx;
	int expy;
	struct node* next;
}node;

node* createNode(int coff,int expx,int expy){
	node* k = (node*)malloc(sizeof(node));
	k->coff=coff;
	k->expx=expx;
	k->expy=expy;
	k->next=NULL;
	return k;
}

void insert(node** p,int coff,int expx,int expy){
	node* temp = createNode(coff,expx,expy);
	if(*p == NULL || (*p)->expx < expx || ((*p)->expx == expx && (*p)->expy==expy)){
		temp->next=*p;
		*p=temp;
	}else{
		node* res=*p;
		while(res->next != NULL && (res->next->expx > expx || (res->next->expx == expx && res->next->expy >= expy))){
			res=res->next;
		}
		if(res->expx == expx && res->expy==expy){
			res->coff += coff;
			free(temp);
		}else{
			temp->next=res->next;
			res->next=temp;
		}
	}
}

void display(node* poly) {
    while (poly != NULL) {
        printf("%dx^%dy^%d", poly->coff, poly->expx, poly->expy);
        poly = poly->next;
        if (poly != NULL)
            printf(" + "); 
    }
    printf("\n");
}

int main() {
    node* poly1 = NULL;

    insert(&poly1, 5, 2, 3);
    insert(&poly1, 4, 1, 2);
    insert(&poly1, 3, 0, 1);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    return 0;
}