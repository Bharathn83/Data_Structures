/**
3. Deletion of alternative node in single linked list
****/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* newnode(int data){
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}

struct node* deleteAlt(struct node *head){
    if(head==NULL){
        printf("\nList is Empty\n");
        return NULL;
    }
    struct node *prev=head, *node=head->next;
    while(prev!=NULL && node!=NULL)
    {
        prev->next=node->next;
        free(node);
        prev=prev->next;
        if(prev!=NULL)
            node=prev->next;
    }
    return head;
}
void display(struct node *head){
    if(head==NULL)
        return;
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("\n");
}

struct node* insertbeg(struct node *head,int data){
    struct node *tmp=newnode(data);
    if(head==NULL){
        return tmp;
    }
    tmp->next=head;
    return tmp;
}
int main(){
    char ch;
    struct node*head=NULL;
    int data;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.insert at begin\n2.delete alternative\n3.display\n*.exit\n");
        scanf("%c",&ch);
        while(getchar()!='\n');
        switch (ch)
        {
        case '1':
            printf("\nEnter data to inserted\n");
            scanf("%d",&data);
            while(getchar()!='\n');
            head=insertbeg(head,data);
            break;
        case '2':
            head=deleteAlt(head);
            break;
        case '3':
            display(head);
            break;
        case '*':
            return 0;
        default:
            printf("\nEnter correct choice\n");
            break;
        }
        fflush(stdin);
    }
}